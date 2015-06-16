#include <Altseed.h>

// �t�F�[�h�A�E�g�E�t�F�[�h�C���ŃV�[���J�ڂ�����T���v���ł��B
void Transition_Fade()
{
	asd::Engine::Initialize(asd::ToAString("Transition_Fade").c_str(), 640, 480, asd::EngineOption());

	// �V�[��(1)�A���C���[�A�I�u�W�F�N�g�𐶐�����B
	auto scene1 = std::make_shared<asd::Scene>();
	auto layer1 = std::make_shared<asd::Layer2D>();
	auto object1 = std::make_shared<asd::TextureObject2D>();

	// �e�N�X�`���𐶐����A�I�u�W�F�N�g�ɐݒ肷��B
	auto texture1 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Scene1.png").c_str());
	object1->SetTexture(texture1);

	// �V�[���Ƀ��C���[��ǉ����A���̃��C���[�ɃI�u�W�F�N�g��ǉ�����B
	scene1->AddLayer(layer1);
	layer1->AddObject(object1);


	// ��Ɠ������̂������P�Z�b�g���B
	auto scene2 = std::make_shared<asd::Scene>();
	auto layer2 = std::make_shared<asd::Layer2D>();
	auto object2 = std::make_shared<asd::TextureObject2D>();

	auto texture2 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Scene2.png").c_str());
	object2->SetTexture(texture2);

	scene2->AddLayer(layer2);
	layer2->AddObject(object2);


	// �V�[�����V�[��1�ɐݒ肷��B
	asd::Engine::ChangeScene(scene1);

	while (asd::Engine::DoEvents())
	{
		asd::Engine::Update();

		// �}�E�X�̍��{�^�����������̂�҂B
		if (asd::Engine::GetMouse()->GetLeftButton()->GetButtonState() == asd::MouseButtonState::Push)
		{
			// �t�F�[�h�A�E�g�E�C���ɂ��V�[���J�ڂ��J�n����B
			// 1�b�����ăt�F�[�h�A�E�g���A1.5�b�����ăt�F�[�h�C���B
			asd::Engine::ChangeSceneWithTransition(scene2, std::make_shared<asd::TransitionFade>(1.0f, 1.5f));
		}
	}
	
	asd::Engine::Terminate();
}