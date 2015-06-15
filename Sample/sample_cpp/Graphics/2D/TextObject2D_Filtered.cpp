
#include <Base.h>

/**
@brief	��������M�U�M�U��h���ŉ�]�����ĕ\������B
*/
void TextObject2D_Filtered()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("TextObject2D_Filtered").c_str(), 640, 480, asd::EngineOption());

	{
		auto edgeFont = asd::Engine::GetGraphics()->CreateFont(asd::ToAString("Data/Font/edge.aff").c_str());
		auto edgeObj = std::make_shared<asd::TextObject2D>();
		edgeObj->SetFont(edgeFont);
		edgeObj->SetPosition(asd::Vector2DF(100, 100));

		// 30�x��]�����ĕ`�悷��B
		edgeObj->SetAngle(30);

		// �`��̃t�B���^����`��Ԃɂ��邱�Ƃɂ���āA�`�掞�ɋ��E���M�U�M�U�ɂȂ�Ȃ��悤�ɂ���B
		edgeObj->SetTextureFilterType(asd::TextureFilterType::Linear);

		edgeObj->SetText(asd::ToAString("������T���v��3").c_str());
		asd::Engine::AddObject2D(edgeObj);
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