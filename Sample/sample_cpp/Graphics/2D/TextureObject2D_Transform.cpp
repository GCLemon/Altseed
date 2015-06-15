
#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void TextureObject2D_Transform()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("TextureObject2D_Transform").c_str(), 640, 480, asd::EngineOption());

	auto obj3 = std::make_shared<asd::TextureObject2D>();
	{

		auto tex3 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample1.png").c_str());

		//�摜(�T�C�Y 512 x 512)�̒��S(256 x 256 �̒n�_)��`��̋N�_�Ƃ���
		obj3->SetCenterPosition(asd::Vector2DF(256, 256));
		obj3->SetTexture(tex3);

		obj3->SetPosition(asd::Vector2DF(320, 240));

		//�摜�𒆐S������45�x��]����
		obj3->SetAngle(45);

		//�摜��X,Y������0.4�{�ɏk������
		obj3->SetScale(asd::Vector2DF(0.4f, 0.4f));

		asd::Engine::AddObject2D(obj3);
	}

	// ace���i�s�\���`�F�b�N����B
	while (asd::Engine::DoEvents())
	{
		//��]�p���擾���āA0.5�x��]������B
		float angle = obj3->GetAngle();
		angle += 0.5f;
		obj3->SetAngle(angle);

		// ace���X�V����B
		asd::Engine::Update();
	}

	// ace���I������B
	asd::Engine::Terminate();
}