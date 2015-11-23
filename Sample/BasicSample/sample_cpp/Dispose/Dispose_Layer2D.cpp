
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

// Vanish���Ă΂ꂽ����j�����ꂽ�Ƃ��ɃR���\�[���ɏo�͂��郌�C���[�B
class Dispose_MessageLayer : public asd::Layer2D
{
protected:
	// Vanish���Ă΂ꂽ�Ƃ��ɌĂ΂��B
	void OnVanish()
	{
		printf("Dispose_MessageLayer.OnVanish\n");
	}

	// ���̃��C���[���j�����ꂽ�Ƃ��ɌĂ΂��B
	void OnDispose()
	{
		printf("Dispose_MessageLayer.OnDispose\n");
	}
};

void Dispose_Layer2D()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("SceneAndLayer_Basic").c_str(), 640, 480, asd::EngineOption());

	// �摜��ǂݍ��ށB
	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Picture1.png").c_str());

	// �V�[���N���X�̃C���X�^���X�𐶐�����B
	auto scene = std::make_shared<asd::Scene>();

	// �J�X�^�}�C�Y�������C���[�̃C���X�^���X�𐶐�����B
	auto layer = std::make_shared<Dispose_MessageLayer>();

	// �J�X�^�}�C�Y�����I�u�W�F�N�g�̃C���X�^���X�𐶐�����B
	auto obj = std::make_shared<Dispose_MessageObject>();

	// �I�u�W�F�N�g�̈ʒu�ƃe�N�X�`����ݒ肷��B
	obj->SetPosition(asd::Vector2DF(50, 50));
	obj->SetTexture(texture);

	// �`�悷��V�[�����w�肷��B
	asd::Engine::ChangeScene(scene);

	// �`�悷�郌�C���[���V�[���ɒǉ�����B
	scene->AddLayer(layer);

	// �`�悷��I�u�W�F�N�g�����C���[�ɒǉ�����B
	layer->AddObject(obj);

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
			printf("���C���[��j�����܂�\n");
			// ���C���[��j������B
			layer->Vanish();
		}
	}

	// Altseed���I������B
	asd::Engine::Terminate();
}