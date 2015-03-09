
#pragma once

#include <ace.common.Base.h>

#include <Math/ace.RectI.h>

#include "ace.Texture2D.h"
#include "../../ace.ReferenceObject.h"

namespace ace
{
	/**
	@brief	�����̉摜���i�[����Ă���N���X
	*/
	class ImagePackage
		: public IReference
	{
	private:

	protected:
		ImagePackage() {}
		virtual ~ImagePackage(){}

		virtual Texture2D* GetImage_(int32_t index) = 0;

	public:
		
		/**
			@brief	�i�[����Ă���摜�̖������擾����B
			@return	�摜�̖���
		*/
		virtual int32_t GetImageCount() = 0;

		/**
			@brief	�i�[����Ă���摜�̖��̂��擾����B
			@param	index	�C���f�b�N�X
			@return	����
		*/
		virtual const achar* GetImageName(int32_t index) = 0;

		/**
		@brief	�i�[����Ă���摜���z�u�����̈���擾����B
		@param	index	�C���f�b�N�X
		@return	�̈�
		*/
		virtual RectI GetImageArea(int32_t index) = 0;

		/**
			@brief	�摜���擾����B
			@param	index	�C���f�b�N�X
			@return	�摜
		*/
		std::shared_ptr<Texture2D> GetImage(int32_t index)
		{
			auto image = GetImage_(index);
			return CreateSharedPtrWithReleaseDLL(image);
		}
	};
}