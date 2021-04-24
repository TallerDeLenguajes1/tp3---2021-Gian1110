// definicion de librerias a usar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *TiposProductos[]= {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
//definicion de estructuras a usar
typedef struct Producto
{
    int ProductoID; //numerado en ciclo iterativo
    int cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;
typedef struct Cliente
{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”   
}Cliente;

//definicion de funciones a usar
int cantidadClientes();
Cliente * cargar (int);
Cliente ingresar(int);
float costoTotal (Producto);
void mostrar(Cliente *, int);
// menu principal
void main()
{
    int cantidadClien = 0;
    Cliente *cl;
    cantidadClien = cantidadClientes();
    cl = cargar(cantidadClien);
    mostrar(cl,cantidadClien);
}
//desarrollo de funciones
int cantidadClientes()
{
    int cantidad=0;
    printf("ingrese la cantidad de clientes:\n");
    scanf("%d",&cantidad);
    return cantidad;
}

Cliente * cargar (int cantidad)
{

    Cliente *puntero;
    puntero= (Cliente *) malloc(sizeof(Cliente)*cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        puntero[sizeof(Cliente)*i] = ingresar (i+1); 
    }
    return puntero;
}
Cliente ingresar(int id)
{
    Cliente nuevo;
    char nombre[40];
    nuevo.ClienteID = id;
    nuevo.NombreCliente = (char *) malloc(sizeof(char)*40);
    printf("\ningrese el nombre:");
    scanf("%s",nuevo.NombreCliente);
    nuevo.CantidadProductosAPedir = (int) rand() % 5 +1;
    printf("%d\n",nuevo.CantidadProductosAPedir);
    nuevo.Productos = (Producto *) malloc(sizeof(Producto*) * nuevo.CantidadProductosAPedir);
    for (int i = 0; i < nuevo.CantidadProductosAPedir; i++) //cargaa los nuevos productos
    {
        nuevo.Productos[i].ProductoID=i;
        nuevo.Productos[i].cantidad = rand() %10 +1;
        int x = rand() % 5;
        nuevo.Productos[i].TipoProducto = (char *) malloc(sizeof(char*) * strlen(TiposProductos[x]));
        strcpy(nuevo.Productos[i].TipoProducto,TiposProductos[x]);   
        nuevo.Productos[i].PrecioUnitario = (float) (rand() % 910 + 1000)/10;
    }
    return nuevo;
}

float costoTotal (Producto pro1)
{
    return pro1.cantidad * pro1.PrecioUnitario;
}

void mostrar(Cliente *Client, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        int direccion = i * sizeof(Cliente);
        printf("\n\n----- el cliente N %d-----\n",i+1);
        printf("el ID del cliente es: %d\n",Client[direccion].ClienteID);
        printf("el nombre del cliente es: %s\n",Client[direccion].NombreCliente);
        printf("los productos comprados por el cliente son:\n");
        for (int j = 0; j < Client[direccion].CantidadProductosAPedir; j++)
        {
            printf("el producto es: %s\n",Client[direccion].Productos[j].TipoProducto);
            printf("se compro la cantidad: %d\n",Client[direccion].Productos[j].cantidad);
            printf("tiene un costo de %f\n",costoTotal(Client[direccion].Productos[j]));
        }
        
    }
    
     
}