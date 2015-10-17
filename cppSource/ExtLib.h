#ifndef _EXTLIB_H_INCLUDED_
#define _EXTLIB_H_INCLUDED_

/*---- include ----*/
#include "library.h"

/*---- extern ----*/

#ifndef EXPORT_API

#if defined(__MINGW32__)
#define EXPORT_API __declspec(dllexport)
#define EXPORT_STDCALL __stdcall

#elif defined(_MSC_VER) /* this is defined when compiling with Visual Studio */
#define EXPORT_API __declspec(dllexport) /* Visual Studio needs annotating exported functions with this */
#define EXPORT_STDCALL 

#elif defined(__psp2__)
#define EXPORT_API __declspec(dllexport)
#define EXPORT_STDCALL 

#else
#define EXPORT_API /* XCode does not need annotating exported functions, so define is empty */
#define EXPORT_STDCALL 
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

//may have some initialization function

//some internal function
void EXT_LIB_InternalFunc();


//function need no input param
extern EXPORT_API int EXPORT_STDCALL EXT_LIB_GetNum();

//function need input param
extern EXPORT_API void EXPORT_STDCALL EXT_LIB_PassingVector(float* pnts, float* floatArray, float* Val);

//may have some terminating function

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _EXTLIB_H_INCLUDED_ */
