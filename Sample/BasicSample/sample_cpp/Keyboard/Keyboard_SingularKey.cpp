
#include <Altseed.h>

/**
@brief	�L�[�{�[�h�ɂ����͂��擾����T���v���B
*/
void Keyboard_SingularKey()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Keyboard_SingularKey").c_str(), 640, 480, asd::EngineOption());

	auto font = asd::Engine::GetGraphics()->CreateDynamicFont(asd::ToAString("").c_str(), 20, asd::Color(255, 255, 255, 255), 1, asd::Color(0, 0, 0, 255));

	// �L�[�̓��͏�Ԃ�\�����镶���`��I�u�W�F�N�g��ݒ肵�āA�G���W���ɒǉ�����B
	auto keyStateText = std::make_shared<asd::TextObject2D>();
	keyStateText->SetPosition(asd::Vector2DF(10, 10));
	keyStateText->SetFont(font);
	asd::Engine::AddObject2D(keyStateText);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{

		// �L�[�{�[�h��Z�L�[�̓��͏�Ԃ��擾����B
		// �L�[���͏�Ԃ�������������X�V����B
		switch (asd::Engine::GetKeyboard()->GetKeyState(asd::Keys::Z))
		{
		case asd::KeyState::Free: // �O�t���[���Ɩ{�t���[���Ŕ񉟉�
			keyStateText->SetText(asd::ToAString("Z�L�[�𗣂��Ă��܂��B").c_str());
			break;
		case asd::KeyState::Hold: // �O�t���[���Ɩ{�t���[���ŉ���
			keyStateText->SetText(asd::ToAString("Z�L�[�������Ă��܂��B").c_str());
			break;
		case asd::KeyState::Release: // �O�t���[���ŉ����A�{�t���[���Ŕ񉟉�
			keyStateText->SetText(asd::ToAString("Z�L�[�𗣂��܂���!").c_str());
			break;
		case asd::KeyState::Push: // �O�t���[���Ŕ񉟉��A�{�t���[���ŉ���
			keyStateText->SetText(asd::ToAString("Z�L�[�������܂���!").c_str());
			break;
		}

		// Altseed���X�V����B
		asd::Engine::Update();
	}

	//Altseed�̏I������������B
	asd::Engine::Terminate();

	return;
}
