
#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void EffectObject2D()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("EffectObject2D").c_str(), 640, 480, asd::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<asd::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<asd::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	asd::Engine::ChangeScene(scene);

	// �G�t�F�N�g��ǂݍ���
	auto effect = asd::Engine::GetGraphics()->CreateEffect(asd::ToAString("Data/Effect/magic.efk").c_str());

	// �G�t�F�N�g�I�u�W�F�N�g�𐶐�����
	auto effectObj = std::make_shared<asd::EffectObject2D>();

	// �G�t�F�N�g�����C���[�ɒǉ�����
	layer->AddObject(effectObj);

	// �G�t�F�N�g�̈ʒu�A�傫�����w�肷��
	effectObj->SetPosition(asd::Vector2DF(320, 240));
	effectObj->SetScale(asd::Vector2DF(50, 50));
	
	// �G�t�F�N�g��ݒ肷��
	effectObj->SetEffect(effect);

	// �G�t�F�N�g���Đ�����
	effectObj->Play();

	// ace���i�s�\���`�F�b�N����B
	while (asd::Engine::DoEvents())
	{
		// ace���X�V����B
		asd::Engine::Update();
	}

	// ace���I������B
	asd::Engine::Terminate();
}