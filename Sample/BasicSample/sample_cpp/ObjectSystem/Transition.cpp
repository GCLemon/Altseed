
#include <ace.h>

// Transition��p���āA�V�[���̕ύX�̌��h����ύX����T���v���ł��B

// Scene1�̉摜��\������V�[��
class Scene1 : public ace::Scene
{
protected:
	virtual void OnUpdated() override;
public:
	Scene1();
};

// Scene2�̉摜��\������V�[��
class Scene2 : public ace::Scene
{
protected:
	virtual void OnUpdated() override;
public:
	Scene2();
};

Scene1::Scene1()
{
	// ���C���[��ǉ�����B
	auto layer = std::make_shared<ace::Layer2D>();
	AddLayer(layer);

	// Scene1��`�悷��C���X�^���X�𐶐����ă��C���[�ɒǉ�����B
	auto obj = std::make_shared<ace::TextureObject2D>();
	obj->SetTexture(ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Scene1.png").c_str()));
	layer->AddObject(obj);
}

void Scene1::OnUpdated()
{
	// �}�E�X�����N���b�N���ꂽ���Ƀt�F�[�h�t����Scene2�ɑJ�ڂ���B
	if (ace::Engine::GetMouse()->GetLeftButton()->GetButtonState() == ace::MouseButtonState::Push)
	{
		auto scene2 = std::make_shared<Scene2>();
		ace::Engine::ChangeSceneWithTransition(scene2, std::make_shared<ace::TransitionFade>(1.0f, 1.0f));
	}
}

Scene2::Scene2()
{
	// ���C���[��ǉ�����B
	auto layer = std::make_shared<ace::Layer2D>();
	AddLayer(layer);

	// Scene2��`�悷��C���X�^���X�𐶐����ă��C���[�ɒǉ�����B
	auto obj = std::make_shared<ace::TextureObject2D>();
	obj->SetTexture(ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Scene2.png").c_str()));
	layer->AddObject(obj);
}

void Scene2::OnUpdated()
{
	// �}�E�X�����N���b�N���ꂽ����Scene1�ɑJ�ڂ���B
	if (ace::Engine::GetMouse()->GetLeftButton()->GetButtonState() == ace::MouseButtonState::Push)
	{
		auto& scene1 = std::make_shared<Scene1>();
		ace::Engine::ChangeScene(scene1);
	}
}

void Transition()
{
	//AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("Transition").c_str(), 640, 480, ace::EngineOption());

	// �V�[����Scene1�ɕύX����B
	auto scene = std::make_shared<Scene1>();
	ace::Engine::ChangeScene(scene);

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
