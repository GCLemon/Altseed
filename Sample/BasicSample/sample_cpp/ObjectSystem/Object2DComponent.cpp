
#include <ace.h>

// Object2DComponent��p���āA�I�u�W�F�N�g�̃p�����[�^�[��ύX����T���v���ł��B

// �I�u�W�F�N�g����]������R���|�[�l���g
class RotatingComponent : public ace::Object2DComponent
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
	// AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("Object2DComponent").c_str(), 640, 480, ace::EngineOption());

	// �g�p����V�[���A���C���[�A�I�u�W�F�N�g�A�R���|�[�l���g�𐶐�����B
	auto scene = std::make_shared<ace::Scene>();
	auto layer = std::make_shared<ace::Layer2D>();
	auto obj = std::make_shared<ace::TextureObject2D>();
	auto component = std::make_shared<RotatingComponent>();

	// �V�[����ύX����B
	ace::Engine::ChangeScene(scene);

	// �V�[���Ƀ��C���[��ǉ�����B
	scene->AddLayer(layer);

	// ���C���[�ɃI�u�W�F�N�g��ǉ�����B
	layer->AddObject(obj);

	// �I�u�W�F�N�g�ɉ�]�R���|�[�l���g���R���|�[�l���g��"Rotate"�Œǉ�����B
	obj->AddComponent(component, ace::ToAString("Rotate"));

	// �摜��ǂݍ��ށB
	auto texture = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Block1.png").c_str());

	// �I�u�W�F�N�g�ɉ摜��ݒ肷��B
	obj->SetTexture(texture);

	// �I�u�W�F�N�g�̈ʒu��ݒ肷��B
	obj->SetPosition(ace::Vector2DF(320, 240));

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		// AC-Engine���X�V����B
		ace::Engine::Update();
	}

	//AC-Engine�̏I������������B
	ace::Engine::Terminate();

	return;
}
