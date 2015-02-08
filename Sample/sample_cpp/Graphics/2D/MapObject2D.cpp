
#include <Base.h>

/**
@brief	�G�t�F�N�g��\������B
*/
void MapObject2D()
{
	// ace������������
	ace::Engine::Initialize(ace::ToAString("MapObject2D").c_str(), 640, 480, ace::EngineOption());

	// �V�[���𐶐�����
	auto scene = std::make_shared<ace::Scene>();

	// ���C���[�𐶐�����
	auto layer = std::make_shared<ace::Layer2D>();

	// �V�[���Ƀ��C���[��ǉ�����
	scene->AddLayer(layer);

	// �V�[����؂�ւ���
	ace::Engine::ChangeScene(scene);

	auto camera = std::make_shared<ace::CameraObject2D>();

	camera->SetSrc(ace::RectI(0, 0, 640, 480));
	camera->SetDst(ace::RectI(0, 0, 640, 480));

	{
		auto mapObject = std::make_shared<ace::MapObject2D>();

		auto texture = ace::Engine::GetGraphics()->CreateTexture2D(ace::ToAString("Data/Texture/Sample2.png").c_str());

		for (int i = 0; i < 50; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				auto chip = ace::Engine::GetGraphics()->CreateChip2D();
				chip->SetTexture(texture);
				chip->SetSrc(ace::RectF(i * 40 - 1000, j * 40 - 1000, 40, 40));
				mapObject->AddChip(chip);
			}
		}

		layer->AddObject(mapObject);
		layer->AddObject(camera);
	}
	// ace���i�s�\���`�F�b�N����B
	while (ace::Engine::DoEvents())
	{
		auto pos = camera->GetSrc();
		pos.X += 1;
		pos.Y += 1;
		camera->SetSrc(pos);
		// ace���X�V����B
		ace::Engine::Update();
	}

	// ace���I������B
	ace::Engine::Terminate();
}