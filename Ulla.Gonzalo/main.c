#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define TAMP 2
typedef struct
{
    char descripcion[20];
    float importe;
    int idCategoria;
    int isEmpty;
} eJuego;

typedef struct
{
    int id;
    char descripcion[51];

} eCategoria;

typedef struct
{
int codigo;
  char nombre[20];
  char sexo;
  int isEmpty;
  int telefono;
} eCliente;

typedef struct
{
  int codigoJuego;
  int codigoCliente;
  //eFecha fechas;
} eAlquileres;


int addCliente(eCliente* list, int tamp,int* pId);
int buscarLibre(eCliente* lista, int tamp);
int inicializarClientes(eCliente* lista, int tamc);
void inicializarJuegos(eJuego* juegos, int tamj);
int removeCliente(eCliente* list, int tamp,int codigo);
void printClientes(eCliente* list, int tamp);
int buscarClientes(eCliente* lista, int tamp, int codigo);
int modifyClientes(eCliente* list,int tamp,int codigo);

int main()
{

    char seguir='s';
     int codigoCliente=1;
     int flag=0;
     int add,i;

    eCliente clientes[TAMP];

    //eDirector directores[TAMD];

   i= inicializarClientes(clientes,TAMP);

    do
    {
        switch(menu())
        {
        case 1:
            add=addCliente(clientes,TAMP,&codigoCliente);
            if(add==0)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
            break;
        case 2:
            system("pause");
            break;
        case 3:
            if(flag==1)
            {
            removeCliente(clientes,TAMP,codigoCliente);
            }
            else
            {
                printf("error datos no cargados");
            }
        break;
        case 4:
            if(flag==1)
            {
            printClientes(clientes,TAMP);
            }
            else
            {
                printf("error datos no cargados");
            }
            system("pause");
            break;
        case 5:
            system("pause");
            break;
        case 6:
            break;

        }
    }
    while(seguir == 's');


    return 0;
}

void inicializarJuegos(eJuego* juegos, int tamj)
{

    for(int i=0; i < tamj; i++)
    {

        juegos[i].isEmpty = 1;
    }

}


int inicializarClientes(eCliente* list, int tamp)
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

int buscarLibre(eCliente* lista, int tamp)
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

int addCliente(eCliente* list, int tamp,int* pId)
{
    int itsfree,existe;
    int codigoCliente= *pId;
    char nombre[51],auxTelefono[21];
    char sexo;
    int retorno= -1,telefono;
    itsfree=buscarLibre(list,tamp);
    eCliente nuevocliente;

    if(itsfree == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        nuevocliente.codigo=codigoCliente;
        while(!onlyLetters("\ningrese Nombre: ",nombre))
        {
            printf("***Error solo numeros Reingrese***\n");

        }

         printf("\ningrese sexo: ");
         fflush(stdin);
         scanf("%c",&sexo);
      /**  while(sexo!= 's' || sexo!= 'f')
        {
            printf("***Error solo letras Reingrese***n");
        }*/

        while(!isNumbers("\ningrese telefono sin lineas: ",auxTelefono))
        {
            printf("***Error solo numeros Reingrese***\n");

        }
        telefono=atoi(auxTelefono);


        retorno=0;


        list[itsfree].sexo=sexo;
        strcpy( list[itsfree].nombre,nombre);
        list[itsfree].telefono=telefono;
        nuevocliente.isEmpty=0;
        list[itsfree]=nuevocliente;
        *pId = codigoCliente + 1;

        system("pause");
        system("cls");
    }

    return retorno;
}

int removeCliente(eCliente* list, int tamp,int codigo)
{

    int control;


    printClientes(list,tamp);
    printf("\n");
    printf("ingrese codigo para dar de baja: ");
    scanf("%d",&codigo);

    control=buscarClientes(list,tamp,codigo);
    if(control== -1)
    {
        printf("no se encontro el codigo\n");
        return -1;
    }
    printf("\nborrando datos espere.... \n- %d - %s - %d - %s - %s - %d\n\n",list[control].codigo,list[control].nombre,list[control].sexo,list[control].telefono);
    printf("\ndatos borrados...\n\n");
    list[control].isEmpty=0;
    printClientes(list,tamp);
    printf("\n\n");

    return 0;

}


void printClientes(eCliente* list, int tamp)
{
    if(tamp>0 && list!=NULL)
    {
        for(int i=0; i<tamp; i++)
        {
            if(list[i].isEmpty==1)
            {
                printf("\ncodigo:%d\n  Nombre:%s\n  sexo:%c\n telefono:%d\n",list[i].codigo,list[i].nombre,list[i].sexo,list[i].telefono);
                printf("\n\n");
            }
        }
    }


}

int buscarClientes(eCliente* lista, int tamp, int codigo)
{
    int indice = -1;

    for(int i=0; i < tamp; i++)
    {

        if(lista[i].codigo == codigo && lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;

}



int modifyClientes(eCliente* list,int tamp, int codigo)
{

    char option;
    int control,telefono;
    char nombre[51],auxtelefono[21],auxCodigo[20];
    int retorno=-1;
    char sexo;


    printClientes(list,tamp);
    printf("\n");
    if(!isNumbers("\ningrese codigo para Modificar los datos: ",auxCodigo))
    {
        printf("error solo numeros. Reingrese\n");
    }
    codigo=atoi(auxCodigo);
    control=buscarClientes(list,tamp,codigo);
    if(control== -1)
    {
        printf("no se encontro el codigo\n");
        return retorno;
    }
    else
    {
        printf("Desea modificar el nombre? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s'|| option =='S')
        {
            while(!onlyLetters("\ningrese nuevo nombre: ",nombre))
            {
                printf("***Error solo letras Reingrese***\n");

            }
            strcpy(list->nombre,nombre);
            printf("Modificacion de nombre finalizada\n");
        }
        else
        {
            printf("\nModificacion no realizada\n");
        }
        printf("Desea modificar el sexo? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s'|| option =='S')
        {
        printf("\ningrese sexo: ");
         fflush(stdin);
         scanf("%c",&sexo);
         list->sexo=sexo;
        printf("Modificacion de sexo finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }

        printf("Desea modificar el telefono? S/N\n");
        fflush(stdin);
        scanf("%c",&option);
        if(option=='s' || option =='S')
        {
            while(!isNumbers("\ningrese nuevo telefono: ",auxtelefono))
            {
                printf("***Error solo numeros Reingrese***\n");
            }
            telefono=atoi(auxtelefono);
            list->telefono=telefono;
            printf("Modificacion de telefono finalizada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }


         retorno=0;

    }
    return retorno;
}
