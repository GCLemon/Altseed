#pragma once
#include <fbxsdk.h>
#include <vector>
#include "../ace_cpp/common/Utility/ace.BinaryWriter.h"
#include "../ace_cpp/common/Math/ace.Vector2DF.h"
#include "Mesh.h"
#include "Deformer.h"
#include "Material.h"
#define EPS 0.0001

class MeshLoader;

/*
���b�V���O���[�v�\����
*/
struct MeshGroup
{
	std::vector<MeshLoader> meshLoaders;
	DeformerManager deformerManager;
	std::vector<Material> materials;

	//���b�V���O���[�v�̍ގ��ꗗ�̏��������o��
	void WriteMaterials(ace::BinaryWriter* writer);
};

class MeshLoader
{
	//���b�V����
	std::string m_name;

	//���_���X�g(UV���тɖ@���̒l�ɂ�镪���O)
	std::vector<Vertex> m_baseVertices;

	//���_���X�g(UV���тɖ@���̒l�ɂ�镪����)
	std::vector<Vertex> m_vertices;

	//�ʃ��X�g
	std::vector<Face> m_faces;

	//�ʍގ����X�g
	std::vector<FacialMaterial> m_facialMaterials;

	int m_faceContinue;
	int m_preFaceIndex;

	//���_�ʒu�ꗗ�ǂݍ��݊֐�
	void _loadPositions(FbxMesh* fbxMesh);

	//�@���ǂݍ��݊֐�
	ace::Vector3DF _loadNormal(FbxMesh* fbxMesh,int lControlPointIndex,int vertexId);

	//�]�@���ǂݍ��݊֐�
	ace::Vector3DF _loadBinormal(FbxMesh* fbxMesh,int lControlPointIndex,int vertexId,bool &found);

	//UV�ǂݍ��݊֐�
	ace::Vector2DF _loadUV(FbxMesh* fbxMesh,int lControlPointIndex,int vertexId,int polygonCount,int polygonVert);

	//���_�J���[�ǂݍ��݊֐�
	std::vector<uint8_t> _loadColor(FbxMesh* fbxMesh,int lControlPointIndex,int vertexId);

	//���_�E�F�C�g����уC���f�b�N�X�ǂݍ��݊֐�
	void _loadWeight(FbxMesh* fbxMesh,int& attachedIndex,std::vector<MeshGroup> &meshGroups);

	//���_���Ɩʏ��̓ǂݍ��݊֐�
	void _loadVerticesAndFaces(FbxMesh* fbxMesh);
	//void _loadFaceIndices(FbxMesh* fbxMesh);

	//�e�N�X�`���i�ʍގ��j�ꗗ�ǂݍ��݊֐�
	void _loadTextures(FbxMesh* fbxMesh);
public:
	MeshLoader();
	
	std::vector<Material> materials;
	std::vector<Vertex> GetVertices();
	std::vector<Face> GetFaces();

	//���b�V���̏���ǂݍ��ފ֐�
	void Load(FbxMesh* fbxMesh,int& attachmentIndex,std::vector<MeshGroup> &meshGroups);

	//���_�ꗗ�����o���֐�
	void WriteVertices(ace::BinaryWriter* writer);

	//�ʈꗗ�����o���֐�
	void WriteFaces(ace::BinaryWriter* writer);

	//�ʍގ��ꗗ�����o���֐�
	void WriteFaceMaterials(ace::BinaryWriter* writer);

	//�{�[���Ή������o���֐�
	void WriteBoneAttachments(ace::BinaryWriter* writer);

	//�ގ��ꗗ�����o���֐�
	void WriteMaterials(ace::BinaryWriter* writer);

	MeshLoader& operator=( const MeshLoader &meshLoader)
	{
		m_baseVertices=meshLoader.m_baseVertices;
		m_vertices=meshLoader.m_vertices;
		m_faces=meshLoader.m_faces;
		m_facialMaterials=meshLoader.m_facialMaterials;

		return *this;
	}

};