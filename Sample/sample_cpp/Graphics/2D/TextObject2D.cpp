
#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void TextObject2D()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("TextObject2D").c_str(), 640, 480, asd::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<asd::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<asd::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	asd::Engine::ChangeScene(scene);

	{
		// �t�H���g�𐶐�����
		auto smallFont = asd::Engine::GetGraphics()->CreateFont(asd::ToAString("Data/Font/small.aff").c_str());

		//TextObject2D�𐶐�����
		auto smallObj = std::make_shared<asd::TextObject2D>();

		//�`��Ɏg���t�H���g��ݒ肷��
		smallObj->SetFont(smallFont);

		//�`��ʒu���w�肷��
		smallObj->SetPosition(asd::Vector2DF(100, 100));

		//�`�悷�镶����̎w��
		smallObj->SetText(asd::ToAString("������T���v��1").c_str());

		//���C���[�֒ǉ�����
		layer->AddObject(smallObj);
	}

	{
		auto largeFont = asd::Engine::GetGraphics()->CreateFont(asd::ToAString("Data/Font/large.aff").c_str());
		auto largeObj = std::make_shared<asd::TextObject2D>();
		largeObj->SetFont(largeFont);
		largeObj->SetPosition(asd::Vector2DF(100, 200));
		largeObj->SetText(asd::ToAString("������T���v��2").c_str());
		layer->AddObject(largeObj);
	}

	{
		auto edgeFont = asd::Engine::GetGraphics()->CreateFont(asd::ToAString("Data/Font/edge.aff").c_str());
		auto edgeObj = std::make_shared<asd::TextObject2D>();
		edgeObj->SetFont(edgeFont);
		edgeObj->SetPosition(asd::Vector2DF(100, 300));

		//30�x��]�����ĕ`�悷��
		edgeObj->SetAngle(30);
		edgeObj->SetText(asd::ToAString("������T���v��3").c_str());
		layer->AddObject(edgeObj);
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