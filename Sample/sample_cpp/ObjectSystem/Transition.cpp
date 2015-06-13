#include <Base.h>

//Sample1.png���E��]�����Ȃ���\������N���X�B
class Scene1 : public asd::Scene
{
	std::shared_ptr<asd::TextureObject2D> obj;
protected:
	virtual void OnUpdated() override;
public:
	Scene1();
};

//Block1.png������]�����Ȃ���\������N���X�B
class Scene2 : public asd::Scene
{
	std::shared_ptr<asd::TextureObject2D> obj;
protected:
	virtual void OnUpdated() override;
public:
	Scene2();
};

Scene1::Scene1()
{
	//���C���[��ǉ�����B
	auto layer = std::make_shared<asd::Layer2D>();
	AddLayer(layer);

	//Sample1.png��`�悷��e�N�X�`���I�u�W�F�N�g��ݒ肷��B
	obj = std::make_shared<asd::TextureObject2D>();
	obj->SetTexture(asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample1.png").c_str()));
	obj->SetCenterPosition(asd::Vector2DF(256, 256));
	obj->SetPosition(asd::Vector2DF(320, 240));
	layer->AddObject(obj);
}

void Scene1::OnUpdated()
{
	//Sample1.png���E������2�x��]����B
	auto v = obj->GetAngle();
	v += 2.0;
	obj->SetAngle(v);

	//�}�E�X�����N���b�N���ꂽ����Scene2�֑J�ڂ���B
	if (asd::Engine::GetMouse()->GetLeftButton()->GetButtonState() == asd::MouseButtonState::Push)
	{
		auto scene2 = std::make_shared<Scene2>();
		asd::Engine::ChangeScene(scene2);
	}
}

Scene2::Scene2()
{
	//���C���[��ǉ�����B
	auto layer = std::make_shared<asd::Layer2D>();
	AddLayer(layer);

	//Block1.png��`�悷��e�N�X�`���I�u�W�F�N�g��ݒ肷��B
	obj = std::make_shared<asd::TextureObject2D>();
	obj->SetTexture(asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Block1.png").c_str()));
	obj->SetPosition(asd::Vector2DF(100, 100));
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
	if (asd::Engine::GetMouse()->GetLeftButton()->GetButtonState() == asd::MouseButtonState::Push)
	{
		auto& scene1 = std::make_shared<Scene1>();
		asd::Engine::ChangeSceneWithTransition(scene1, std::make_shared<asd::TransitionFade>(1.0f, 1.0f));
	}
}

void Transition()
{
	//ace������������B
	asd::Engine::Initialize(asd::ToAString("Transition").c_str(), 640, 480, asd::EngineOption());

	// �V�[����Scene1�ɐݒ肷��B
	auto scene = std::make_shared<Scene1>();
	asd::Engine::ChangeScene(scene);

	// ace���i�s�\���`�F�b�N����B
	while (asd::Engine::DoEvents())
	{
		//ace���X�V����B
		asd::Engine::Update();
	}

	//ace���I������B
	asd::Engine::Terminate();
}
