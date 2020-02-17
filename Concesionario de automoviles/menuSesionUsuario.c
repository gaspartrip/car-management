#include <windows.h>
#include "conio.h"
#include "menuSesionUsuario.h"
#include "menuGestionAdmin.h"

//ENCABEZADO - [1] Iniciar sesion [2] Crear una cuenta [3] Salir

void menuPrincipal ()
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
    printf("\n%c [1] Iniciar sesion                                                                         %c",186,186);
    printf("\n%c [2] Crear una cuenta                                                                       %c",186,186);
    printf("\n%c [3] Salir                                                                                  %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
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
}

//INICIO SESION

void menuInicioSesionUsuario ()
{
    int i=0,band=1;
    char op,pass;
    usuario miUsuario;
    encabezadoMenuInicioSesionUsuario();
    printf("\n\n>Ingrese su nombre de usuario: ");
    fflush(stdin);
    scanf("%s",miUsuario.nombre);
    printf(">Ingrese su contrase%ca: ",164);
    while (band==1 && i<a_dim)
    {
        fflush(stdin);
        pass=getch();
        if (pass!=13) //13=ENTER EN CODIGO ASCII
        {
            miUsuario.pass[i]=pass;
            printf("*");
        }
        else
        {
            band=0;
            miUsuario.pass[i]=NULL;
        }
        i++;
    }
    if (strcmp(miUsuario.nombre,"admin")==0 && strcmp(miUsuario.pass,"admin")==0)
    {
        menuGestionAdmin(); //->LIBRERIA - menuGestionAdmin.h
    }
    else
    {
        if (comprobarDatosUsuario(miUsuario))
            menuGestion(miUsuario);
        else
        {
            textcolor(8);
            printf("\n\n>Nombre de usuario o contrase%ca incorrecto/a. Ingrese la tecla 's' para volver a intentar u otra tecla para volver al menu: ",164);
            textcolor(15);
            fflush(stdin);
            scanf("%c",&op);
            if (op=='s')
            {
                system("cls");
                menuInicioSesionUsuario(); //->LIBRERIA - menuGestion.h
            }
        }
    }
}

void encabezadoMenuInicioSesionUsuario ()
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
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                   %c INICIAR SESION %c                                       %c",186,186,186,186);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
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
}

int comprobarDatosUsuario (usuario miUsuario)
{
    int rta=0;
    usuario usuarioArchivo;
    FILE * archi=fopen(nombreArchivo,"rb");
    if (archi!=NULL)
    {
        while (rta==0 && fread(&usuarioArchivo,sizeof(usuario),1,archi)>0)
        {
            if (strcmp(miUsuario.nombre,usuarioArchivo.nombre)==0 && strcmp(miUsuario.pass,usuarioArchivo.pass)==0)
                rta=1;
        }
        fclose(archi);
    }
    return rta;
}

//CREACION CUENTA

void menuCreacionUsuario ()
{
    int i=0,band=1;
    char op,pass;
    encabezadoMenuCreacionUsuario();
    usuario miUsuario;
    miUsuario.ventas=0;
    miUsuario.sumaVentas=0;
    printf("\n\n>Ingrese su nombre de usuario: ");
    fflush(stdin);
    scanf("%s",miUsuario.nombre);
    if (!comprobarExistenciaUsuario(miUsuario))
    {
        printf(">Ingrese su contrase%ca: ",164);
        while (band==1 && i<a_dim)
        {
            fflush(stdin);
            pass=getch();
            if (pass!=13)
            {
                miUsuario.pass[i]=pass;
                printf("*");
            }
            else
            {
                band=0;
                miUsuario.pass[i]=NULL;
            }
            i++;
        }
        FILE * archi;
        archi=fopen(nombreArchivo,"ab");
        if (archi!=NULL)
        {
            fwrite(&miUsuario,sizeof(usuario),1,archi);
            fclose(archi);
            textcolor(8);
            printf("\n\n>Cuenta creada. ");
            system("pause");
            textcolor(15);
        }
    }
    else
    {
        textcolor(8);
        printf("\n>Nombre de usuario ya existente. Ingrese la tecla 's' para volver al registro de cuenta u otra tecla para volver al menu: ");
        textcolor(15);
        fflush(stdin);
        scanf("%c",&op);
        if (op=='s')
        {
            system("cls");
            menuCreacionUsuario();
        }
    }
}

void encabezadoMenuCreacionUsuario ()
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
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                   %c CREAR UNA CUENTA %c                                     %c",186,186,186,186);
    printf("\n%c                                                                                            %c",186,186);
    printf("\n%c                                                                                            %c",186,186);
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
}

int comprobarExistenciaUsuario (usuario miUsuario)
{
    int rta=0;
    usuario usuarioArchivo;
    FILE * archi;
    archi=fopen(nombreArchivo,"rb");
    if (archi!=NULL)
    {
        while (rta==0 && fread(&usuarioArchivo,sizeof(usuario),1,archi)>0)
        {
            if (strcmp(miUsuario.nombre,usuarioArchivo.nombre)==0)
                rta=1;
        }
        fclose(archi);
    }
    return rta;
}
