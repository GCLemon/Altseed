#include <Base.h>

/**
@brief	���C���[�Ƀ��C�g�u���[���̃|�X�g�G�t�F�N�g��K�p����B
*/
void PostEffect_LightBloom()
{
	// Altseed������������
	asd::Engine::Initialize(asd::ToAString("PostEffect_LightBloom").c_str(), 640, 480, asd::EngineOption());

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

	// ���C�g�u���[���̃R���X�g���N�^���Ăяo���B
	auto posteffect = std::make_shared<asd::PostEffectLightBloom>();

	// ���C�g�u���[���̂ڂ����̋�����ݒ肷��B
	posteffect->SetIntensity(10.0f);

	// ���C�g�u���[���̘I���̋�����ݒ肷��B
	posteffect->SetExposure(1.0f);

	// ���C�g�u���[���Ō��点�閾�邳�̂������l��ݒ肷��B
	posteffect->SetThreshold(0.3f);

	// ���C���[�Ƀ��C�g�u���[���̃|�X�g�G�t�F�N�g��K�p�B
	layer->AddPostEffect(posteffect);

	// HDR���[�h��ON�ɂ���i���C�g�u���[���̌��ʂ�������悤�ɂ��邽�߁j
	scene->SetHDRMode(true);

	while (asd::Engine::DoEvents())
	{
		asd::Engine::Update();
	}

	asd::Engine::Terminate();
}