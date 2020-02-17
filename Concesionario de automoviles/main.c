#include <stdio.h>
#include <stdlib.h>
#include "menuSesionUsuario.h"

int main()
{
    int opcionMenu;
    char control='s';
    while (control=='s')
    {
        menuPrincipal(); //ENCABEZADO - [1] Iniciar sesion [2] Crear una cuenta [3] Salir
        printf("\n\n>Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&opcionMenu);
        system("cls");
        switch(opcionMenu)
        {
        case 1:
            menuInicioSesionUsuario(); //->LIBRERIA - menuSesionUsuario.h
            break;
        case 2:
            menuCreacionUsuario(); //->LIBRERIA - menuSesionUsuario.h
            break;
        case 3:
            control='n';
            break;
        }
        system("cls");
    }
    return 0;
}
