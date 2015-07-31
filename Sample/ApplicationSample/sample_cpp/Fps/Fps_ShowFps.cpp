#include <Altseed.h>

// ���݂�FPS����ʂɕ\������T���v���B

void Fps_ShowFps()
{
	// Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Fps_ShowFps").c_str(), 640, 480, asd::EngineOption());

	// ���I�t�H���g�𐶐�����B
	auto font = asd::Engine::GetGraphics()->CreateDynamicFont(
		asd::ToAString("").c_str(),
		32,
		asd::Color(255, 255, 255, 255),
		1,
		asd::Color(255, 255, 255, 255));

	// FPS��\�����邽�߂̃I�u�W�F�N�g�𐶐�����B
	auto obj = std::make_shared<asd::TextObject2D>();
	obj->SetFont(font);

	// �I�u�W�F�N�g���G���W���ɒǉ�����B
	asd::Engine::AddObject2D(obj);

	while (asd::Engine::DoEvents())
	{
		asd::Engine::Update();

		// ���݂�FPS���擾����B
		float fps = asd::Engine::GetCurrentFPS();
		
		// �\�����镶����𐶐�����B
		char str[16];
		sprintf_s(str, 16, "%2.1ffps", fps);

		// ��������I�u�W�F�N�g�ɐݒ肷��B
		obj->SetText(asd::ToAString(str).c_str());
	}

	// Altseed�̏I������������B
	asd::Engine::Terminate();
}