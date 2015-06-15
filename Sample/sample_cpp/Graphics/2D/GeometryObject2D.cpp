#include <Base.h>

/**
@brief	�}�`��\������B
*/
void GeometryObject2D()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("GeometryObject2D").c_str(), 640, 480, asd::EngineOption());

	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample1.png").c_str());

	//�}�`�`��N���X�̃R���X�g���N�^���Ăяo���B
	auto geometryObj1 = std::make_shared<asd::GeometryObject2D>();
	auto geometryObj2 = std::make_shared<asd::GeometryObject2D>();
	auto geometryObj3 = std::make_shared<asd::GeometryObject2D>();

	//�}�`�`��N���X�����C���[�ɒǉ�����B
	asd::Engine::AddObject2D(geometryObj1);
	asd::Engine::AddObject2D(geometryObj2);
	asd::Engine::AddObject2D(geometryObj3);

	//�ʂ�}�`�`��N���X1�ɂĕ`�悷��B
	{
		//�ʂ̊O�a�A���a�A���_���A���S�ʒu�A�J�n���_�ԍ��A�I�����_�ԍ����w��B
		auto arc = std::make_shared<asd::ArcShape>();
		arc->SetOuterDiameter(100);
		arc->SetInnerDiameter(10);
		arc->SetNumberOfCorners(96);
		arc->SetPosition(asd::Vector2DF(300, 100));
		arc->SetStartingCorner(90);
		arc->SetEndingCorner(5);

		//�ʂ�`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
		geometryObj1->SetShape(arc);
		geometryObj1->SetTexture(texture);
		geometryObj1->SetPosition(asd::Vector2DF(0, 0));
	}

	//��`��}�`�`��N���X2�ɂĕ`�悷��B
	{
		//��`�̕`��͈́AUV�͈͂��w��B
		auto rect = std::make_shared<asd::RectangleShape>();
		rect->SetDrawingArea(asd::RectF(10, 210, 300, 200));
		rect->SetUV(asd::RectF(0, 0, 0.5, 0.5));

		//��`��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
		geometryObj2->SetShape(rect);
		geometryObj2->SetTexture(texture);
		geometryObj2->SetPosition(asd::Vector2DF(0, 0));
	}

	//���p�`��}�`�`��N���X3�ɂĕ`�悷��B
	{

		auto polygon = std::make_shared<asd::PolygonShape>();
		//���p�`���\�����钸�_��ǉ����Ă����B�i���`�ɂȂ�悤�ɂ���B�j
		for (int i = 0; i < 10; ++i)
		{
			asd::Vector2DF vec = asd::Vector2DF(1, 0);
			vec.SetDegree(i * 36);
			vec.SetLength((i % 2 == 0) ? 100 : 55);
			polygon->AddVertex(vec + asd::Vector2DF(500, 250));

		}

		//���p�`��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
		geometryObj3->SetShape(polygon);
		geometryObj3->SetTexture(texture);
		geometryObj3->SetPosition(asd::Vector2DF(0, 0));
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