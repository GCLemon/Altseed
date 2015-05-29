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

	//�}�`�`��N���X�̃R���X�g���N�^���Ăяo���B
	auto geometryObj1 = std::make_shared<ace::GeometryObject2D>();
	auto geometryObj2 = std::make_shared<ace::GeometryObject2D>();
	auto geometryObj3 = std::make_shared<ace::GeometryObject2D>();

	//�}�`�`��N���X�����C���[�ɒǉ�����B
	layer->AddObject(geometryObj1);
	layer->AddObject(geometryObj2);
	layer->AddObject(geometryObj3);

	//���C���[���V�[���ɒǉ�����B
	scene->AddLayer(layer);

	//�V�[����ύX����B
	ace::Engine::ChangeScene(scene);

	//�ʂ�}�`�`��N���X1�ɂĕ`�悷��B
	{
		//�ʂ̊O�a�A���a�A���_���A���S�ʒu�A�J�n���_�ԍ��A�I�����_�ԍ����w��B
		auto arc = std::make_shared<ace::ArcShape>();
		arc->SetOuterDiameter(100);
		arc->SetInnerDiameter(10);
		arc->SetNumberOfCorners(96);
		arc->SetPosition(ace::Vector2DF(300, 100));
		arc->SetStartingCorner(90);
		arc->SetEndingCorner(5);

		//�ʂ�`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
		geometryObj1->SetShape(arc);
		geometryObj1->SetTexture(texture);
		geometryObj1->SetPosition(ace::Vector2DF(0, 0));
	}

	//��`��}�`�`��N���X2�ɂĕ`�悷��B
	{
		//��`�̕`��͈́AUV�͈͂��w��B
		auto rect = std::make_shared<ace::RectangleShape>();
		rect->SetDrawingArea(ace::RectF(10, 210, 300, 200));
		rect->SetUV(ace::RectF(0, 0, 0.5, 0.5));

		//��`��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
		geometryObj2->SetShape(rect);
		geometryObj2->SetTexture(texture);
		geometryObj2->SetPosition(ace::Vector2DF(0, 0));
	}

	//���p�`��}�`�`��N���X3�ɂĕ`�悷��B
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
		geometryObj3->SetShape(polygon);
		geometryObj3->SetTexture(texture);
		geometryObj3->SetPosition(ace::Vector2DF(0, 0));
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