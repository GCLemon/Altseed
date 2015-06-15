
#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void TextObject2D_Rotate()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("TextObject2D_Rotate").c_str(), 640, 480, asd::EngineOption());

	{
		auto edgeFont = asd::Engine::GetGraphics()->CreateFont(asd::ToAString("Data/Font/edge.aff").c_str());
		auto edgeObj = std::make_shared<asd::TextObject2D>();
		edgeObj->SetFont(edgeFont);
		edgeObj->SetPosition(asd::Vector2DF(100, 300));

		//30�x��]�����ĕ`�悷��
		edgeObj->SetAngle(30);
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