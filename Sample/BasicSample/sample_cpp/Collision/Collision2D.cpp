#include <ace.h>

// Collision2D�̃T���v���B�}�E�X�ɂ���đ��삷��~�������ꂩ�̃I�u�W�F�N�g�Ƀq�b�g������~���Ԃ����܂�܂��B
void Collision2D()
{
	// AC-Engine������������
	ace::Engine::Initialize(ace::ToAString("GeometryObject2D").c_str(), 640, 480, ace::EngineOption());

	//�}�`�`��N���X�̃R���X�g���N�^���Ăяo���B
	std::shared_ptr<ace::GeometryObject2D> geometryObj0 = std::make_shared<ace::GeometryObject2D>();
	std::shared_ptr<ace::GeometryObject2D> geometryObj1 = std::make_shared<ace::GeometryObject2D>();
	std::shared_ptr<ace::GeometryObject2D> geometryObj2 = std::make_shared<ace::GeometryObject2D>();
	std::shared_ptr<ace::GeometryObject2D> geometryObj3 = std::make_shared<ace::GeometryObject2D>();

	//�}�E�X�ɂ���ē������~
	std::shared_ptr<ace::CircleShape> selfCircle;

	//��~���Ă���~�A�O�p�`�A��`
	std::shared_ptr<ace::CircleShape> circle;
	std::shared_ptr<ace::TriangleShape> triangle;
	std::shared_ptr<ace::RectangleShape> rect;

	// �V�[���𐶐�����
	auto scene = std::make_shared<ace::Scene>();

	// �V�[���Ƀ��C���[��ǉ�����B
	auto layer = std::make_shared<ace::Layer2D>();


	//�}�`�`��N���X�����C���[�ɒǉ�����B
	layer->AddObject(geometryObj0);
	layer->AddObject(geometryObj1);
	layer->AddObject(geometryObj2);
	layer->AddObject(geometryObj3);

	//���C���[��ǉ�����B
	scene->AddLayer(layer);

	// �V�[����؂�ւ���B
	ace::Engine::ChangeScene(scene);

	//�}�E�X�ɂ���ē������~�̌`��ƕ`��̐ݒ���s���B
	{
		//�~�̊O�a�A���a�A���_���A���S�ʒu���w��B
		selfCircle = std::make_shared<ace::CircleShape>();
		selfCircle->SetOuterDiameter(100);
		selfCircle->SetInnerDiameter(0);
		selfCircle->SetNumberOfCorners(96);
		selfCircle->SetPosition(ace::Vector2DF(100, 50));

		//�~��`�悷��}�`�Ƃ��Đݒ肷��B
		geometryObj0->SetShape(selfCircle);
		geometryObj0->SetPosition(ace::Vector2DF(0, 0));
	}

	//��~���Ă���~�̌`��ƕ`��̐ݒ���s���B
	{
		//�~�̊O�a�A���a�A���_���A���S�ʒu���w��B
		circle = std::make_shared<ace::CircleShape>();
		circle->SetOuterDiameter(100);
		circle->SetInnerDiameter(0);
		circle->SetNumberOfCorners(96);
		circle->SetPosition(ace::Vector2DF(100, 50));

		//�~��`�悷��}�`�Ƃ��Đݒ肷��B
		geometryObj1->SetShape(circle);
		geometryObj1->SetPosition(ace::Vector2DF(0, 0));
	}

	//��~���Ă���O�p�`�̌`��ƕ`��̐ݒ���s���B
	{
		//�O�p�`�̊e���_�̈ʒu���w��B
		triangle = std::make_shared<ace::TriangleShape>();
		triangle->SetPointByIndex(ace::Vector2DF(400, 350), 0);
		triangle->SetPointByIndex(ace::Vector2DF(300, 450), 1);
		triangle->SetPointByIndex(ace::Vector2DF(540, 450), 2);

		//�O�p�`��`�悷��}�`�Ƃ��Đݒ肷��B
		geometryObj2->SetShape(triangle);
		geometryObj2->SetPosition(ace::Vector2DF(0, 0));
	}

	//��~���Ă����`�̌`��ƕ`��̐ݒ���s���B
	{
		rect = std::make_shared<ace::RectangleShape>();
		rect->SetDrawingArea(ace::RectF(10, 110, 300, 200));
		rect->SetAngle(15);

		geometryObj3->SetShape(rect);
		geometryObj3->SetPosition(ace::Vector2DF(0, 0));
	}


	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		{
			//�}�E�X�ɂ���Đ��䂳���~�̒��S�ʒu���}�E�X�̈ʒu�Ƃ���B
			selfCircle->SetPosition(ace::Engine::GetMouse()->GetPosition());

			//��~���Ă���~�A�O�p�`�A��`�Ƀ}�E�X�ɂ���ē����~���Փ˂������ɉ~��Ԃ��h��Ԃ��B
			//�����łȂ����͔����h��Ԃ��B
			if (selfCircle->GetIsCollidedWith(circle)
				|| selfCircle->GetIsCollidedWith(triangle)
				|| selfCircle->GetIsCollidedWith(rect))
			{
				geometryObj0->SetColor(ace::Color(255, 0, 0, 255));
			}
			else
			{
				geometryObj0->SetColor(ace::Color(255, 255, 255, 255));
			}
		}
		// AC-Engine���X�V����B
		ace::Engine::Update();
	}

	// AC-Engine�̏I������������B
	ace::Engine::Terminate();

}