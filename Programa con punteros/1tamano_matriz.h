#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char caracter;
int cantidad_columnas = 0; // Cuando la funcion inicia no hay columnas contadas
int cantidad_filas = 1; // La funcion comienza a leer en la fila 1
int maximo_columnas = 0; // 0 si no se ha llegado al maximo de columnas y 1 si se llego al maximo de columnas

void dimensiona_la_matriz(int *F,int *C)
{
    FILE *archivo;

    archivo = fopen("laberinto.txt", "r"); //Abre el archivo

    while (feof(archivo) == 0) //feof devuelve un 0 si aun no ha terminado de leer el archivo
    {
        caracter = fgetc(archivo); //fgetc lee caracter por caracter el archivo
        printf("%c", caracter);        

        if ((caracter == '0' || caracter == '1' || caracter == '2') && maximo_columnas == 0) // Agrega una columna si el caracter es 0, 1 o 2
        {
            cantidad_columnas++;
        }

        if (caracter == '\n') // Agrega una fila cuando se llega a un salto de linea y reinicia el contador de columnas si hay otra fila
        {
            cantidad_filas++;
            maximo_columnas = 1;
        }
    }

    fclose(archivo); //Cierra el archivo

    *F = cantidad_filas;
    *C =  cantidad_columnas;

}
