
#include <ace.h>

// Sound��p���ĉ���炷�T���v���ł��B
void Sound()
{
	// AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("Sound").c_str(), 640, 480, ace::EngineOption());

	// ���t�@�C����ǂݍ��ށB
	std::shared_ptr<ace::SoundSource> se1 = ace::Engine::GetSound()->CreateSoundSource(ace::ToAString("Data/Sound/se1.wav").c_str(), true);
	std::shared_ptr<ace::SoundSource> bgm1 = ace::Engine::GetSound()->CreateSoundSource(ace::ToAString("Data/Sound/bgm1.ogg").c_str(), false);

	// �����Đ�����B
	int id_se1 = ace::Engine::GetSound()->Play(se1);
	int id_bgm1 = ace::Engine::GetSound()->Play(bgm1);

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		// AC-Engine���X�V����B
		ace::Engine::Update();

		// �����Đ��I�����Ă邩���ׂ�B
		if (!ace::Engine::GetSound()->GetIsPlaying(id_bgm1))
		{
			break;
		}
	}

	// AC-Engine�̏I������������B
	ace::Engine::Terminate();

	return;
}
