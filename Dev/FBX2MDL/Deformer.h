
#pragma once

#include "FBX2MDL.Base.h"

struct Deformer
{
	//�{�[����
	std::string name;

	//�e�{�[���C���f�b�N�X
	int parentIndex;

	//��]����
	int rotationOrder;

	//�`��p�t�s��
	ace::Matrix44 invMatrix;

	//�e�ɑ΂���ϊ��s��
	ace::Matrix44 relationMatrix;

	//�C���f�b�N�X
	int index;

	//�C���f�b�N�X���蓖�ĕϐ�
	static int indexCount;
public:

	Deformer()
	{
		index = GetIndexCount();
	}

	//���蓖�ăC���f�b�N�X�擾
	static int GetIndexCount()
	{
		return indexCount++;
	}

	//���蓖�ăC���f�b�N�X���Z�b�g
	static void ResetIndexCount()
	{
		indexCount=0;
	}
};

//���b�V���O���[�v�����f�t�H�[�}�ꗗ���Ǘ�����N���X
class DeformerManager
{
	std::vector<Deformer*> m_deformer;

public:
	DeformerManager(){}
	~DeformerManager();

	//�f�t�H�[�}�ǉ�
	void AddDeformer(Deformer*);

	//�f�t�H�[�}�������Ƀf�t�H�[�}�̊i�[�C���f�b�N�X���擾
	int GetIndexByName(std::string name);

	//�f�t�H�[�}�������Ƀf�t�H�[�}�ւ̎Q�Ƃ��擾
	Deformer* GetDeformerByName(std::string name);

	//�C���f�b�N�X�����Ƀf�t�H�[�ւ̎Q�Ƃ��擾
	Deformer* GetDeformerByIndex(int index);

	//�f�t�H�[�}�̏��������o��
	void WriteDeformerInformation(ace::BinaryWriter* binaryWriter);

	//�f�t�H�[�}���̎擾
	int GetDeformerNum();
};