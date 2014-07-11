
#include <fstream>
#include "Generator.h"
#include <Graphics/Font/ace.AffHeader.h>
#include <Graphics/Font/ace.AffIndexTable.h>
#include <Graphics/Font/ace.GlyphData.h>
#include <Utility/ace.BinaryWriter.h>
#include <Utility/ace.BinaryReader.h>
#include <ft2build.h>
#include FT_FREETYPE_H

using namespace std;
using namespace ace;

namespace FontGenerator
{
	Generator::Generator()
		: m_sheetName(ToAString(L"font"))
		, m_sheetSize(DEFAULT_SIZE)
	{
		m_setting = SettingForRendering();
		m_setting.SetBold(nullptr);
		m_setting.SetBorder(nullptr);
		m_setting.SetFontSize(16);
		m_setting.SetFontColor(Color(0, 0, 0, 255));
	}

	void Generator::GenerateFontFile(
		astring fontPath,
		astring textPath)
	{
		auto result = RenderPng(fontPath, textPath);

		BinaryWriter writer;
		PushAff(writer, result);

		ofstream file(m_sheetName + L".aff", ios::out | ios::binary);
		writer.WriteOut(file);
	}

	ResultOfGeneratingPng Generator::RenderPng(astring fontPath, astring textPath)
	{
		auto charactors = GetCharactors(ToAString(textPath.c_str()));

		auto& color = m_setting.GetFontColor();
		printf("%d,%d,%d,%d", color.r, color.g, color.b, color.a);

		PngGenerator png;
		png.SetSetting(m_setting);
		png.SetSheetName(m_sheetName);
		png.SetSheetSize(m_sheetSize);

		auto result = png.Generate_(ToAString(fontPath.c_str()), charactors);
		return result;
	}

	void Generator::PushAff(BinaryWriter& writer, ResultOfGeneratingPng& result)
	{
		AffHeader header(m_sheetName);
		header.SetFontSize(m_setting.GetFontSize());
		header.SetFontCount(result.fonts.size());
		header.SetSheetCount(result.sheetCount);

		AffIndexTable indexTable;
		for (int i = 0; i < result.fonts.size(); ++i)
		{
			indexTable.AppendFontIndex(result.fonts[i].GetCharactor(), (int16_t)i);
		}

		header.Push(writer);
		indexTable.Push(writer);
		for (auto& f : result.fonts)
		{
			f.Push(writer);
		}
	}

	// UTF-16���Ώ�
	vector<achar> Generator::GetCharactors(astring textPath)
	{
		std::set<achar> charactors;

		// r���Ɠǂݍ��߂Ȃ�����������̂�rb�œǂݍ���
		FILE* file = nullptr;
		_wfopen_s(&file, textPath.c_str(), L"rb");

		// BOM����
		achar bom;
		fread(&bom, sizeof(achar), 1, file);
		if (bom != 65279)
		{
			charactors.insert(bom);
		}

		// �������
		while (!feof(file))
		{
			achar c;
			if (fread(&c, sizeof(achar), 1, file) == 1)
			{
				charactors.insert(c);
			}
		}

		fclose(file);

		// �݊����ێ�
		vector<achar> result;
		for (auto c : charactors)
		{
			result.push_back(c);
		}

		return result;
	}

	astring Generator::GetSheetName() const
	{
		return m_sheetName;
	}

	void Generator::SetSheetName(astring value)
	{
		m_sheetName = value;
	}

	SettingForRendering Generator::GetSetting() const
	{
		return m_setting;
	}

	void Generator::SetSetting(SettingForRendering value)
	{
		m_setting = value;
	}

	int Generator::GetSheetSize() const
	{
		return m_sheetSize;
	}

	void Generator::SetSheetSize(int value)
	{
		m_sheetSize = value;
	}

}