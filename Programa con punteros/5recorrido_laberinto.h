#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables globales
int A;
int cantidad_columnas;
int cantidad_inicios_5;

// Guarda informacion a utilizar del arreglo y numero de columnas y filas
void llamar_arreglo(int arreglo, int C_C, int C_I)
{
    A = arreglo;
    cantidad_columnas = C_C;
}

int *puntero = &A;

// Recorre los caminos del laberitos con un puntero del arreglo donde se encuentra el laberinto
void recorre_camino1(int direccion, int p_actual_x,int p_actual_y, int p_anterior_x, int p_anterior_y)
{

    if(*(puntero+1) == 1 && p_actual_y != p_anterior_y) // Avanza a la posicion derecha de la posicion actual en el camino del laberinto
    {
        p_anterior_x = p_actual_x;
        p_anterior_y = p_actual_y;
        p_actual_x += 0;
        p_actual_y += 1;
        puntero++;
        recorre_camino1(puntero,p_actual_x,p_actual_y,p_anterior_x,p_anterior_y)
    }

    if (*(puntero-1) == 1 && p_actual_y != p_anterior_y) // Avanza a la posicion izquierda de la posicion actual en el camino del laberinto
    {
        p_anterior_x = p_actual_x;
        p_anterior_y = p_actual_y;
        p_actual_x += 0;
        p_actual_y -= 1;
        puntero--;
        recorre_camino1(puntero,p_actual_x,p_actual_y,p_anterior_x,p_anterior_y)
    }
    
    if (*(puntero-cantidad_columnas) == 1 && p_actual_x != p_anterior_x) // Avanza a la posicion superior de la posicion actual en el camino del laberinto
    {
        p_anterior_x = p_actual_x;
        p_anterior_y = p_actual_y;
        p_actual_x -= 1;
        p_actual_y -= 0;
        puntero -= cantidad_columnas;
        recorre_camino1(puntero,p_actual_x,p_actual_y,p_anterior_x,p_anterior_y)
    }
    
    if (*(puntero+cantidad_columnas) == 1 && p_actual_x != p_anterior_x) // Avanza a la posicion inferior de la posicion actual en el camino del laberinto
    {
        p_anterior_x = p_actual_x;
        p_anterior_y = p_actual_y;
        p_actual_x += 1;
        p_actual_y -= 0;
        puntero += cantidad_columnas;
        recorre_camino1(puntero,p_actual_x,p_actual_y,p_anterior_x,p_anterior_y)
    }

    if (*puntero == 2) // Imprime la posicion en la cual se encuentra la solucion del laberinto
    {
        printf("Solucion encontrada en la posicion: %i, %i", p_actual_x,p_actual_y)
    }
    
}

// Con la informacion de los inicios empieza el recorrido del laberinto en cada posicion inicial
void inicia_inicios(int *i_x, int *i_y)
{

    for (int i = 0; i < cantidad_inicios_5; i++)
    {
        puntero += ((*i_x)*cantidad_columnas) + (*i_y);
        recorre_camino1(puntero,*i_x,*i_y,-1,-1)
        *i_x++;
        *i_y++;
    }
}