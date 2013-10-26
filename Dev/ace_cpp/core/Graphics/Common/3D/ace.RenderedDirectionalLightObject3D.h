
#pragma once

#include "ace.RenderedObject3D.h"

namespace ace
{
	/**
		@brief	���������璍�������I�u�W�F�N�g�̃N���X
		@note
		���[�J�����W��(0,0,1)�̕����Ɍ����Ǝ˂���B
	*/
	class RenderedDirectionalLightObject3D
		: public RenderedObject3D
	{
	private:
		struct
		{
			Color		color;
		} m_values;

		struct
		{
			Color		color;

		} m_values_FR;

	public:
		RenderedDirectionalLightObject3D(Graphics* graphics);
		virtual ~RenderedDirectionalLightObject3D();

		void Flip() override;
		void Rendering(RenderingProperty& prop) override;

		Color GetColor_FR();
		void SetColor(Color color);

		Vector3DF GetDirection_FR();

		eRenderedObject3DType GetObjectType() const override { return RENDERED_OBJECT3D_TYPE_DIRECTIONALLIGHT; }
	};
}