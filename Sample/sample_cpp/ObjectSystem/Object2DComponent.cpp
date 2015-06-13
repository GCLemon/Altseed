#include <Base.h>

class RotatingComponent : public asd::Object2DComponent
{
public:
	void OnUpdate()
	{
		// ���t���[���A�I�u�W�F�N�g�̊p�x����]������
		GetOwner()->SetAngle(GetOwner()->GetAngle() + 2);
	}
};

void Object2DComponent()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("Object2DComponent").c_str(), 640, 480, asd::EngineOption());

	// �g�p����V�[���A���C���[�A�I�u�W�F�N�g�A�R���|�[�l���g�𐶐�
	auto scene = std::make_shared<asd::Scene>();
	auto layer = std::make_shared<asd::Layer2D>();
	auto object = std::make_shared<asd::TextureObject2D>();
	auto component = std::make_shared<RotatingComponent>();


	// �V�[����ύX
	asd::Engine::ChangeScene(scene);

	// �V�[���Ƀ��C���[��ǉ�
	scene->AddLayer(layer);

	// ���C���[�ɃI�u�W�F�N�g��ǉ�
	layer->AddObject(object);

	// �I�u�W�F�N�g�ɉ�]�R���|�[�l���g���R���|�[�l���g��"Rotate"�Œǉ�
	object->AddComponent(component, asd::ToAString("Rotate"));


	// �O���t�B�b�N�X�I�u�W�F�N�g���擾
	auto graphics = asd::Engine::GetGraphics();

	// �e�N�X�`�������[�h
	auto texture = graphics->CreateTexture2D(asd::ToAString("Data/Texture/Block1.png").c_str());

	// �I�u�W�F�N�g�ɉ摜���Z�b�g
	object->SetTexture(texture);

	// �I�u�W�F�N�g�̈ʒu���w��
	object->SetPosition(asd::Vector2DF(320, 240));


	while (asd::Engine::DoEvents())
	{
		asd::Engine::Update();
	}

	asd::Engine::Terminate();
}