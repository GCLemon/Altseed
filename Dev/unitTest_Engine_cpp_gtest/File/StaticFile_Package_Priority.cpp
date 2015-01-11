#include <ace.h>
#include <gtest/gtest.h>
#include <memory>
#include "../EngineTest.h"

using namespace std;
using namespace ace;

class File_StaticFile_Package_Priority : public EngineTest
{
public:
	File_StaticFile_Package_Priority(bool isOpenGLMode)
		: EngineTest(ace::ToAString("StaticFile_Package_Priority"), isOpenGLMode, 1)
	{

	}

protected:

	void OnStart()
	{
		{
			//���ʂɓǂݍ��񂾃o�C�i��
			BinaryReader reader1;
			auto data1 = GetBinaryData(ace::ToAString("Data/Texture/Cloud1.png"));
			reader1.ReadIn(data1.begin(), data1.end());

			//�t�@�C���@�\�œǂݍ��񂾃o�C�i��
			ace::Engine::GetFile()->AddRootDirectories(ace::ToAString("Data/Texture2.pack").c_str());
			ace::Engine::GetFile()->AddRootDirectories(ace::ToAString("Data/Texture.pack").c_str());
			auto staticFile = ace::Engine::GetFile()->CreateStaticFile(ace::ToAString("Cloud1.png").c_str());
			auto staticFileData = staticFile->ReadAllBytes();

			int cnt = 0;
			while (!reader1.IsEmpty())
			{
				int8_t byteFromRaw = reader1.Get<int8_t>();

				int8_t byteFromFile = staticFileData[cnt++];

				ASSERT_EQ(byteFromRaw, byteFromFile);
			}
			ASSERT_EQ(cnt, staticFileData.size());

			ace::Engine::GetFile()->ClearRootDirectories();
		}
		{
			//���ʂɓǂݍ��񂾃o�C�i��
			BinaryReader reader2;
			auto data2 = GetBinaryData(ace::ToAString("Sample1.png"));
			reader2.ReadIn(data2.begin(), data2.end());

			//�t�@�C���@�\�œǂݍ��񂾃o�C�i��
			ace::Engine::GetFile()->AddRootDirectories(ace::ToAString("Data/Texture.pack").c_str());
			ace::Engine::GetFile()->AddRootDirectories(ace::ToAString("Data/Texture2.pack").c_str());
			auto staticFile = ace::Engine::GetFile()->CreateStaticFile(ace::ToAString("Cloud1.png").c_str());
			auto staticFileData = staticFile->ReadAllBytes();

			int cnt = 0;
			while (!reader2.IsEmpty())
			{
				int8_t byteFromRaw = reader2.Get<int8_t>();

				int8_t byteFromFile = staticFileData[cnt++];

				ASSERT_EQ(byteFromRaw, byteFromFile);
			}
			//ASSERT_EQ(cnt, staticFileData.size());
		}
	}
};

ENGINE_TEST(File, StaticFile_Package_Priority)