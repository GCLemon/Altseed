
#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void ImagePackage()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("ImagePackage").c_str(), 640, 480, asd::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<asd::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<asd::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	asd::Engine::ChangeScene(scene);

	// �C���[�W�p�b�P�[�W��ǂݍ���
	auto imagePackage = asd::Engine::GetGraphics()->CreateImagePackage(asd::ToAString("Data/ImagePackage/Game.aip").c_str());

	for (int i = 0; i < imagePackage->GetImageCount(); i++)
	{
		// �e�N�X�`�������o��
		auto texture = imagePackage->GetImage(i);
		auto area = imagePackage->GetImageArea(i);

		// �e�N�X�`�����I�u�W�F�N�g�Ƃ��Ēǉ�����
		auto textureObject2D = std::make_shared<asd::TextureObject2D>();
		textureObject2D->SetTexture(texture);
		textureObject2D->SetPosition(asd::Vector2DF(area.X, area.Y));
		layer->AddObject(textureObject2D);
	}

	// ace���i�s�\���`�F�b�N����B
	while (asd::Engine::DoEvents())
	{
		// ace���X�V����B
		asd::Engine::Update();
	}

	// ace���I������B
	asd::Engine::Terminate();
}