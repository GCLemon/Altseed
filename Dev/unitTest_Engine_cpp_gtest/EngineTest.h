#pragma once
#include <ace.h>

class EngineTest
{
private:
	int m_exitTime;
	bool m_isOpenGLMode;
	ace::astring m_title;

protected:
	/**
		@brief	�I�[�o�[���C�h���āA���C�����[�v���O�̃A�T�[�V�����⏉�������L�q�ł���B
	*/
	virtual void OnStart();

	/**
		@brief	�I�[�o�[���C�h���āA���C�����[�v���̃A�T�[�V�����Ȃǂ��L�q�ł���B
	*/
	virtual void OnUpdating();

	/**
		@brief	�I�[�o�[���C�h���āA���C�����[�v���̃A�T�[�V�����Ȃǂ��L�q�ł���B
	*/
	virtual void OnUpdated();

	/**
		@brief	�I�[�o�[���C�h���āA���C�����[�v�̌�̃A�T�[�V������I���������L�q�ł���B
	*/
	virtual void OnFinish();

public:
	EngineTest(ace::astring title, bool isOpenGLMode, int exitTime);
	void Run();
};