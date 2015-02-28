#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void CameraObject2D()
{
	// ace������������B
	ace::Engine::Initialize(ace::ToAString("CameraObject2D").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����B
	auto scene = std::make_shared<ace::Scene>();

	// ���C���[�𐶐�����B
	auto layer = std::make_shared<ace::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����B
	scene->AddLayer(layer);

	// �V�[����؂�ւ���B
	ace::Engine::ChangeScene(scene);


	{
		// �e�N�X�`���𐶐�����B
		auto tex0 = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample1.png").c_str());

		//TextureObject2D�𐶐�����B
		auto obj0 = std::make_shared<ace::TextureObject2D>();

		//�`��Ɏg���e�N�X�`����ݒ肷��B
		obj0->SetTexture(tex0);

		//�`��ʒu���w�肷��B
		obj0->SetCenterPosition(ace::Vector2DF(256, 256));
		obj0->SetPosition(ace::Vector2DF(320, 240));
		obj0->SetScale(ace::Vector2DF(0.5f, 0.5f));

		//���C���[�֒ǉ�����B
		layer->AddObject(obj0);
	}

	//��ʑS�̂��ʂ��J�����B(�I�u�W�F�N�g�����̂܂ܕ`��)
	auto camera1 = std::make_shared<ace::CameraObject2D>();
	camera1->SetSrc(ace::RectI(0, 0, 640, 480));
	camera1->SetDst(ace::RectI(0, 0, 640, 480));

	layer->AddObject(camera1);

	//�}�E�X�|�C���^�̎��ӂ��g�債�ĕ\������J�����B
	auto camera2 = std::make_shared<ace::CameraObject2D>();

	layer->AddObject(camera2);

	// ace���i�s�\���`�F�b�N����B
	while (ace::Engine::DoEvents())
	{
		//�}�E�X�|�C���^�̈ʒu���擾
		auto pos = ace::Engine::GetMouse()->GetPosition();

		//�g��p�J�����̕`�挳���w�肷��B
		camera2->SetSrc(ace::RectI(pos.X - 25, pos.Y - 25, 50, 50));

		//�|�C���^�𒆐S��100x100�̊g��摜��\������B
		camera2->SetDst(ace::RectI(pos.X - 50, pos.Y - 50, 100, 100));

		// ace���X�V����B
		ace::Engine::Update();
	}

	// ace���I������B
	ace::Engine::Terminate();
}