
#include <Base.h>

/**
@brief	�e�N�X�`����\������B
*/
void TextureObject2D_Default()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("TextureObject2D_Default").c_str(), 640, 480, asd::EngineOption());

	{
		// �e�N�X�`���𐶐�����
		auto tex0 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample2.png").c_str());

		//TextureObject2D�𐶐�����
		auto obj0 = std::make_shared<asd::TextureObject2D>();

		//�`��Ɏg���e�N�X�`����ݒ肷��
		obj0->SetTexture(tex0);

		//�`��ʒu���w�肷��
		obj0->SetPosition(asd::Vector2DF(100, 400));

		//���C���[�֒ǉ�����
		asd::Engine::AddObject2D(obj0);
	}

	// ace���i�s�\���`�F�b�N����B
	while (asd::Engine::DoEvents())
	{
		// ace���X�V����B
		asd::Engine::Update();
	}

	// ace���I������B
	asd::Engine::Terminate();
}