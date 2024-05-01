#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} Cliente;

float calcularPrecio(int cantidad, float precio);

int main() {
    int cant_clientes;
    Cliente *clientes;

    srand(time(NULL));

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cant_clientes);

    clientes = (Cliente *)malloc(cant_clientes*sizeof(Cliente));

    for (int i = 0; i < cant_clientes; i++) {
        printf("Ingrese el nombre del cliente %d: ", i+1); fflush(stdin);

        clientes[i].NombreCliente = (char *)malloc(50*sizeof(char));

        gets(clientes[i].NombreCliente);

        clientes[i].ClienteID = i;

        clientes[i].CantidadProductosAPedir = rand()%5 + 1;

        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosAPedir*sizeof(Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j;
            clientes[i].Productos[j].Cantidad = rand()%10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
            clientes[i].Productos[j].PrecioUnitario = rand()%(100-10) + 10 + 1;
        }
    }

    for (int i = 0; i < cant_clientes; i++) {
        float sum=0;

        printf("Cliente %d:\n", i+1);

        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("ID: %d\n", clientes[i].ClienteID);
        printf("Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("Producto %d:\n", j+1);
            printf("ID: %d\n", clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("Precio Total: %.2f\n", calcularPrecio(clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario));
            sum += calcularPrecio(clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario);
        }

        printf("\nTOTAL A PAGAR: %.2f\n\n", sum);
    }

    return 0;
}

float calcularPrecio(int cantidad, float precio) {
    return cantidad*precio;
}