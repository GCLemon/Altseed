
#include <Base.h>

/**
@brief	����炷�T���v��
*/
void Sound()
{
	// ace������������B
	ace::Engine::Initialize(ace::ToAString("Sound").c_str(), 640, 480, ace::EngineOption());

	// �t�@�C����ǂݍ��ށB
	std::shared_ptr<ace::SoundSource> se1 = ace::Engine::GetSound()->CreateSoundSource(ace::ToAString("Data/Sound/se1.wav").c_str(), true);
	std::shared_ptr<ace::SoundSource> bgm1 = ace::Engine::GetSound()->CreateSoundSource(ace::ToAString("Data/Sound/bgm1.ogg").c_str(), false);

	// �Đ�����B
	int id_se1 = ace::Engine::GetSound()->Play(se1);
	int id_bgm1 = ace::Engine::GetSound()->Play(bgm1);

	// ace���i�s�\���`�F�b�N����B
	while (ace::Engine::DoEvents())
	{
		// ace���X�V����B
		ace::Engine::Update();

		// �����Đ��I�����Ă邩���ׂ�B
		if (!ace::Engine::GetSound()->IsPlaying(id_bgm1))
		{
			break;
		}
	}

	// ace���I������B
	ace::Engine::Terminate();
}
