#pragma once
#include <vector>
#include <memory>
#include "Color.h"
#include <freetype/ft2build.h>
#include FT_GLYPH_H

namespace FontGenerator
{
	struct Span
	{
		Span() {}
		Span(int _x, int _y, int _width, int _coverage)
			: x(_x), y(_y), width(_width), coverage(_coverage)
		{
		}

		int x, y, width, coverage;
	};

	typedef std::vector<Span> Spans;

	class Glyph
	{
	private:
		FT_Library* m_library;
		FT_OutlineGlyph m_glyph;
		Color m_color;

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

		/**
			@brief	���̃O���t�̕`�敝���擾����B
		*/
		int GetAdvance() const;

		/**
			@brief	���̃O���t��`�悷��ۂ̐F��ݒ肷��B
		*/
		void SetColor(Color color);

		/**
			@brief	���̃O���t��֊s���p�ɏ��������O���t��V�����������ĕԂ��B
		*/
		Glyph::Ptr Border(float width, Color color);

		/**
			@brief	���̃O���t�𑾎��ɂ����O���t��V�����������ĕԂ��B
		*/
		Glyph::Ptr Enbolden(float weight);

		/**
			@brief	�w�肵���o�b�t�@�ɂ��̃O���t��`�悷��B
			@param	buffer	�`���ƂȂ�o�b�t�@
					width	�o�b�t�@�̕�
					height	�o�b�t�@�̍���
					x		�`�挴�_�� x���W
					y		�x�[�X���C���� y���W
		*/
		void Draw(int32_t* buffer, int width, int height, int x, int y);
	};
}