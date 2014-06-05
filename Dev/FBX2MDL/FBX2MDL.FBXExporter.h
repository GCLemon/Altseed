
#include "FBX2MDL.Base.h"

namespace FBX2MDL
{

	class FBXExporter
	{
	private:
		struct Bone
		{
			ace::astring	Name;
			int32_t			ParentIndex;

		};

		
		std::shared_ptr<ace::BinaryWriter> m_writer;

		void WriteHeader();
		void WriteAnimationSource(AnimationSource& source);
		void WriteAnimationSources(std::vector<AnimationSource>& animationSources);

		void WriteMaterial(const Material& material);
		void WriteMaterials(const std::vector<Material>& materials);

		void WriteMesh(const std::shared_ptr<Mesh>& mesh);

		static std::vector<std::shared_ptr<Mesh>> GetMeshes(const std::shared_ptr<Node>& node);

		std::vector<std::function<void()>> GetWritingDeformerFuncs(const std::shared_ptr<Node>& node, int32_t parentIndex, int32_t& currentIndex);

		std::map<ace::astring, int32_t> GetDeformerNameToIndexes(const std::shared_ptr<Node>& node, int32_t& currentIndex);

	public:
		FBXExporter();
		virtual ~FBXExporter();

		/**
			@brief	�V�[�����o�C�i���Ƃ��ďo�͂���B
			@param	scene	�V�[��
			@return	�o�C�i��
			@note
			���̊֐���scene�ɂ͔j��I�ύX��������B
		*/
		std::shared_ptr<ace::BinaryWriter> Export(std::shared_ptr<Scene> scene);
	};
}