
#include <Altseed.h>

// BGM�����[�v�Đ�����T���v���B
void Sound_Loop()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Sound").c_str(), 640, 480, asd::EngineOption());

	// �����t�@�C����ǂݍ��ށB
	std::shared_ptr<asd::SoundSource> bgm1 = asd::Engine::GetSound()->CreateSoundSource(asd::ToAString("Data/Sound/bgm1.ogg").c_str(), false);

	// �����̃��[�v��L���ɂ���B
	bgm1->SetIsLoopingMode(true);

	// �����̃��[�v�n�[��1�b�ɁA���[�v�I�[��6�b�ɐݒ肷��B
	bgm1->SetLoopStartingPoint(1.0f);
	bgm1->SetLoopEndPoint(6.0f);

	// �������Đ�����B
	int id_bgm1 = asd::Engine::GetSound()->Play(bgm1);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();
	}

	// Altseed�̏I������������B
	asd::Engine::Terminate();
}
