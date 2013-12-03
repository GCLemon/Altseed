
#pragma once

#include "ace.Object3D.h"

namespace ace
{
	class CameraObject3D
		: public Object3D
	{
	private:
		std::shared_ptr<CoreCameraObject3D> m_coreObject;

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
		CameraObject3D();
		virtual ~CameraObject3D();

		Vector2DI GetWindowSize() const;
		void SetWindowSize(const Vector2DI& size);

		Vector3DF GetFocus();
		void SetFocus(const Vector3DF& focus);

		float GetFieldOfView();
		void SetFieldOfView(float fov);

		float GetZFar();
		void SetZFar(float zfar);

		float GetZNear();
		void SetZNear(float znear);
	};
}