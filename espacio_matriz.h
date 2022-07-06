#include <stdio.h>
#include <stdlib.h>

void reserva_espacio(int *arreglo, int F_espacio,int C_espacio)
{
    int n_espacios = F_espacio*C_espacio;
    arreglo = malloc(n_espacios*sizeof(int));
}
