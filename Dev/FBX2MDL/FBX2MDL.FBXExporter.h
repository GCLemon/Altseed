
#include "FBX2MDL.Base.h"

namespace FBX2MDL
{

	class FBXExporter
	{
	private:
		struct Bone
		{
			asd::astring	Name;
			int32_t			ParentIndex;

		};

		struct MaterialOffset
		{
			int32_t		MaterialIndex;
			int32_t		FaceOffset;
		};
		
		std::shared_ptr<asd::BinaryWriter> m_writer;

		void WriteHeader();

		void WriteAnimationSource(AnimationSource& source);
		void WriteAnimationSources(std::vector<AnimationSource>& animationSources);

		void WriteMaterial(const Material& material);
		void WriteMaterials(const std::vector<Material>& materials);

		void WriteMesh(const asd::Model_IO::DividedMesh& mesh);

		static std::vector<std::shared_ptr<Mesh>> GetMeshes(const std::shared_ptr<Node>& node);

		std::vector<std::function<void()>> GetWritingDeformerFuncs(const std::shared_ptr<Node>& node, int32_t parentIndex, int32_t& currentIndex);

		std::map<asd::astring, int32_t> GetDeformerNameToIndexes(const std::shared_ptr<Node>& node, int32_t& currentIndex);

		asd::Model_IO::Vertex ConverterVertexToModelVertex(asd::Model_IO::Vertex);

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
		std::shared_ptr<asd::BinaryWriter> Export(std::shared_ptr<Scene> scene);
	};
}