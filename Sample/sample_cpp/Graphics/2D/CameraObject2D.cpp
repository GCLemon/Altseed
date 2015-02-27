#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void CameraObject2D()
{
	// ace������������
	ace::Engine::Initialize(ace::ToAString("CameraObject2D").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<ace::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<ace::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	ace::Engine::ChangeScene(scene);


	{
		// �e�N�X�`���𐶐�����
		auto tex0 = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample2.png").c_str());

		//TextureObject2D�𐶐�����
		auto obj0 = std::make_shared<ace::TextureObject2D>();

		//�`��Ɏg���e�N�X�`����ݒ肷��
		obj0->SetTexture(tex0);

		//�`��ʒu���w�肷��
		obj0->SetPosition(ace::Vector2DF(100, 100));

		//���C���[�֒ǉ�����
		layer->AddObject(obj0);
	}

	auto camera1 = std::make_shared<ace::CameraObject2D>();
	camera1->SetSrc(ace::RectI(0, 0, 200, 200));
	camera1->SetDst(ace::RectI(0, 0, 200, 200));

	layer->AddObject(camera1);


	// ace���i�s�\���`�F�b�N����B
	while (ace::Engine::DoEvents())
	{
		// ace���X�V����B
		ace::Engine::Update();
	}

	// ace���I������B
	ace::Engine::Terminate();
}