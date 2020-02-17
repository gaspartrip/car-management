#include "conio.h"
#include <time.h>
#include "menuGestionAdmin.h"

//->MODO ADMINISTRADOR

//MENU Y ENCABEZADOS

void menuGestionAdmin ()
{
    nodoVenta * listaVentas;
    inicListaVentas(&listaVentas);
    int op;
    char control='s';
    while (control=='s')
    {
        system("cls");
        encabezadoMenuVentasAdmin();
        printf("\n\n>Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&op);
        system("cls");
        encabezadoSubMenuVentas();
        printf("\n");
        switch (op)
        {
        case 1:
            iniciarMostrarListaVentasAdmin(&listaVentas);
            break;
        case 2:
            iniciarBorrarNodoEnListaVentasAdmin(&listaVentas);
            break;
        case 3:
            iniciarEstadisticasVentas_Admin(&listaVentas);
            break;
        case 4:
            iniciarMostrarUsuarios();
            break;
        case 5:
            iniciarBorrarUsuario();
            break;
        case 6:
            control='n';
            break;
        }
        system("cls");
    }
}

void encabezadoMenuVentasAdmin ()
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
    printf("\n%c *MODO ADMINISTRADOR*                                                                       %c",186,186);
    printf("\n%c [1] Mostrar ventas                                                                         %c",186,186);
    printf("\n%c [2] Quitar venta                                                                           %c",186,186);
    printf("\n%c [3] Estadisticas de ventas                                                                 %c",186,186);
    printf("\n%c [4] Mostrar usuarios                                                                       %c",186,186);
    printf("\n%c [5] Quitar usuario                                                                         %c",186,186);
    printf("\n%c [6] Salir                                                                                  %c",186,186);
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

void encabezadoSubMenuVentasAdmin ()
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
    printf("\n%c                                      %c MODO ADMINISTRADOR %c                              %c",186,186,186,186);
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

//MUESTRA DE TODAS LAS VENTAS

void iniciarMostrarListaVentasAdmin (nodoVenta ** listaVentas)
{
    cargarListaVentasDeArchivo(listaVentas);
    if ((*listaVentas)!=NULL)
    {
        printf("\n>Muestra de las ventas:\n");
        mostrarListaVentasAdmin((*listaVentas));
        printf("\n\n");
    }
    else
    {
        textcolor(8);
        printf("\n>No hay ventas cargadas. ");
        textcolor(15);
    }
    system("pause");
    borrarListaVentas(listaVentas);
}

void mostrarListaVentasAdmin (nodoVenta * listaVentas)
{
    nodoVenta * seg=listaVentas;
    while (seg!=NULL)
    {
        mostrarVentaAdmin(seg->miVenta);
        seg=seg->sig;
    }
}

void mostrarVentaAdmin (venta miVenta)
{
    int i;
    char marca[a_dim];
    cargarNombreMarca(marca,miVenta.miProducto.idMarca);
    printf("\n");
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("\n%c VENTA",254);
    printf("\nID: %d",miVenta.idVenta);
    printf("\nVendedor: %s",miVenta.nombreUsuario);
    printf("\nFecha: %d/%d/%d",miVenta.dia,miVenta.mes,miVenta.anio);
    printf("\n%c CLIENTE",254);
    printf("\nID: %d",miVenta.miCliente.idCliente);
    printf("\nDNI: %s",miVenta.miCliente.dni);
    printf("\nNombre y apellido: %s",miVenta.miCliente.nombreYApellido);
    printf("Telefono: %s",miVenta.miCliente.telefono);
    printf("\n%c AUTOMOVIL VENDIDO",254);
    printf("\nID: %d",miVenta.miProducto.idProducto);
    printf("\nMarca: %s",marca);
    printf("\nNombre: %s",miVenta.miProducto.nombre);
    printf("Km.: %0.2f",miVenta.miProducto.km);
    printf("\nPrecio: $%0.2f",miVenta.miProducto.precio);
    printf("\n");
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
}

//ELIMINACION DE UNA VENTA

void iniciarBorrarNodoEnListaVentasAdmin (nodoVenta ** listaVentas)
{
    int idVentaABorrar,eliminacion;
    cargarListaVentasDeArchivo(listaVentas);
    if ((*listaVentas)!=NULL)
    {
        printf("\n>Muestra de todas las ventas:\n");
        mostrarListaVentasAdmin((*listaVentas));
        printf("\n\n>Ingrese el ID de la venta a borrar: ");
        scanf("%d",&idVentaABorrar);
        eliminacion=borrarNodoVentaAdmin(listaVentas,idVentaABorrar);
        if (eliminacion)
        {
            guardarVentasEnArchivoNuevo(listaVentas);
            textcolor(8);
            printf("\n>Venta borrada. ");
            textcolor(15);
        }
        else
        {
            borrarListaVentas(listaVentas);
            textcolor(8);
            printf("\n>[ERROR] El ID de la venta ingresada no corresponde a ninguna venta. ");
            textcolor(15);
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay ventas cargadas. ");
        textcolor(15);
    }
    system("pause");
}

int borrarNodoVentaAdmin (nodoVenta ** listaVentas,int dato)
{
    int rta=0;
    nodoVenta * seg;
    nodoVenta * ante;
    if((*listaVentas)!=NULL && (*listaVentas)->miVenta.idVenta==dato)
    {
        devolverDisponibilidadAProducto((*listaVentas)->miVenta);
        quitarVentaAUsuarioAdmin((*listaVentas)->miVenta.nombreUsuario,(*listaVentas)->miVenta.miProducto.precio);
        nodoVenta * aux=(*listaVentas);
        (*listaVentas)=(*listaVentas)->sig;
        free(aux);
        rta=1;
    }
    else
    {
        seg=(*listaVentas);
        while(seg!=NULL && seg->miVenta.idVenta!=dato)
        {
            ante=seg;
            seg=seg->sig;
        }
        if(seg!=NULL && seg->miVenta.idVenta==dato)
        {
            ante->sig=seg->sig;
            devolverDisponibilidadAProducto(seg->miVenta);
            quitarVentaAUsuarioAdmin(seg->miVenta.nombreUsuario,seg->miVenta.miProducto.precio);
            free(seg);
            rta=1;
        }
    }
    return rta;
}

void quitarVentaAUsuarioAdmin (char miUsuario[],float precioVenta)
{
    usuario usuarioArchivo;
    FILE * archi=fopen(nombreArchivo,"r+b");
    int band=0;
    if (archi!=NULL)
    {
        while (band==0 && fread(&usuarioArchivo,sizeof(usuario),1,archi)>0)
        {
            if (strcmp(miUsuario,usuarioArchivo.nombre)==0)
            {
                band=1;
                usuarioArchivo.ventas=(usuarioArchivo.ventas)-1;
                usuarioArchivo.sumaVentas=(usuarioArchivo.sumaVentas)-precioVenta;
                fseek(archi,-1*(sizeof(usuario)),SEEK_CUR);
                fwrite(&usuarioArchivo,sizeof(usuario),1,archi);
            }
        }
        fclose(archi);
    }
}

//ESTADISTICAS

void iniciarEstadisticasVentas_Admin (nodoVenta ** listaVentas)
{
    cargarListaVentasDeArchivo(listaVentas);
    if ((*listaVentas)!=NULL)
    {
        int dia,mes,anio;
        int op=7;
        while (op<1 || op>4)
        {
            system("cls");
            encabezadoEstadisticas();
            printf("\n\n>Ingrese opcion: ");
            scanf("%d",&op);
            system("cls");
            encabezadoSubMenuEstadisticas();
            printf("\n");
            switch (op)
            {
            case 1:
                estadisticasVentas_Admin((*listaVentas));
                system("pause");
                break;
            case 2:
                printf("\n>Ingrese el dia: ");
                scanf("%d",&dia);
                printf(">Ingrese el mes: ");
                scanf("%d",&mes);
                printf(">Ingrese el a%co: ",164);
                scanf("%d",&anio);
                estadisticasVentasDia_Admin((*listaVentas),dia,mes,anio);
                system("pause");
                break;
            case 3:
                printf("\n>Ingrese el mes: ");
                scanf("%d",&mes);
                printf(">Ingrese el a%co: ",164);
                scanf("%d",&anio);
                estadisticasVentasMes_Admin((*listaVentas),anio,mes);
                system("pause");
                break;
            case 4:
                printf("\n>Ingrese el a%co: ",164);
                scanf("%d",&anio);
                estadisticasVentasAnio_Admin((*listaVentas),anio);
                system("pause");
                break;
            case 5:
                op=1;
                break;
            }
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay ventas cargadas. ");
        textcolor(15);
        system("pause");
    }
    borrarListaVentas(listaVentas);
}

void datosUsuarios (nodoVenta * listaVentas,char usuarioMasVentas[],int * cantidadUsuarioMasVentas,char usuarioMenosVentas[],int * cantidadUsuarioMenosVentas,int dia,int mes,int anio)
{
    int cantidadVentas,cantidadUsuarioMasVentas_Aux=0,cantidadUsuarioMenosVentas_Aux=999999;
    usuario usuarioArchivo;
    FILE * archi=fopen(nombreArchivo,"rb");
    if (archi!=NULL)
    {
        while (fread(&usuarioArchivo,sizeof(usuario),1,archi)>0)
        {
            cantidadVentas=retornarCantidadVentasUsuario(listaVentas,usuarioArchivo.nombre,dia,mes,anio);
            if (cantidadVentas>cantidadUsuarioMasVentas_Aux)
            {
                cantidadUsuarioMasVentas_Aux=cantidadVentas;
                strcpy(usuarioMasVentas,usuarioArchivo.nombre);
            }
            if (cantidadVentas<cantidadUsuarioMenosVentas_Aux)
            {
                cantidadUsuarioMenosVentas_Aux=cantidadVentas;
                strcpy(usuarioMenosVentas,usuarioArchivo.nombre);
            }
        }
    }
    (*cantidadUsuarioMasVentas)=cantidadUsuarioMasVentas_Aux;
    (*cantidadUsuarioMenosVentas)=cantidadUsuarioMenosVentas_Aux;
    fclose (archi);
}

int retornarCantidadVentasUsuario (nodoVenta * listaVentas,char nombreUsuario[],int dia,int mes,int anio)
{
    int rta=0;
    while (listaVentas!=NULL)
    {
        if (strcmp(listaVentas->miVenta.nombreUsuario,nombreUsuario)==0)
        {
            if (dia==0 && mes==0 && anio==0)
            {
                rta++;
            }
            else if (dia==listaVentas->miVenta.dia && mes==listaVentas->miVenta.mes && anio==listaVentas->miVenta.anio)
            {
                rta++;
            }
            else if (dia==0 && mes==listaVentas->miVenta.mes && anio==listaVentas->miVenta.anio)
            {
                rta++;
            }
            else if (dia==0 && mes==0 && anio==listaVentas->miVenta.anio)
            {
                rta++;
            }
        }
        listaVentas=listaVentas->sig;
    }
    return rta;
}

//--->ESTADISTICAS SIEMPRE

void estadisticasVentas_Admin (nodoVenta * listaVentas)
{
    nodoVenta * seg=listaVentas;
    //Contador de ventas/acumulador de ganancias
    float gananciasTotalVentas=0;
    int contadorTotalVentas=0;
    //Marca con mas/menos ventas
    int arregloDeContadores[7]= {0},idMarcaMasVendida,idMarcaMenosVendida;
    char marcaMasVendida[a_dim],marcaMenosVendida[a_dim];
    //Usuario con mas/menos ventas
    char usuarioMasVentas[a_dim],usuarioMenosVentas[a_dim];
    int cantidadUsuarioMasVentas,cantidadUsuarioMenosVentas;
    //Venta de mayor/menor precio
    float precioVentaMasCara=0,precioVentaMasBarata=seg->miVenta.miProducto.precio;
    venta ventaMasCara,ventaMasBarata;
    while (seg!=NULL)
    {
        contadorTotalVentas++;
        gananciasTotalVentas=gananciasTotalVentas+seg->miVenta.miProducto.precio;
        contadorMarcasMasYMenosVendidas(seg->miVenta.miProducto.idMarca,arregloDeContadores);
        if (seg->miVenta.miProducto.precio>=precioVentaMasCara)
        {
            precioVentaMasCara=seg->miVenta.miProducto.precio;
            ventaMasCara=seg->miVenta;
        }

        if (seg->miVenta.miProducto.precio<=precioVentaMasBarata)
        {
            precioVentaMasBarata=seg->miVenta.miProducto.precio;
            ventaMasBarata=seg->miVenta;
        }
        seg=seg->sig;
    }
    retornarIdMarcasMasYMenosVendidas(arregloDeContadores,&idMarcaMasVendida,&idMarcaMenosVendida);
    cargarNombreMarca(marcaMasVendida,idMarcaMasVendida);
    cargarNombreMarca(marcaMenosVendida,idMarcaMenosVendida);
    if (comprobarExistenciaUsuarios())
    {
        nodoVenta * aux=listaVentas;
        datosUsuarios(aux,usuarioMasVentas,&cantidadUsuarioMasVentas,usuarioMenosVentas,&cantidadUsuarioMenosVentas,0,0,0);
    }
    mostrarEstadisticasVentas_Admin(marcaMasVendida,marcaMenosVendida,ventaMasCara,ventaMasBarata,contadorTotalVentas,gananciasTotalVentas,usuarioMasVentas,cantidadUsuarioMasVentas,usuarioMenosVentas,cantidadUsuarioMenosVentas);
}

void mostrarEstadisticasVentas_Admin (char marcaMasVendida[],char marcaMenosVendida[],venta ventaMasCara,venta ventaMasBarata,int contadorTotalVentas,float gananciasTotalVentas,char usuarioMasVentas[],int cantidadUsuarioMasVentas,char usuarioMenosVentas[],int cantidadUsuarioMenosVentas)
{
    textcolor(10);
    printf("\n%c Reporte de estadisticas de ventas",254);
    textcolor(15);
    printf("\n\n%c Ventas: %i",205,contadorTotalVentas);
    printf("\n\n%c Suma total de la ganancia de todas las ventas: $%0.2f",205,gananciasTotalVentas);
    printf("\n\n%c Marca mas vendida: %s",205,marcaMasVendida);
    printf("\n\n%c Marca menos vendida: %s",205,marcaMenosVendida);
    if (comprobarExistenciaUsuarios())
    {
        printf("\n\n%c Usuario con mas ventas: %s (%i venta/s)",205,usuarioMasVentas,cantidadUsuarioMasVentas);
        printf("\n\n%c Usuario con menos ventas: %s (%i venta/s)",205,usuarioMenosVentas,cantidadUsuarioMenosVentas);
    }
    printf("\n\n>Venta de mayor precio:\n");
    mostrarVenta(ventaMasCara);
    printf("\n\n>Venta de menor precio:\n");
    mostrarVenta(ventaMasBarata);
    printf("\n\n");
}

//--->ESTADISTICAS DIA

void estadisticasVentasDia_Admin (nodoVenta * listaVentas,int dia,int mes,int anio)
{
    system("cls");
    encabezadoSubMenuEstadisticas();
    printf("\n");
    nodoVenta * seg=listaVentas;
    //Contador de ventas/acumulador de ganancias
    float gananciasTotalVentas=0;
    int contadorTotalVentas=0;
    //Marca con mas/menos ventas
    int arregloDeContadores[7]= {0},idMarcaMasVendida,idMarcaMenosVendida;
    char marcaMasVendida[a_dim],marcaMenosVendida[a_dim];
    //Usuario con mas/menos ventas
    char usuarioMasVentas[a_dim],usuarioMenosVentas[a_dim];
    int cantidadUsuarioMasVentas,cantidadUsuarioMenosVentas;
    //Venta de mayor/menor precio
    float precioVentaMasCara=0,precioVentaMasBarata=seg->miVenta.miProducto.precio;
    venta ventaMasCara,ventaMasBarata;
    while (seg!=NULL)
    {
        if (seg->miVenta.anio==anio && seg->miVenta.mes==mes && seg->miVenta.dia==dia)
        {
            contadorTotalVentas++;
            gananciasTotalVentas=gananciasTotalVentas+seg->miVenta.miProducto.precio;
            contadorMarcasMasYMenosVendidas(seg->miVenta.miProducto.idMarca,arregloDeContadores);
            if (seg->miVenta.miProducto.precio>=precioVentaMasCara)
            {
                precioVentaMasCara=seg->miVenta.miProducto.precio;
                ventaMasCara=seg->miVenta;
            }

            if (seg->miVenta.miProducto.precio<=precioVentaMasBarata)
            {
                precioVentaMasBarata=seg->miVenta.miProducto.precio;
                ventaMasBarata=seg->miVenta;
            }
        }
        seg=seg->sig;
    }
    retornarIdMarcasMasYMenosVendidas(arregloDeContadores,&idMarcaMasVendida,&idMarcaMenosVendida);
    cargarNombreMarca(marcaMasVendida,idMarcaMasVendida);
    cargarNombreMarca(marcaMenosVendida,idMarcaMenosVendida);
    if (comprobarExistenciaUsuarios())
    {
        nodoVenta * aux=listaVentas;
        datosUsuarios(aux,usuarioMasVentas,&cantidadUsuarioMasVentas,usuarioMenosVentas,&cantidadUsuarioMenosVentas,dia,mes,anio);
    }
    mostrarEstadisticasVentasDia_Admin(listaVentas,marcaMasVendida,marcaMenosVendida,ventaMasCara,ventaMasBarata,contadorTotalVentas,gananciasTotalVentas,usuarioMasVentas,cantidadUsuarioMasVentas,usuarioMenosVentas,cantidadUsuarioMenosVentas,dia,mes,anio);
}

void mostrarEstadisticasVentasDia_Admin (nodoVenta * listaVentas,char marcaMasVendida[],char marcaMenosVendida[],venta ventaMasCara,venta ventaMasBarata,int contadorTotalVentas,float gananciasTotalVentas,char usuarioMasVentas[],int cantidadUsuarioMasVentas,char usuarioMenosVentas[],int cantidadUsuarioMenosVentas,int dia,int mes,int anio)
{
    textcolor(10);
    if (contadorTotalVentas!=0)
    {
        printf("\n%c Reporte de estadisticas de ventas - %i/%i/%i",254,dia,mes,anio);
        textcolor(15);
        printf("\n\n%c Ventas: %i",205,contadorTotalVentas);
        printf("\n\n%c Suma total de la ganancia de todas las ventas: $%0.2f",205,gananciasTotalVentas);
        printf("\n\n%c Marca mas vendida: %s",205,marcaMasVendida);
        printf("\n\n%c Marca menos vendida: %s",205,marcaMenosVendida);
        if (comprobarExistenciaUsuarios())
        {
            printf("\n\n%c Usuario con mas ventas: %s (%i venta/s)",205,usuarioMasVentas,cantidadUsuarioMasVentas);
            printf("\n\n%c Usuario con menos ventas: %s (%i venta/s)",205,usuarioMenosVentas,cantidadUsuarioMenosVentas);
        }
        printf("\n\n>Venta de mayor precio:\n");
        mostrarVenta(ventaMasCara);
        printf("\n\n>Venta de menor precio:\n");
        mostrarVenta(ventaMasBarata);
        printf("\n\n");
    }
    else
    {
        textcolor(8);
        printf("\n>No hay ventas cargadas en esta fecha. ");
        textcolor(15);
    }
}

//--->ESTADISTICAS MES

void estadisticasVentasMes_Admin (nodoVenta * listaVentas,int anio,int mes)
{
    system("cls");
    encabezadoSubMenuEstadisticas();
    printf("\n");
    nodoVenta * seg=listaVentas;
    //Contador de ventas/acumulador de ganancias
    float gananciasTotalVentas=0;
    int contadorTotalVentas=0;
    //Marca con mas/menos ventas
    int arregloDeContadores[7]= {0},idMarcaMasVendida,idMarcaMenosVendida;
    char marcaMasVendida[a_dim],marcaMenosVendida[a_dim];
    //Usuario con mas/menos ventas
    char usuarioMasVentas[a_dim],usuarioMenosVentas[a_dim];
    int cantidadUsuarioMasVentas,cantidadUsuarioMenosVentas;
    //Venta de mayor/menor precio
    float precioVentaMasCara=0,precioVentaMasBarata=seg->miVenta.miProducto.precio;
    venta ventaMasCara,ventaMasBarata;
    while (seg!=NULL)
    {
        if (seg->miVenta.anio==anio && seg->miVenta.mes==mes)
        {
            contadorTotalVentas++;
            gananciasTotalVentas=gananciasTotalVentas+seg->miVenta.miProducto.precio;
            contadorMarcasMasYMenosVendidas(seg->miVenta.miProducto.idMarca,arregloDeContadores);
            if (seg->miVenta.miProducto.precio>=precioVentaMasCara)
            {
                precioVentaMasCara=seg->miVenta.miProducto.precio;
                ventaMasCara=seg->miVenta;
            }

            if (seg->miVenta.miProducto.precio<=precioVentaMasBarata)
            {
                precioVentaMasBarata=seg->miVenta.miProducto.precio;
                ventaMasBarata=seg->miVenta;
            }
        }
        seg=seg->sig;
    }
    retornarIdMarcasMasYMenosVendidas(arregloDeContadores,&idMarcaMasVendida,&idMarcaMenosVendida);
    cargarNombreMarca(marcaMasVendida,idMarcaMasVendida);
    cargarNombreMarca(marcaMenosVendida,idMarcaMenosVendida);
    if (comprobarExistenciaUsuarios())
    {
        nodoVenta * aux=listaVentas;
        datosUsuarios(aux,usuarioMasVentas,&cantidadUsuarioMasVentas,usuarioMenosVentas,&cantidadUsuarioMenosVentas,0,mes,anio);
    }
    mostrarEstadisticasVentasMes_Admin(listaVentas,marcaMasVendida,marcaMenosVendida,ventaMasCara,ventaMasBarata,contadorTotalVentas,gananciasTotalVentas,usuarioMasVentas,cantidadUsuarioMasVentas,usuarioMenosVentas,cantidadUsuarioMenosVentas,anio,mes);
}

void mostrarEstadisticasVentasMes_Admin (nodoVenta * listaVentas,char marcaMasVendida[],char marcaMenosVendida[],venta ventaMasCara,venta ventaMasBarata,int contadorTotalVentas,float gananciasTotalVentas,char usuarioMasVentas[],int cantidadUsuarioMasVentas,char usuarioMenosVentas[],int cantidadUsuarioMenosVentas,int anio,int mes)
{
    textcolor(10);
    if (contadorTotalVentas!=0)
    {
        printf("\n%c Reporte de estadisticas de ventas - %i/%i",254,mes,anio);
        textcolor(15);
        printf("\n\n%c Ventas: %i",205,contadorTotalVentas);
        printf("\n\n%c Suma total de la ganancia de todas las ventas: $%0.2f",205,gananciasTotalVentas);
        printf("\n\n%c Marca mas vendida: %s",205,marcaMasVendida);
        printf("\n\n%c Marca menos vendida: %s",205,marcaMenosVendida);
        if (comprobarExistenciaUsuarios())
        {
            printf("\n\n%c Usuario con mas ventas: %s (%i venta/s)",205,usuarioMasVentas,cantidadUsuarioMasVentas);
            printf("\n\n%c Usuario con menos ventas: %s (%i venta/s)",205,usuarioMenosVentas,cantidadUsuarioMenosVentas);
        }
        printf("\n\n>Venta de mayor precio:\n");
        mostrarVenta(ventaMasCara);
        printf("\n\n>Venta de menor precio:\n");
        mostrarVenta(ventaMasBarata);
        printf("\n\n");
    }
    else
    {
        textcolor(8);
        printf("\n>No hay ventas cargadas en esta fecha. ");
        textcolor(15);
    }
}

//--->ESTADISTICAS AÑO

void estadisticasVentasAnio_Admin (nodoVenta * listaVentas,int anio)
{
    system("cls");
    encabezadoSubMenuEstadisticas();
    printf("\n");
    nodoVenta * seg=listaVentas;
    //Contador de ventas/acumulador de ganancias
    float gananciasTotalVentas=0;
    int contadorTotalVentas=0;
    //Marca con mas/menos ventas
    int arregloDeContadores[7]= {0},idMarcaMasVendida,idMarcaMenosVendida;
    char marcaMasVendida[a_dim],marcaMenosVendida[a_dim];
    //Usuario con mas/menos ventas
    char usuarioMasVentas[a_dim],usuarioMenosVentas[a_dim];
    int cantidadUsuarioMasVentas,cantidadUsuarioMenosVentas;
    //Venta de mayor/menor precio
    float precioVentaMasCara=0,precioVentaMasBarata=seg->miVenta.miProducto.precio;
    venta ventaMasCara,ventaMasBarata;
    while (seg!=NULL)
    {
        if (seg->miVenta.anio==anio)
        {
            contadorTotalVentas++;
            gananciasTotalVentas=gananciasTotalVentas+seg->miVenta.miProducto.precio;
            contadorMarcasMasYMenosVendidas(seg->miVenta.miProducto.idMarca,arregloDeContadores);
            if (seg->miVenta.miProducto.precio>=precioVentaMasCara)
            {
                precioVentaMasCara=seg->miVenta.miProducto.precio;
                ventaMasCara=seg->miVenta;
            }

            if (seg->miVenta.miProducto.precio<=precioVentaMasBarata)
            {
                precioVentaMasBarata=seg->miVenta.miProducto.precio;
                ventaMasBarata=seg->miVenta;
            }
        }
        seg=seg->sig;
    }
    retornarIdMarcasMasYMenosVendidas(arregloDeContadores,&idMarcaMasVendida,&idMarcaMenosVendida);
    cargarNombreMarca(marcaMasVendida,idMarcaMasVendida);
    cargarNombreMarca(marcaMenosVendida,idMarcaMenosVendida);
    if (comprobarExistenciaUsuarios())
    {
        nodoVenta * aux=listaVentas;
        datosUsuarios(aux,usuarioMasVentas,&cantidadUsuarioMasVentas,usuarioMenosVentas,&cantidadUsuarioMenosVentas,0,0,anio);
    }
    mostrarEstadisticasVentasAnio_Admin(listaVentas,marcaMasVendida,marcaMenosVendida,ventaMasCara,ventaMasBarata,contadorTotalVentas,gananciasTotalVentas,usuarioMasVentas,cantidadUsuarioMasVentas,usuarioMenosVentas,cantidadUsuarioMenosVentas,anio);
}

void mostrarEstadisticasVentasAnio_Admin (nodoVenta * listaVentas,char marcaMasVendida[],char marcaMenosVendida[],venta ventaMasCara,venta ventaMasBarata,int contadorTotalVentas,float gananciasTotalVentas,char usuarioMasVentas[],int cantidadUsuarioMasVentas,char usuarioMenosVentas[],int cantidadUsuarioMenosVentas,int anio)
{
    textcolor(10);
    if (contadorTotalVentas!=0)
    {
        printf("\n%c Reporte de estadisticas de ventas - %i",254,anio);
        textcolor(15);
        printf("\n\n%c Ventas: %i",205,contadorTotalVentas);
        printf("\n\n%c Suma total de la ganancia de todas las ventas: $%0.2f",205,gananciasTotalVentas);
        printf("\n\n%c Marca mas vendida: %s",205,marcaMasVendida);
        printf("\n\n%c Marca menos vendida: %s",205,marcaMenosVendida);
        if (comprobarExistenciaUsuarios())
        {
            printf("\n\n%c Usuario con mas ventas: %s (%i venta/s)",205,usuarioMasVentas,cantidadUsuarioMasVentas);
            printf("\n\n%c Usuario con menos ventas: %s (%i venta/s)",205,usuarioMenosVentas,cantidadUsuarioMenosVentas);
        }
        printf("\n\n>Venta de mayor precio:\n");
        mostrarVenta(ventaMasCara);
        printf("\n\n>Venta de menor precio:\n");
        mostrarVenta(ventaMasBarata);
        printf("\n\n");
    }
    else
    {
        textcolor(8);
        printf("\n>No hay ventas cargadas en esta fecha. ");
        textcolor(15);
    }
}

//MUESTRA DE TODOS LOS USUARIOS

void iniciarMostrarUsuarios ()
{
    if (comprobarExistenciaUsuarios())
    {
        usuario miUsuario;
        FILE * archi=fopen(nombreArchivo,"rb");
        if (archi!=NULL)
        {
            printf("\n>Muestra de todos los usuarios:\n");
            while (fread(&miUsuario,sizeof(usuario),1,archi)>0)
                mostrarUsuario(miUsuario);
            printf("\n\n");
            fclose(archi);
        }
        else
        {
            textcolor(8);
            printf("\n\n>[ERROR] Ocurrio un problema al cargar el archivo de los usuarios. ");
            textcolor(15);
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay usuarios cargados. ");
        textcolor(15);
    }
    system("pause");
}

int comprobarExistenciaUsuarios ()
{
    usuario miUsuario;
    int rta=0;
    FILE * archi=fopen(nombreArchivo,"rb");
    if (archi!=NULL)
    {
        if (fread(&miUsuario,sizeof(usuario),1,archi)>0)
            rta=1;
    }
    return rta;
}

void mostrarUsuario (usuario miUsuario)
{
    int i;
    printf("\n");
    for(i=0; i<65; i++)
    {
        printf("%c",205);
    }
    printf("\n%c %s | Ventas: %i | Suma total vendida: $%0.2f",254,miUsuario.nombre,miUsuario.ventas,miUsuario.sumaVentas);
    printf("\n");
    for(i=0; i<65; i++)
    {
        printf("%c",205);
    }
}

//ELIMINACION DE UN USUARIO

void iniciarBorrarUsuario ()
{
    if (comprobarExistenciaUsuarios())
    {
        FILE * archi=fopen(nombreArchivo,"rb");
        if (archi!=NULL)
        {
            usuario usuarioArchivo;
            char nombreUsuario[a_dim];
            int band=0,i=0,cantidadDeUsuarios=contarCantidadUsuarios();
            usuario * arregloDeUsuarios;
            arregloDeUsuarios=malloc(cantidadDeUsuarios*sizeof(usuario));
            iniciarMostrarUsuarios();
            printf("\n>Ingrese el -nombre de usuario- del usuario a borrar: ");
            fflush(stdin);
            scanf("%s",nombreUsuario);
            while (fread(&usuarioArchivo,sizeof(usuario),1,archi)>0)
            {
                if (strcmp(&usuarioArchivo.nombre,nombreUsuario)!=0)
                {
                    arregloDeUsuarios[i]=usuarioArchivo;
                    i++;
                }
                else
                    band=1;
            }
            fclose(archi);
            if (band==1)
            {
                cargarListaUsuariosNueva(arregloDeUsuarios,i);
                textcolor(8);
                printf("\n>Usuario borrado. ");
                textcolor(15);
            }
            else
            {
                textcolor(8);
                printf("\n>[ERROR] No se encontro el usuario a borrar. ");
                textcolor(15);
            }
        }
        else
        {
            textcolor(8);
            printf("\n>[ERROR] Ocurrio un problema al cargar el archivo de los usuarios. ");
            textcolor(15);
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay usuarios cargados. ");
        textcolor(15);
    }
    system("pause");
}

int contarCantidadUsuarios ()
{
    int contador=0;
    usuario miUsuario;
    FILE * archi=fopen(nombreArchivo,"rb");
    if (archi!=NULL)
    {
        while (fread(&miUsuario,sizeof(usuario),1,archi)>0)
            contador++;
        fclose(archi);
    }
    return contador;
}

void cargarListaUsuariosNueva (usuario arregloDeUsuarios[],int validos)
{
    int i=0;
    FILE * archi=fopen(nombreArchivo,"wb");
    if (archi!=NULL)
    {
        while (i<validos)
        {
            fwrite(&arregloDeUsuarios[i],sizeof(usuario),1,archi);
            i++;
        }
        fclose(archi);
    }
}
