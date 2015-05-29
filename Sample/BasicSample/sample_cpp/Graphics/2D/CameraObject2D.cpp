
#include <ace.h>

/**
@brief	CameraObject2D�̃T���v���B�}�E�X�|�C���^�̐���g��\������B
*/
void CameraObject2D()
{
	// AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("CameraObject2D").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����B
	auto scene = std::make_shared<ace::Scene>();

	// ���C���[�𐶐�����B
	auto layer = std::make_shared<ace::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����B
	scene->AddLayer(layer);

	// �V�[����؂�ւ���B
	ace::Engine::ChangeScene(scene);

	// ��ʂɃe�N�X�`����\������I�u�W�F�N�g�𐶐�����B
	{
		auto tex0 = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample1.png").c_str());
		auto obj0 = std::make_shared<ace::TextureObject2D>();
		layer->AddObject(obj0);
	}

	// ��ʂɃe�N�X�`����\������I�u�W�F�N�g�𐶐�����B
	{
		auto baseCameraObj = std::make_shared<ace::CameraObject2D>();
		baseCameraObj->SetSrc(ace::RectI(0, 0, 640, 480));
		baseCameraObj->SetDst(ace::RectI(0, 0, 640, 480));
		layer->AddObject(baseCameraObj);
	}

	// �}�E�X�|�C���^�̎��ӂ��g��\������J�����𐶐�����B
	auto cameraObj = std::make_shared<ace::CameraObject2D>();
	layer->AddObject(cameraObj);

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		//�}�E�X�|�C���^�̈ʒu���擾����B
		auto pos = ace::Engine::GetMouse()->GetPosition();

		//�g��p�J�����̕`�挳���w�肷��B
		cameraObj->SetSrc(ace::RectI(pos.X - 25, pos.Y - 25, 50, 50));

		//�|�C���^�𒆐S��100x100�̊g��摜��\������B
		cameraObj->SetDst(ace::RectI(pos.X - 50, pos.Y - 50, 100, 100));

		// AC-Engine���X�V����B
		ace::Engine::Update();
	}

	// AC-Engine�̏I������������B
	ace::Engine::Terminate();
}