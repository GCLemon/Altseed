﻿
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
#include "ace.RenderState_Imp_GL.h"

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace ace {
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
RenderState_Imp_GL::RenderState_Imp_GL(Graphics_Imp_GL* graphics)
	: m_graphics(graphics)
{
#ifdef	__USE_SAMPLERS
	glGenSamplers(4, m_samplers);
#endif
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
RenderState_Imp_GL::~RenderState_Imp_GL()
{
#ifdef	__USE_SAMPLERS
	glDeleteSamplers(4, m_samplers);
#endif
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void RenderState_Imp_GL::Update(bool forced)
{
	if (m_active.DepthTest != m_next.DepthTest || forced)
	{
		if (m_next.DepthTest)
		{
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}
	}

	if (m_active.DepthWrite != m_next.DepthWrite || forced)
	{
		glDepthMask(m_next.DepthWrite);
	}

	if (m_active.CullingType != m_next.CullingType || forced)
	{
		if (m_next.CullingType == CULLING_FRONT)
		{
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
		}
		else if (m_next.CullingType == CULLING_BACK)
		{
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
		}
		else if (m_next.CullingType == CULLING_DOUBLE)
		{
			glDisable(GL_CULL_FACE);
			glCullFace(GL_FRONT_AND_BACK);
		}
	}

	if (m_active.AlphaBlend != m_next.AlphaBlend || forced)
	{
		if (m_next.AlphaBlend == ALPHA_BLEND_OPACITY)
		{
			glDisable(GL_BLEND);
		}
		else
		{
			glEnable(GL_BLEND);

			if (m_next.AlphaBlend == ALPHA_BLEND_SUB)
			{
				//glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
				//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
				glBlendEquationSeparate(GL_FUNC_REVERSE_SUBTRACT, GL_FUNC_ADD);
				glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE, GL_ONE, GL_ONE);
			}
			else
			{
				//glBlendEquation(GL_FUNC_ADD);
				glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
				if (m_next.AlphaBlend == ALPHA_BLEND_BLEND)
				{
					glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
				}
				else if (m_next.AlphaBlend == ALPHA_BLEND_ADD)
				{
					glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE, GL_ONE, GL_ONE);
				}
				else if (m_next.AlphaBlend == ALPHA_BLEND_MUL)
				{
					glBlendFuncSeparate(GL_ZERO, GL_SRC_COLOR, GL_ONE, GL_ONE);
				}
			}
		}
	}

	static const GLint glfilter [] = { GL_NEAREST, GL_LINEAR };
	static const GLint glwrap [] = { GL_REPEAT, GL_CLAMP_TO_EDGE };

#ifdef	__USE_SAMPLERS
	for (int32_t i = 0; i < 4; i++)
	{
		if (m_active.TextureFilterTypes[i] != m_next.TextureFilterTypes[i] || forced)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			int32_t filter_ = (int32_t) m_next.TextureFilterTypes[i];

			glSamplerParameteri(m_samplers[i], GL_TEXTURE_MAG_FILTER, glfilter[filter_]);
			glSamplerParameteri(m_samplers[i], GL_TEXTURE_MIN_FILTER, glfilter[filter_]);
			//glSamplerParameteri( m_samplers[i],  GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			//glSamplerParameteri( m_samplers[i],  GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

			glBindSampler(i, m_samplers[i]);
		}

		if (m_active.TextureWrapTypes[i] != m_next.TextureWrapTypes[i] || forced)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			int32_t wrap_ = (int32_t) m_next.TextureWrapTypes[i];
			glSamplerParameteri(m_samplers[i], GL_TEXTURE_WRAP_S, glwrap[wrap_]);
			glSamplerParameteri(m_samplers[i], GL_TEXTURE_WRAP_T, glwrap[wrap_]);

			glBindSampler(i, m_samplers[i]);
		}
	}
#else
	for (int32_t i = 0; i < 4; i++)
	{
		if (m_active.TextureFilterTypes[i] != m_next.TextureFilterTypes[i] || forced)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			int32_t filter_ = (int32_t) m_next.TextureFilterTypes[i];

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glfilter[filter_]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glfilter[filter_]);
		}

		if (m_active.TextureWrapTypes[i] != m_next.TextureWrapTypes[i] || forced)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			int32_t wrap_ = (int32_t) m_next.TextureWrapTypes[i];
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, glwrap[wrap_]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, glwrap[wrap_]);
		}
	}
#endif

	glActiveTexture(GL_TEXTURE0);

	m_active = m_next;
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}