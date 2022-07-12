#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct info_posicion
{
    int posicion_actual_x;
    int posicion_actual_y;

    int posicion_arriba_x;
    int posicion_arriba_y;

    int posicion_abajo_x;
    int posicion_abajo_y;

    int posicion_derecha_x;
    int posicion_derecha_y;

    int posicion_izquierda_x;
    int posicion_izquierda_y;

    int posicion_anterior_x;
    int posicion_anterior_y;
}Info_Posicion;

Info_Posicion posicion;

int recorre_camino(int *arreglo)
{
    // Posicion a la derecha
    if ((*arreglo) + 1 == 1)
    {
        /* code */
    }
    

    if (espacio_de_juego[posicion_actual_F - 1][posicion_actual_C] == 1 && (posicion_actual_F - 1) >= 0 && (posicion_actual_F - 1) != posicion_anterior_F)
    {
        recorre_camino(posicion_actual_F, posicion_actual_C, posicion_actual_F - 1, posicion_actual_C);
    }
    if (espacio_de_juego[posicion_actual_F][posicion_actual_C - 1] == 1 && (posicion_actual_C - 1) >= 0 && (posicion_actual_C - 1) != posicion_anterior_C)
    {
        recorre_camino(posicion_actual_F, posicion_actual_C, posicion_actual_F, posicion_actual_C - 1);
    }
    if (espacio_de_juego[posicion_actual_F + 1 ][posicion_actual_C] == 1 && (posicion_actual_F + 1) <= cantidad_filas && (posicion_actual_F + 1) != posicion_anterior_F)
    {
        recorre_camino(posicion_actual_F, posicion_actual_C, posicion_actual_F + 1, posicion_actual_C);
    }
    if (espacio_de_juego[posicion_actual_F][posicion_actual_C + 1] == 1 && (posicion_actual_C + 1) <= cantidad_columnas && (posicion_actual_C + 1) != posicion_anterior_C)
    {
        recorre_camino(posicion_actual_F, posicion_actual_C, posicion_actual_F, posicion_actual_C + 1);
    }
    if (espacio_de_juego[posicion_actual_F + 1][posicion_actual_C] == 2 && solucion_encontrada == 0)
    {
        printf("\nLa solucion fue encontrada en la posicion: %i,%i", posicion_actual_F + 1, posicion_actual_C);
        solucion_encontrada = 1;
    }
    if (espacio_de_juego[posicion_actual_F - 1][posicion_actual_C] == 2 && solucion_encontrada == 0)
    {
        printf("\nLa solucion fue encontrada en la posicion: %i,%i", posicion_actual_F - 1, posicion_actual_C);
        solucion_encontrada = 1;
    }
    if (espacio_de_juego[posicion_actual_F][posicion_actual_C + 1] == 2 && solucion_encontrada == 0)
    {
        printf("\nLa solucion fue encontrada en la posicion: %i,%i", posicion_actual_F, posicion_actual_C + 1);
        solucion_encontrada = 1;
    }
    if (espacio_de_juego[posicion_actual_F][posicion_actual_C - 1] == 2 && solucion_encontrada == 0)
    {
        printf("\nLa solucion fue encontrada en la posicion: %i,%i", posicion_actual_F, posicion_actual_C - 1);
        solucion_encontrada = 1;
    }
}

void inicia_inicios(int arreglo,int *arreglo_x,int *arreglo_y,int c_inicios)
{
    for (int i = 0; i < c_inicios; i++)
    {
        posicion.posicion_actual_x = *arreglo_x;
        posicion.posicion_actual_y = *arreglo_y;

        posicion.posicion_arriba_x = (*arreglo_x)-1;
        posicion.posicion_arriba_y = (*arreglo_y);

        posicion.posicion_abajo_x = (*arreglo_x)+1;
        posicion.posicion_abajo_x = (*arreglo_y);

        posicion.posicion_derecha_x = (*arreglo_x);
        posicion.posicion_derecha_y = (*arreglo_y)-1;

        posicion.posicion_izquierda_x = (*arreglo_x);
        posicion.posicion_izquierda_y = (*arreglo_y)+1;

        posicion.posicion_anterior_x = -1;
        posicion.posicion_anterior_y = -1;

        recorre_camino(&arreglo);

        arreglo_x++;
        arreglo_y++;
    }
    
}