#pragma once

#include "../ace_cpp/common/Math/ace.Vector2DF.h"
#include "../ace_cpp/common/Utility/ace.BinaryWriter.h"
#include "fbxsdk.h"
#include <vector>
#include <string>

//�A�j���[�V�����N���b�v�\����
struct AnimationClip
{
	//�A�j���[�V�����N���b�v��
	std::string animationName;

	//�A�j���[�V�����\�[�X�̃C���f�b�N�X
	int animationSourceIndex;
};

//�L�[�t���[���\����
struct KeyFrame
{
	//���Ԃƒl
	ace::Vector2DF keyValue;

	//������W�n
	ace::Vector2DF leftPosition;

	//�E����W�n
	ace::Vector2DF rightPosition;

	//�ۊǕ��@
	int interpolation;
};

struct KeyFrameAnimation
{
	//�L�[�t���[���A�j���[�V������
	std::string targetName;

	//�L�[�t���[���ꗗ
	std::vector<KeyFrame> keyFrames;
};

//�A�j���[�V�����\�[�X�\����
struct AnimationSource
{
	//�A�j���[�V������
	std::string animationName;

	//�L�[�t���[���ꗗ
	std::vector<KeyFrameAnimation> keyFrameAnimations;

	//�J�n����
	FbxTime startTime;

	//�I������
	FbxTime stopTime;

	//�A�j���[�V�����\�[�X�ꗗ�����o���֐�
	void WriteAnimationSource(ace::BinaryWriter *binaryWriter);
};

