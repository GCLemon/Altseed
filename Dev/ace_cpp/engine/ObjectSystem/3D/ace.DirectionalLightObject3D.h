
#pragma once

#include "ace.Object3D.h"

namespace ace
{
	class DirectionalLightObject3D
		: public Object3D
	{
	private:
		std::shared_ptr<CoreDirectionalLightObject3D> m_coreObject;

	protected:
		/**
		@brief	�I�[�o�[���C�h���āA���̃I�u�W�F�N�g�̏������������L�q�ł���B
		*/
		virtual void OnStart() {};

		/**
		@brief	�I�[�o�[���C�h���āA���t���[�����s�����X�V�������L�q�ł���B
		*/
		virtual void OnUpdate() {};

		/**
		@brief	�I�[�o�[���C�h���āA�ǉ��̕`�揈�����L�q�ł���B
		*/
		virtual void OnDrawAdditionally() {};

	public:
		DirectionalLightObject3D();
		virtual ~DirectionalLightObject3D();

		Color GetColor();
		void SetColor(const Color& color);
	};
}