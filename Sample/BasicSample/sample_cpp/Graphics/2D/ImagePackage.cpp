
#include <ace.h>

/**
@brief	ImagePackage�̃T���v���B�摜�p�b�P�[�W�����ɉ摜��z�u����B
*/
void ImagePackage()
{
	// AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("ImagePackage").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<ace::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<ace::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	ace::Engine::ChangeScene(scene);

	// �C���[�W�p�b�P�[�W��ǂݍ���
	auto imagePackage = ace::Engine::GetGraphics()->CreateImagePackage(ace::ToAString("Data/ImagePackage/Game.aip").c_str());

	for (int i = 0; i < imagePackage->GetImageCount(); i++)
	{
		// �e�N�X�`�������o��
		auto texture = imagePackage->GetImage(i);
		auto area = imagePackage->GetImageArea(i);

		// �e�N�X�`�����I�u�W�F�N�g�Ƃ��Ēǉ�����
		auto textureObject2D = std::make_shared<ace::TextureObject2D>();
		textureObject2D->SetTexture(texture);
		textureObject2D->SetPosition(ace::Vector2DF(area.X, area.Y));
		layer->AddObject(textureObject2D);
	}

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		// AC-Engine���X�V����B
		ace::Engine::Update();
	}

	// AC-Engine�̏I������������B
	ace::Engine::Terminate();
}