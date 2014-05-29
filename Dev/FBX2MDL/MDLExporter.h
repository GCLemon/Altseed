#pragma once

#include "FBX2MDL.Base.h"

#include "Deformer.h"
#include "MeshLoader.h"

#include "Animation.h"

//�匳�N���X
class MDLExporter
{
	//�����o���t�@�C����
	std::string m_outName;

	//SDK�}�l�[�W��
	FbxManager* m_SdkManager;

	//�V�[��
	FbxScene* m_Scene;

	//�o�C�i���t�@�C�������o���N���X
	ace::BinaryWriter* m_binaryWriter;

	//���b�V���O���[�v�ꗗ
	std::vector<MeshGroup> m_meshGroups;

	//�A�j���[�V�����\�[�X�ꗗ
	std::vector<AnimationSource> m_animationSources;

	//�t�@�C���̃w�b�_�������o���֐�
	void PrintHeader();

	//���b�V�����擾���āA�K�؂ȃ��b�V���O���[�v�ɕ��ނ���
	void GetMeshGroup(FbxNode* pNode, int depth);

	//���b�V�������l���擾����֐�
	void GetMeshProperty(FbxNode* node);

	//�f�t�H�[�}���擾����֐�(�ċA�I�ɑS�Ē��ׂ�����)
	void GetDeformer(Deformer* parentSkeleton, FbxNode* pNode, DeformerManager &deformerManager);

	//�f�t�H�[�}�����l���擾����֐�
	void GetDeformerProperty(Deformer* parentSkeleton, FbxNode* node, Deformer *deformer, DeformerManager &deformerManager);

	//���[�V�������擾����֐�(�ċA�I�ɑS�Ē��ׂ�����)
	void GetMotion(FbxNode *parentNode, FbxNode* node, FbxAnimLayer* pLayer, AnimationSource &animationSource);

	//�e�X�̃A�j���[�V�����Ɋւ��Ē������s��
	void AnimStackAnalyze(FbxAnimStack* pStack, FbxNode *rootNode, AnimationSource &animationSource);

	//�{�[���̊g��A��]�A�ړ��̎��Ԃɂ��l���擾����
	void GetSkeletonCurve(FbxNode* fbxNode, FbxAnimLayer* fbxAnimLayer, AnimationSource &animationSource);

	//�w�肵���ϊ��̃A�j���[�V�����̃J�[�u����͂���
	void AnalyzeCurve(std::string target, FbxAnimCurve* pCurve, AnimationSource &animationSource, float defaultValue);

public:
	MDLExporter(){}

	MDLExporter(const char* fileName, const char *exportName);

	//�ϊ����s
	void Convert();

	~MDLExporter();
};