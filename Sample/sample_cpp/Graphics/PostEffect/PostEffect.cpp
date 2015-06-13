
#include <Base.h>

/**
@brief	�|�X�g�G�t�F�N�g��K�p����B
*/
void PostEffect()
{
	// ����
	printf("Z : �O���[�X�P�[���ǉ�\n");
	printf("X : �Z�s�A���ǉ�\n");
	printf("C : �K�E�X�ڂ����ǉ�\n");
	printf("V : ���C�g�u���[���ǉ�\n");
	printf("A : �S�Ẵ|�X�g�G�t�F�N�g����\n");

	// ace������������
	asd::Engine::Initialize(asd::ToAString("PostEffect").c_str(), 640, 480, asd::EngineOption());

	// �V�[����������������
	auto scene = std::make_shared<asd::Scene>();
	auto layer = std::make_shared<asd::Layer2D>();
	auto effectObj = std::make_shared<asd::EffectObject2D>();
	auto effect = asd::Engine::GetGraphics()->CreateEffect(asd::ToAString("Data/Effect/magic.efk").c_str());

	scene->SetHDRMode(true);
	scene->AddLayer(layer);
	layer->AddObject(effectObj);
	asd::Engine::ChangeScene(scene);

	effectObj->SetScale(asd::Vector2DF(50, 50));
	effectObj->SetPosition(asd::Vector2DF(320, 240));
	effectObj->SetEffect(effect);
	effectObj->Play();

	// ace���i�s�\���`�F�b�N����B
	while (asd::Engine::DoEvents())
	{
		// ace���X�V����B
		asd::Engine::Update();

		// A����������|�X�g�G�t�F�N�g��S�Ĕj������B
		if (asd::Engine::GetKeyboard()->GetKeyState(asd::Keys::A) == asd::KeyState::Push)
		{
			layer->ClearPostEffects();
		}

		// Z����������O���[�X�P�[����ǉ�����B
		if (asd::Engine::GetKeyboard()->GetKeyState(asd::Keys::Z) == asd::KeyState::Push)
		{
			auto posteffect = std::make_shared<asd::PostEffectGrayScale>();
			layer->AddPostEffect(posteffect);
		}

		// X����������Z�s�A��ǉ�����B
		if (asd::Engine::GetKeyboard()->GetKeyState(asd::Keys::X) == asd::KeyState::Push)
		{
			auto posteffect = std::make_shared<asd::PostEffectSepia>();
			layer->AddPostEffect(posteffect);
		}

		// C����������K�E�X�ڂ�����ǉ�����B
		if (asd::Engine::GetKeyboard()->GetKeyState(asd::Keys::C) == asd::KeyState::Push)
		{
			auto posteffect = std::make_shared<asd::PostEffectGaussianBlur>();
			posteffect->SetIntensity(5.0f);
			layer->AddPostEffect(posteffect);
		}

		// V���������烉�C�g�u���[����ǉ�����B
		if (asd::Engine::GetKeyboard()->GetKeyState(asd::Keys::V) == asd::KeyState::Push)
		{
			auto posteffect = std::make_shared<asd::PostEffectLightBloom>();
			posteffect->SetIntensity(10.0f);
			posteffect->SetExposure(1.0f);
			posteffect->SetThreshold(0.3f);
			layer->AddPostEffect(posteffect);
		}
	}

	// ace���I������B
	asd::Engine::Terminate();
}
