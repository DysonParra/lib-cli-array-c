/*
 * @overview        {FileName}
 *
 * @version         2.0
 *
 * @author          Dyson Arley Parra Tilano <dysontilano@gmail.com>
 *
 * @copyright       Dyson Parra
 * @see             github.com/DysonParra
 *
 * History
 * @version 1.0     Implementation done.
 * @version 2.0     Documentation added.
 */
#include "array.h"
#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Entrada principal del sistema.
 *
 * @param argc cantidad de argumentos pasados en la linea de comandos.
 * @param argv argumentos de la linea de comandos.
 * @return {0} si el programa se ejecutó correctamente.
 */
int main(int argc, char** argv) {

    Array* root = new_array_generic();
    add_array_element(root, new_array_generic_with_elements(3, "-use", "--notUse", "--find") );
    add_array_element(root, new_array_generic_with_elements(2, "-name", "--noName") );
    add_array_element(root, new_array_generic_with_elements(2, "-encoder", "--noEncoder") );

    for (int i = 0; i < root->length; i++) {
        Array* spec = (Array*)root->data[i];
        for (int j = 0; j < spec->length; j++)
            printf("'%s' ", (char*)spec->data[j]);
        printf("\n");
    }

    /*-
    printf("\n...START...\n");

    char* requiredFlags[][20] = {
        {"-use", "--notUse", "--find"},
        {"-name", "--noName"},
        {"-encoder", "--noEncoder"}, {0}};

    char* optionalFlags[][20] = {
        {"-flag", "--noFlag"},
        {"-test", "--noTest"}, {0}};

    printf("...END...");

    */

    /*-
    //Array* array = new_array(sizeof(char*));
    Array* array = new_array_generic();

    char text[20] = "";
    for (int i = 0; i < 5; i++) {
        sprintf(text, "Prueba %d", i);
        //add_array_element(array, text);
        add_array_element_copy(array, text, strlen(text)+1);
    }

    for (int i = 0; i < array->length; i++) {
        printf("Length: %d'\t", array->length);
        printf("Size:  '%d'\t", array->elem_size);
        printf("Word:  '%s'\n", (char*)array->data[i]);
    }
    printf("\n");

    remove_last_array_element_and_free(array);
    add_array_various_elements(array, 3, "AAAA", "BBBB", "CCCCC");
    for (int i = 0; i < array->length; i++) {
        printf("Length: %d'\t", array->length);
        printf("Size:  '%d'\t", array->elem_size);
        printf("Word:  '%s'\n", (char*)array->data[i]);
    }
    printf("\n");
    printf("\nLLEGA\n");
    */

    return 0;
}
