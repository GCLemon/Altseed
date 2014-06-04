
#include "FBX2MDL.FBXLoader.h"

namespace FBX2MDL
{
	ace::Vector3DF FBXLoader::LoadPosition(FbxMesh* fbxMesh, int32_t ctrlPointIndex)
	{
		ace::Vector3DF position;

		auto controlPoints = fbxMesh->GetControlPoints();
		
		position.X = controlPoints[ctrlPointIndex][0];
		position.Y = controlPoints[ctrlPointIndex][1];
		position.Z = controlPoints[ctrlPointIndex][2];
	
		return position;
	}

	ace::Vector3DF FBXLoader::LoadNormal(FbxLayerElementNormal* normals, int32_t vertexID, int32_t ctrlPointIndex)
	{
		ace::Vector3DF normal;

		if (normals->GetMappingMode() == FbxGeometryElement::eByPolygonVertex)
		{
			switch (normals->GetReferenceMode())
			{
			case FbxGeometryElement::eDirect:
				normal.X = normals->GetDirectArray().GetAt(vertexID)[0];
				normal.Y = normals->GetDirectArray().GetAt(vertexID)[1];
				normal.Z = normals->GetDirectArray().GetAt(vertexID)[2];
				break;
			case FbxGeometryElement::eIndexToDirect:
			{
				int id = normals->GetIndexArray().GetAt(vertexID);
				normal.X = normals->GetDirectArray().GetAt(id)[0];
				normal.Y = normals->GetDirectArray().GetAt(id)[1];
				normal.Z = normals->GetDirectArray().GetAt(id)[2];
			}
				break;
			}
		}

		return normal;
	}

	ace::Vector2DF FBXLoader::LoadUV(FbxMesh* fbxMesh, FbxLayerElementUV* uvs, int32_t vertexID, int32_t ctrlPointIndex, int32_t polygonIndex, int32_t polygonPointIndex)
	{
		ace::Vector2DF uv;

		switch (uvs->GetMappingMode())
		{
			case FbxGeometryElement::eByControlPoint:
				switch (uvs->GetReferenceMode())
				{
					case FbxGeometryElement::eDirect:
					{
						uv.X = uvs->GetDirectArray().GetAt(ctrlPointIndex)[0];
						uv.Y = uvs->GetDirectArray().GetAt(ctrlPointIndex)[1];
						break;
					}
					case FbxGeometryElement::eIndexToDirect:
					{
						 auto id = uvs->GetIndexArray().GetAt(ctrlPointIndex);
						 uv.X = uvs->GetDirectArray().GetAt(id)[0];
						 uv.Y = uvs->GetDirectArray().GetAt(id)[1];
						 break;
					}	
				}
				break;

			case FbxGeometryElement::eByPolygonVertex:
			{
				auto textureUVIndex = fbxMesh->GetTextureUVIndex(polygonIndex, polygonPointIndex);
				switch (uvs->GetReferenceMode())
				{
					case FbxGeometryElement::eDirect:
					case FbxGeometryElement::eIndexToDirect:
					{
						uv.X = uvs->GetDirectArray().GetAt(textureUVIndex)[0];
						uv.Y = uvs->GetDirectArray().GetAt(textureUVIndex)[1];
						break;
					}
				}
				break;
			}
		default:
			break;
		}

		// �㉺�t
		uv.Y = 1.0 - uv.Y;
		
		return uv;
	}

	ace::Color FBXLoader::LoadVertexColor(FbxMesh* fbxMesh, FbxLayerElementVertexColor* colors, int32_t vertexID, int32_t ctrlPointIndex, int32_t polygonIndex, int32_t polygonPointIndex)
	{
		ace::Color color;

		switch (colors->GetMappingMode())
		{
		default:
			break;

		case FbxGeometryElement::eByControlPoint:
			switch (colors->GetReferenceMode())
			{
			case FbxGeometryElement::eDirect:
				color.R = static_cast<uint8_t>(colors->GetDirectArray().GetAt(ctrlPointIndex)[0] * 255);
				color.G = static_cast<uint8_t>(colors->GetDirectArray().GetAt(ctrlPointIndex)[1] * 255);
				color.B = static_cast<uint8_t>(colors->GetDirectArray().GetAt(ctrlPointIndex)[2] * 255);
				color.A = static_cast<uint8_t>(colors->GetDirectArray().GetAt(ctrlPointIndex)[3] * 255);
				break;

			case FbxGeometryElement::eIndexToDirect:
			{
				auto id = colors->GetIndexArray().GetAt(ctrlPointIndex);
				color.R = static_cast<uint8_t>(colors->GetDirectArray().GetAt(id)[0] * 255);
				color.G = static_cast<uint8_t>(colors->GetDirectArray().GetAt(id)[1] * 255);
				color.B = static_cast<uint8_t>(colors->GetDirectArray().GetAt(id)[2] * 255);
				color.A = static_cast<uint8_t>(colors->GetDirectArray().GetAt(id)[3] * 255);
			}
				break;
			default:
				break;
			}
			break;

		case FbxGeometryElement::eByPolygonVertex:
			switch (colors->GetReferenceMode())
			{
			case FbxGeometryElement::eDirect:
				color.R = static_cast<uint8_t>(colors->GetDirectArray().GetAt(vertexID)[0] * 255);
				color.G = static_cast<uint8_t>(colors->GetDirectArray().GetAt(vertexID)[1] * 255);
				color.B = static_cast<uint8_t>(colors->GetDirectArray().GetAt(vertexID)[2] * 255);
				color.A = static_cast<uint8_t>(colors->GetDirectArray().GetAt(vertexID)[3] * 255);
				break;

			case FbxGeometryElement::eIndexToDirect:
				auto id = colors->GetIndexArray().GetAt(vertexID);
				color.R = static_cast<uint8_t>(colors->GetDirectArray().GetAt(id)[0] * 255);
				color.G = static_cast<uint8_t>(colors->GetDirectArray().GetAt(id)[1] * 255);
				color.B = static_cast<uint8_t>(colors->GetDirectArray().GetAt(id)[2] * 255);
				color.A = static_cast<uint8_t>(colors->GetDirectArray().GetAt(id)[3] * 255);
				break;
			}

			break;
		}
		
		return color;
	}

	void FBXLoader::LoadSkin(FbxMesh* fbxMesh, std::vector<BoneConnector>& boneConnectors, std::vector<FbxVertexWeight>& weights)
	{
		weights.resize(fbxMesh->GetControlPointsCount());

		auto skinCount = fbxMesh->GetDeformerCount(FbxDeformer::eSkin);

		for (auto skinInd = 0; skinInd < skinCount; skinInd++)
		{
			auto skin = (FbxSkin*) fbxMesh->GetDeformer(skinInd, FbxDeformer::eSkin);
		
			auto clusterCount = skin->GetClusterCount();
			for (auto clusterInd = 0; clusterInd < clusterCount; clusterInd++)
			{
				auto cluster = skin->GetCluster(clusterInd);
				if (cluster->GetLink() == nullptr) continue;
				
				// �{�[���擾
				auto name = cluster->GetLink()->GetName();

				FbxAMatrix m1, m2;
				cluster->GetTransformMatrix(m1);
				cluster->GetTransformLinkMatrix(m2);

				auto m1_ = ToAce(m1);
				auto m2_ = ToAce(m2);

				int32_t id = boneConnectors.size();

				BoneConnector connector;
				connector.Name = ace::ToAString(name);

				auto m2_inv = m2_.GetInverted();
				auto m = m1_ * m2_inv;
				
				connector.TransformMatrix = m1_;
				connector.TransformLinkMatrix = m2_;
				connector.OffsetMatrix = m;

				boneConnectors.push_back(connector);

				// ���_���Ƃ̃E�G�C�g���擾
				auto indexCount = cluster->GetControlPointIndicesCount();
				auto vindices = cluster->GetControlPointIndices();
				auto vweights = cluster->GetControlPointWeights();

				for (auto ind = 0; ind < indexCount; ind++)
				{
					FbxWeight data;
					data.Index = id;
					data.Weight = (float) vweights[ind];

					weights[vindices[ind]].Data.push_back(data);
				}
			}
		}

		// �E�G�C�g�v�Z
		for (auto& weight : weights)
		{
			if (weight.Data.size() == 0)
			{
				assert(weight.Indexes[0] == 255);
				assert(weight.Indexes[1] == 0);
			}
			else
			{
				weight.Data.push_back(FbxWeight());
				weight.Data.push_back(FbxWeight());
				weight.Data.push_back(FbxWeight());
				std::sort(weight.Data.begin(), weight.Data.end(), FbxWeight());

				float fSum = 0.0f;
				for (auto ind = 0; ind < 4; ind++)
				{
					fSum += weight.Data[ind].Weight;
				}

				if (fSum > 0)
				{
					for (auto ind = 0; ind < 4; ind++)
					{
						weight.Indexes[ind] = weight.Data[ind].Index;
						weight.Weights[ind] = (weight.Data[ind].Weight / fSum) * 255;
					}

					weight.Weights[0] = 255 - weight.Weights[1] - weight.Weights[2] - weight.Weights[3];
				}
				else
				{
					assert(weight.Indexes[0] == 255);
					assert(weight.Indexes[1] == 0);
				}
			}
		}
	}

	void FBXLoader::LoadMaterial(FbxMesh* fbxMesh, FbxLayerElementMaterial* materials, std::vector<Material>& dst)
	{
		auto node = fbxMesh->GetNode();
		if (node == nullptr) return;
	
		auto materialCount = node->GetMaterialCount();

		for (auto materialIndex = 0; materialIndex < materialCount; materialIndex++)
		{
			auto material = node->GetMaterial(materialIndex);

			auto name = material->GetName();

			auto m = Material();

			m.Name = ace::ToAString(name);

			// �e�N�X�`���擾
			FbxProperty prop = material->FindProperty(FbxSurfaceMaterial::sDiffuse);
			auto fileTextureCount = prop.GetSrcObjectCount<FbxFileTexture>();

			for (auto fileTextureIndex = 0; fileTextureIndex < fileTextureCount; fileTextureIndex++)
			{
				auto texture = prop.GetSrcObject<FbxFileTexture>(fileTextureIndex);
				if (texture != nullptr)
				{
					m.DiffuseTexturePath = ace::ToAString(texture->GetRelativeFileName());
				}
			}

			dst.push_back(m);
		}

	}

	std::shared_ptr<Mesh> FBXLoader::LoadMesh(FbxMesh* fbxMesh)
	{
		assert(fbxMesh->GetLayerCount() > 0);

		auto node = fbxMesh->GetNode();
		auto layer = fbxMesh->GetLayer(0);
		auto uvs = layer->GetUVs();
		auto vcolors = layer->GetVertexColors();
		auto normals = layer->GetNormals();
		auto binormals = layer->GetBinormals();
		auto materials = layer->GetMaterials();

		auto controlPoints = fbxMesh->GetControlPoints();
		auto controlPointsCount = fbxMesh->GetControlPointsCount();

		auto polygonCount = fbxMesh->GetPolygonCount();

		std::vector<FbxVertexWeight> weights;
		std::vector<FbxFace> faces;
		std::vector<BoneConnector> boneConnectors;
		std::vector<Material> materials_;

		LoadSkin(fbxMesh, boneConnectors, weights);

		// �|���S������
		int32_t vertexID = 0;
		for (int32_t polygonIndex = 0; polygonIndex < polygonCount; polygonIndex++)
		{
			int polygonPointCount = fbxMesh->GetPolygonSize(polygonIndex);

			FbxFace face;

			for (int32_t polygonPointIndex = 0; polygonPointIndex < polygonPointCount; polygonPointIndex++)
			{
				auto ctrlPointIndex = fbxMesh->GetPolygonVertex(polygonIndex, polygonPointIndex);

				Vertex v;

				v.Position = LoadPosition(fbxMesh, ctrlPointIndex);
				
				for (auto i = 0; i < 4; i++)
				{
					v.Weight[i] = weights[ctrlPointIndex].Weights[i];
					v.WeightIndexOriginal[i] = weights[ctrlPointIndex].Indexes[i];
				}

				if (normals != nullptr)
				{
					v.Normal = LoadNormal(normals, vertexID, ctrlPointIndex);
				}

				if (uvs != nullptr)
				{
					v.UV = LoadUV(fbxMesh, uvs, vertexID, ctrlPointIndex, polygonIndex, polygonPointIndex);
				}

				if (vcolors != nullptr)
				{
					v.Color = LoadVertexColor(fbxMesh, vcolors, vertexID, ctrlPointIndex, polygonIndex, polygonPointIndex);
				}

				face.Vertecies.push_back(v);
				vertexID++;
			}

			faces.push_back(face);
		}

		// �ގ��C���f�b�N�X�ݒ�
		if (materials != nullptr && materials->GetReferenceMode() == FbxLayerElement::eIndexToDirect)
		{
			auto indexArrayCount = materials->GetIndexArray().GetCount();

			for (auto i = 0; i < indexArrayCount; i++)
			{
				auto index = materials->GetIndexArray().GetAt(i);
				faces[i].MaterialIndex = index;
			}
		}

		if (materials != nullptr)
		{
			LoadMaterial(fbxMesh, materials, materials_);
		}
		
		// ���b�V���Ŏg�p�\�Ȍ`���ɕϊ�
	
		// ���_�ϊ��e�[�u���쐬
		int32_t vInd = 0;
		std::map<Vertex, int32_t> v2ind;
		std::map<int32_t, Vertex> ind2v;

		for (auto& face : faces)
		{
			if (face.Vertecies.size() != 3) continue;

			for (auto& vertex : face.Vertecies)
			{
				auto it = v2ind.find(vertex);
				if (it == v2ind.end())
				{
					v2ind[vertex] = vInd;
					ind2v[vInd] = vertex;
					vInd++;
				}
			}
		}

		// �ݒ�
		auto mesh = std::make_shared<Mesh>();
		mesh->Name = ace::ToAString(node->GetName());
		mesh->BoneConnectors = boneConnectors;
		mesh->Materials = materials_;

		mesh->Vertexes.resize(vInd);
		for (auto& iv : ind2v)
		{
			mesh->Vertexes[iv.first] = iv.second;
		}

		for (auto& face : faces)
		{
			if (face.Vertecies.size() != 3) continue;

			Face f;
			f.Index[0] = v2ind[face.Vertecies[0]];
			f.Index[1] = v2ind[face.Vertecies[1]];
			f.Index[2] = v2ind[face.Vertecies[2]];

			f.MaterialIndex = face.MaterialIndex;

			mesh->Faces.push_back(f);
		}

		return mesh;
	}

	std::shared_ptr<Node> FBXLoader::LoadHierarchy(std::shared_ptr<Node> parent, FbxNode* fbxNode, FbxManager* fbxManager)
	{
		FbxMesh* mesh = nullptr;
		std::shared_ptr<Node> node = std::make_shared<Node>();

		node->Name = ace::ToAString(fbxNode->GetName());

		auto attributeType = fbxNode->GetNodeAttribute()->GetAttributeType();
		
		switch (attributeType)
		{
		case FbxNodeAttribute::eMesh:
			mesh = fbxNode->GetMesh();

			if (!mesh->IsTriangleMesh())
			{
				FbxGeometryConverter converter(fbxManager);
				mesh = (FbxMesh*) converter.Triangulate(mesh, true);
			}

			node->MeshParameter = LoadMesh(mesh);
			break;
		case FbxNodeAttribute::eSkeleton:
			break;
		default:
			return std::shared_ptr<Node>();
			break;
		}

		// ��]����
		fbxsdk_2015_1::EFbxRotationOrder fbxRotationOrder;
		fbxNode->GetRotationOrder(FbxNode::eDestinationPivot, fbxRotationOrder);

		switch (fbxRotationOrder)
		{
		case eEulerXYZ:
			node->RotationOrder = ace::ROTATION_ORDER_XYZ;
			break;
		case eEulerXZY:
			node->RotationOrder = ace::ROTATION_ORDER_XZY;
			break;
		case eEulerYZX:
			node->RotationOrder = ace::ROTATION_ORDER_YZX;
			break;
		case eEulerYXZ:
			node->RotationOrder = ace::ROTATION_ORDER_YXZ;
			break;
		case eEulerZXY:
			node->RotationOrder = ace::ROTATION_ORDER_ZXY;
			break;
		case eEulerZYX:
			node->RotationOrder = ace::ROTATION_ORDER_ZYX;
			break;
		case eSphericXYZ:
			break;
		}

		// �f�t�H���g
		auto lclT = fbxNode->LclTranslation.Get();
		auto lclR = fbxNode->LclRotation.Get();
		auto lclS = fbxNode->LclScaling.Get();
		node->LclMatrix = CalcMatrix(node->RotationOrder, lclT[0], lclT[1], lclT[2], lclR[0], lclR[1], lclR[2], lclS[0], lclS[1], lclS[2]);

		// �W�I���g��
		auto geT = fbxNode->GeometricTranslation.Get();
		auto geR = fbxNode->GeometricRotation.Get();
		auto geS = fbxNode->GeometricScaling.Get();
		node->GeometricMatrix = CalcMatrix(node->RotationOrder, geT[0], geT[1], geT[2], geR[0], geR[1], geR[2], geS[0], geS[1], geS[2]);

		// �q�̑���
		for (auto i = 0; i < fbxNode->GetChildCount(); i++)
		{
			auto childNode = LoadHierarchy(node, fbxNode->GetChild(i), fbxManager);
			if (childNode != nullptr)
			{
				node->Children.push_back(childNode);
			}
		}

		return node;
	}

	ace::Matrix44 FBXLoader::CalcMatrix(ace::eRotationOrder order, float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz)
	{
		ace::Matrix44 matT, matRx, matRy, matRz, matS;
		matT.SetTranslation(tx, ty, tz);
		matRx.SetRotationX(rx / 180.0 * 3.141592);
		matRy.SetRotationY(ry / 180.0 * 3.141592);
		matRz.SetRotationZ(rz / 180.0 * 3.141592);
		matS.SetScale(sx, sy, sz);

		if (order == ace::ROTATION_ORDER_XYZ) return matT * matRz * matRy * matRx * matS;
		if (order == ace::ROTATION_ORDER_XZY) return matT * matRy * matRz * matRx * matS;
		if (order == ace::ROTATION_ORDER_YZX) return matT * matRx * matRz * matRy * matS;

		if (order == ace::ROTATION_ORDER_YXZ) return matT * matRz * matRx * matRy * matS;
		if (order == ace::ROTATION_ORDER_ZXY) return matT * matRy * matRx * matRz * matS;
		if (order == ace::ROTATION_ORDER_ZYX) return matT * matRx * matRy * matRz * matS;

		return ace::Matrix44();
	}

	void FBXLoader::LoadAnimationSource(FbxAnimStack* fbxAnimStack, FbxNode* fbxRootNode, AnimationSource &animationSource)
	{
		const int32_t layerCount = fbxAnimStack->GetMemberCount<FbxAnimLayer>();
		if (layerCount == 0) return;

		auto animationName = fbxAnimStack->GetName();

		FbxTime startTime = fbxAnimStack->LocalStart;
		FbxTime endTime = fbxAnimStack->LocalStop;

		animationSource.Name = ace::ToAString(animationName);
		//animationSource.StartTime = startTime;
		//animationSource.StopTime = endTime;


		for (auto i = 0; i < layerCount; ++i)
		{
			auto layer = fbxAnimStack->GetMember<FbxAnimLayer>();
			LoadCurve(fbxRootNode, layer, animationSource);
			// break;
		}
	}

	void FBXLoader::LoadCurve(FbxNode* fbxNode, FbxAnimLayer* fbxAnimLayer, AnimationSource &animationSource)
	{
		auto boneName = ace::ToAString(fbxNode->GetName());

		LoadCurve(boneName + ace::ToAString(".pos.x"), fbxNode->LclTranslation.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_X), animationSource);
		LoadCurve(boneName + ace::ToAString(".pos.z"), fbxNode->LclTranslation.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_Y), animationSource);
		LoadCurve(boneName + ace::ToAString(".pos.y"), fbxNode->LclTranslation.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_Z), animationSource);

		LoadCurve(boneName + ace::ToAString(".rot.x"), fbxNode->LclRotation.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_X), animationSource);
		LoadCurve(boneName + ace::ToAString(".rot.z"), fbxNode->LclRotation.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_Y), animationSource);
		LoadCurve(boneName + ace::ToAString(".rot.y"), fbxNode->LclRotation.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_Z), animationSource);

		LoadCurve(boneName + ace::ToAString(".scl.x"), fbxNode->LclScaling.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_X), animationSource);
		LoadCurve(boneName + ace::ToAString(".scl.z"), fbxNode->LclScaling.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_Y), animationSource);
		LoadCurve(boneName + ace::ToAString(".scl.y"), fbxNode->LclScaling.GetCurve(fbxAnimLayer, FBXSDK_CURVENODE_COMPONENT_Z), animationSource);

		// �q�̏���
		for (auto i = 0; i< fbxNode->GetChildCount(); i++)
		{
			LoadCurve(fbxNode->GetChild(i), fbxAnimLayer, animationSource);
		}
	}

	void FBXLoader::LoadCurve(ace::astring target, FbxAnimCurve* curve, AnimationSource &animationSource)
	{
		KeyFrameAnimation keyFrameAnimation;
		keyFrameAnimation.TargetName = target;

		const auto keyCount = curve->KeyGetCount();

		int hour, minute, second, frame, field, residual;

		for (auto i = 0; i < keyCount; i++)
		{
			float value = curve->KeyGetValue(i);
			auto time = curve->KeyGetTime(i);
			auto interpolation = curve->KeyGetInterpolation(i);
			time.GetTime(hour, minute, second, frame, field, residual, FbxTime::eFrames60);

			KeyFrame keyFrame;
			keyFrame.KeyValue = ace::Vector2DF(60 * (hour * 60 * 60 + minute * 60 + second) + frame, value);
			keyFrame.LeftPosition = keyFrame.KeyValue;
			keyFrame.RightPosition = keyFrame.KeyValue;

			switch (interpolation)
			{
			case fbxsdk_2015_1::FbxAnimCurveDef::eInterpolationConstant:
			{
				keyFrame.Interpolation = 1;
			}
				break;
			case fbxsdk_2015_1::FbxAnimCurveDef::eInterpolationLinear:
			{
				keyFrame.Interpolation = 2;
			}
				break;
			case fbxsdk_2015_1::FbxAnimCurveDef::eInterpolationCubic:
			{
				keyFrame.Interpolation = 3;
			}
				break;
			}

			keyFrameAnimation.KeyFrames.push_back(keyFrame);
		}
		animationSource.keyFrameAnimations.push_back(keyFrameAnimation);
	}

	std::shared_ptr<Scene> FBXLoader::LoadScene(FbxScene* fbxScene, FbxManager* fbxManager)
	{
		// ���W�n�ϊ�
		FbxAxisSystem axis(FbxAxisSystem::eOpenGL);
		axis.ConvertScene(fbxScene);

		auto scene = std::make_shared<Scene>();

		// �m�[�h
		auto root = fbxScene->GetRootNode();
		scene->Root = LoadHierarchy(nullptr, root, fbxManager);

		// �A�j���[�V����
		auto animStackCount = fbxScene->GetSrcObjectCount<FbxAnimStack>();

		for (auto animStackIndex = 0; animStackIndex < animStackCount; animStackIndex++)
		{
			AnimationSource source;

			auto animStack = fbxScene->GetSrcObject<FbxAnimStack>(animStackIndex);

			fbxScene->SetCurrentAnimationStack(animStack);
			LoadAnimationSource(animStack, root, source);

			scene->AnimationSources.push_back(source);
		}

		return scene;
	}
}