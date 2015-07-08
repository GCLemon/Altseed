#include <Base.h>

/**
@brief	���p�`���e�N�X�`��������������ŕ\������T���v���B
*/
void GeometryObject2D_PolygonShape_Textured()
{
	// Altseed������������
	asd::Engine::Initialize(asd::ToAString("GeometryObject2D_PolygonShape_Textured").c_str(), 640, 480, asd::EngineOption());

	// �e�N�X�`���Ƃ��Đ}�`�ɍ�������摜��ǂݍ��ށB
	auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample1.png").c_str());

	// �}�`�`��N���X�̃R���X�g���N�^���Ăяo���B
	auto geometryObj = std::make_shared<asd::GeometryObject2D>();

	// �}�`�`��N���X�����C���[�ɒǉ�����B
	asd::Engine::AddObject2D(geometryObj);

	// ���p�`��}�`�`��N���X�ɂĕ`�悷��B
	{
		auto polygon = std::make_shared<asd::PolygonShape>();

		// ���p�`���\�����钸�_��ǉ����Ă����B�i���`�ɂȂ�悤�ɂ���B�j
		for (int i = 0; i < 10; ++i)
		{
			asd::Vector2DF vec = asd::Vector2DF(1, 0);
			vec.SetDegree(i * 36);
			vec.SetLength((i % 2 == 0) ? 100 : 55);
			polygon->AddVertex(vec + asd::Vector2DF(500, 250));

		}

		// ���p�`��`�悷��}�`�Ƃ��Đݒ肵�A��������e�N�X�`�����ݒ�B
		geometryObj->SetShape(polygon);
		geometryObj->SetTexture(texture);
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