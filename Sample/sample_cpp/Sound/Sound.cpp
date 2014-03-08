
#include <Base.h>

/**
@brief	����炷�B
*/
void Sound()
{
	// ace������������
	ace::Engine::Initialize(L"Sound", 640, 480, ace::EngineOption());

	// �t�@�C����ǂݍ���
	std::shared_ptr<ace::SoundSource> se1 = ace::Engine::GetSound()->CreateSoundSource(ace::ToAString("Data/Sound/se1.wav").c_str(), true);
	std::shared_ptr<ace::SoundSource> bgm1 = ace::Engine::GetSound()->CreateSoundSource(ace::ToAString("Data/Sound/bgm1.ogg").c_str(), false);

	// �Đ�����
	int id_se1 = ace::Engine::GetSound()->Play(se1);
	int id_bgm1 = ace::Engine::GetSound()->Play(bgm1);

	// ace���i�s�\���`�F�b�N����B
	while (ace::Engine::DoEvents())
	{
		// ace���X�V����B
		ace::Engine::Update();

		// �����Đ��I�����Ă邩���ׂ�
		if (!ace::Engine::GetSound()->IsPlaying(id_bgm1))
		{
			break;
		}
	}

	// ace���I������B
	ace::Engine::Terminate();
}
