#include <Base.h>

/**
@brief	�~��`�悷��T���v���B
*/
void GeometryObject2D_CircleShape()
{
	// Altseed������������
	asd::Engine::Initialize(asd::ToAString("GeometryObject2D_CircleShape").c_str(), 640, 480, asd::EngineOption());

	// �}�`�`��N���X�̃R���X�g���N�^���Ăяo���B
	auto geometryObj = std::make_shared<asd::GeometryObject2D>();

	// �}�`�`��N���X�����C���[�ɒǉ�����B
	asd::Engine::AddObject2D(geometryObj);

	// �ʂ�}�`�`��N���X�ɂĕ`�悷��B
	{
		// �ʂ̊O�a�A���S�ʒu���w��B
		auto arc = std::make_shared<asd::ArcShape>();
		arc->SetOuterDiameter(100);
		arc->SetPosition(asd::Vector2DF(300, 100));

		// �ʂ�`�悷��}�`�Ƃ��Đݒ肷��B
		geometryObj->SetShape(arc);
		geometryObj->SetPosition(asd::Vector2DF(0, 0));
	}

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();
	}

	// Altseed���I������B
	asd::Engine::Terminate();
}