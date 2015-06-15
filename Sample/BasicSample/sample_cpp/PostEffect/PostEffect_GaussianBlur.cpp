#include <Base.h>

/**
@brief	���C���[�ɃK�E�X�ڂ����̃|�X�g�G�t�F�N�g��K�p����B
*/
void PostEffect_GaussianBlur()
{
	// Altseed������������
	asd::Engine::Initialize(asd::ToAString("PostEffect_GaussianBlur").c_str(), 640, 480, asd::EngineOption());

	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Object.png").c_str());

	// �V�[���̃R���X�g���N�^���Ăяo���B
	auto scene = std::make_shared<asd::Scene>();

	// ���C���[�̃R���X�g���N�^���Ăяo���B
	auto layer = std::make_shared<asd::Layer2D>();

	// �I�u�W�F�N�g�̃R���X�g���N�^���Ăяo���B
	auto obj = std::make_shared<asd::TextureObject2D>();

	// �I�u�W�F�N�g�̈ʒu�ƃe�N�X�`����ݒ�B
	obj->SetPosition(asd::Vector2DF(100, 100));
	obj->SetTexture(texture);

	// �V�[����ύX���A���̃V�[���Ƀ��C���[��ǉ����A���̃��C���[�ɃI�u�W�F�N�g��ǉ�����B
	asd::Engine::ChangeScene(scene);
	scene->AddLayer(layer);
	layer->AddObject(obj);

	// ���C���[�ɃK�E�X�ڂ����̃|�X�g�G�t�F�N�g��K�p�B
	layer->AddPostEffect(std::make_shared<asd::PostEffectGaussianBlur>());

	while (asd::Engine::DoEvents())
	{
		asd::Engine::Update();
	}

	asd::Engine::Terminate();
}