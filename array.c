/*
 * @fileoverview {FileName} se encarga de realizar tareas especificas.
 *
 * @version             1.0
 *
 * @author              Dyson Arley Parra Tilano <dysontilano@gmail.com>
 * Copyright (C) Dyson Parra
 *
 * @History v1.0 --- La implementacion de {FileName} fue realizada el 31/07/2022.
 * @Dev - La primera version de {FileName} fue escrita por Dyson A. Parra T.
 */
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <Windows.h>

#if (!defined STATIC_LIB_) && (!defined NO_DLL_MAIN_)
/**
 * Entrada principal de la dll (creado si no se indica que es biblioteca estática)
 *
 * @param instance identificador del módulo.
 * @param reason   razón de la llamada.
 * @param reserved argumento reservado.
 * @return {@code TRUE} si se completó exitosamente la llamada, caso contrario {@code FALSE}.
 */
BOOL APIENTRY DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    /*
     * Evalúa la razón de la llamada a la dll.
     */
    switch (reason) {
        /*
         * Se cargó la dll en el proceso actual.
         */
        case DLL_PROCESS_ATTACH:
            // printf("%s\n", "DLL_PROCESS_ATTACH");
            break;

        /*
         * Se liberó la dll en el proceso actual.
         */
        case DLL_PROCESS_DETACH:
            // printf("%s\n", "DLL_PROCESS_DETACH");
            break;

        /*
         * Se cargó la dll en un nuevo hilo.
         */
        case DLL_THREAD_ATTACH:
            // printf("%s\n", "DLL_THREAD_ATTACH");
            break;

        /*
         * Se liberó la dll en el nuevo hilo.
         */
        case DLL_THREAD_DETACH:
            // printf("%s\n", "DLL_THREAD_DETACH");
            break;
    }

    return TRUE;
}
#endif

/**
 * TODO: Definición de {@code new_array}.
 */
LANGUAGE DLLIMPORT CALLING Array* new_array(int elem_size) {
    Array* array = malloc(sizeof(Array));
    array->length = 0;
    array->elem_size = elem_size;
    array->data = NULL;
    return array;
}

/**
 * TODO: Definición de {@code new_array_with_elements}.
 */
LANGUAGE DLLIMPORT CALLING Array* new_array_with_elements(int elem_size, int nargs, ...) {
    Array* array = new_array(elem_size);
    va_list ap;
    va_start(ap, nargs);
    for (int i =0; i<nargs; i++)
        add_array_element(array, va_arg(ap, void*));
    va_end(ap);
    return array;
}

/**
 * TODO: Definición de {@code new_array_generic}.
 */
LANGUAGE DLLIMPORT CALLING Array* new_array_generic() {
    return new_array(sizeof(void*));
}

/**
 * TODO: Definición de {@code new_array_generic_with_elements}.
 */
LANGUAGE DLLIMPORT CALLING Array* new_array_generic_with_elements(int nargs, ...) {
    Array* array = new_array(sizeof(void*));
    va_list ap;
    va_start(ap, nargs);
    for (int i =0; i<nargs; i++)
        add_array_element(array, va_arg(ap, void*));
    va_end(ap);
    return array;
}

/**
 * TODO: Definición de {@code add_array_element}.
 */
LANGUAGE DLLIMPORT CALLING void add_array_element(Array* array, void* element) {
    array->length++;
    if (array->length == 1)
        array->data = malloc(array->elem_size);
    else
        array->data = realloc(array->data, array->elem_size*array->length);
    array->data[array->length-1] = element;
}

/**
 * TODO: Definición de {@code add_array_element_copy}.
 */
LANGUAGE DLLIMPORT CALLING void add_array_element_copy(Array* array, void* element, int length) {
    void* aux = malloc(array->elem_size*length);
    memcpy(aux, element, length);
    add_array_element(array, aux);
}

/**
 * TODO: Definición de {@code add_array_various_elements}.
 */
LANGUAGE DLLIMPORT CALLING void add_array_various_elements(Array* array, int nargs, ...) {
    va_list ap;
    va_start(ap, nargs);
    for (int i =0; i<nargs; i++)
        add_array_element(array, va_arg(ap, void*));
    va_end(ap);
}

/**
 * TODO: Definición de {@code remove_last_array_element}.
 */
LANGUAGE DLLIMPORT CALLING void remove_last_array_element(Array* array) {
    array->length--;
    if (array->length == 0)
        array->data = NULL;
    else
        array->data = realloc(array->data, array->elem_size*array->length);
}

/**
 * TODO: Definición de {@code remove_last_array_element_and_free}.
 */
LANGUAGE DLLIMPORT CALLING void remove_last_array_element_and_free(Array* array) {
    free(array->data[array->length-1]);
    remove_last_array_element(array);
}
