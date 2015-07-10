
#include <Altseed.h>

// Sound��p����BGM��炷�T���v���ł��B
void Sound_BGM()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Sound").c_str(), 640, 480, asd::EngineOption());

	// �����t�@�C����ǂݍ��ށB
	std::shared_ptr<asd::SoundSource> bgm1 = asd::Engine::GetSound()->CreateSoundSource(asd::ToAString("Data/Sound/bgm1.ogg").c_str(), false);

	// �������Đ�����B
	int id_bgm1 = asd::Engine::GetSound()->Play(bgm1);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();

		// �����Đ��I�����Ă邩���ׂ�B
		if (!asd::Engine::GetSound()->GetIsPlaying(id_bgm1))
		{
			break;
		}
	}

	// Altseed�̏I������������B
	asd::Engine::Terminate();
}
