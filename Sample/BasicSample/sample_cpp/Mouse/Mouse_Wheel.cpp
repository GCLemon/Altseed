#include <Altseed.h>

// �}�E�X�̗l�X�ȏ�Ԃ��擾����T���v���B
void Mouse_Wheel()
{
	//Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Mouse_Wheel").c_str(), 640, 480, asd::EngineOption());

	auto font = asd::Engine::GetGraphics()->CreateDynamicFont(asd::ToAString("").c_str(), 20, asd::Color(255, 255, 255, 255), 1, asd::Color(0, 0, 0, 255));

	auto wheelStateText = std::make_shared<asd::TextObject2D>();
	wheelStateText->SetPosition(asd::Vector2DF(100, 300));
	wheelStateText->SetFont(font);

	asd::Engine::AddObject2D(wheelStateText);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{

		// �}�E�X�̃z�C�[���̉�]��Ԃ��擾���ĕ\������B
		{
			wheelStateText->SetText(asd::ToAString(("�z�C�[���̉�]�x�� : " + std::to_string(asd::Engine::GetMouse()->GetMiddleButton()->GetRotation())).c_str()).c_str());
		}

		// Altseed���X�V����B
		asd::Engine::Update();
	}

	//Altseed�̏I������������B
	asd::Engine::Terminate();

	return;
}
