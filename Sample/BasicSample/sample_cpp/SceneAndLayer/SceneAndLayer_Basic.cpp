#include <Altseed.h>

// �V�[���ƃ��C���[���蓮�Őݒ肷��T���v���B
void SceneAndLayer_Basic()
{
	// Altseed������������
	asd::Engine::Initialize(asd::ToAString("SceneAndLayer_Basic").c_str(), 640, 480, asd::EngineOption());

	// �e�N�X�`�������[�h����B
	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Picture1.png").c_str());

	// �V�[���̃R���X�g���N�^���Ăяo���B
	auto scene = std::make_shared<asd::Scene>();

	// ���C���[�̃R���X�g���N�^���Ăяo���B
	auto layer = std::make_shared<asd::Layer2D>();

	// �I�u�W�F�N�g�̃R���X�g���N�^���Ăяo���B
	auto obj = std::make_shared<asd::TextureObject2D>();

	// �I�u�W�F�N�g�̈ʒu�ƃe�N�X�`����ݒ�B
	obj->SetPosition(asd::Vector2DF(50, 50));
	obj->SetTexture(texture);

	// �`�悷��V�[�����w�肷��B
	asd::Engine::ChangeScene(scene);

	// �`�悷�郌�C���[���V�[���ɒǉ�����B
	scene->AddLayer(layer);

	// �`�悷��I�u�W�F�N�g�����C���[�ɒǉ�����B
	layer->AddObject(obj);

	while (asd::Engine::DoEvents())
	{
		asd::Engine::Update();
	}

	asd::Engine::Terminate();
}