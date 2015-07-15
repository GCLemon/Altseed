#include <Altseed.h>

// ���̃T���v���Ŏg�p����J�X�^�}�C�Y���ꂽ�V�[���B
class SceneAndLayer_SampleScene : public asd::Scene
{
private:
	// �t���[�����𐔂���J�E���^�B
	int count;

public:
	SceneAndLayer_SampleScene()
	{
		// �J�E���^��������
		count = 0;
	}

	void OnUpdated()
	{
		// �t���[�����𐔂���B
		count++;

		// 60�t���[�����ƂɃ��C���[��ǉ����鏈��
		if (count % 60 == 0)
		{
			// ���C���[�N���X�̃C���X�^���X�𐶐�����B
			auto layer = std::make_shared<asd::Layer2D>();

			// �`�悷�郌�C���[���V�[���ɒǉ�����B
			AddLayer(layer);

			// �I�u�W�F�N�g�𐶐�����B
			auto obj = std::make_shared<asd::TextureObject2D>();

			// �I�u�W�F�N�g�ɉ摜��ݒ肷��B
			auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Picture1.png").c_str());
			obj->SetTexture(texture);

			// �I�u�W�F�N�g�̈ʒu��ݒ肷��B
			auto p = count / 60 * 20;
			obj->SetPosition(asd::Vector2DF(p, p));

			// �I�u�W�F�N�g�����C���[�ɒǉ�����B
			layer->AddObject(obj);
		}
	}
};

// Scene�N���X���p�����邱�ƂŃJ�X�^�}�C�Y���ꂽ�V�[�������A��莞�Ԃ��ƂɃ��C���[��ǉ����Ă����T���v���B
void SceneAndLayer_CustomScene()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("SceneAndLayer_CustomScene").c_str(), 640, 480, asd::EngineOption());

	// �V�[���N���X�̃C���X�^���X�𐶐�����B
	auto scene = std::make_shared<SceneAndLayer_SampleScene>();

	// �`�悷��V�[�����w�肷��B
	asd::Engine::ChangeScene(scene);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();
	}

	// Altseed���I������B
	asd::Engine::Terminate();
}