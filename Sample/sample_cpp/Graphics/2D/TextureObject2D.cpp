
#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void TextureObject2D()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("TextureObject2D").c_str(), 640, 480, asd::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<asd::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<asd::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	asd::Engine::ChangeScene(scene);

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
		layer->AddObject(obj0);
	}

	{
		auto tex1 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample2.png").c_str());

		auto obj1 = std::make_shared<asd::TextureObject2D>();

		obj1->SetTexture(tex1);

		obj1->SetPosition(asd::Vector2DF(500, 400));

		//�摜���㉺�ɔ��]����
		obj1->SetTurnUL(true);

		layer->AddObject(obj1);
	}

	auto obj2 = std::make_shared<asd::TextureObject2D>();
	{

		auto tex2 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Character.png").c_str());

		obj2->SetTexture(tex2);

		obj2->SetPosition(asd::Vector2DF(500, 50));

		layer->AddObject(obj2);
	}


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
		obj3->SetScale(asd::Vector2DF(0.4, 0.4));

		layer->AddObject(obj3);
	}

	{
		auto obj4 = std::make_shared<asd::TextureObject2D>();

		auto tex4 = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Character.png").c_str());

		obj4->SetTexture(tex4);

		obj4->SetPosition(asd::Vector2DF(50, 50));

		layer->AddObject(obj4);
	}


	int count = 0;
	int index = 0;
	// ace���i�s�\���`�F�b�N����B
	while (asd::Engine::DoEvents())
	{

		int xi = index % 3;
		int yi = (index / 3) % 4;

		//�e�N�X�`���̐؂�o���͈͂��w�肷��B
		obj2->SetSrc(asd::RectF(32 * xi, 32 * yi, 32, 32));

		if (count % 5 == 0)
		{
			index = (++index) % 12;
		}
		++count;

		float angle = obj3->GetAngle();
		angle += 0.5;
		obj3->SetAngle(angle);

		// ace���X�V����B
		asd::Engine::Update();
	}

	// ace���I������B
	asd::Engine::Terminate();
}