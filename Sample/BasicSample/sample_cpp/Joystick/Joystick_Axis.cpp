
#include <Altseed.h>

// �W���C�X�e�B�b�N�ɂ����͂��擾����T���v���B

void Joystick_Axis()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Joystick_Axis").c_str(), 640, 480, asd::EngineOption());

	// �W���C�X�e�B�b�N�̏�Ԃ�\������e�L�X�g�𐶐�����B
	auto font = asd::Engine::GetGraphics()->CreateDynamicFont(asd::ToAString("").c_str(), 25, asd::Color(255, 255, 255, 255), 1, asd::Color(0, 0, 0, 255));

	auto stateText = std::make_shared<asd::TextObject2D>();
	stateText->SetPosition(asd::Vector2DF(10, 10));
	stateText->SetFont(font);

	asd::Engine::AddObject2D(stateText);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		asd::astring displayStr = asd::ToAString("");

		// �W���C�X�e�B�b�N���ڑ�����Ă��邩�ǂ������m�F����B
		if (!asd::Engine::GetJoystickContainer()->GetIsPresentAt(0))
		{
			displayStr += asd::ToAString("�W���C�X�e�B�b�N���ڑ�����Ă��܂���B");
		}
		else
		{
			// 1�ڂ̃W���C�X�e�B�b�N�̑S�ẴA�i���O�X�e�B�b�N�̓��͏�Ԃ�\������
			asd::Joystick* joystick = asd::Engine::GetJoystickContainer()->GetJoystickAt(0);

			for (int axisIndex = 0; axisIndex < joystick->GetAxesCount(); ++axisIndex)
			{
				auto axisVal = joystick->GetAxisState(axisIndex);
				displayStr += asd::ToAString(("�� " + std::to_string(axisIndex) + ": ").c_str());
				displayStr += asd::ToAString(std::to_string(axisVal).c_str());
				displayStr += asd::ToAString("\n");
			}

		}

		stateText->SetText(displayStr.c_str());

		// Altseed���X�V����B
		asd::Engine::Update();
	}

	//Altseed�̏I������������B
	asd::Engine::Terminate();

	return;
}
