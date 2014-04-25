
#include "ace.CubemapTexture.h"
#include "../ace.DeviceObject.h"

namespace ace
{
	class CubemapTexture_Imp
		: public CubemapTexture
		, public DeviceObject
	{
	protected:
		CubemapTexture_Imp(Graphics* graphics);
		virtual ~CubemapTexture_Imp();

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