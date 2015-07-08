#include <Altseed.h>

// Collision2D�̃T���v���B�}�E�X�ɂ���đ��삷��~���Œ肳�ꂽ�~�Ƀq�b�g������~���Ԃ��ω����܂��B
void Collision2D_Basic()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Collision2D_Basic").c_str(), 640, 480, asd::EngineOption());

	// �}�`�`��I�u�W�F�N�g�̃C���X�^���X�𐶐�����B
	std::shared_ptr<asd::GeometryObject2D> geometryObj0 = std::make_shared<asd::GeometryObject2D>();
	std::shared_ptr<asd::GeometryObject2D> geometryObj1 = std::make_shared<asd::GeometryObject2D>();

	// �}�E�X�ɂ���ē������~�B
	std::shared_ptr<asd::CircleShape> selfCircle;

	// ��~���Ă���~�A�O�p�`�A��`�B
	std::shared_ptr<asd::CircleShape> circle;

	// �}�`�`��N���X���G���W���ɒǉ�����B
	asd::Engine::AddObject2D(geometryObj0);
	asd::Engine::AddObject2D(geometryObj1);

	// �}�E�X�ɂ���ē������~�̌`��ƕ`��̐ݒ���s���B
	{
		// �~�̊O�a�A���a�A���_���A���S�ʒu���w�肷��B
		selfCircle = std::make_shared<asd::CircleShape>();
		selfCircle->SetOuterDiameter(100);

		// �~��`�悷��}�`�Ƃ��čőO�ʂɕ`�悳���悤�ɐݒ肷��B
		geometryObj0->SetShape(selfCircle);
	}

	// ��~���Ă���~�̌`��ƕ`��̐ݒ���s���B
	{
		// �~�̊O�a�A���a�A���_���A���S�ʒu���w�肷��B
		circle = std::make_shared<asd::CircleShape>();
		circle->SetOuterDiameter(100);
		circle->SetPosition(asd::Vector2DF(100, 100));

		// �~��`�悷��}�`�Ƃ��Đݒ肷��B
		geometryObj1->SetShape(circle);
	}


	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// �}�E�X�ɂ���Đ��䂳���~�̒��S�ʒu���}�E�X�̈ʒu�Ƃ���B
		selfCircle->SetPosition(asd::Engine::GetMouse()->GetPosition());

		// �Œ肳��Ă���~�ɁA�}�E�X�ɂ���ē����~���Փ˂������ɉ~��Ԃ��ω�������B
		// �����łȂ����͔����ω�������B
		if (selfCircle->GetIsCollidedWith(circle))
		{
			geometryObj0->SetColor(asd::Color(255, 0, 0, 255));
		}
		else
		{
			geometryObj0->SetColor(asd::Color(255, 255, 255, 255));
		}

		// Altseed���X�V����B
		asd::Engine::Update();
	}

	// Altseed�̏I������������B
	asd::Engine::Terminate();

	return;
}