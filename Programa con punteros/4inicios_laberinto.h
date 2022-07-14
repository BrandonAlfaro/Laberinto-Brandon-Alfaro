#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int C_Inicios = 0;

void cantidad_inicios(int *arreglo, int C_F,int C_C,int *c_inicios)
{
    int C_Inicios = 0;
    for (int i = 0; i < C_C; i++) // Fila superior
    {
        if (*arreglo == 1)
        {
            C_Inicios++;
        }
        arreglo++;
    }
    
    for (int i = 0; i < C_F-2; i++) // Columna derecha e izquierda
    {
        // printf("\nValor que ocupo: %i",*arreglo);
        if (*arreglo == 1)
        {
            C_Inicios++;
        }

        arreglo += (C_C-1);

        // printf("\nValor que ocupo: %i",*arreglo);
        if (*arreglo == 1)
        {
            C_Inicios++;
        }

        arreglo++;
    }
    
    for (int i = 0; i < C_C; i++) // Fila inferior
    {
        if (*arreglo == 1)
        {
            C_Inicios++;
        }
        arreglo++;
    }
    printf("\nCantidad de inicios: %i",C_Inicios);
    *c_inicios = C_Inicios;
    printf("\nLo que ocupo: %i",*c_inicios);
}

void reserva_espacio_inicios(int *arreglo1,int *arreglo2)
{
    arreglo1 = malloc(C_Inicios*sizeof(int));
    arreglo2 = malloc(C_Inicios*sizeof(int));
}

void posicion_inicios(int *arreglo,int *arreglo_x,int *arreglo_y, int C_F,int C_C)
{
    int indice_x = 0;
    int indice_y = 0;
    for (int i = 0; i < C_C; i++) // Fila superior
    {
        if (*arreglo == 1)
        {
            *arreglo_x = indice_x;
            *arreglo_y = i;
            arreglo_x++;
            arreglo_y++;
        }
        arreglo++;
        indice_y++;
    }
    
    for (int i = 0; i < C_F-2; i++) // Columna derecha e izquierda
    {
        indice_y = 0;
        indice_x++;
        if (*arreglo == 1)
        {
            *arreglo_x = indice_x;
            *arreglo_y = indice_y;
            arreglo_x++;
            arreglo_y++;
        }

        arreglo += (C_C-1);
        indice_y += (C_C-1);

        if (*arreglo == 1)
        {
            *arreglo_x = indice_x;
            *arreglo_y = indice_y;
            arreglo_x++;
            arreglo_y++;
        }

        arreglo++;
    }
    
    for (int i = 0; i < C_C; i++) // Fila inferior
    {
        if (*arreglo == 1)
        {
            *arreglo_x = indice_x;
            *arreglo_y = indice_y;
            arreglo_x++;
            arreglo_y++;
        }
        arreglo++;
        indice_y++;
    }
}