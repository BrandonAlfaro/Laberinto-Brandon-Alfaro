#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1tamano_matriz.h"
#include "2espacio_matriz.h"
#include "3txt_a_arreglo.h"
#include "4inicios_laberinto.h"
#include "5recorrido_laberinto.h"

int c_filas,c_columnas;
int espacio_de_juego [];
int inicios_x [];
int inicios_y [];
int cantidad_de_inicios = 0;


int main()
{
    dimensiona_la_matriz(&c_filas,&c_columnas);

    printf("\n");
    printf("\nEspacios de filas y columnas: ");
    printf("%i , %i\n",c_filas,c_columnas);

    reserva_espacio(&espacio_de_juego,c_filas,c_columnas);

    
    matriz_txt_a_arreglo(&espacio_de_juego);

    cantidad_inicios(&espacio_de_juego,c_filas,c_columnas,&cantidad_de_inicios);

    reserva_espacio_inicios(&inicios_x,&inicios_y);
    
    posicion_inicios(&espacio_de_juego,&inicios_x,&inicios_y,c_filas,c_columnas);

    printf("\n%i", cantidad_de_inicios);

    return 0;
}