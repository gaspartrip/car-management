#include "conio.h"
#include "menuGestion.h"

void menuGestion (usuario miUsuario)
{
    int opcionMenu;
    char control='s';
    while (control=='s')
    {
        system("cls");
        encabezadoMenuGestion(miUsuario); //ENCABEZADO - [1] Automoviles [2] Clientes [3] Ventas [4] Cerrar sesion
        printf("\n\n>Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&opcionMenu);
        system("cls");
        switch(opcionMenu)
        {
        case 1:
            menuProductos(); //->LIBRERIA: menuProductosClientesVentas.h
            break;
        case 2:
            menuClientes(); //->LIBRERIA menuProductosClientesVentas.h
            break;
        case 3:
            menuVentas(miUsuario); //->LIBRERIA menuProductosClientesVentas.h
            break;
        case 4:
            control='n';
            break;
        }
        system("cls");
    }
}

void encabezadoMenuGestion (usuario miUsuario)
{
    int i;
    textcolor(15);
    printf("%c",201);
    textcolor(9);
    for(i=0; i<92; i++)
    {
        printf("%c",205);
    }
    textcolor(15);
    printf("%c",187);
    textcolor(10);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c SOFTWARE DE GESTION %c CONCESIONARIO DE AUTOMOVILES                                         %c",186,254,186);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c [1] Automoviles                                                                            %c",186,186);
    printf("\n%c [2] Clientes                                                                               %c",186,186);
    printf("\n%c [3] Ventas                                                                                 %c",186,186);
    printf("\n%c [4] Cerrar sesion                                                                          %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
    textcolor(15);
    printf("\n%c",200);
    textcolor(9);
    for(i=0; i<92; i++)
    {
        printf("%c",205);
    }
    textcolor(15);
    printf("%c",188);
    textcolor(9);
    printf("\n\n %c",254);
    textcolor(10);
    printf(" Usuario: ");
    textcolor(9);
    printf("%s",miUsuario.nombre);
    textcolor(15);
}
