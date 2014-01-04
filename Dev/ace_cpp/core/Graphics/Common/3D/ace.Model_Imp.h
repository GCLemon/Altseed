
#pragma once

#include "ace.Model.h"
#include <Utility/ace.BinaryReader.h>

namespace ace
{
	class Model_Imp
		: public Model
		, public ReferenceObject
	{
	private:
		
		std::vector<Mesh_Imp*>		m_meshes;
		std::vector<astring>		m_animationClipNames;
		std::vector<AnimationClip*>	m_animationClips;

		void Reset();

	public:
		Model_Imp();
		virtual ~Model_Imp();

		bool Load(Graphics* g, std::vector<uint8_t>& data, const achar* path);

	private:
		Mesh_Imp* LoadMeshGroup(Graphics* g, BinaryReader& reader, const achar* path);
		Mesh_Imp* LoadMesh(Graphics* g, BinaryReader& reader, const achar* path);
		Deformer_Imp* LoadDeformer(Graphics* g, BinaryReader& reader, const achar* path);

		void LoadAnimationClip(BinaryReader& reader, std::vector<AnimationSource*>& source);
		AnimationSource* LoadAnimationSource(BinaryReader& reader);
		KeyframeAnimation* LoadKeyframeAnimation(BinaryReader& reader);

	public:
		std::vector<AnimationClip*>& GetAnimationClips() { return m_animationClips; }
		std::vector < Mesh_Imp*> GetMeshes() { return m_meshes; }
		
		// IReference���p�������f�o�C�X�I�u�W�F�N�g������`
#if !SWIG
	public:
		virtual int GetRef() { return ReferenceObject::GetRef(); }
		virtual int AddRef() { return ReferenceObject::AddRef(); }
		virtual int Release() { return ReferenceObject::Release(); }
#endif
	};
}