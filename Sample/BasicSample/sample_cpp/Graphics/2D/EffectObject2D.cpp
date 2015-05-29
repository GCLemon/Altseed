
#include <ace.h>

/**
@brief	EffectObject2D�̃T���v���B�G�t�F�N�g��\������B
*/
void EffectObject2D()
{
	// AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("EffectObject2D").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<ace::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<ace::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	ace::Engine::ChangeScene(scene);

	// �G�t�F�N�g��ǂݍ���
	auto effect = ace::Engine::GetGraphics()->CreateEffect(ace::ToAString("Data/Effect/magic.efk").c_str());

	// �G�t�F�N�g�I�u�W�F�N�g�𐶐�����
	auto effectObj = std::make_shared<ace::EffectObject2D>();

	// �G�t�F�N�g�����C���[�ɒǉ�����
	layer->AddObject(effectObj);

	// �G�t�F�N�g�̈ʒu�A�傫�����w�肷��
	effectObj->SetPosition(ace::Vector2DF(320, 240));
	effectObj->SetScale(ace::Vector2DF(50, 50));
	
	// �G�t�F�N�g��ݒ肷��
	effectObj->SetEffect(effect);

	// �G�t�F�N�g���Đ�����
	effectObj->Play();

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		// AC-Engine���X�V����B
		ace::Engine::Update();
	}

	// AC-Engine�̏I������������B
	ace::Engine::Terminate();
}