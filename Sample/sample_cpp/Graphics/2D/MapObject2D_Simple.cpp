
#include <Base.h>

/**
@brief	�}�b�v��\������B
*/
void MapObject2D_Simple()
{
	// ace������������
	asd::Engine::Initialize(asd::ToAString("MapObject2D_Simple").c_str(), 640, 480, asd::EngineOption());

	{
		//�}�b�v�I�u�W�F�N�g�𐶐�����B
		auto mapObject = std::make_shared<asd::MapObject2D>();

		auto texture = asd::Engine::GetGraphics()->CreateTexture2D(asd::ToAString("Data/Texture/Sample2.png").c_str());

		//�}�b�v�I�u�W�F�N�g��50*50=2500�̃`�b�v��o�^����B
		for (int i = 0; i < 50; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				//�`�b�v�𐶐�����B
				auto chip = std::make_shared<asd::Chip2D>();

				//�`�b�v�Ƀe�N�X�`����ݒ肷��B
				chip->SetTexture(texture);

				//�`�b�v�̕`�����w�肷��B
				chip->SetPosition(asd::Vector2DF(i * 40 - 1000, j * 40 - 1000));

				//�}�b�v�I�u�W�F�N�g�Ƀ`�b�v��ǉ�����B
				mapObject->AddChip(chip);
			}
		}

		//���C���[�Ƀ}�b�v�I�u�W�F�N�g��ǉ�����B
		asd::Engine::AddObject2D(mapObject);
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