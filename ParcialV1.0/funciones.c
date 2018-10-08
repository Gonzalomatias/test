#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int menu()
{
    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1-  Alta Peliculas\n");
    printf(" 2-  modificar datos de una pelicula\n");
    printf(" 3-  Baja de la Pelicula\n");
    printf(" 4-  Nuevo director\n");
    printf(" 5-  Eliminar director\n");
    printf(" 6-  Listar\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int letters(char letter[])
{
    int i=0;

    while(letter[i] != '\0')
    {
        if((letter[i] != ' ') && (letter[i] < 'a' || letter[i] > 'z') && (letter[i] < 'A' || letter[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int Mensage(char msj[])
{
    int aux;

    printf("%s",msj);
    scanf("%d",&aux);

    return aux;
}

int isNumbers(char msj[],char loadText[])
{
    char aux[300];
    isString(msj,aux);
    if(isNumeric(aux))
    {
        strcpy(loadText,aux);
        return 1;
    }
    return 0;
}

void isString(char msj[],char cargarTexto[])
{
    printf("%s",msj);
    fflush(stdin);
    gets(cargarTexto);

}

int onlyLetters(char msj[],char cargarTexto[])
{
    char aux[300];
    isString(msj,aux);
    if(letters(aux))
    {
        strcpy(cargarTexto,aux);
        return 1;
    }
    return 0;
}


int isNumeric(char number[])
{
    int i=0;
    while(number[i] != '\0')
    {
        if(number[i] < '0' || number[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

