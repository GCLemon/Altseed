#include <Base.h>

/**
@brief	�~��`�悷��T���v���B
*/
void GeometryObject2D_CircleShape()
{
	// Altseed������������
	asd::Engine::Initialize(asd::ToAString("GeometryObject2D_CircleShape").c_str(), 640, 480, asd::EngineOption());

	// �}�`�`��I�u�W�F�N�g�̃C���X�^���X�𐶐�����B
	auto geometryObj = std::make_shared<asd::GeometryObject2D>();

	// �}�`�`��I�u�W�F�N�g�̃C���X�^���X���G���W���ɒǉ�����B
	asd::Engine::AddObject2D(geometryObj);

	// �~��}�`�`��N���X�ɂĕ`�悷��B
	auto arc = std::make_shared<asd::ArcShape>();

	// �~�̊O�a�A���S�ʒu���w��B
	arc->SetOuterDiameter(100);
	arc->SetPosition(asd::Vector2DF(300, 100));

	// �~��`�悷��}�`�Ƃ��Đݒ肷��B
	geometryObj->SetShape(arc);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();
	}

	// Altseed���I������B
	asd::Engine::Terminate();
}