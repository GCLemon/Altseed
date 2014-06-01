
#include "FBX2MDL.FBXExporter.h"

namespace FBX2MDL
{
	void FBXExporter::WriteHeader()
	{
		m_writer->Push((uint8_t)'M');
		m_writer->Push((uint8_t)'D');
		m_writer->Push((uint8_t)'L');
		m_writer->Push((uint8_t) 0);

		m_writer->Push(1);
	}

	void FBXExporter::WriteAnimationSource(AnimationSource& source)
	{
		m_writer->Push(source.Name);
		m_writer->Push((int32_t) source.keyFrameAnimations.size());

		for (auto& anim : source.keyFrameAnimations)
		{
			m_writer->Push(anim.TargetName);
			m_writer->Push((int32_t)anim.KeyFrames.size());

			for (auto& keyframe : anim.KeyFrames)
			{
				m_writer->Push(keyframe.KeyValue);
				m_writer->Push(keyframe.LeftPosition);
				m_writer->Push(keyframe.RightPosition);
				m_writer->Push(keyframe.Interpolation);
			}
		}
	}

	void FBXExporter::WriteAnimationSources(std::vector<AnimationSource>& animationSources)
	{
		m_writer->Push((int32_t) animationSources.size());
		for (auto& animationSource : animationSources)
		{
			WriteAnimationSource(animationSource);
		}
	}

	FBXExporter::FBXExporter()
	{
	}

	FBXExporter::~FBXExporter()
	{
	}


	std::shared_ptr<ace::BinaryWriter> FBXExporter::Export(std::shared_ptr<Scene> scene)
	{
		auto writer = std::make_shared<ace::BinaryWriter>();
		m_writer = writer;

		WriteHeader();

		// �{�[���\������

		// ���b�V���ҏW

		// ���b�V�����o��

		// �{�[�����o��

		// �A�j���[�V�����o��
		std::remove_if(
			scene->AnimationSources.begin(), 
			scene->AnimationSources.end(),
			[](const AnimationSource& source) {
			return source.keyFrameAnimations.size() == 0;
		});

		// �A�j���[�V�����\�[�X�o��
		WriteAnimationSources(scene->AnimationSources);

		// �A�j���[�V�����N���b�v�o��
		{
			m_writer->Push((int32_t) scene->AnimationSources.size());
			for (auto i = 0; i < scene->AnimationSources.size(); i++)
			{
				m_writer->Push(scene->AnimationSources[i].Name);
				m_writer->Push(i);
			}
		}
		m_writer.reset();
		return writer;
	}
}