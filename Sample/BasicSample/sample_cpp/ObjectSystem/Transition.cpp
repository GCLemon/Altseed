#include <Base.h>

//Sample1.png���E��]�����Ȃ���\������N���X�B
class Scene1 : public ace::Scene
{
	std::shared_ptr<ace::TextureObject2D> obj;
protected:
	virtual void OnUpdated() override;
public:
	Scene1();
};

//Block1.png������]�����Ȃ���\������N���X�B
class Scene2 : public ace::Scene
{
	std::shared_ptr<ace::TextureObject2D> obj;
protected:
	virtual void OnUpdated() override;
public:
	Scene2();
};

Scene1::Scene1()
{
	//���C���[��ǉ�����B
	auto layer = std::make_shared<ace::Layer2D>();
	AddLayer(layer);

	//Sample1.png��`�悷��e�N�X�`���I�u�W�F�N�g��ݒ肷��B
	obj = std::make_shared<ace::TextureObject2D>();
	obj->SetTexture(ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample1.png").c_str()));
	obj->SetCenterPosition(ace::Vector2DF(256, 256));
	obj->SetPosition(ace::Vector2DF(320, 240));
	layer->AddObject(obj);
}

void Scene1::OnUpdated()
{
	//Sample1.png���E������2�x��]����B
	auto v = obj->GetAngle();
	v += 2.0;
	obj->SetAngle(v);

	//�}�E�X�����N���b�N���ꂽ����Scene2�֑J�ڂ���B
	if (ace::Engine::GetMouse()->GetLeftButton()->GetButtonState() == ace::MouseButtonState::Push)
	{
		auto scene2 = std::make_shared<Scene2>();
		ace::Engine::ChangeScene(scene2);
	}
}

Scene2::Scene2()
{
	//���C���[��ǉ�����B
	auto layer = std::make_shared<ace::Layer2D>();
	AddLayer(layer);

	//Block1.png��`�悷��e�N�X�`���I�u�W�F�N�g��ݒ肷��B
	obj = std::make_shared<ace::TextureObject2D>();
	obj->SetTexture(ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Block1.png").c_str()));
	obj->SetPosition(ace::Vector2DF(100, 100));
	layer->AddObject(obj);
}

void Scene2::OnUpdated()
{
	//Block1.png����������2�x��]����B
	auto v = obj->GetAngle();
	v -= 2.0;
	obj->SetAngle(v);

	//�}�E�X�����N���b�N���ꂽ���Ƀt�F�[�h�t����Scene1�֑J�ڂ���B
	//�i�t�F�[�h�A�E�g�ƃt�F�[�h�C���͂��ꂼ��1�b�Ԃ����čs���B�j
	if (ace::Engine::GetMouse()->GetLeftButton()->GetButtonState() == ace::MouseButtonState::Push)
	{
		auto& scene1 = std::make_shared<Scene1>();
		ace::Engine::ChangeSceneWithTransition(scene1, std::make_shared<ace::TransitionFade>(1.0f, 1.0f));
	}
}

void Transition()
{
	//AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("Transition").c_str(), 640, 480, ace::EngineOption());

	// �V�[����Scene1�ɐݒ肷��B
	auto scene = std::make_shared<Scene1>();
	ace::Engine::ChangeScene(scene);

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		//ace���X�V����B
		ace::Engine::Update();
	}

	//AC-Engine�̏I������������B
	ace::Engine::Terminate();
}
