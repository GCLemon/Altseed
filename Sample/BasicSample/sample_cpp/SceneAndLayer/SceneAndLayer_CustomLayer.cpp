#include <Altseed.h>

// ���̃T���v���Ŏg�p����J�X�^�}�C�Y�������C���[�B
class SceneAndLayer_SampleLayer : public asd::Layer2D
{
private:
	// �t���[�����𐔂���J�E���^�B
	int count;

public:
	SceneAndLayer_SampleLayer()
	{
		// �J�E���^��������
		count = 0;
	}

	// ���t���[�����s�����֐����I�[�o�[���C�h�B
	void OnUpdated()
	{
		// �t���[�����𐔂���
		count++;

		// 60�t���[�����Ƃ�
		if (count % 60 == 0)
		{
			// �I�u�W�F�N�g�𐶐�
			auto obj = std::make_shared<asd::TextureObject2D>();

			// �I�u�W�F�N�g�̃e�N�X�`����ݒ�
			auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Picture1.png").c_str());
			obj->SetTexture(texture);

			// �I�u�W�F�N�g�̈ʒu��ݒ�
			auto p = count / 60 * 20;
			obj->SetPosition(asd::Vector2DF(p, p));

			// �I�u�W�F�N�g�����̃��C���[�ɒǉ�
			AddObject(obj);
		}
	}
};

// Layer2D���p�����邱�ƂŃJ�X�^�}�C�Y�������C���[�����A��莞�Ԃ��ƂɃI�u�W�F�N�g��ǉ�����T���v���B
void SceneAndLayer_CustomLayer()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("SceneAndLayer_CustomLayer").c_str(), 640, 480, asd::EngineOption());

	// �V�[���N���X�̃C���X�^���X�𐶐�����B
	auto scene = std::make_shared<asd::Scene>();

	// �`�悷��V�[�����w�肷��B
	asd::Engine::ChangeScene(scene);

	// ���C���[�N���X�̃C���X�^���X�𐶐�����B
	auto layer = std::make_shared<SceneAndLayer_SampleLayer>();

	// �`�悷�郌�C���[���V�[���ɒǉ�����B
	scene->AddLayer(layer);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();
	}

	// Altseed���I������B
	asd::Engine::Terminate();
}