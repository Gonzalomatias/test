#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMP 2
#define TAMD 2
#include "funciones.h"



typedef struct
{
    char nombre[20];
    int fechaNacimiento;
    int paisOrigen;
} eDirector;

typedef struct
{
    char titulo[20];
    int anio;
    char nacionalidad[20];
    int indentificador;
    int isEmpty;
    eDirector directores;
} ePeliculas;



int buscarLibre(ePeliculas* lista, int tamp);

int addPelicula(ePeliculas* list, int tamp);

int buscarPelicula(ePeliculas* lista, int tamp, int indentificador);

int inicializarPeliculas(ePeliculas* list, int tamp);

void printPeliculas(ePeliculas* list, int tamp);

int removePeliculas(ePeliculas* list, int tamp,int identificador);

int modifyPeliculas(ePeliculas* list,int tamp);

int main()
{

    char seguir='s';
    int identificador=0,flag=0;

    ePeliculas peliculas[TAMP];
    //eDirector directores[TAMD];

    inicializarPeliculas(peliculas,TAMP);

    do
    {
        switch(menu())
        {
        case 1:
            addPelicula(peliculas,TAMP);
            flag=1;
            break;
        case 2:
            system("pause");
            break;
        case 3:
            if(flag!=1)
            {
                printf("\nerror no hay datos en el sistema\n\n");
                system("pause\n");

            }
            else
            {


                removePeliculas(peliculas,TAMP,identificador);
            }
            break;
        case 4:
            system("pause");
            break;
        case 5:
            system("pause");
            break;
        case 6:
            if(flag!=1)
            {
                printf("\nerror no hay datos en el sistema\n\n");
                system("pause\n");

            }
            else
            {
                printPeliculas(peliculas,TAMP);
                system("pause");
            }
            break;

        }
    }
    while(seguir == 's');


    return 0;
}




int inicializarPeliculas(ePeliculas* list, int tamp)
{
    int isEmpty=-1;

    if(tamp>0 && list!=0)
    {
        isEmpty=0;

        for(int i=0; i<tamp; i++)
        {
            list[i].isEmpty=0;
        }

    }
    return isEmpty;
}

int buscarLibre(ePeliculas* lista, int tamp)
{
    int indice = -1;

    for(int i=0; i < tamp; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarPelicula(ePeliculas* lista, int tamp, int indentificador)
{
    int indice = -1;

    for(int i=0; i < tamp; i++)
    {

        if( lista[i].indentificador == indentificador && lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


int addPelicula(ePeliculas* list, int tamp)
{
    int indentificador,anio,itsfree,existe;
    char auxIndentificador[20],auxAnio[20],titulo[20],director[20],nacionalidad[20];
    int retorno= -1;
    itsfree=buscarLibre(list,tamp);

    if(itsfree == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        while(!isNumbers("\ningrese identificador: ",auxIndentificador))
        {
            printf("***Error solo numeros Reingrese***\n");

        }
        indentificador=atoi(auxIndentificador);
        /** existe=buscarPelicula(list,tamp,indentificador);
         if(existe== -1)
         {
             printf("Ya existe una pelicula con el identificador %d\n", indentificador);
             system("pause");
         }*/

        while(!onlyLetters("\ningrese titulo de la pelicula: ",titulo))
        {
            printf("***Error solo letras Reingrese***\n");

        }
        while(!isNumbers("\ningrese anio: ",auxAnio))
        {
            printf("***Error solo numeros Reingrese***\n");

        }
        anio=atoi(auxAnio);
        while(!onlyLetters("\ningrese nacionalidad de la pelicula: ",nacionalidad))
        {
            printf("***Error solo letras Reingrese***\n");

        }
        while(!onlyLetters("\ningrese director de la pelicula: ",director))
        {
            printf("***Error solo letras Reingrese***\n");

        }



        retorno=0;

        list[itsfree].indentificador=indentificador;
        strcpy(list[itsfree].titulo,titulo);
        list[itsfree].anio=anio;
        strcpy(list[itsfree].nacionalidad,nacionalidad);
        strcpy(list[itsfree].directores.nombre,director);
        list[itsfree].isEmpty=1;


        system("pause");
        system("cls");
    }

    return retorno;
}

void printPeliculas(ePeliculas* list, int tamp)
{
    if(tamp>0 && list!=NULL)
    {
        for(int i=0; i<tamp; i++)
        {
            if(list[i].isEmpty==1)
            {
                printf("Identificador:%d\n  Titulo:%s\n  anio:%d\n nacionalidad:%s\n director:%s \n",list[i].indentificador,list[i].titulo,list[i].anio,list[i].nacionalidad,list[i].directores.nombre);
                printf("\n\n");
            }
        }
    }


}


int removePeliculas(ePeliculas* list, int tamp,int identificador)
{
    char auxIdentificador[20];
    int control;

    printPeliculas(list,tamp);
    printf("\n");
    while(!isNumbers("\ningrese identificador para dar de baja: ",auxIdentificador))
    {
        printf("error solo numeros. Reingrese\n");
    }
    identificador=atoi(auxIdentificador);
    control=buscarPelicula(list,tamp,identificador);
    if(control== -1)
    {
        printf("no se encontro el identificador\n");
        return -1;
    }
    printf("\nborrando datos espere.... \n- %d - %s - %d - %s - %s - %d\n\n",list[control].indentificador,list[control].titulo,list[control].anio,list[control].nacionalidad,list[control].directores.nombre);
    printf("\ndatos borrados...\n\n");
    list[control].isEmpty=2;
    printPeliculas(list,tamp);
    printf("\n\n");

    return 0;

}


int modifyPeliculas(ePeliculas* list,int tamp)
{
    char auxIdentificador[20],auxAnio[20],titulo[20],nacionalidad[20],director[20];
    int control,identificador,anio;
    char option;

    printEmployees(list,size);
    printf("\n");
    if(!isNumbers("\ningrese id para Modificar los datos: ",auxIdentificador))
    {
        printf("error solo numeros. Reingrese\n");
    }
    identificador=(auxIdentificador);
    control=buscarPelicula(list,tamp,identificador);
    if(control== -1)
    {
        printf("no se encontro el Identificador\n");
        return retorno;
    }
    else
    {

        printf("Desea modificar el nombre? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s'|| option =='S')
        {
            while(!onlyLetters("\ningrese nuevo nombre: ",name))
            {
                printf("***Error solo letras Reingrese***\n");

            }
            strcpy(list->name,name);
            printf("Modificacion de nombre finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }
        printf("Desea modificar el apellido? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s'|| option =='S')
        {
            while(!onlyLetters("\ningrese nuevo apellido: ",lastName))
            {
                printf("***Error solo letras Reingrese***\n");
            }
            strcpy(list->lastName,lastName);
            printf("Modificacion de apellido finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }

        printf("Desea modificar el sector? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s' || option =='S')
        {
            while(!isNumbers("\ningrese nuevo sector: ",auxSector))
            {
                printf("***Error solo numeros Reingrese***\n");
            }
            sector=atoi(auxSector);
            list->sector=sector;
            printf("Modificacion de sector finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }

        printf("Desea modificar el salario? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s' || option =='S')
        {
            while(!isNumbers("\ningrese nuevo salario: ",auxSalary))
            {
                printf("***Error solo numeros Reingrese***\n");
            }
            salary=atoi(auxSalary);
            list->salary=salary;
            printf("Modificacion de salario finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }

        retorno=0;

    }

    return retorno;
}
