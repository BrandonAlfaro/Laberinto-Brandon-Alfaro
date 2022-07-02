#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int espacio_de_juego[100][100];

int inicios[2][100];
int indice_inicio = 0;
int cantidad_inicios = 0;
int solucion_encontrada = 0;

char caracter;
int cantidad_columnas = 0;
int cantidad_filas = 1;
int maximo_columnas = 0; // 0 si no se ha llegado al maximo de columnas y 1 si se llego al maximo de columnas

FILE *archivo;

int dimensiona_la_matriz()
{
    archivo = fopen("laberinto - copia.txt", "r"); //Abre el archivo

    while (feof(archivo) == 0) //feof devuelve un 0 si aun no ha terminado de leer el archivo
    {
        caracter = fgetc(archivo); //fgetc lee caracter por caracter el archivo
        printf("%c", caracter);        

        if ((caracter == '0' || caracter == '1' || caracter == '2') && maximo_columnas == 0) // Agrega una columna si el caracter es 0, 1 o 2
        {
            cantidad_columnas++;

        }
        else if (caracter == '\n') // Agrega una fila cuando se llega a un salto de linea
        {
            cantidad_filas++;
            maximo_columnas = 1;
        }
    }

    fclose(archivo); //Cierra el archivo
}

int matriz_txt_a_arreglo()
{
    archivo = fopen("laberinto - copia.txt", "r"); //Abre el archivo

    cantidad_columnas = 0;
    cantidad_filas = 1;

    while (feof(archivo) == 0) //feof devuelve un 0 si aun no ha terminado de leer el archivo
    {
        caracter = fgetc(archivo); //fgetc lee caracter por caracter el archivo

        if (caracter == '0' || caracter == '1' || caracter == '2') // Modifica el valor de la matriz
        {
            cantidad_columnas++;
            
            if (caracter == '0')
            {
                espacio_de_juego[cantidad_filas - 1][cantidad_columnas - 1] = 0;
            }
            else if (caracter == '1')
            {
                espacio_de_juego[cantidad_filas - 1][cantidad_columnas - 1] = 1;
            }
            else if (caracter == '2')
            {
                espacio_de_juego[cantidad_filas - 1][cantidad_columnas - 1] = 2;
            }
            
        }
        else if (caracter == '\n') // Se salta a la siguiente fila para modificar
        {
            cantidad_filas++;
            cantidad_columnas = 0;
        }
    }

    fclose(archivo);
} 

int busca_inicios_laberinto()
{
    for (int i = 1; i < cantidad_columnas; i++) // Fila superior
    {
        if (espacio_de_juego[0][i] == 1)
        {
            inicios[0][indice_inicio] = 0;
            inicios[1][indice_inicio] = i;
            indice_inicio++;
            cantidad_inicios++;
        }
    }
    for (int i = 1; i < cantidad_columnas; i++) // Fila inferior
    {
        if (espacio_de_juego[cantidad_filas - 1][i] == 1)
        {
            inicios[0][indice_inicio] = (cantidad_filas - 1);
            inicios[1][indice_inicio] = i;
            indice_inicio++;
            cantidad_inicios++;
        }
    }
    for (int i = 1; i < cantidad_filas; i++) // Columna izquierda
    {
        if (espacio_de_juego[i][0] == 1)
        {
            inicios[0][indice_inicio] = i;
            inicios[1][indice_inicio] = 0;
            indice_inicio++;
            cantidad_inicios++;
        }
    }
    for (int i = 1; i < cantidad_filas; i++) // Columna derecha
    {
        if (espacio_de_juego[i][cantidad_columnas - 1] == 1)
        {
            inicios[0][indice_inicio] = i;
            inicios[1][indice_inicio] = cantidad_columnas - 1;
            indice_inicio++;
            cantidad_inicios++;
        }
    }
    
    return 0;
}

int recorre_camino(int posicion_anterior_F, int posicion_anterior_C, int posicion_actual_F, int posicion_actual_C)
{
    printf("\n%i",posicion_anterior_F);
    printf("\n%i",posicion_anterior_C);
    printf("\n%i",posicion_actual_F);
    printf("\n%i",posicion_actual_C);
    printf("\n");
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

int empieza_recorrido_con_inicios()
{
    if(cantidad_inicios > 0)
    {
        for(int i = 0; i < cantidad_inicios; i++)
        {
            recorre_camino(-1,-1,inicios[0][i],inicios[1][i]);
        }
    }
}

int main()
{
    dimensiona_la_matriz();
    matriz_txt_a_arreglo();
    busca_inicios_laberinto();
    printf("\n%i", cantidad_inicios);
    for (int i = 0; i < cantidad_inicios; i++)
    {
        printf("\n%i , %i",inicios[0][i], inicios[1][i]);
    }
    
    // printf("\n%i, %i", cantidad_filas, cantidad_columnas);
    // printf("\n%i", espacio_de_juego[3][7]);
    // printf("\n%i", inicios[0][0]);
    // printf("\n%i", inicios[1][0]);
    // printf("\n%i", inicios[0][1]);
    // printf("\n%i", inicios[1][1]);
    empieza_recorrido_con_inicios();
}
