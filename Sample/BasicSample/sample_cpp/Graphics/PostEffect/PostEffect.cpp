
#include <ace.h>

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

	// AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("PostEffect").c_str(), 640, 480, ace::EngineOption());

	// �V�[����������������
	auto scene = std::make_shared<ace::Scene>();
	auto layer = std::make_shared<ace::Layer2D>();
	auto effectObj = std::make_shared<ace::EffectObject2D>();
	auto effect = ace::Engine::GetGraphics()->CreateEffect(ace::ToAString("Data/Effect/magic.efk").c_str());

	scene->SetHDRMode(true);
	scene->AddLayer(layer);
	layer->AddObject(effectObj);
	ace::Engine::ChangeScene(scene);

	effectObj->SetScale(ace::Vector2DF(50, 50));
	effectObj->SetPosition(ace::Vector2DF(320, 240));
	effectObj->SetEffect(effect);
	effectObj->Play();

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		// AC-Engine���X�V����B
		ace::Engine::Update();

		// A����������|�X�g�G�t�F�N�g��S�Ĕj������B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::A) == ace::KeyState::Push)
		{
			layer->ClearPostEffects();
		}

		// Z����������O���[�X�P�[����ǉ�����B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::Z) == ace::KeyState::Push)
		{
			auto posteffect = std::make_shared<ace::PostEffectGrayScale>();
			layer->AddPostEffect(posteffect);
		}

		// X����������Z�s�A��ǉ�����B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::X) == ace::KeyState::Push)
		{
			auto posteffect = std::make_shared<ace::PostEffectSepia>();
			layer->AddPostEffect(posteffect);
		}

		// C����������K�E�X�ڂ�����ǉ�����B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::C) == ace::KeyState::Push)
		{
			auto posteffect = std::make_shared<ace::PostEffectGaussianBlur>();
			posteffect->SetIntensity(5.0f);
			layer->AddPostEffect(posteffect);
		}

		// V���������烉�C�g�u���[����ǉ�����B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::V) == ace::KeyState::Push)
		{
			auto posteffect = std::make_shared<ace::PostEffectLightBloom>();
			posteffect->SetIntensity(10.0f);
			posteffect->SetExposure(1.0f);
			posteffect->SetThreshold(0.3f);
			layer->AddPostEffect(posteffect);
		}
	}

	// AC-Engine�̏I������������B
	ace::Engine::Terminate();
}
