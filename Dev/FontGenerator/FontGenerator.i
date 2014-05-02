%module FontGenerator

%{
#include "DLL.h"
%}

//-----------------------------------------------------------------------------------
// csharp
//-----------------------------------------------------------------------------------
%include "arrays_csharp.i"
%include "wchar.i"
%include "stdint.i"
%include "std_vector.i"
%include "std_string.i"
%include "std_wstring.i"

// �SOS���ʂ�wchar_t����
namespace ace {
typedef wchar_t achar;
typedef std::wstring astring;
}


// �Z�L�����e�B�`�F�b�N���O���č�����
%pragma(csharp) imclassclassmodifiers="
[System.Security.SuppressUnmanagedCodeSecurity]
public class"

// �S�Ă�class �� unsafe partial class �ɁB
%typemap(csclassmodifiers) SWIGTYPE "unsafe partial class"

// csharp void �̒�`
%typemap(ctype) void * "void *"
%typemap(imtype) void * "IntPtr"
%typemap(cstype) void * "IntPtr"
%typemap(in) void * { $1 = $input; }
%typemap(out) void * { $result = $1; }
%typemap(csin) void * "$csinput"
%typemap(csout) void * { return $imcall; }
%typemap(csvarin) void * { set { $imcall; } }
%typemap(csvarout) void * { get { return $imcall; } } 

//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
%define STRUCT_OBJECT( CTYPE, CSTYPE )
%ignore CTYPE;

// ��؉����t���Ă��Ȃ��Ƃ��̏��������������\������
%typemap(ctype)		CTYPE	"CTYPE"
%typemap(imtype)	CTYPE	"CSTYPE"
%typemap(cstype)	CTYPE	"CSTYPE"
%typemap(in)		CTYPE	{ $1 = $input; }
%typemap(out)		CTYPE	{ $result = $1; }
%typemap(csin)		CTYPE	"$csinput"
%typemap(csout)		CTYPE	{ return $imcall; }
%typemap(csvarin)	CTYPE	{ set { $imcall; } }
%typemap(csvarout)	CTYPE	{ get { return $imcall; } } 

%typemap(ctype)		CTYPE* "void*"
%typemap(imtype)	CTYPE* "ref CSTYPE"
%typemap(cstype)	CTYPE* "ref CSTYPE"
%typemap(in)		CTYPE* "$1 = (CTYPE*)$input;"
%typemap(csin)		CTYPE* "ref $csinput"

%typemap(ctype)		const CTYPE* "void*"
%typemap(imtype)	const CTYPE* "ref CSTYPE"
%typemap(cstype)	const CTYPE* "ref CSTYPE"
%typemap(in)		const CTYPE* "$1 = (CTYPE*)$input;"
%typemap(csin)		const CTYPE* "ref $csinput"

%typemap(ctype)		CTYPE& "void*"
%typemap(imtype)	CTYPE& "ref CSTYPE"
%typemap(cstype)	CTYPE& "ref CSTYPE"
%typemap(in)		CTYPE& "$1 = (CTYPE*)$input;"
%typemap(csin)		CTYPE& "ref $csinput"

%typemap(ctype)		const CTYPE& "void*"
%typemap(imtype)	const CTYPE& "ref CSTYPE"
%typemap(cstype)	const CTYPE& "ref CSTYPE"
%typemap(in)		const CTYPE& "$1 = (CTYPE*)$input;"
%typemap(csin)		const CTYPE& "ref $csinput"
%enddef

%define STRUCT_OBJECT_RET( CTYPE, RCTYPE, CSTYPE )
%ignore CTYPE;

// ��؉����t���Ă��Ȃ��Ƃ��̏��������������\������
%typemap(ctype)		CTYPE	"RCTYPE"
%typemap(imtype)	CTYPE	"CSTYPE"
%typemap(cstype)	CTYPE	"CSTYPE"
%typemap(in)		CTYPE	{ assert(sizeof(CTYPE)==sizeof(RCTYPE)); memcpy(&$1, &$input, sizeof(RCTYPE)); }
%typemap(out)		CTYPE	{ assert(sizeof(CTYPE)==sizeof(RCTYPE)); memcpy(&$result, &$1, sizeof(RCTYPE)); }
%typemap(csin)		CTYPE	"$csinput"
%typemap(csout)		CTYPE	{ return $imcall; }
%typemap(csvarin)	CTYPE	{ set { $imcall; } }
%typemap(csvarout)	CTYPE	{ get { return $imcall; } } 

%typemap(ctype)		CTYPE* "void*"
%typemap(imtype)	CTYPE* "ref CSTYPE"
%typemap(cstype)	CTYPE* "ref CSTYPE"
%typemap(in)		CTYPE* "$1 = (CTYPE*)$input;"
%typemap(csin)		CTYPE* "ref $csinput"


%typemap(ctype)		const CTYPE* "void*"
%typemap(imtype)	const CTYPE* "ref CSTYPE"
%typemap(cstype)	const CTYPE* "ref CSTYPE"
%typemap(in)		const CTYPE* "$1 = (CTYPE*)$input;"
%typemap(csin)		const CTYPE* "ref $csinput"

%typemap(ctype)		CTYPE& "void*"
%typemap(imtype)	CTYPE& "ref CSTYPE"
%typemap(cstype)	CTYPE& "ref CSTYPE"
%typemap(in)		CTYPE& "$1 = (CTYPE*)$input;"
%typemap(csin)		CTYPE& "ref $csinput"

%typemap(ctype)		const CTYPE& "void*"
%typemap(imtype)	const CTYPE& "ref CSTYPE"
%typemap(cstype)	const CTYPE& "ref CSTYPE"
%typemap(in)		const CTYPE& "$1 = (CTYPE*)$input;"
%typemap(csin)		const CTYPE& "ref $csinput"
%enddef


%define DEL_OBJECT( _DEL_OBJ )
%typemap(csout) _DEL_OBJ
%{
{
	lock(this) {
		$imcall;
		swigCMemOwn = false;
		swigCPtr = new HandleRef(null, IntPtr.Zero);
		GC.SuppressFinalize(this);
	}
}
%}
%enddef

//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
%include "FontGeneratorCore/DLL.h"

