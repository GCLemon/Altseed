
#include <Base.h>

/**
	@brief	�E�C���h�E��\������B
*/
void Empty()
{
	/* ace������������B*/
	ace::GetEngine()->Initialize(L"Empty", 640, 480, false);

	/* ace���i�s�\���`�F�b�N����B */
	while (ace::GetEngine()->DoEvents())
	{
		/* ace���X�V����B*/
		ace::GetEngine()->Update();
	}

	/* ace���I������B*/
	ace::GetEngine()->Terminate();
}