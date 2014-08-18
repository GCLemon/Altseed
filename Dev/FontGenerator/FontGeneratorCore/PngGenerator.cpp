
#include <iostream>
#include <sstream>
#include <fstream>
#include "PngGenerator.h"
#include "Rendering/ImageBuffer.h"
#include <png.h>

#if _DEBUG
#pragma comment(lib,"freetype253MT_D.lib")
#pragma comment(lib,"libpng16.Debug.lib")
#pragma comment(lib,"zlib.Debug.lib")
#pragma comment(lib,"ace_common.lib")
#else
#pragma comment(lib,"freetype253MT.lib")
#pragma comment(lib,"libpng16.Release.lib")
#pragma comment(lib,"zlib.Release.lib")
#pragma comment(lib,"ace_common.lib")
#endif

#pragma warning(disable:4996)

using namespace std;
using namespace ace;

namespace FontGenerator
{
	/**
	@brief	PNG�t�@�C����ۑ�����B
	@param	filepath	�ۑ���
	@param	width	����
	@param	height	�c��
	@param	data	���ԂȂ��~���l�߂�ꂽ��f�f�[�^(1��f4byte�Œ�)
	@param	rev		�㉺���]�ŕۑ�����B
	*/
	static void SavePNGImage(const wchar_t* filepath, int32_t width, int32_t height, void* data, bool rev)
	{
		png_bytep raw1D;
		png_bytepp raw2D;

		/* �\���̊m�� */
#if _WIN32
		FILE *fp = _wfopen(filepath, L"wb");
#else
		FILE *fp = fopen(ToUtf8String(filepath).c_str(), "wb");
#endif

		if (fp == nullptr) return;

		png_structp pp = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
		png_infop ip = png_create_info_struct(pp);

		/* �������ݏ��� */
		png_init_io(pp, fp);
		png_set_IHDR(pp, ip, width, height,
			8, /* 8bit�ȊO�ɂ���Ȃ�ς��� */
			PNG_COLOR_TYPE_RGBA, /* RGBA�ȊO�ɂ���Ȃ�ς��� */
			PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

		/* �s�N�Z���̈�m�� */
		raw1D = (png_bytep)malloc(height * png_get_rowbytes(pp, ip));
		raw2D = (png_bytepp)malloc(height * sizeof(png_bytep));
		for (int32_t i = 0; i < height; i++)
		{
			raw2D[i] = &raw1D[i*png_get_rowbytes(pp, ip)];
		}

		memcpy((void*)raw1D, data, width * height * 4);

		/* �㉺���] */
		if (rev)
		{
			for (int32_t i = 0; i < height / 2; i++)
			{
				png_bytep swp = raw2D[i];
				raw2D[i] = raw2D[height - i - 1];
				raw2D[height - i - 1] = swp;
			}
		}

		/* �������� */
		png_write_info(pp, ip);
		png_write_image(pp, raw2D);
		png_write_end(pp, ip);

		/* �J�� */
		png_destroy_write_struct(&pp, &ip);
		fclose(fp);
		free(raw1D);
		free(raw2D);
	}

	PngGenerator::PngGenerator()
		: m_sheetName(L"font.png")
		, m_fonts(vector<FontData>())
		, m_setting(SettingForRendering())
	{
	}

	ResultOfGeneratingPng PngGenerator::Generate(astring fontPath, vector<achar>& charactors)
	{
		Font font(fontPath);
		font.SetFontSize(m_setting.GetFontSize());

		ImageBuffer buffer(font, m_sheetSize);
		vector<GlyphData> fontData;

		for (auto& glyph : font.GetGlyphs(charactors))
		{
			auto result = buffer.Draw(glyph, m_setting.GetFontColor(), m_setting.GetBorder());
			fontData.push_back(result);
		}

		auto buffers = buffer.GetBuffers();

		for (size_t i = 0; i < buffers.size(); i++)
		{
			std::ostringstream os;
			os << "_" << i << ".png";
			auto pngPath = GetSheetName() + ToAString(os.str().c_str());
			SavePNGImage(pngPath.c_str(), m_sheetSize, m_sheetSize, buffers[i]->data(), false);
		}

		ResultOfGeneratingPng result;
		result.sheetCount = buffers.size();
		result.fonts = fontData;
		return result;
	}

#pragma region GetSet
	astring PngGenerator::GetSheetName() const
	{
		return m_sheetName;
	}

	void PngGenerator::SetSheetName(astring value)
	{
		m_sheetName = value;
	}

	int PngGenerator::GetSheetSize() const
	{
		return m_sheetSize;
	}

	void PngGenerator::SetSheetSize(int value)
	{
		m_sheetSize = value;
	}

	SettingForRendering PngGenerator::GetSetting() const
	{
		return m_setting;
	}

	void PngGenerator::SetSetting(SettingForRendering value)
	{
		m_setting = value;
	}

#pragma endregion
}