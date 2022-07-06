#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tamano_matriz.h"
#include "espacio_matriz.h"
#include "txt_a_arreglo.h"

int c_filas,c_columnas;
int espacio_de_juego [];

int main()
{
    dimensiona_la_matriz(&c_filas,&c_columnas);
    reserva_espacio(&espacio_de_juego,c_filas,c_columnas);
    matriz_txt_a_arreglo(&espacio_de_juego);
    return 0;
}