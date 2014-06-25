
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
	ace::Engine::Initialize(L"PostEffect", 640, 480, ace::EngineOption());

	// �V�[����������������(�{�T���v���̃��C���̓��e�ɂ͊֌W�Ȃ�)
	auto scene = std::make_shared<ace::Scene>();
	auto layer = std::make_shared<ace::Layer3D>();
	auto effectObj = std::make_shared<ace::EffectObject3D>();
	auto cameraObj = std::make_shared<ace::CameraObject3D>();
	auto effect = ace::Engine::GetGraphics()->CreateEffect(ace::ToAString("Data/Effect/magic.efk").c_str());

	scene->SetHDRMode(true);
	scene->AddLayer(layer);
	layer->AddObject(effectObj);
	layer->AddObject(cameraObj);
	ace::Engine::ChangeScene(scene);

	cameraObj->SetPosition(ace::Vector3DF(2, 2, 20));
	cameraObj->SetFieldOfView(20);
	cameraObj->SetZNear(1);
	cameraObj->SetZFar(40);
	cameraObj->SetWindowSize(ace::Vector2DI(640, 480));

	effectObj->SetEffect(effect);
	effectObj->Play();

	// ace���i�s�\���`�F�b�N����B
	while (ace::Engine::DoEvents())
	{
		// ace���X�V����B
		ace::Engine::Update();

		// A����������|�X�g�G�t�F�N�g��S�Ĕj������B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::A) == ace::KeyboardButtonState::Push)
		{
			layer->ClearPostEffects();
		}

		// Z����������O���[�X�P�[����ǉ�����B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::Z) == ace::KeyboardButtonState::Push)
		{
			auto posteffect = std::make_shared<ace::PostEffectGrayScale>();
			layer->AddPostEffect(posteffect);
		}

		// X����������Z�s�A��ǉ�����B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::X) == ace::KeyboardButtonState::Push)
		{
			auto posteffect = std::make_shared<ace::PostEffectSepia>();
			layer->AddPostEffect(posteffect);
		}

		// C����������K�E�X�ڂ�����ǉ�����B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::C) == ace::KeyboardButtonState::Push)
		{
			auto posteffect = std::make_shared<ace::PostEffectGaussianBlur>();
			posteffect->SetIntensity(5.0f);
			layer->AddPostEffect(posteffect);
		}

		// V���������烉�C�g�u���[����ǉ�����B
		if (ace::Engine::GetKeyboard()->GetKeyState(ace::Keys::V) == ace::KeyboardButtonState::Push)
		{
			auto posteffect = std::make_shared<ace::PostEffectLightBloom>();
			posteffect->SetIntensity(10.0f);
			posteffect->SetPower(1.0f);
			posteffect->SetThreshold(0.3f);
			layer->AddPostEffect(posteffect);
		}
	}

	// ace���I������B
	ace::Engine::Terminate();
}
