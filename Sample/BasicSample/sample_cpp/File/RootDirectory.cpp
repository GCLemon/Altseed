
#include <Altseed.h>

// AddRootDirectory ��p���āA�t�@�C���̋N�_�ƂȂ�ꏊ���w��B
// ���̋N�_����Ƃ������΃p�X�ŉ摜���w�肵�`�悷��T���v���ł��B

void RootDirectory()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("RootDirectory").c_str(), 640, 480, asd::EngineOption());

	// ���[�g�f�B���N�g����ǉ�����B
	asd::Engine::GetFile()->AddRootDirectory(asd::ToAString("Data/Texture").c_str());

	// �I�u�W�F�N�g�𐶐�����B
	auto obj = std::make_shared<asd::TextureObject2D>();

	// �摜��ǂݍ��ށB
	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Picture1.png").c_str());

	// �I�u�W�F�N�g�ɉ摜��ݒ肷��B
	obj->SetTexture(texture);

	// �I�u�W�F�N�g�̈ʒu��ݒ肷��B
	obj->SetPosition(asd::Vector2DF(320, 240));

	// �G���W���ɃI�u�W�F�N�g��ǉ�����B
	asd::Engine::AddObject2D(obj);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();
	}

	//Altseed�̏I������������B
	asd::Engine::Terminate();

	return;
}
