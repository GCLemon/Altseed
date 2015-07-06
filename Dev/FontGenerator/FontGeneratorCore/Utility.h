#pragma once
#include <array>
#include <vector>
#include <png.h>
#include <cstdint>
#include <iostream>

#pragma warning(disable:4996)

namespace FontGenerator
{
	template<typename T>
	std::vector<char> GetBytesOf(T& data)
	{
		std::vector<char> result;
		char* buf = reinterpret_cast<char*>(&data);
		int size = sizeof(T);
		for (int i = 0; i < size; ++i)
		{
			result.push_back(buf[i]);
		}
		return result;
	}

	static void AddRange(std::vector<char>& dst, std::vector<char>& src)
	{
		dst.insert(dst.end(), src.begin(), src.end());
	}

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

}