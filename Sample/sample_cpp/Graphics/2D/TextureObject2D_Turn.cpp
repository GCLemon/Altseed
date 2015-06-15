
#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void TextureObject2D_Turn()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("TextureObject2D_Turn").c_str(), 640, 480, asd::EngineOption());

	{
		auto tex1 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample2.png").c_str());

		auto obj1 = std::make_shared<asd::TextureObject2D>();

		obj1->SetTexture(tex1);

		obj1->SetPosition(asd::Vector2DF(500, 400));

		//�摜���㉺�ɔ��]����
		obj1->SetTurnUL(true);

		asd::Engine::AddObject2D(obj1);
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