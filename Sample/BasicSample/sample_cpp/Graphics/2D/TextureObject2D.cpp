
#include <ace.h>

// TextureObject2D�̃T���v���BTextureObject2D��p���ĉ摜��\�����Ă��܂��B
void TextureObject2D()
{
	// AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("TextureObject2D").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<ace::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<ace::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	ace::Engine::ChangeScene(scene);

	// �e�N�X�`����ǂݍ���
	auto tex = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample1.png").c_str());

	// TextureObject2D�̃C���X�^���X�𐶐�����
	auto obj = std::make_shared<ace::TextureObject2D>();

	// �`��Ɏg���e�N�X�`����ݒ肷��
	obj->SetTexture(tex);

	// �`��ʒu���w�肷��
	obj->SetPosition(ace::Vector2DF(100, 100));

	// ���C���[�֒ǉ�����
	layer->AddObject(obj);

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		// AC-Engine���X�V����B
		ace::Engine::Update();
	}

	// AC-Engine�̏I������������B
	ace::Engine::Terminate();

	return;
}