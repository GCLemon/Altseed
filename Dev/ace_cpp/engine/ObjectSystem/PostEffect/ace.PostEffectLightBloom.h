#pragma once

#include<memory>
#include <vector>
#include"ace.PostEffect.h"


namespace ace
{

	/**
		@brief	�P�x�̍�����f�݂̂��ڂ����ĉ��Z����|�X�g�G�t�F�N�g
	*/
	class PostEffectLightBloom : public PostEffect
	{
	private:

		std::shared_ptr<ace::Shader2D>		m_shaderX, m_shaderY;
		std::shared_ptr<ace::Material2D>	m_material2dX, m_material2dY;
		ace::Graphics *m_graphics;

		std::shared_ptr<RenderTexture2D>	m_tempTexture;

		PostEffectLightBloom() = default;

		float intensity = 5.0f;

	public:
		PostEffectLightBloom(Graphics *g);

		virtual ~PostEffectLightBloom() = default;

		/**
		@brief �ڂ����̋�����ݒ肷��B�����l��0.5
		@detail �����I�ɂ̓K�E�X�֐��̕��U�ɂ�����l�̕������B1.0f����5.0f�����肪�K��
		*/
		void SetIntensity(float const value){ if (value <= 0.0f){ return; }intensity = value; }


		virtual void OnDraw(std::shared_ptr<RenderTexture2D> dst, std::shared_ptr<RenderTexture2D> src) override;
	};

}