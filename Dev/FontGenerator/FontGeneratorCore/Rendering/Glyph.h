#pragma once
#include <vector>
#include <memory>
#include "Color.h"
#include "Setting.h"
#include "RasterizedGlyph.h"
#include <ft2build.h>
#include FT_GLYPH_H

namespace FontGenerator
{
	class RasterizedGlyph;

	class Glyph
	{
	private:
		FT_Library* m_library;
		FT_Face m_face;
		FT_OutlineGlyph m_glyph;
		Color m_color;
		BorderSetting::Ptr m_border;
		wchar_t m_charactor;

		/**
			@brief	�ێ�����freetype�̃O���t�𒼐ڎw�肵�ď���������B
			@param	library	freetype�̃��C�u���� �I�u�W�F�N�g
					glyph	�O���t
		*/
		Glyph(FT_Library& library, FT_OutlineGlyph& glyph);

	public:
		typedef std::shared_ptr<Glyph> Ptr;

		Glyph(FT_Library& library, FT_Face& face, wchar_t ch);
		~Glyph();

		wchar_t GetCharactor() const;

		/**
			@brief	���̃O���t�̕`�敝���擾����B
		*/
		int GetAdvance() const;

		/**
			@brief	���̃O���t��`�悷��ۂ̐F��ݒ肷��B
		*/
		void SetColor(Color color);

		/**
			@brief	�w�肵���o�b�t�@�ɂ��̃O���t��`�悷��B
			@param	buffer	�`���ƂȂ�o�b�t�@
					width	�o�b�t�@�̕�
					height	�o�b�t�@�̍���
					x		�`�挴�_�� x���W
					y		�x�[�X���C���� y���W
		*/
		void Draw(int32_t* buffer, int width, int height, int x, int y);

		BorderSetting::Ptr GetBorderSetting() const;
		void SetBorderSetting(BorderSetting::Ptr value);

		RasterizedGlyph::Ptr Rasterize();
	};
}