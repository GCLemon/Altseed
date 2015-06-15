#include <Base.h>

/**
@brief	��`��\������B
*/
void GeometryObject2D_RectangleShape()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("GeometryObject2D_Rectangle").c_str(), 640, 480, asd::EngineOption());

	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample1.png").c_str());

	//�}�`�`��N���X�̃R���X�g���N�^���Ăяo���B
	auto geometryObj = std::make_shared<asd::GeometryObject2D>();

	//�}�`�`��N���X�����C���[�ɒǉ�����B
	asd::Engine::AddObject2D(geometryObj);

	//��`��}�`�`��N���X2�ɂĕ`�悷��B
	{
		//��`�̕`��͈́AUV�͈͂��w��B
		auto rect = std::make_shared<asd::RectangleShape>();
		rect->SetDrawingArea(asd::RectF(10, 210, 300, 200));
		rect->SetUV(asd::RectF(0, 0, 0.5f, 0.5f));

		//��`��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
		geometryObj->SetShape(rect);
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