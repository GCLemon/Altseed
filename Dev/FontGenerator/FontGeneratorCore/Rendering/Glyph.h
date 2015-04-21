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
	class Font;

	class Glyph
	{
	private:
		Font& font;
		FT_OutlineGlyph m_glyph;
		wchar_t m_charactor;

	public:
		typedef std::shared_ptr<Glyph> Ptr;

		Glyph(Font& font, wchar_t charctor, FT_OutlineGlyph glyph);
		~Glyph();

		wchar_t GetCharactor() const;

		/**
			@brief	���̃O���t�̕`�敝���擾����B
		*/
		int GetAdvance() const;

		/**
			@brief	�w�肵���o�b�t�@�ɂ��̃O���t��`�悷��B
			@param	buffer	�`���ƂȂ�o�b�t�@
					width	�o�b�t�@�̕�
					height	�o�b�t�@�̍���
					x		�`�挴�_�� x���W
					y		�x�[�X���C���� y���W
		*/
		void Draw(int32_t* buffer, int width, int height, int x, int y);

		std::shared_ptr<RasterizedGlyph> Rasterize();

		std::shared_ptr<RasterizedGlyph> RasterizeWithOutline(int32_t outline);
	};
}