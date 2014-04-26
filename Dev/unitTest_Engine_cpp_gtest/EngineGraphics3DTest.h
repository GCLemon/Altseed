
#include "EngineTest.h"

/**
	@brief	3D�`��e�X�g�p�t���[�����[�N
	@note
	�����I�u�W�F�N�g�Ƃ��āA
	�J����1��
	���^�����Ă���B
*/
class EngineGraphics3DTest
	: public EngineTest
{
private:
	std::shared_ptr<ace::Scene>		m_scene;
	std::shared_ptr<ace::Layer3D>	m_layer3d;
	std::vector<std::shared_ptr<ace::CameraObject3D>>	m_cameras;

	bool	m_isFreeView;

	float			m_cameraDistance = 10.0f;
	float			m_cameraRotX = 15.0f;
	float			m_cameraRotY = 15.0f;
	ace::Vector3DF	m_cameraFocus = ace::Vector3DF(0, 0, 0);

	ace::Vector2DF	m_mousePos;

	const float PI = 3.14159265358979f;

public:

	std::shared_ptr<ace::Scene> GetScene();
	std::shared_ptr<ace::Layer3D> GetLayer3D();

	void AddCamera();
	std::shared_ptr<ace::CameraObject3D> GetCamera(int32_t index);

	/**
	@brief	�I�[�o�[���C�h���āA���C�����[�v���O�̃A�T�[�V�����⏉�������L�q�ł���B
	*/
	virtual void OnStart() override;

	/**
	@brief	�I�[�o�[���C�h���āA���C�����[�v���̃A�T�[�V�����Ȃǂ��L�q�ł���B
	*/
	virtual void OnUpdating() override;

	EngineGraphics3DTest(ace::astring title, bool isOpenGLMode, int exitTime, bool isFreeView);
};