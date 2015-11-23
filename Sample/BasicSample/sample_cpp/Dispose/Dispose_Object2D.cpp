
#include <Altseed.h>

// Vanish���Ă΂ꂽ����j�����ꂽ�Ƃ��ɃR���\�[���ɏo�͂���I�u�W�F�N�g�B
class Dispose_MessageObject : public asd::TextureObject2D
{
protected:
	// Vanish���Ă΂ꂽ�Ƃ��ɌĂ΂��B
	void OnVanish()
	{
		printf("Dispose_MessageObject.OnVanish\n");
	}

	// ���̃I�u�W�F�N�g���j�����ꂽ�Ƃ��ɌĂ΂��B
	void OnDispose()
	{
		printf("Dispose_MessageObject.OnDispose\n");
	}
};

void Dispose_Object2D()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Dispose_Object2D").c_str(), 640, 480, asd::EngineOption());

	// �摜��ǂݍ��ށB
	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Picture1.png").c_str());

	// �摜�`��I�u�W�F�N�g�̃C���X�^���X�𐶐�����B
	auto obj = std::make_shared<Dispose_MessageObject>();

	// �`�悳���摜��ݒ肷��B
	obj->SetTexture(texture);

	// �`��ʒu���w�肷��B
	obj->SetPosition(asd::Vector2DF(50, 50));

	// �摜�`��I�u�W�F�N�g�̃C���X�^���X���G���W���ɒǉ�����B
	asd::Engine::AddObject2D(obj);

	// �t���[�����𐔂��邽�߂̕ϐ��B
	int count = 0;

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();

		// �t���[���𐔂���B
		++count;

		// 10�t���[���ڂɂȂ�����
		if (count == 10)
		{
			printf("�I�u�W�F�N�g��j�����܂�\n");
			// �I�u�W�F�N�g��j������B
			obj->Vanish();
		}
	}

	// Altseed���I������B
	asd::Engine::Terminate();
}