#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void CameraObject2D()
{
	// ace������������B
	asd::Engine::Initialize(asd::ToAString("CameraObject2D").c_str(), 640, 480, asd::EngineOption());

	// �e�N�X�`���摜����������B
	{
		auto tex0 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample1.png").c_str());
		auto obj0 = std::make_shared<asd::TextureObject2D>();
		obj0->SetTexture(tex0);
		obj0->SetCenterPosition(asd::Vector2DF(256, 256));
		obj0->SetPosition(asd::Vector2DF(320, 240));
		obj0->SetScale(asd::Vector2DF(0.5f, 0.5f));

		asd::Engine::AddObject2D(obj0);
	}

	//��ڂ̉�ʑS�̂��ʂ��J������ݒ肷��B(�I�u�W�F�N�g�����̂܂ܕ`�悷��B)
	{
		auto camera1 = std::make_shared<asd::CameraObject2D>();
		camera1->SetSrc(asd::RectI(0, 0, 640, 480));
		camera1->SetDst(asd::RectI(0, 0, 640, 480));
		asd::Engine::AddObject2D(camera1);
	}

	//��ڂ̃}�E�X�|�C���^�̎��ӂ��g�債�ĕ\������J������ݒ肷��B
	auto camera2 = std::make_shared<asd::CameraObject2D>();

	asd::Engine::AddObject2D(camera2);

	//�t���[���p�e�N�X�`���摜����������B
	auto frame = std::make_shared<asd::TextureObject2D>();
	{
		auto tex = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Frame.png").c_str());
		frame->SetTexture(tex);
		frame->SetCenterPosition(asd::Vector2DF(55.0f, 55.0f));

		asd::Engine::AddObject2D(frame);
	}

	// ace���i�s�\���`�F�b�N����B
	while (asd::Engine::DoEvents())
	{
		//�}�E�X�|�C���^�̈ʒu���擾����B
		auto pos = asd::Engine::GetMouse()->GetPosition();

		//�g��p�J�����̕`�挳���w�肷��B
		camera2->SetSrc(asd::RectI(pos.X - 25, pos.Y - 25, 50, 50));

		//�|�C���^�𒆐S��100x100�̊g��摜��\������B
		camera2->SetDst(asd::RectI(pos.X - 50, pos.Y - 50, 100, 100));

		//�t���[���摜�̕`�撆�S���}�E�X�|�C���^�̈ʒu�ɍ��킹��B
		frame->SetPosition(pos);

		// ace���X�V����B
		asd::Engine::Update();
	}

	// ace���I������B
	asd::Engine::Terminate();
}