#include <Base.h>

/**
@brief	�}�`��\������B
*/
void GeometryObject2D()
{
	// ace������������
	ace::Engine::Initialize(ace::ToAString("GeometryObject2D").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<ace::Scene>();

	auto layer = std::make_shared<ace::Layer2D>();
	auto texture = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample1.png").c_str());

	//�}�`�`��N���X�̃R���X�g���N�^���Ăяo��
	auto geometryObj1 = std::make_shared<ace::GeometryObject2D>();
	auto geometryObj2 = std::make_shared<ace::GeometryObject2D>();
	auto geometryObj3 = std::make_shared<ace::GeometryObject2D>();
	auto geometryObj4 = std::make_shared<ace::GeometryObject2D>();
	auto geometryObj5 = std::make_shared<ace::GeometryObject2D>();
	auto geometryObj6 = std::make_shared<ace::GeometryObject2D>();

	//�}�`�`��N���X�����C���[�ɒǉ�����B
	layer->AddObject(geometryObj1);
	layer->AddObject(geometryObj2);
	layer->AddObject(geometryObj3);
	layer->AddObject(geometryObj4);
	layer->AddObject(geometryObj5);
	layer->AddObject(geometryObj6);

	//���C���[���V�[���ɒǉ�����B
	scene->AddLayer(layer);

	//�V�[����ύX����B
	ace::Engine::ChangeScene(scene);

	//�~��}�`�`��N���X1�ɂĕ`�悷��B
	{
		//�~�̊O�a�A���a�A���_���A���S�ʒu���w��B
		auto circle = std::make_shared<ace::CircleShape>();
		circle->SetOuterDiameter(100);
		circle->SetInnerDiameter(10);
		circle->SetNumberOfCorners(96);
		circle->SetPosition(ace::Vector2DF(100, 50));

		//�~��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
		geometryObj1->SetShape(circle);
		geometryObj1->SetTexture(texture);
		geometryObj1->SetPosition(ace::Vector2DF(0, 0));
	}

	//�ʂ�}�`�`��N���X2�ɂĕ`�悷��B
		{
			//�ʂ̊O�a�A���a�A���_���A���S�ʒu�A�J�n���_�ԍ��A�I�����_�ԍ����w��B
			auto arc = std::make_shared<ace::ArcShape>();
			arc->SetOuterDiameter(100);
			arc->SetInnerDiameter(10);
			arc->SetNumberOfCorners(96);
			arc->SetPosition(ace::Vector2DF(300, 50));
			arc->SetStartingCorner(90);
			arc->SetEndingCorner(5);

			//�ʂ�`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
			geometryObj2->SetShape(arc);
			geometryObj2->SetTexture(texture);
			geometryObj2->SetPosition(ace::Vector2DF(0, 0));
		}

		//������}�`�`��N���X3�ɂĕ`�悷��B
		{
			//�����̎n�_�A�I�_�A�������w��B
			auto line = std::make_shared<ace::LineShape>();
			line->SetStartingPosition(ace::Vector2DF(410, 50));
			line->SetEndingPosition(ace::Vector2DF(630, 50));
			line->SetThickness(5.0f);

			//������`�悷��}�`�Ƃ��Đݒ�B
			geometryObj3->SetShape(line);
			geometryObj3->SetPosition(ace::Vector2DF(0, 0));
		}

		//��`��}�`�`��N���X4�ɂĕ`�悷��B
		{
			//��`�̕`��͈́AUV�͈͂��w��B
			auto rect = std::make_shared<ace::RectangleShape>();
			rect->SetDrawingArea(ace::RectF(10, 110, 300, 200));
			rect->SetUV(ace::RectF(0, 0, 0.5, 0.5));

			//��`��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
			geometryObj4->SetShape(rect);
			geometryObj4->SetTexture(texture);
			geometryObj4->SetPosition(ace::Vector2DF(0, 0));
		}

		//�O�p�`��}�`�`��N���X5�ɂĕ`�悷��B
		{
			//�O�p�`�̊e���_�̈ʒu��UV���w��B
			auto triangle = std::make_shared<ace::TriangleShape>();
			triangle->SetPointByIndex(ace::Vector2DF(320, 350), 0);
			triangle->SetPointByIndex(ace::Vector2DF(100, 450), 1);
			triangle->SetPointByIndex(ace::Vector2DF(540, 450), 2);

			triangle->SetUVByIndex(ace::Vector2DF(0.5, 0.2), 0);
			triangle->SetUVByIndex(ace::Vector2DF(0.1, 0.5), 1);
			triangle->SetUVByIndex(ace::Vector2DF(0.9, 0.7), 2);

			//�O�p�`��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
			geometryObj5->SetShape(triangle);
			geometryObj5->SetTexture(texture);
			geometryObj5->SetPosition(ace::Vector2DF(0, 0));
		}

		//���p�`��}�`�`��N���X6�ɂĕ`�悷��B
		{

			auto polygon = std::make_shared<ace::PolygonShape>();
			//���p�`���\�����钸�_��ǉ����Ă����B�i���`�ɂȂ�悤�ɂ���B�j
			for (int i = 0; i < 10; ++i)
			{
				ace::Vector2DF vec = ace::Vector2DF(1, 0);
				vec.SetDegree(i * 36);
				vec.SetLength((i % 2 == 0) ? 100 : 55);
				polygon->AddVertex(vec + ace::Vector2DF(500, 250));

			}

			//���p�`��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
			geometryObj6->SetShape(polygon);
			geometryObj6->SetTexture(texture);
			geometryObj6->SetPosition(ace::Vector2DF(0, 0));
		}

		// ace���i�s�\���`�F�b�N����B
		while (ace::Engine::DoEvents())
		{
			// ace���X�V����B
			ace::Engine::Update();
		}

		// ace���I������B
		ace::Engine::Terminate();
}