#include <Base.h>

/**
@brief	�}�`��\������B
*/
void GeometryObject2D_ArcShape()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("GeometryObject2D_ArcShape").c_str(), 640, 480, asd::EngineOption());

	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample1.png").c_str());

	//�}�`�`��N���X�̃R���X�g���N�^���Ăяo���B
	auto geometryObj = std::make_shared<asd::GeometryObject2D>();

	//�}�`�`��N���X�����C���[�ɒǉ�����B
	asd::Engine::AddObject2D(geometryObj);

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
		geometryObj->SetShape(arc);
		geometryObj->SetTexture(texture);
		geometryObj->SetPosition(asd::Vector2DF(0, 0));
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