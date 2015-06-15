
#include <Base.h>

/**
@brief	�������\������B
*/
void TextObject2D_Simple()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("TextObject2D_Simple").c_str(), 640, 480, asd::EngineOption());

	{
		// �t�H���g�𐶐�����
		auto font = asd::Engine::GetGraphics()->CreateFont(asd::ToAString("Data/Font/edge.aff").c_str());

		//TextObject2D�𐶐�����
		auto obj = std::make_shared<asd::TextObject2D>();

		//�`��Ɏg���t�H���g��ݒ肷��
		obj->SetFont(font);

		//�`��ʒu���w�肷��
		obj->SetPosition(asd::Vector2DF(100, 100));

		//�`�悷�镶����̎w��
		obj->SetText(asd::ToAString("������T���v��1").c_str());

		//���C���[�֒ǉ�����
		asd::Engine::AddObject2D(obj);
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