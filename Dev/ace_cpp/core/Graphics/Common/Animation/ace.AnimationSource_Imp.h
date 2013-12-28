
#pragma once

#include "../../../ace.Core.Base_Imp.h"
#include "ace.AnimationSource.h"

namespace ace
{
	class AnimationSource_Imp
		: public AnimationSource
		, public ReferenceObject
	{
	private:
		std::set<KeyframeAnimation*>	m_animations;

	public:
		AnimationSource_Imp();
		virtual ~AnimationSource_Imp();
		void AddAnimation(KeyframeAnimation* keyframeAnimation) override;
		void RemoveAnimation(KeyframeAnimation* keyframeAnimation) override;

		std::set<KeyframeAnimation*>& GetAnimations() { return m_animations; }

		// IReference���p�������f�o�C�X�I�u�W�F�N�g������`
#if !SWIG
	public:
		virtual int GetRef() { return ReferenceObject::GetRef(); }
		virtual int AddRef() { return ReferenceObject::AddRef(); }
		virtual int Release() { return ReferenceObject::Release(); }
#endif
	};
}

