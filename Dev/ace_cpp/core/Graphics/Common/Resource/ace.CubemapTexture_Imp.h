
#include "ace.CubemapTexture.h"

namespace ace
{
	class CubemapTexture_Imp
		: public CubemapTexture
		, public ReferenceObject
	{
	private:

	public:

		// IReference���p�������f�o�C�X�I�u�W�F�N�g������`
#if !SWIG
	public:
		virtual int GetRef() { return ReferenceObject::GetRef(); }
		virtual int AddRef() { return ReferenceObject::AddRef(); }
		virtual int Release() { return ReferenceObject::Release(); }
#endif
	};
}