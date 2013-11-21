#pragma once
#include <ace.h>

class EngineTest
{
private:
	const ace::astring directory;

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

extern void AssertMemoryDoesntLeak();

/**
	@brief	EngineTest�N���X���p�������e�X�g �N���X�ɂ��e�X�g�����s����B
	@param	T				���s����e�X�g�N���X�̌^�B�����ɁAOpenGL���[�h���ǂ�����\���^�U�l���P�����Ƃ�R���X�g���N�^���K�v�ł���B
	@param	isOpenGLMode	OpenGL���[�h���ǂ����B
*/
template<class T>
extern void RunTest(bool isOpenGLMode)
{
	T(isOpenGLMode).Run();
	AssertMemoryDoesntLeak();
}