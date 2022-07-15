#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matriz_txt_a_arreglo(int *arreglo)
{
    FILE *archivo;

    archivo = fopen("laberinto.txt", "r"); //Abre el archivo

    while (feof(archivo) == 0) //feof devuelve un 0 si aun no ha terminado de leer el archivo
    {
        int caracter = fgetc(archivo); //fgetc lee caracter por caracter el archivo

        switch (caracter)
        {
        case '0':
            *arreglo = 0;
            arreglo++;
            break;
        case '1':
            *arreglo = 1;
            arreglo++;
            break;
        case '2':
            *arreglo = 2;
            arreglo++;
            break;
        default:
            break;
        }
    }
    fclose(archivo);
} 