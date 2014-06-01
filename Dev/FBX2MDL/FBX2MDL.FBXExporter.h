
#include "FBX2MDL.Base.h"

namespace FBX2MDL
{

	class FBXExporter
	{
	private:
		std::shared_ptr<ace::BinaryWriter> m_writer;

		void WriteHeader();
		void WriteAnimationSource(AnimationSource& source);
		void WriteAnimationSources(std::vector<AnimationSource>& animationSources);

	public:
		FBXExporter();
		virtual ~FBXExporter();

		/**
			@brief	�V�[�����o�C�i���Ƃ��ďo�͂���E
			@param	scene	�V�[��
			@return	�o�C�i��
			@note
			���̊֐���scene�ɂ͔j��I�ύX��������B
		*/
		std::shared_ptr<ace::BinaryWriter> Export(std::shared_ptr<Scene> scene);
	};
}