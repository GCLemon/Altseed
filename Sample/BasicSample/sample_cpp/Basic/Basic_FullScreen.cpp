#include <Altseed.h>

void Basic_FullScreen()
{
	// �t���X�N���[���ŋN������悤�ɏ������I�v�V�����𐶐�����B
	auto option = asd::EngineOption();
	option.IsFullScreen = true;

	// �쐬�����������I�v�V������p����Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Empty").c_str(), 640, 480, option);

	// ����������𕶎���I�u�W�F�N�g�Ƃ��č쐬�BCreateDynamicFont�ō쐬�����t�H���g�I�u�W�F�N�g��p����
	auto font = asd::Engine::GetGraphics()->CreateDynamicFont(asd::ToAString("").c_str(), 20, asd::Color(255, 255, 255, 255), 2, asd::Color(0, 0, 0, 255));
	auto obj = std::make_shared<asd::TextObject2D>();
	obj->SetFont(font);
	obj->SetText(asd::ToAString("Esc�L�[�ŏI��").c_str());

	// ����������̃I�u�W�F�N�g���G���W���ɓo�^����B
	asd::Engine::AddObject2D(obj);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();

		// Esc�L�[��������Ă�����
		if (asd::Engine::GetKeyboard()->GetKeyState(asd::Keys::Escape) == asd::KeyState::Push)
		{
			// �Q�[�����[�v�𔲂���
			break;
		}
	}

	// Altseed�̏I������������B
	asd::Engine::Terminate();
}