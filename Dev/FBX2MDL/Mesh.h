
#pragma once

#include <Math/ace.Vector3DF.h>
#include <Math/ace.Vector2DF.h>
#include "Material.h"

//���_
struct Vertex
{
	//�ʒu
	ace::Vector3DF position;

	//�@��
	ace::Vector3DF normal;

	//�]�@��
	ace::Vector3DF binormal;

	//UV
	ace::Vector2DF uv;

	//�⏕UV
	ace::Vector2DF subuv;

	//�@�����Z��
	int normalAddCount;

	//�]�@�����Z��
	int binormalAddCount;

	//���_�J���[
	int color[4];

	//���_�E�F�C�g
	uint8_t weight[4];

	//���_�E�F�C�g�C���f�b�N�X(�����ς�)
	uint8_t weightIndexDivided[4];

	//���_�E�F�C�g�C���f�b�N�X(�I���W�i��)
	uint8_t weightIndexOriginal[4];

	//�E�F�C�g�z��|�C���^
	int weightPtr;

	bool operator == (const Vertex& o)
	{
		return position==o.position && normal==o.normal && uv == o.uv && subuv == o.subuv
		&& color[0]==o.color[0] && color[1] == o.color[1] && color[2] == o.color[2] && color[3] == o.color[3];
	}

	bool operator != (const Vertex& o)
	{
		return !(position==o.position && normal==o.normal && uv == o.uv && subuv == o.subuv
		&& color[0]==o.color[0] && color[1] == o.color[1] && color[2] == o.color[2] && color[3] == o.color[3]);
	}
};

//��
struct Face
{
	//���_�C���f�b�N�X
	int vertexIndex[3];

	//�ʍގ��C���f�b�N�X
	int materialIndex;
};

//�ʍގ�
struct FacialMaterial
{
	//�ʐ�
	int faceNum;

	//�ʍގ��ւ̎Q��
	Material &materialRef;

	FacialMaterial(int facenum,Material &materialref)
		:materialRef(materialref)
	{
		faceNum = facenum;
	}

	FacialMaterial& operator=( const FacialMaterial &facialMaterial)
	{
		faceNum=facialMaterial.faceNum;
		materialRef=facialMaterial.materialRef;

		return *this;
	}

};

struct BoneAttachment
{
	uint8_t boneIndex[32];
	int faceNum;
};