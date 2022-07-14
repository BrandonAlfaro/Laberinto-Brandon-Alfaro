#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variables Globales
int espacio_de_juego[100][100]; // Espacio en el que se guardan los datos del laberinto

int inicios[2][100]; // Espacio en el que se guardan los datos de la posicion de los inicios del laberinto
int cantidad_inicios = 0; // Cantidad de inicios del laberinto
int solucion_encontrada = 0; // Aux para identificar cuando se encontro el inicio (1 = solucion encontrada)

int cantidad_columnas = 0; // Almacena la cantidad de columnas del laberinto
int cantidad_filas = 1; // Almacena la cantidad de filas del laberinto
int maximo_columnas = 0; // Aux, 0 si no se ha llegado al maximo de columnas y 1 si se llego al maximo de columnas

FILE *archivo; // Inicializa puntero a archivo

void dimensiona_la_matriz()
{
    char caracter; // Guarda el caracter que se lee
    archivo = fopen("laberinto.txt", "r"); //Abre el archivo

    while (feof(archivo) == 0) //feof devuelve un 0 si aun no ha terminado de leer el archivo
    {
        caracter = fgetc(archivo); //fgetc lee caracter por caracter el archivo
        printf("%c", caracter);        

        if ((caracter == '0' || caracter == '1' || caracter == '2') && maximo_columnas == 0) // Agrega una columna si el caracter es 0, 1 o 2
        {
            cantidad_columnas++;
        }
        else if (caracter == '\n') // Agrega una fila si se llega a un salto de linea
        {
            cantidad_filas++;
            maximo_columnas = 1;
        }
    }

    fclose(archivo); //Cierra el archivo
}

void matriz_txt_a_arreglo()
{
    char caracter;
    archivo = fopen("laberinto.txt", "r"); //Abre el archivo

    cantidad_columnas = 0;
    cantidad_filas = 1;

    while (feof(archivo) == 0) //feof devuelve un 0 si aun no ha terminado de leer el archivo
    {
        caracter = fgetc(archivo); //fgetc lee caracter por caracter el archivo

        if (caracter == '0' || caracter == '1' || caracter == '2') // Modifica el valor de la matriz de espacio de juego y pone los valores del laberinto
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

void busca_inicios_laberinto()
{
    int indice_inicio = 0;

    // Guarda en la matriz de inicios la informacion de la posicion de un inicio
    for (int i = 1; i < cantidad_columnas; i++) // Revisa la fila superior
    {
        if (espacio_de_juego[0][i] == 1)
        {
            inicios[0][indice_inicio] = 0;
            inicios[1][indice_inicio] = i;
            indice_inicio++;
            cantidad_inicios++;
        }
    }
    for (int i = 1; i < cantidad_columnas; i++) // Revisa la fila inferior
    {
        if (espacio_de_juego[cantidad_filas - 1][i] == 1)
        {
            inicios[0][indice_inicio] = (cantidad_filas - 1);
            inicios[1][indice_inicio] = i;
            indice_inicio++;
            cantidad_inicios++;
        }
    }
    for (int i = 1; i < cantidad_filas; i++) // Revisa la columna izquierda
    {
        if (espacio_de_juego[i][0] == 1)
        {
            inicios[0][indice_inicio] = i;
            inicios[1][indice_inicio] = 0;
            indice_inicio++;
            cantidad_inicios++;
        }
    }
    for (int i = 1; i < cantidad_filas; i++) // Revisa la columna derecha
    {
        if (espacio_de_juego[i][cantidad_columnas - 1] == 1)
        {
            inicios[0][indice_inicio] = i;
            inicios[1][indice_inicio] = cantidad_columnas - 1;
            indice_inicio++;
            cantidad_inicios++;
        }
    }
}

void recorre_camino(int posicion_anterior_F, int posicion_anterior_C, int posicion_actual_F, int posicion_actual_C)
{
    // imprime la coordenadas de la posicion anterior y actual
    printf("\n%i",posicion_anterior_F);
    printf("\n%i",posicion_anterior_C);
    printf("\n%i",posicion_actual_F);
    printf("\n%i",posicion_actual_C);
    printf("\n");

    // Recorre camino
    if (espacio_de_juego[posicion_actual_F - 1][posicion_actual_C] == 1 && (posicion_actual_F - 1) >= 0 && (posicion_actual_F - 1) != posicion_anterior_F) // Posicion Arriba
    {
        recorre_camino(posicion_actual_F, posicion_actual_C, posicion_actual_F - 1, posicion_actual_C);
    }
    if (espacio_de_juego[posicion_actual_F][posicion_actual_C - 1] == 1 && (posicion_actual_C - 1) >= 0 && (posicion_actual_C - 1) != posicion_anterior_C) // Posicion Izquierda
    {
        recorre_camino(posicion_actual_F, posicion_actual_C, posicion_actual_F, posicion_actual_C - 1);
    }
    if (espacio_de_juego[posicion_actual_F + 1 ][posicion_actual_C] == 1 && (posicion_actual_F + 1) <= cantidad_filas && (posicion_actual_F + 1) != posicion_anterior_F) //Posicion Abajo
    {
        recorre_camino(posicion_actual_F, posicion_actual_C, posicion_actual_F + 1, posicion_actual_C);
    }
    if (espacio_de_juego[posicion_actual_F][posicion_actual_C + 1] == 1 && (posicion_actual_C + 1) <= cantidad_columnas && (posicion_actual_C + 1) != posicion_anterior_C) // Posicion Derecha
    {
        recorre_camino(posicion_actual_F, posicion_actual_C, posicion_actual_F, posicion_actual_C + 1);
    }

    // Si encuentra la solucion se ejecuta algun if
    if (espacio_de_juego[posicion_actual_F + 1][posicion_actual_C] == 2 && solucion_encontrada == 0) // Posicion Arriba
    {
        printf("\nLa solucion fue encontrada en la posicion: %i,%i", posicion_actual_F + 1, posicion_actual_C);
        solucion_encontrada = 1;
    }
    if (espacio_de_juego[posicion_actual_F - 1][posicion_actual_C] == 2 && solucion_encontrada == 0) // Posicion Izquierda
    {
        printf("\nLa solucion fue encontrada en la posicion: %i,%i", posicion_actual_F - 1, posicion_actual_C);
        solucion_encontrada = 1;
    }
    if (espacio_de_juego[posicion_actual_F][posicion_actual_C + 1] == 2 && solucion_encontrada == 0) //Posicion Abajo
    {
        printf("\nLa solucion fue encontrada en la posicion: %i,%i", posicion_actual_F, posicion_actual_C + 1);
        solucion_encontrada = 1;
    }
    if (espacio_de_juego[posicion_actual_F][posicion_actual_C - 1] == 2 && solucion_encontrada == 0) // Posicion Derecha
    {
        printf("\nLa solucion fue encontrada en la posicion: %i,%i", posicion_actual_F, posicion_actual_C - 1);
        solucion_encontrada = 1;
    }
}

void empieza_recorrido_con_inicios()
{
    // Empieza el recorrido desde la posicion de los inicios
    if(cantidad_inicios > 0)
    {
        for(int i = 0; i < cantidad_inicios; i++)
        {
            recorre_camino(-1,-1,inicios[0][i],inicios[1][i]);
        }
    }
    // Imprime mensaje si la solucion no fue encontrada
    if(solucion_encontrada == 0)
    {
        printf("La solucion no fue encontrada");
    }
}

int main()
{
    // Main ejecuta todas la funciones

    dimensiona_la_matriz();
    matriz_txt_a_arreglo();
    busca_inicios_laberinto();
    printf("\n%i", cantidad_inicios);

    for (int i = 0; i < cantidad_inicios; i++)
    {
        printf("\n%i , %i",inicios[0][i], inicios[1][i]);
    }
    empieza_recorrido_con_inicios();
    return 0;
}
