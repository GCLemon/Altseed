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

	// �e�N�X�`���摜����������B
	{
		auto tex0 = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample1.png").c_str());
		auto obj0 = std::make_shared<ace::TextureObject2D>();
		obj0->SetTexture(tex0);
		obj0->SetCenterPosition(ace::Vector2DF(256, 256));
		obj0->SetPosition(ace::Vector2DF(320, 240));
		obj0->SetScale(ace::Vector2DF(0.5f, 0.5f));

		layer->AddObject(obj0);
	}

	//��ڂ̉�ʑS�̂��ʂ��J������ݒ肷��B(�I�u�W�F�N�g�����̂܂ܕ`�悷��B)
	{
		auto camera1 = std::make_shared<ace::CameraObject2D>();
		camera1->SetSrc(ace::RectI(0, 0, 640, 480));
		camera1->SetDst(ace::RectI(0, 0, 640, 480));
		layer->AddObject(camera1);
	}

	//��ڂ̃}�E�X�|�C���^�̎��ӂ��g�債�ĕ\������J������ݒ肷��B
	auto camera2 = std::make_shared<ace::CameraObject2D>();

	layer->AddObject(camera2);

	//�t���[���p�e�N�X�`���摜����������B
	auto frame = std::make_shared<ace::TextureObject2D>();
	{
		auto tex = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Frame.png").c_str());
		frame->SetTexture(tex);
		frame->SetCenterPosition(ace::Vector2DF(55.0f, 55.0f));

		layer->AddObject(frame);
	}

	// ace���i�s�\���`�F�b�N����B
	while (ace::Engine::DoEvents())
	{
		//�}�E�X�|�C���^�̈ʒu���擾����B
		auto pos = ace::Engine::GetMouse()->GetPosition();

		//�g��p�J�����̕`�挳���w�肷��B
		camera2->SetSrc(ace::RectI(pos.X - 25, pos.Y - 25, 50, 50));

		//�|�C���^�𒆐S��100x100�̊g��摜��\������B
		camera2->SetDst(ace::RectI(pos.X - 50, pos.Y - 50, 100, 100));

		//�t���[���摜�̕`�撆�S���}�E�X�|�C���^�̈ʒu�ɍ��킹��B
		frame->SetPosition(pos);

		// ace���X�V����B
		ace::Engine::Update();
	}

	// ace���I������B
	ace::Engine::Terminate();
}