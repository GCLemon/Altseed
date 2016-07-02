#include <Altseed.h>

void Log_Table()
{
	//Altseed������������B
	asd::Engine::Initialize(asd::ToAString("Log_OutputLevel").c_str(), 640, 480, asd::EngineOption());

	// Engine�̕W���̃��K�[���g���iLog.html�ɏo�͂����j
	auto log = asd::Engine::GetLogger();

	// �w�b�_�[��������o�͂���
	log->WriteHeading("�T���v���o��");

	// �\�g�݂ł̏o�͂��J�n����
	log->BeginTable();

	// �\�̃Z���ɕ�������o�͂���
	log->Write("�Z���P");

	// ���̗�ɐi��
	log->ChangeColumn();

	// �\�̃Z���ɕ�������o�͂���
	log->Write("�Z���Q(ChangeColmun)");

	// ���̍s�ɐi�ށB�O�̍s�ɂ͂����߂�Ȃ�
	log->ChangeRow();

	// �\�̃Z���ɕ�������o�͂���
	log->Write("�Z���R(ChangeRow)");

	// �\�g�݂ł̏o�͂��I������
	log->EndTable();

	// SetOutputLevel���\�b�h�Ŏw�肵�����̂��Ⴂ���x���Ɏw�肵���o�͂́A���s����Ȃ�
	// ���x�������������珇�ɁAInformation, Warning, Critical, Error
	log->SetOutputLevel(asd::LogLevel::Critical);

	// Warning���x���ŕ\�g�݂ŏo�͂���BCritical���Ⴂ���x���Ȃ̂ŏo�͂���Ȃ�
	log->BeginTable(asd::LogLevel::Warning);
	log->Write("�o�͂���Ȃ��e�[�u��", asd::LogLevel::Warning);
	log->EndTable(asd::LogLevel::Warning);


	// ���b�Z�[�W�p�̕������p�ӂ���BTextObject2D_DynamicFont�̃T���v���Q��
	auto font = asd::Engine::GetGraphics()->CreateDynamicFont(asd::ToAString("").c_str(), 35, asd::Color(255, 0, 0, 255), 1, asd::Color(255, 255, 255, 255));
	auto obj = std::make_shared<asd::TextObject2D>();
	obj->SetFont(font);
	obj->SetPosition(asd::Vector2DF(0, 0));
	obj->SetText(asd::ToAString("Log.html�Ƀ��O���o�͂��܂����B\n�E�B���h�E�����O�Ɋm�F���Ă��������B").c_str());
	asd::Engine::AddObject2D(obj);

	// Altseed�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (asd::Engine::DoEvents())
	{
		// Altseed���X�V����B
		asd::Engine::Update();
	}

	// Altseed���I������B
	asd::Engine::Terminate();
}