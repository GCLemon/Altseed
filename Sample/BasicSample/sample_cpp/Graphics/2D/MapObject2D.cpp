
#include <ace.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void MapObject2D()
{
	// AC-Engine������������B
	ace::Engine::Initialize(ace::ToAString("MapObject2D").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<ace::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<ace::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	ace::Engine::ChangeScene(scene);

	//�J������ݒ肷��B
	auto camera = std::make_shared<ace::CameraObject2D>();

	camera->SetSrc(ace::RectI(0, 0, 640, 480));
	camera->SetDst(ace::RectI(0, 0, 640, 480));

	{
		//�}�b�v�I�u�W�F�N�g�𐶐�����B
		auto mapObject = std::make_shared<ace::MapObject2D>();

		auto texture = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample2.png").c_str());

		//�}�b�v�I�u�W�F�N�g��50*50=2500�̃`�b�v��o�^����B
		for (int i = 0; i < 50; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				//�`�b�v�𐶐�����B
				auto chip = std::make_shared<ace::Chip2D>();

				//�`�b�v�Ƀe�N�X�`����ݒ肷��B
				chip->SetTexture(texture);

				//�`�b�v�̕`�����w�肷��B
				chip->SetPosition(ace::Vector2DF(i * 40 - 1000, j * 40 - 1000));

				//�}�b�v�I�u�W�F�N�g�Ƀ`�b�v��ǉ�����B
				mapObject->AddChip(chip);
			}
		}

		//���C���[�Ƀ}�b�v�I�u�W�F�N�g��ǉ�����B
		layer->AddObject(mapObject);

		//���C���[�ɃJ�����I�u�W�F�N�g��ǉ�����B
		layer->AddObject(camera);
	}

	// AC-Engine�̃E�C���h�E�������Ă��Ȃ����m�F����B
	while (ace::Engine::DoEvents())
	{
		//�J�������ړ�������
		auto pos = camera->GetSrc();
		pos.X += 1;
		pos.Y += 1;
		pos.X %= 1000;
		pos.Y %= 1000;
		camera->SetSrc(pos);

		// AC-Engine���X�V����B
		ace::Engine::Update();
	}

	// AC-Engine�̏I������������B
	ace::Engine::Terminate();
}