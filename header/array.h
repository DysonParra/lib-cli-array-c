#ifndef ARRAY_H_

#define ARRAY_H_

/* Includes for the header file */

#if defined __cplusplus
#define LANGUAGE extern "C"
#elif defined __GNUC__
#define LANGUAGE extern
#endif

#if defined ARRAY_STATIC_
#define DLLIMPORT
#elif defined BUILDING
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

#define CALLING __cdecl
//#define CALLING __stdcall

/* Macros and definitions for the source file. */
#ifdef ARRAY_DEFINITIONS_
#define elif else if
#define null NULL
#define String char*
#endif

DLLIMPORT typedef struct Array Array;
LANGUAGE DLLIMPORT CALLING Array* new_array(int elem_size);
LANGUAGE DLLIMPORT CALLING Array* new_array_with_elements(int elem_size, int nargs, ...);
LANGUAGE DLLIMPORT CALLING Array* new_array_generic();
LANGUAGE DLLIMPORT CALLING Array* new_array_generic_with_elements(int nargs, ...);
LANGUAGE DLLIMPORT CALLING void add_array_element(Array* array, void* element);
LANGUAGE DLLIMPORT CALLING void add_array_element_copy(Array* array, void* element, int length);
LANGUAGE DLLIMPORT CALLING void add_array_various_elements(Array* array, int nargs, ...);
LANGUAGE DLLIMPORT CALLING void remove_last_array_element(Array* array);
LANGUAGE DLLIMPORT CALLING void remove_last_array_element_and_free(Array* array);

struct Array {
    int elem_size;
    int length;
    void** data;
};

#endif

#if !defined BUILDING
#undef LANGUAGE
#undef DLLIMPORT
#undef CALLING
#endif
