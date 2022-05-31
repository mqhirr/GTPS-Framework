#ifndef __MACROS_H__
#define __MACROS_H__
#ifdef WIN32
#ifdef FRAMEWORK_DLL
#ifdef FRAMEWORK_LIB
    #define FRAMEWORK_EXPORT __declspec(dllexport)
#else
    #define FRAMEWORK_EXPORT __declspec(dllimport)
#endif /* FRAMEWORK_LIB */
#else /* !FRAMEWORK_DLL */
    #define FRAMEWORK_EXPORT extern
#endif /* FRAMEWORK_DLL */  
#else // !WIN32
#define FRAMEWORK_EXPORT extern
#endif
#endif // __MACROS_H__