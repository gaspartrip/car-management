#include "conio.h"
#include <time.h>
#include "menuProductosClientesVentas.h"

const char nombreArchivoProductos[15]= {"productos.bin"};
const char nombreArchivoClientes[15]= {"clientes.bin"};
const char nombreArchivoVentas[15]= {"ventas.bin"};
const char nombreArchivo[15]= {"usuarios.bin"};

//->PRODUCTOS - Forma de trabajo: Estructura compuesta mediante el uso de un arreglo de arboles binarios.

//MENU Y ENCABEZADOS

void menuProductos ()
{
    int dim=7,op;
    char control='s';
    nodoArbolProducto * arregloArbolesProductos[dim];
    inicArregloArbolesProductos(arregloArbolesProductos,dim);
    while (control=='s')
    {
        encabezadoMenuProductos();
        printf("\n\n>Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&op);
        system("cls");
        encabezadoSubMenuProductos();
        printf("\n");
        switch (op)
        {
        case 1:
            cargarArregloArbolesProductos(arregloArbolesProductos,dim);
            guardarProductosEnArchivo(arregloArbolesProductos,dim);
            break;
        case 2:
            iniciarBorrarNodoEnArregloArbolesProductos(arregloArbolesProductos,dim);
            break;
        case 3:
            iniciarModificarNodoEnArregloArbolesProductos(arregloArbolesProductos,dim);
            break;
        case 4:
            iniciarMostrarArregloArbolesProductos(arregloArbolesProductos,dim);
            break;
        case 5:
            control='n';
            break;
        }
        system("cls");
    }
}

void encabezadoMenuProductos ()
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
    printf("\n%c [1] Agregar automoviles                                                                    %c",186,186);
    printf("\n%c [2] Quitar automovil                                                                       %c",186,186);
    printf("\n%c [3] Modificar automovil                                                                    %c",186,186);
    printf("\n%c [4] Mostrar automoviles                                                                    %c",186,186);
    printf("\n%c [5] Volver                                                                                 %c",186,186);
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

void encabezadoSubMenuProductos ()
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
    printf("\n%c                                      %c AUTOMOVILES %c                                       %c",186,186,186,186);
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

//ALTA DE NODOS

void inicArregloArbolesProductos (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    int i;
    for (i=0; i<dim; i++)
        arregloArbolesProductos[i]=NULL;
}

void cargarArregloArbolesProductos (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    producto miProducto;
    nodoArbolProducto * nuevoNodo;
    int pos,comprobacion,idProducto=retornarIdMasGrande_Producto();
    char control='s';
    while (control=='s')
    {
        system("cls");
        encabezadoSubMenuProductos();
        printf("\n");
        comprobacion=cargarProducto(&miProducto,arregloArbolesProductos,dim,&idProducto);
        if (comprobacion)
        {
            crearNodoProducto(&nuevoNodo,miProducto);
            pos=miProducto.idMarca;
            arregloArbolesProductos[pos]=insertarUnNodoAlArbolProductos(arregloArbolesProductos[pos],nuevoNodo);
            textcolor(8);
            printf("\n>Carga exitosa. Desea seguir ingresando automoviles? Ingrese la tecla 's' para seguir u otra tecla para volver al menu de automoviles: ");
            textcolor(15);
            fflush(stdin);
            scanf("%c",&control);
        }
        else
        {
            textcolor(8);
            printf(">Ingrese la tecla 's' para seguir ingresando automoviles u otra tecla para volver al menu de automoviles: ");
            textcolor(15);
            fflush(stdin);
            scanf("%c",&control);
        }
    }
}

int cargarProducto (producto * miProducto,nodoArbolProducto * arregloArbolesProductos[],int dim,int * idProducto)
{
    int rta;
    producto aux;
    aux.idProducto=(*idProducto)+1;
    printf("\n>ID del automovil: %i. ",aux.idProducto);
    system("pause");
    printf(">Ingrese el ID de la marca del automovil [0: Chevrolet | 1: Citroen | 2: Fiat | 3: Ford | 4: Honda | 5: Peugeot | 6: Otros]: ");
    scanf("%i",&aux.idMarca);
    if (aux.idMarca<7 && aux.idMarca>=0)
    {
        printf(">Ingrese el nombre del automovil: ");
        fflush(stdin);
        fgets(aux.nombre,a_dim,stdin);
        printf(">Ingrese los km. del automovil: ");
        scanf("%f",&aux.km);
        printf(">Ingrese el precio del automovil: ");
        scanf("%f",&aux.precio);
        (*idProducto)=(*idProducto)+1;
        rta=1;
    }
    else
    {
        textcolor(8);
        printf("\n>[ERROR] El ID de marca del automovil ingresado es invalido.\n");
        textcolor(15);
        rta=0;
    }
    (*miProducto)=aux;
    return rta;
}

int retornarIdMasGrande_Producto ()
{
    int rta,idMasGrande; //Funcion que retorna el numero ID mas grande dentro del archivo. Si el archivo no existe o no tiene elementos, retorna 0.
    producto archivoProducto;
    FILE * archi=fopen(nombreArchivoProductos,"rb");
    if (archi!=NULL)
    {
        fread(&archivoProducto,sizeof(producto),1,archi);
        idMasGrande=archivoProducto.idProducto;
        if (!feof(archi))
        {
            while (fread(&archivoProducto,sizeof(producto),1,archi)>0)
            {
                if (archivoProducto.idProducto>idMasGrande)
                {
                    idMasGrande=archivoProducto.idProducto;
                }
            }
            rta=idMasGrande;
        }
        else
            rta=0;
        fclose(archi);
    }
    else
        rta=0;
    return rta;
}

int buscarNodoEnArbolProductos_PorId (nodoArbolProducto * arbol,int dato)
{
    int rta=0;
    if (arbol!=NULL)
    {
        if (dato==arbol->miProducto.idProducto)
            rta=1;
        else
        {
            if (dato<arbol->miProducto.idProducto)
                rta=buscarNodoEnArbolProductos_PorId(arbol->izq,dato);
            else
                rta=buscarNodoEnArbolProductos_PorId(arbol->der,dato);
        }
    }
    return rta;
}

void crearNodoProducto (nodoArbolProducto ** nuevoNodo,producto miProducto)
{
    (*nuevoNodo)=malloc(sizeof(nodoArbolProducto));
    (*nuevoNodo)->miProducto=miProducto;
    (*nuevoNodo)->izq=NULL;
    (*nuevoNodo)->der=NULL;
}

nodoArbolProducto * insertarUnNodoAlArbolProductos (nodoArbolProducto * arbolProductos,nodoArbolProducto * nuevoNodo)
{
    if (arbolProductos==NULL)
        arbolProductos=nuevoNodo;
    else
    {
        if (nuevoNodo->miProducto.idProducto>=arbolProductos->miProducto.idProducto)
            arbolProductos->der=insertarUnNodoAlArbolProductos(arbolProductos->der,nuevoNodo);
        else
            arbolProductos->izq=insertarUnNodoAlArbolProductos(arbolProductos->izq,nuevoNodo);
    }
    return arbolProductos;
}

//CARGA Y GUARDADO EN ARCHIVO

void guardarProductosEnArchivo (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    int i;
    producto miProducto;
    FILE * archi=fopen(nombreArchivoProductos,"ab");
    if (archi!=NULL)
    {
        for (i=0; i<dim; i++)
        {
            while (arregloArbolesProductos[i]!=NULL)
            {
                miProducto=arregloArbolesProductos[i]->miProducto;
                fwrite(&miProducto,sizeof(producto),1,archi);
                arregloArbolesProductos[i]=borrarNodoEnArbolProductos_PorIdProducto(arregloArbolesProductos[i],miProducto.idProducto);
            }
        }
        fclose(archi);
    }
}

void guardarProductosEnArchivoNuevo (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    int i;
    producto miProducto;
    FILE * archi=fopen(nombreArchivoProductos,"wb");
    if (archi!=NULL)
    {
        for (i=0; i<dim; i++)
        {
            while (arregloArbolesProductos[i]!=NULL)
            {
                miProducto=arregloArbolesProductos[i]->miProducto;
                fwrite(&miProducto,sizeof(producto),1,archi);
                arregloArbolesProductos[i]=borrarNodoEnArbolProductos_PorIdProducto(arregloArbolesProductos[i],miProducto.idProducto);
            }
        }
        fclose(archi);
    }
}

void cargarArregloArbolesProductosDeArchivo (nodoArbolProducto * arregloArbolesProductos[])
{
    int pos;
    producto miProducto;
    nodoArbolProducto * nuevoNodo;
    FILE * archi=fopen(nombreArchivoProductos,"rb");
    if (archi!=NULL)
    {
        while (fread(&miProducto,sizeof(producto),1,archi)>0)
        {
            crearNodoProducto(&nuevoNodo,miProducto);
            pos=miProducto.idMarca;
            arregloArbolesProductos[pos]=insertarUnNodoAlArbolProductos(arregloArbolesProductos[pos],nuevoNodo);
        }
        fclose(archi);
    }
}

//ELIMINACION Y MODIFICACION

int arregloVacio (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    int i,contador=0,rta=0;
    for (i=0; i<dim; i++)
    {
        if (arregloArbolesProductos[i]==NULL)
            contador++;
    }
    if (contador==7)
        rta=1;
    return rta;
}

void borrarArregloArbolesProductos_PorIdProducto (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    int i;
    for (i=0; i<dim; i++)
        while (arregloArbolesProductos[i]!=NULL)
            arregloArbolesProductos[i]=borrarNodoEnArbolProductos_PorIdProducto(arregloArbolesProductos[i],arregloArbolesProductos[i]->miProducto.idProducto);
}

void iniciarBorrarNodoEnArregloArbolesProductos (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    int idProductoABorrar,eliminacion;
    cargarArregloArbolesProductosDeArchivo(arregloArbolesProductos);
    if (!arregloVacio(arregloArbolesProductos,dim))
    {
        printf("\n>Muestra de automoviles:\n");
        mostrarArregloArbolesProductos(arregloArbolesProductos,dim);
        printf("\n>Ingrese el ID del automovil a borrar: ");
        scanf("%d",&idProductoABorrar);
        eliminacion=borrarNodoEnArregloArbolesProductos_PorIdProducto(arregloArbolesProductos,dim,idProductoABorrar);
        if (eliminacion)
        {
            guardarProductosEnArchivoNuevo(arregloArbolesProductos,dim);
            textcolor(8);
            printf("\n>Automovil borrado. ");
            textcolor(15);
        }
        else
        {
            borrarArregloArbolesProductos_PorIdProducto(arregloArbolesProductos,dim);
            textcolor(8);
            printf("\n>[ERROR] El ID del automovil ingresado no corresponde a ningun automovil. ");
            textcolor(15);
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay automoviles cargados. ");
        textcolor(15);
    }
    system("pause");
}

int borrarNodoEnArregloArbolesProductos_PorIdProducto (nodoArbolProducto * arregloArbolesProductos[],int dim,int dato)
{
    int i=0,rta=0;
    while (i<dim && rta==0)
    {
        if (buscarNodoEnArbolProductos_PorId(arregloArbolesProductos[i],dato))
        {
            arregloArbolesProductos[i]=borrarNodoEnArbolProductos_PorIdProducto(arregloArbolesProductos[i],dato);
            rta=1;
        }
        i++;
    }
    return rta;
}

nodoArbolProducto * borrarNodoEnArbolProductos_PorIdProducto (nodoArbolProducto * arbol,int dato)
{
    if (arbol!=NULL)
    {
        if(dato==arbol->miProducto.idProducto)
        {
            if (arbol->izq!=NULL)
            {
                nodoArbolProducto * masDer=NMD(arbol->izq);
                arbol->miProducto=masDer->miProducto;
                arbol->izq=borrarNodoEnArbolProductos_PorIdProducto(arbol->izq,masDer->miProducto.idProducto);
            }
            else if (arbol->der!=NULL)
            {
                nodoArbolProducto * masIzq=NMI(arbol->der);
                arbol->miProducto=masIzq->miProducto;
                arbol->der=borrarNodoEnArbolProductos_PorIdProducto(arbol->der,masIzq->miProducto.idProducto);
            }
            else //Arbol es hoja
            {
                free(arbol);
                arbol=NULL;
            }
        }
        else if (dato<arbol->miProducto.idProducto)
        {
            arbol->izq=borrarNodoEnArbolProductos_PorIdProducto(arbol->izq,dato);
        }
        else
        {
            arbol->der=borrarNodoEnArbolProductos_PorIdProducto(arbol->der,dato);
        }
    }
    return arbol;
}

nodoArbolProducto * NMD (nodoArbolProducto * arbol)
{
    if (arbol->der!=NULL)
    {
        arbol=NMD(arbol->der); //Nodo más derecho del subárbol izquierdo
    }
    return arbol;
}

nodoArbolProducto * NMI (nodoArbolProducto * arbol)
{
    if (arbol->izq!=NULL)
    {
        arbol=NMD(arbol->izq); //Nodo más izquierdo del subárbol derecho
    }
    return arbol;
}

void iniciarModificarNodoEnArregloArbolesProductos (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    int idProductoAModificar,modificacion;
    cargarArregloArbolesProductosDeArchivo(arregloArbolesProductos);
    if (!arregloVacio(arregloArbolesProductos,dim))
    {
        printf("\n>Muestra de automoviles:\n");
        mostrarArregloArbolesProductos(arregloArbolesProductos,dim);
        printf("\n>Ingrese el ID del automovil a modificar: ");
        scanf("%d",&idProductoAModificar);
        modificacion=modificarNodoEnArregloArbolesProductos_PorIdProducto(arregloArbolesProductos,dim,idProductoAModificar);
        if (modificacion)
        {
            guardarProductosEnArchivoNuevo(arregloArbolesProductos,dim);
            textcolor(8);
            printf("\n>Modificacion terminada. ");
            textcolor(15);
        }
        else
        {
            borrarArregloArbolesProductos_PorIdProducto(arregloArbolesProductos,dim);
            textcolor(8);
            printf("\n>[ERROR] El ID del automovil ingresado no corresponde a ningun automovil. ");
            textcolor(15);
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay automoviles cargados. ");
        textcolor(15);
    }
    system("pause");
}

int modificarNodoEnArregloArbolesProductos_PorIdProducto (nodoArbolProducto * arregloArbolesProductos[],int dim,int dato)
{
    int i=0,rta=0;
    while (i<dim && rta==0)
    {
        if (buscarNodoEnArbolProductos_PorId(arregloArbolesProductos[i],dato))
        {
            arregloArbolesProductos[i]=modificarNodoEnArbolProductos_PorIdProducto(arregloArbolesProductos[i],dato);
            rta=1;
        }
        i++;
    }
    return rta;
}

nodoArbolProducto * modificarNodoEnArbolProductos_PorIdProducto (nodoArbolProducto * arbol,int dato)
{
    if (arbol!=NULL)
    {
        if(dato==arbol->miProducto.idProducto)
        {
            arbol->miProducto=modificarProducto(arbol->miProducto);
        }
        else if (dato<arbol->miProducto.idProducto)
        {
            arbol->izq=modificarNodoEnArbolProductos_PorIdProducto(arbol->izq,dato);
        }
        else
        {
            arbol->der=modificarNodoEnArbolProductos_PorIdProducto(arbol->der,dato);
        }
    }
    return arbol;
}

producto modificarProducto (producto miProducto)
{
    int op;
    char control='s';
    while (control=='s')
    {
        system("cls");
        encabezadoSubMenuProductos();
        printf("\n\n>Automovil a modificar:\n");
        mostrarProducto(miProducto);
        textcolor(8);
        printf("\n\n>Ingrese:\n [1] Para modificar el nombre del automovil\n [2] Para modificar los km. del automovil\n [3] Para modificar el precio del automovil\n>Opcion: ");
        textcolor(15);
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("\n>Ingrese el nombre del automovil: ");
            fflush(stdin);
            fgets(miProducto.nombre,a_dim,stdin);
            break;
        case 2:
            printf("\n>Ingrese los km. del automovil: ");
            scanf("%f",&miProducto.km);

            break;
        case 3:
            printf("\n>Ingrese el precio del automovil: ");
            scanf("%f",&miProducto.precio);
            break;
        }
        textcolor(8);
        printf("\n>Desea seguir modificando el automovil? Ingrese la tecla 's' para seguir u otra tecla para volver al menu de automoviles: ");
        textcolor(15);
        fflush(stdin);
        scanf("%c",&control);
    }
    return miProducto;
}

//MUESTRA

void iniciarMostrarArregloArbolesProductos (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    cargarArregloArbolesProductosDeArchivo(arregloArbolesProductos);
    if (!arregloVacio(arregloArbolesProductos,dim))
    {
        printf("\n>Muestra de automoviles:\n");
        mostrarArregloArbolesProductos(arregloArbolesProductos,dim);
        borrarArregloArbolesProductos_PorIdProducto(arregloArbolesProductos,dim);
        printf("\n");
    }
    else
    {
        textcolor(8);
        printf("\n>No hay automoviles cargados. ");
        textcolor(15);
    }
    system("pause");
}

void mostrarArregloArbolesProductos (nodoArbolProducto * arregloArbolesProductos[],int dim)
{
    int i,u;
    char marca[a_dim];
    for (i=0; i<dim; i++)
    {
        cargarNombreMarca(marca,i);
        printf("\n %c AUTOMOVILES %s\n",254,marca);
        if (arregloArbolesProductos[i]!=NULL)
        {
            preOrden(arregloArbolesProductos[i]);
        }
        else
        {
            printf("\n\t");
            for(u=0; u<11; u++)
            {
                printf("%c",205);
            }
            printf("\n\tLista vacia\n\t");
            for(u=0; u<11; u++)
            {
                printf("%c",205);
            }
            printf("\n");
        }
    }
}

void cargarNombreMarca (char marca[],int i)
{
    switch (i)
    {
    case 0:
        strcpy(marca,"Chevrolet");
        break;
    case 1:
        strcpy(marca,"Citroen");
        break;
    case 2:
        strcpy(marca,"Fiat");
        break;
    case 3:
        strcpy(marca,"Ford");
        break;
    case 4:
        strcpy(marca,"Honda");
        break;
    case 5:
        strcpy(marca,"Peugeot");
        break;
    case 6:
        strcpy(marca,"Otros");
        break;
    }
}

void preOrden (nodoArbolProducto * arbolProductos)
{
    if (arbolProductos!=NULL)
    {
        mostrarProducto(arbolProductos->miProducto);
        printf("\n");
        preOrden(arbolProductos->izq);
        preOrden(arbolProductos->der);
    }
}

void mostrarProducto (producto miProducto)
{
    char marca[a_dim];
    cargarNombreMarca(marca,miProducto.idMarca);
    printf("\n\t%cID: %d",186,miProducto.idProducto);
    printf("\n\t%cNombre: %s",186,miProducto.nombre);
    printf("\t%cKm.: %0.2f",186,miProducto.km);
    printf("\n\t%cPrecio: $%0.2f",186,miProducto.precio);
}

//->CLIENTES - Forma de trabajo: Lista enlazadada simple. Las funciones solo usan punteros dobles.

//MENU Y ENCABEZADOS

void menuClientes ()
{
    nodoCliente * listaClientes;
    inicListaClientes(&listaClientes);
    int op;
    char control='s';
    while (control=='s')
    {
        encabezadoMenuClientes();
        printf("\n\n>Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&op);
        system("cls");
        encabezadoSubMenuClientes();
        printf("\n");
        switch (op)
        {
        case 1:
            cargarListaClientes(&listaClientes);
            guardarClientesEnArchivo(&listaClientes);
            break;
        case 2:
            iniciarBorrarNodoEnListaClientes(&listaClientes);
            break;
        case 3:
            iniciarModificarNodoEnListaClientes(&listaClientes);
            break;
        case 4:
            iniciarMostrarListaClientes(&listaClientes);
            break;
        case 5:
            control='n';
            break;
        }
        system("cls");
    }
}

void encabezadoMenuClientes ()
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
    printf("\n%c [1] Agregar clientes                                                                       %c",186,186);
    printf("\n%c [2] Quitar cliente                                                                         %c",186,186);
    printf("\n%c [3] Modificar cliente                                                                      %c",186,186);
    printf("\n%c [4] Mostrar clientes                                                                       %c",186,186);
    printf("\n%c [5] Volver                                                                                 %c",186,186);
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

void encabezadoSubMenuClientes ()
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
    printf("\n%c                                      %c CLIENTES %c                                          %c",186,186,186,186);
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

//ALTA DE NODOS

void inicListaClientes (nodoCliente ** listaClientes)
{
    (*listaClientes)=NULL;
}

void cargarListaClientes (nodoCliente ** listaClientes)
{
    int comprobacion,idCliente=retornarIdMasGrande_Cliente();
    cliente miCliente;
    nodoCliente * nuevoNodo;
    char control='s';
    while (control=='s')
    {
        system("cls");
        encabezadoSubMenuClientes();
        printf("\n");
        comprobacion=cargarCliente(&miCliente,listaClientes,&idCliente);
        if (comprobacion)
        {
            crearNodoCliente(&nuevoNodo,miCliente);
            agregarUnNodoClienteAlFinal(listaClientes,nuevoNodo);
            textcolor(8);
            printf("\n>Carga exitosa. Desea seguir ingresando clientes? Ingrese la tecla 's' para seguir u otra tecla para volver al menu de clientes: ");
            textcolor(15);
            fflush(stdin);
            scanf("%c",&control);
        }
        else
        {
            textcolor(8);
            printf(">Ingrese la tecla 's' para seguir ingresando clientes u otra tecla para volver al menu de clientes: ");
            textcolor(15);
            fflush(stdin);
            scanf("%c",&control);
        }
    }
}

int cargarCliente (cliente * miCliente,nodoCliente ** listaClientes,int * idCliente)
{
    int rta;
    cliente aux;
    aux.idCliente=(*idCliente)+1;
    printf("\n>ID del cliente: %i. ",aux.idCliente);
    system("pause");
    printf(">Ingrese el DNI del cliente: ");
    fflush(stdin);
    scanf("%s",aux.dni);
    if (comprobarNoRepeticionDNIClienteEnArchivo(aux.dni) && comprobarNoRepeticionDNIClienteEnLista((*listaClientes),aux.dni))
    {
        printf(">Ingrese el nombre y el apellido del cliente: ");
        fflush(stdin);
        fgets(aux.nombreYApellido,a_dim,stdin);
        printf(">Ingrese el telefono del cliente: ");
        fflush(stdin);
        scanf("%s",aux.telefono);
        (*idCliente)=(*idCliente)+1;
        rta=1;
    }
    else
    {
        textcolor(8);
        printf("\n>[ERROR] El DNI del cliente ingresado ya corresponde a un cliente cargado.\n");
        textcolor(15);
        rta=0;
    }
    (*miCliente)=aux;
    return rta;
}

int retornarIdMasGrande_Cliente ()
{
    int rta,idMasGrande; //Funcion que retorna el numero ID mas grande dentro del archivo. Si el archivo no existe o no tiene elementos, retorna 0.
    cliente archivoCliente;
    FILE * archi=fopen(nombreArchivoClientes,"rb");
    if (archi!=NULL)
    {
        fread(&archivoCliente,sizeof(cliente),1,archi);
        idMasGrande=archivoCliente.idCliente;
        if (!feof(archi))
        {
            while (fread(&archivoCliente,sizeof(cliente),1,archi)>0)
            {
                if (archivoCliente.idCliente>idMasGrande)
                {
                    idMasGrande=archivoCliente.idCliente;
                }
            }
            rta=idMasGrande;
        }
        else
            rta=0;
        fclose(archi);
    }
    else
        rta=0;
    return rta;
}

int comprobarNoRepeticionDNIClienteEnArchivo (char dniCliente[])
{
    cliente clienteArchivo;
    int rta=1;
    FILE * archi=fopen(nombreArchivoClientes,"rb");
    if (archi!=NULL)
    {
        while(fread(&clienteArchivo,sizeof(cliente),1,archi)>0 && rta==1)
        {
            if (strcmp(clienteArchivo.dni,dniCliente)==0)
                rta=0;
        }
        fclose(archi);
    }
    return rta;
}

int comprobarNoRepeticionDNIClienteEnLista (nodoCliente * listaClientes,char dniCliente[])
{
    int rta=1;
    while (listaClientes!=NULL && rta==1)
    {
        if (strcmp(listaClientes->miCliente.dni,dniCliente)==0)
            rta=0;
        listaClientes=listaClientes->sig;
    }
    return rta;
}

void crearNodoCliente (nodoCliente ** nuevoNodo,cliente miCliente)
{
    (*nuevoNodo)=malloc(sizeof(nodoCliente));
    (*nuevoNodo)->miCliente=miCliente;
    (*nuevoNodo)->sig=NULL;
}

void agregarUnNodoClienteAlFinal (nodoCliente ** listaClientes,nodoCliente * nuevoNodo)
{
    if((*listaClientes)==NULL)
    {
        (*listaClientes)=nuevoNodo;
    }
    else
    {
        nodoCliente * ultimo;
        buscarUltimoNodoCliente(listaClientes,&ultimo);
        ultimo->sig=nuevoNodo;
    }
}

void buscarUltimoNodoCliente (nodoCliente ** listaClientes,nodoCliente ** ultimo)
{
    nodoCliente * seg=(*listaClientes);
    if(seg!=NULL)
        while(seg->sig!=NULL)
        {
            seg=seg->sig;
        }
    (*ultimo)=seg;
}

//CARGA Y GUARDADO EN ARCHIVO

void guardarClientesEnArchivo (nodoCliente ** listaClientes)
{
    int eliminacion;
    cliente miCliente;
    FILE * archi=fopen(nombreArchivoClientes,"ab");
    if (archi!=NULL)
    {
        while ((*listaClientes)!=NULL)
        {
            miCliente=((*listaClientes)->miCliente);
            fwrite(&miCliente,sizeof(cliente),1,archi);
            eliminacion=borrarNodoCliente(listaClientes,(*listaClientes)->miCliente.idCliente);
        }
        fclose(archi);
    }
}

void guardarClientesEnArchivoNuevo (nodoCliente ** listaClientes)
{
    int eliminacion;
    cliente miCliente;
    FILE * archi=fopen(nombreArchivoClientes,"wb");
    if (archi!=NULL)
    {
        while ((*listaClientes)!=NULL)
        {
            miCliente=((*listaClientes)->miCliente);
            fwrite(&miCliente,sizeof(cliente),1,archi);
            eliminacion=borrarNodoCliente(listaClientes,(*listaClientes)->miCliente.idCliente);
        }
        fclose(archi);
    }
}

void cargarListaClientesDeArchivo (nodoCliente ** listaClientes)
{
    cliente miCliente;
    nodoCliente * nuevoNodo;
    FILE * archi=fopen(nombreArchivoClientes,"rb");
    if (archi!=NULL)
    {
        while (fread(&miCliente,sizeof(cliente),1,archi)>0)
        {
            crearNodoCliente(&nuevoNodo,miCliente);
            agregarUnNodoClienteAlFinal(listaClientes,nuevoNodo);
        }
        fclose(archi);
    }
}

//ELIMINACION Y MODIFICACION

void borrarListaClientes (nodoCliente ** listaClientes)
{
    nodoCliente * nodoABorrar;
    while ((*listaClientes)!=NULL)
    {
        nodoABorrar=(*listaClientes);
        (*listaClientes)=(*listaClientes)->sig;
        free(nodoABorrar);
    }
}

void iniciarBorrarNodoEnListaClientes (nodoCliente ** listaClientes)
{
    int idClienteABorrar,eliminacion;
    cargarListaClientesDeArchivo(listaClientes);
    if ((*listaClientes)!=NULL)
    {
        printf("\n>Muestra de clientes:\n");
        mostrarListaClientes(*listaClientes);
        printf("\n\n>Ingrese el ID del cliente a borrar: ");
        scanf("%d",&idClienteABorrar);
        eliminacion=borrarNodoCliente(listaClientes,idClienteABorrar);
        if (eliminacion)
        {
            guardarClientesEnArchivoNuevo(listaClientes);
            textcolor(8);
            printf("\n>Cliente borrado. ");
            textcolor(15);
        }
        else
        {
            borrarListaClientes(listaClientes);
            textcolor(8);
            printf("\n>[ERROR] El ID del cliente ingresado no corresponde a ningun cliente. ");
            textcolor(15);
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay clientes cargados. ");
        textcolor(15);
    }
    system("pause");
}

int borrarNodoCliente (nodoCliente ** listaClientes,int dato)
{
    int rta=0;
    nodoCliente * seg;
    nodoCliente * ante;
    if((*listaClientes)!=NULL && (*listaClientes)->miCliente.idCliente==dato)
    {
        nodoCliente * aux=(*listaClientes);
        (*listaClientes)=(*listaClientes)->sig;
        free(aux);
        rta=1;
    }
    else
    {
        seg=(*listaClientes);
        while(seg!=NULL && seg->miCliente.idCliente!=dato)
        {
            ante=seg;
            seg=seg->sig;
        }
        if(seg!=NULL)
        {
            ante->sig=seg->sig;
            free(seg);
            rta=1;
        }
    }
    return rta;
}

void iniciarModificarNodoEnListaClientes (nodoCliente ** listaClientes)
{
    int idClienteAModificar,modificacion;
    cargarListaClientesDeArchivo(listaClientes);
    if ((*listaClientes)!=NULL)
    {
        printf("\n>Muestra de clientes:\n");
        mostrarListaClientes(*listaClientes);
        printf("\n\n>Ingrese el ID del cliente a modificar: ");
        scanf("%d",&idClienteAModificar);
        modificacion=modificarNodoCliente(listaClientes,idClienteAModificar);
        if (modificacion)
        {
            guardarClientesEnArchivoNuevo(listaClientes);
            textcolor(8);
            printf("\n>Modificacion terminada. ");
            textcolor(15);
        }
        else
        {
            borrarListaClientes(listaClientes);
            textcolor(8);
            printf("\n>[ERROR] El ID del cliente ingresado no corresponde a ningun cliente. ");
            textcolor(15);
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay clientes cargados. ");
        textcolor(15);
    }
    system("pause");
}

int modificarNodoCliente (nodoCliente ** listaClientes,int dato)
{
    int rta=0;
    nodoCliente * seg;
    if((*listaClientes)!=NULL && (*listaClientes)->miCliente.idCliente==dato)
    {
        (*listaClientes)->miCliente=modificarCliente((*listaClientes)->miCliente);
        rta=1;
    }
    else
    {
        seg=(*listaClientes);
        while(seg!=NULL && seg->miCliente.idCliente!=dato)
        {
            seg=seg->sig;
        }
        if(seg!=NULL)
        {
            seg->miCliente=modificarCliente(seg->miCliente);
            rta=1;
        }
    }
    return rta;
}

cliente modificarCliente (cliente miCliente)
{
    int op;
    char control='s';
    while (control=='s')
    {
        system("cls");
        encabezadoSubMenuClientes();
        printf("\n\n>Cliente a modificar:\n");
        mostrarCliente(miCliente);
        textcolor(8);
        printf("\n\n>Ingrese:\n [1] Para modificar el nombre y el apellido del cliente\n [2] Para modificar el telefono del cliente\n>Opcion: ");
        textcolor(15);
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("\n>Ingrese el nombre y el apellido del cliente: ");
            fflush(stdin);
            fgets(miCliente.nombreYApellido,a_dim,stdin);
            break;
        case 2:
            printf("\n>Ingrese el telefono del cliente: ");
            fflush(stdin);
            scanf("%s",miCliente.telefono);
            break;
        }
        textcolor(8);
        printf("\n>Desea seguir modificando el cliente? Ingrese la tecla 's' para seguir u otra tecla para volver al menu de clientes: ");
        textcolor(15);
        fflush(stdin);
        scanf("%c",&control);
    }
    return miCliente;
}

//MUESTRA

void iniciarMostrarListaClientes (nodoCliente ** listaClientes)
{
    cargarListaClientesDeArchivo(listaClientes);
    if ((*listaClientes)!=NULL)
    {
        printf("\n>Muestra de clientes:\n");
        mostrarListaClientes(*listaClientes);
        printf("\n\n");
    }
    else
    {
        textcolor(8);
        printf("\n>No hay clientes cargados. ");
        textcolor(15);
    }
    system("pause");
    borrarListaClientes(listaClientes);
}

void mostrarListaClientes (nodoCliente * listaClientes)
{
    nodoCliente * seg=listaClientes;
    while (seg!=NULL)
    {
        mostrarCliente(seg->miCliente);
        seg=seg->sig;
    }
}

void mostrarCliente (cliente miCliente)
{
    int i;
    printf("\n");
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
    printf("\nID: %d",miCliente.idCliente);
    printf("\nDNI: %s",miCliente.dni);
    printf("\nNombre y apellido: %s",miCliente.nombreYApellido);
    printf("Telefono: %s",miCliente.telefono);
    printf("\n");
    for(i=0; i<50; i++)
    {
        printf("%c",205);
    }
}

//->VENTAS - Forma de trabajo: Lista enlazadada simple. Las funciones solo usan punteros dobles.

//MENU Y ENCABEZADOS

void menuVentas (usuario miUsuario)
{
    nodoVenta * listaVentas;
    inicListaVentas(&listaVentas);
    int op;
    char control='s';
    while (control=='s')
    {
        encabezadoMenuVentas();
        printf("\n\n>Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&op);
        system("cls");
        switch (op)
        {
        case 1:
            cargarListaVentas(&listaVentas,miUsuario);
            guardarVentasEnArchivo(&listaVentas,miUsuario);
            break;
        case 2:
            iniciarBorrarNodoEnListaVentas(&listaVentas,miUsuario);
            break;
        case 3:
            iniciarMostrarListaVentas(&listaVentas,miUsuario);
            break;
        case 4:
            iniciarEstadisticasVentas(&listaVentas,miUsuario);
            break;
        case 5:
            control='n';
            break;
        }
        system("cls");
    }
}

void encabezadoMenuVentas ()
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
    printf("\n%c [1] Agregar ventas                                                                         %c",186,186);
    printf("\n%c [2] Quitar venta                                                                           %c",186,186);
    printf("\n%c [3] Mostrar mis ventas                                                                     %c",186,186);
    printf("\n%c [4] Estadisticas de mis ventas                                                             %c",186,186);
    printf("\n%c [5] Volver                                                                                 %c",186,186);
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

void encabezadoSubMenuVentas ()
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
    printf("\n%c                                      %c VENTAS %c                                            %c",186,186,186,186);
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

//ALTA DE NODOS

void inicListaVentas (nodoVenta ** listaVentas)
{
    (*listaVentas)=NULL;
}

void cargarListaVentas (nodoVenta ** listaVentas,usuario miUsuario)
{
    encabezadoSubMenuVentas();
    printf("\n");
    if (comprobacionExistenciaClientesYProductos())
    {
        int comprobacion,idVenta=retornarIdMasGrande_Venta();
        venta miVenta;
        nodoVenta * nuevoNodo;
        char control='s';
        while (control=='s')
        {
            system("cls");
            encabezadoSubMenuVentas();
            printf("\n");
            comprobacion=cargarVenta(&miVenta,listaVentas,miUsuario,&idVenta);
            if (comprobacion)
            {
                crearNodoVenta(&nuevoNodo,miVenta);
                agregarUnNodoVentaAlFinal(listaVentas,nuevoNodo);
                textcolor(8);
                printf("\n>Carga exitosa. Desea seguir ingresando ventas? Ingrese la tecla 's' para seguir u otra tecla para volver al menu de ventas: ");
                textcolor(15);
                fflush(stdin);
                scanf("%c",&control);
            }
            else
            {
                textcolor(8);
                printf(">Ingrese la tecla 's' para seguir ingresando ventas u otra tecla para volver al menu de ventas: ");
                textcolor(15);
                fflush(stdin);
                scanf("%c",&control);
            }
        }
    }
    else
    {
        textcolor(8);
        printf("\n>No hay automoviles/clientes cargados. ");
        textcolor(15);
        system("pause");
    }
}

int comprobacionExistenciaClientesYProductos ()
{
    int rta; //Funcion que retorna 1 si existen y ademas si tienen elementos los archivos de productos y de ventas. Caso contrario, retorna 0.
    cliente archivoCliente;
    FILE * archi=fopen(nombreArchivoClientes,"rb");
    if (archi!=NULL)
    {
        fread(&archivoCliente,sizeof(cliente),1,archi);
        if (!feof(archi))
            rta=1;
        else
            rta=0;
        fclose(archi);
    }
    else
        rta=0;
    if (rta)
    {
        producto archivoProducto;
        FILE * archi=fopen(nombreArchivoProductos,"rb");
        if (archi!=NULL)
        {
            fread(&archivoProducto,sizeof(producto),1,archi);
            if (!feof(archi))
                rta=1;
            else
                rta=0;
            fclose(archi);
        }
        else
            rta=0;
    }
    return rta;
}

int cargarVenta (venta * miVenta,nodoVenta ** listaVentas,usuario miUsuario,int * idVenta)
{
    //CARGA FECHA AUTOMATICA
    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);
    //
    int rta;
    venta aux;
    aux.idVenta=(*idVenta)+1;
    printf("\n>ID de la venta: %i. ",aux.idVenta);
    system("pause");
    system("cls");
    encabezadoSubMenuVentas();
    printf("\n\n %c CLIENTES\n",254);
    mostrarClientesEnVenta();
    printf("\n>Ingrese el ID del cliente asociado a la venta: ");
    scanf("%d",&aux.miCliente.idCliente);
    if (!(comprobarNoRepeticionIdClienteEnArchivo(aux.miCliente.idCliente)))
    {
        system("cls");
        encabezadoSubMenuVentas();
        printf("\n\n %c AUTOMOVILES\n\n",254);
        mostrarProductosEnVenta();
        printf("\n>Ingrese el ID del automovil asociado a la venta: ");
        scanf("%d",&aux.miProducto.idProducto);
        if (comprobarProductoDeVenta(aux.miProducto.idProducto))
        {
            producto miProducto;
            miProducto=(retornarProductoVenta(aux.miProducto.idProducto));
            aux.miProducto=miProducto;

            cliente miCliente;
            miCliente=(retornarClienteVenta(aux.miCliente.idCliente));
            aux.miCliente=miCliente;

            strcpy(aux.nombreUsuario,miUsuario.nombre);
            aux.dia=tm->tm_mday;
            aux.mes=tm->tm_mon+1;
            aux.anio=1900+tm->tm_year;
            (*idVenta)=(*idVenta)+1;
            borrarProductoPostVenta(aux.miProducto.idProducto);
            rta=1;
        }
        else
        {
            textcolor(8);
            printf("\n>[ERROR] El ID del automovil asociado a la venta ingresada no corresponde a un automovil cargado.\n");
            textcolor(15);
            rta=0;
        }
    }
    else
    {
        textcolor(8);
        printf("\n>[ERROR] El ID del cliente asociado a la venta ingresada no corresponde a un cliente cargado.\n");
        textcolor(15);
        rta=0;
    }
    (*miVenta)=aux;
    return rta;
}

void borrarProductoPostVenta (int idProductoABorrar)
{
    int dim=7,eliminacion;
    nodoArbolProducto * arregloArbolesProductos[dim];
    inicArregloArbolesProductos(arregloArbolesProductos,dim);
    cargarArregloArbolesProductosDeArchivo(arregloArbolesProductos);
    eliminacion=borrarNodoEnArregloArbolesProductos_PorIdProducto(arregloArbolesProductos,dim,idProductoABorrar);
    guardarProductosEnArchivoNuevo(arregloArbolesProductos,dim);
}

int retornarIdMasGrande_Venta ()
{
    int rta,idMasGrande; //Funcion que retorna el numero ID mas grande dentro del archivo. Si el archivo no existe o no tiene elementos, retorna 0.
    venta archivoVenta;
    FILE * archi=fopen(nombreArchivoVentas,"rb");
    if (archi!=NULL)
    {
        fread(&archivoVenta,sizeof(venta),1,archi);
        idMasGrande=archivoVenta.idVenta;
        if (!feof(archi))
        {
            while (fread(&archivoVenta,sizeof(venta),1,archi)>0)
            {
                if (archivoVenta.idVenta>idMasGrande)
                {
                    idMasGrande=archivoVenta.idVenta;
                }
            }
            rta=idMasGrande;
        }
        else
            rta=0;
        fclose(archi);
    }
    else
        rta=0;
    return rta;
}

void mostrarClientesEnVenta ()
{
    nodoCliente * listaClientes;
    inicListaClientes(&listaClientes);
    iniciarMostrarListaClientes(&listaClientes);
}

void mostrarProductosEnVenta ()
{
    int dim=7;
    nodoArbolProducto * arregloArbolesProductos[dim];
    inicArregloArbolesProductos(arregloArbolesProductos,dim);
    iniciarMostrarArregloArbolesProductos(arregloArbolesProductos,dim);
}

int comprobarNoRepeticionIdClienteEnArchivo (int idCliente)
{
    cliente clienteArchivo;
    int rta=1;
    FILE * archi=fopen(nombreArchivoClientes,"rb");
    if (archi!=NULL)
    {
        while(fread(&clienteArchivo,sizeof(cliente),1,archi)>0 && rta==1)
        {
            if (clienteArchivo.idCliente==idCliente)
                rta=0;
        }
        fclose(archi);
    }
    return rta;
}

int comprobarProductoDeVenta (int idProducto)
{
    producto productoArchivo;
    int rta=0;
    FILE * archi=fopen(nombreArchivoProductos,"r+b");
    if (archi!=NULL)
    {
        while (rta==0 && fread(&productoArchivo,sizeof(producto),1,archi)>0)
        {
            if (productoArchivo.idProducto==idProducto)
            {
                rta=1;
            }
        }
        fclose(archi);
    }
    return rta;
}

producto retornarProductoVenta (int idProducto)
{
    producto productoArchivo;
    float rta=0;
    FILE * archi=fopen(nombreArchivoProductos,"rb");
    if (archi!=NULL)
    {
        while (rta==0 && fread(&productoArchivo,sizeof(producto),1,archi)>0)
        {
            if (productoArchivo.idProducto==idProducto)
                rta=1;
        }
        fclose(archi);
    }
    return productoArchivo;
}

cliente retornarClienteVenta (int idCliente)
{
    cliente clienteArchivo;
    float rta=0;
    FILE * archi=fopen(nombreArchivoClientes,"rb");
    if (archi!=NULL)
    {
        while (rta==0 && fread(&clienteArchivo,sizeof(cliente),1,archi)>0)
        {
            if (clienteArchivo.idCliente==idCliente)
                rta=1;
        }
        fclose(archi);
    }
    return clienteArchivo;
}

void crearNodoVenta (nodoVenta ** nuevoNodo,venta miVenta)
{
    (*nuevoNodo)=malloc(sizeof(nodoVenta));
    (*nuevoNodo)->miVenta=miVenta;
    (*nuevoNodo)->sig=NULL;
}

void agregarUnNodoVentaAlFinal (nodoVenta ** listaVentas,nodoVenta * nuevoNodo)
{
    if((*listaVentas)==NULL)
    {
        (*listaVentas)=nuevoNodo;
    }
    else
    {
        nodoVenta * ultimo;
        buscarUltimoNodoVenta(listaVentas,&ultimo);
        ultimo->sig=nuevoNodo;
    }
}

void buscarUltimoNodoVenta (nodoVenta ** listaVentas,nodoVenta ** ultimo)
{
    nodoVenta * seg=(*listaVentas);
    if(seg!=NULL)
        while(seg->sig!=NULL)
        {
            seg=seg->sig;
        }
    (*ultimo)=seg;
}

//CARGA Y GUARDADO EN ARCHIVO

void guardarVentasEnArchivo (nodoVenta ** listaVentas,usuario miUsuario)
{
    int eliminacion;
    venta miVenta;
    nodoVenta * seg=(*listaVentas);
    FILE * archi=fopen(nombreArchivoVentas,"ab");
    if (archi!=NULL)
    {
        while (seg!=NULL)
        {
            miVenta=(seg->miVenta);
            fwrite(&miVenta,sizeof(venta),1,archi);
            seg=seg->sig;
            guardarVentaDeUsuario(miUsuario,miVenta.miProducto.precio);
        }
        fclose(archi);
    }
    borrarListaVentas(listaVentas);
}

void guardarVentaDeUsuario (usuario miUsuario,float precioVenta)
{
    usuario usuarioArchivo;
    FILE * archi=fopen(nombreArchivo,"r+b");
    int band=0;
    if (archi!=NULL)
    {
        while (band==0 && fread(&usuarioArchivo,sizeof(usuario),1,archi)>0)
        {
            if (strcmp(miUsuario.nombre,usuarioArchivo.nombre)==0)
            {
                band=1;
                usuarioArchivo.ventas=(usuarioArchivo.ventas)+1;
                usuarioArchivo.sumaVentas=(usuarioArchivo.sumaVentas)+precioVenta;
                fseek(archi,-1*(sizeof(usuario)),SEEK_CUR);
                fwrite(&usuarioArchivo,sizeof(usuario),1,archi);
            }
        }
        fclose(archi);
    }
}

void guardarVentasEnArchivoNuevo (nodoVenta ** listaVentas)
{
    int eliminacion;
    venta miVenta;
    nodoVenta * seg=(*listaVentas);
    FILE * archi=fopen(nombreArchivoVentas,"wb");
    if (archi!=NULL)
    {
        while (seg!=NULL)
        {
            miVenta=(seg->miVenta);
            fwrite(&miVenta,sizeof(venta),1,archi);
            seg=seg->sig;
        }
        fclose(archi);
    }
    borrarListaVentas(listaVentas);
}

void cargarListaVentasDeArchivo (nodoVenta ** listaVentas)
{
    venta miVenta;
    nodoVenta * nuevoNodo;
    FILE * archi=fopen(nombreArchivoVentas,"rb");
    if (archi!=NULL)
    {
        while (fread(&miVenta,sizeof(venta),1,archi)>0)
        {
            crearNodoVenta(&nuevoNodo,miVenta);
            agregarUnNodoVentaAlFinal(listaVentas,nuevoNodo);
        }
        fclose(archi);
    }
}

int verificarVentasDelUsuario (nodoVenta * listaVentas,usuario miUsuario)
{
    int rta=0;
    nodoVenta * seg=listaVentas;
    if (seg!=NULL)
    {
        while (rta==0 && seg!=NULL)
        {
            if (strcmp(seg->miVenta.nombreUsuario,miUsuario.nombre)==0)
                rta=1;
            seg=seg->sig;
        }
    }
    return rta;
}

//ELIMINACION Y MODIFICACION

void borrarListaVentas (nodoVenta ** listaVentas)
{
    nodoVenta * nodoABorrar;
    while ((*listaVentas)!=NULL)
    {
        nodoABorrar=(*listaVentas);
        (*listaVentas)=(*listaVentas)->sig;
        free(nodoABorrar);
    }
}

void iniciarBorrarNodoEnListaVentas (nodoVenta ** listaVentas,usuario miUsuario)
{
    encabezadoSubMenuVentas();
    printf("\n");
    int idVentaABorrar,eliminacion;
    cargarListaVentasDeArchivo(listaVentas);
    if ((*listaVentas)!=NULL && verificarVentasDelUsuario((*listaVentas),miUsuario))
    {
        printf("\n>Muestra de tus ventas:\n");
        mostrarListaVentas((*listaVentas),miUsuario);
        printf("\n\n>Ingrese el ID de la venta a borrar: ");
        scanf("%d",&idVentaABorrar);
        eliminacion=borrarNodoVenta(listaVentas,idVentaABorrar,miUsuario);
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
            printf("\n>[ERROR] El ID de la venta ingresada no corresponde a ninguna de tus ventas. ");
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

int borrarNodoVenta (nodoVenta ** listaVentas,int dato,usuario miUsuario)
{
    int rta=0;
    nodoVenta * seg;
    nodoVenta * ante;
    if((*listaVentas)!=NULL && strcmp(miUsuario.nombre,(*listaVentas)->miVenta.nombreUsuario)==0 && (*listaVentas)->miVenta.idVenta==dato)
    {
        devolverDisponibilidadAProducto((*listaVentas)->miVenta);
        quitarVentaAUsuario(miUsuario,(*listaVentas)->miVenta.miProducto.precio);
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
        if(seg!=NULL && strcmp(miUsuario.nombre,seg->miVenta.nombreUsuario)==0 && seg->miVenta.idVenta==dato)
        {
            ante->sig=seg->sig;
            devolverDisponibilidadAProducto(seg->miVenta);
            quitarVentaAUsuario(miUsuario,seg->miVenta.miProducto.precio);
            free(seg);
            rta=1;
        }
    }
    return rta;
}

void devolverDisponibilidadAProducto (venta miVenta)
{
    producto productoAAgregar;
    productoAAgregar=miVenta.miProducto;
    FILE * archi=fopen(nombreArchivoProductos,"a+b");
    if (archi!=NULL)
    {
        fwrite(&productoAAgregar,sizeof(producto),1,archi);
        fclose(archi);
    }
}

void quitarVentaAUsuario (usuario miUsuario,float precioVenta)
{
    usuario usuarioArchivo;
    FILE * archi=fopen(nombreArchivo,"r+b");
    int band=0;
    if (archi!=NULL)
    {
        while (band==0 && fread(&usuarioArchivo,sizeof(usuario),1,archi)>0)
        {
            if (strcmp(miUsuario.nombre,usuarioArchivo.nombre)==0)
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

//MUESTRA

void iniciarMostrarListaVentas (nodoVenta ** listaVentas,usuario miUsuario)
{
    encabezadoSubMenuVentas();
    printf("\n");
    cargarListaVentasDeArchivo(listaVentas);
    if ((*listaVentas)!=NULL && verificarVentasDelUsuario((*listaVentas),miUsuario))
    {
        printf("\n>Muestra de tus ventas:\n");
        mostrarListaVentas((*listaVentas),miUsuario);
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

void mostrarListaVentas (nodoVenta * listaVentas,usuario miUsuario)
{
    nodoVenta * seg=listaVentas;
    while (seg!=NULL)
    {
        if (strcmp(seg->miVenta.nombreUsuario,miUsuario.nombre)==0)
            mostrarVenta(seg->miVenta);
        seg=seg->sig;
    }
}

void mostrarVenta (venta miVenta)
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

//ESTADISTICAS

void iniciarEstadisticasVentas (nodoVenta ** listaVentas,usuario miUsuario)
{
    system("cls");
    encabezadoSubMenuVentas();
    printf("\n");
    cargarListaVentasDeArchivo(listaVentas);
    if ((*listaVentas)!=NULL && verificarVentasDelUsuario((*listaVentas),miUsuario))
    {
        int dia,mes,anio;
        int op=7;
        while (op<1 || op>4)
        {
            encabezadoEstadisticas();
            printf("\n\n>Ingrese opcion: ");
            scanf("%d",&op);
            system("cls");
            encabezadoSubMenuEstadisticas();
            printf("\n");
            switch (op)
            {
            case 1:
                estadisticasVentas((*listaVentas),miUsuario);
                system("pause");
                break;
            case 2:
                printf("\n>Ingrese el dia: ");
                scanf("%d",&dia);
                printf(">Ingrese el mes: ");
                scanf("%d",&mes);
                printf(">Ingrese el a%co: ",164);
                scanf("%d",&anio);
                estadisticasVentasDia((*listaVentas),miUsuario,dia,mes,anio);
                system("pause");
                break;
            case 3:
                printf("\n>Ingrese el mes: ");
                scanf("%d",&mes);
                printf(">Ingrese el a%co: ",164);
                scanf("%d",&anio);
                estadisticasVentasMes((*listaVentas),miUsuario,anio,mes);
                system("pause");
                break;
            case 4:
                printf("\n>Ingrese el a%co: ",164);
                scanf("%d",&anio);
                estadisticasVentasAnio((*listaVentas),miUsuario,anio);
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

void encabezadoEstadisticas ()
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
    printf("\n%c >Intervalo de tiempo:                                                                      %c",186,186);
    printf("\n%c [1] Siempre                                                                                %c",186,186);
    printf("\n%c [2] Un dia determinado                                                                     %c",186,186);
    printf("\n%c [3] Un mes determinado                                                                     %c",186,186);
    printf("\n%c [4] Un a%co determinado                                                                     %c",186,164,186);
    printf("\n%c [5] Volver                                                                                 %c",186,186);
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

void encabezadoSubMenuEstadisticas ()
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
    printf("\n%c                                    %c ESTADISTICAS %c                                        %c",186,186,186,186);
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

//--->ESTADISTICAS SIEMPRE

void estadisticasVentas (nodoVenta * listaVentas,usuario miUsuario)
{
    nodoVenta * seg=listaVentas;
    //Marca mas vendida. Marca menos vendida.
    int arregloDeContadores[7]= {0},idMarcaMasVendida,idMarcaMenosVendida;
    char marcaMasVendida[a_dim],marcaMenosVendida[a_dim];
    //Venta de mayor precio. Venta de menor precio.
    float precioVentaMasCara=0,precioVentaMasBarata=seg->miVenta.miProducto.precio;
    venta ventaMasCara,ventaMasBarata;
    //Porcentaje de mis ventas/mis ganancias con respecto al total
    float porcentajeVentas=0,porcentajeGanancias=0,gananciasMisVentas=0,gananciasTotalVentas=0;
    int contadorMisVentas=0,contadorTotalVentas=0;
    while (seg!=NULL)
    {
        contadorTotalVentas++;
        gananciasTotalVentas=gananciasTotalVentas+seg->miVenta.miProducto.precio;
        if (strcmp(seg->miVenta.nombreUsuario,miUsuario.nombre)==0)
        {
            contadorMisVentas++;
            gananciasMisVentas=gananciasMisVentas+seg->miVenta.miProducto.precio;
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
    if (contadorTotalVentas!=0)
        porcentajeVentas=(contadorMisVentas*100)/contadorTotalVentas;
    if (gananciasTotalVentas!=0)
        porcentajeGanancias=(gananciasMisVentas*100)/gananciasTotalVentas;
    retornarIdMarcasMasYMenosVendidas(arregloDeContadores,&idMarcaMasVendida,&idMarcaMenosVendida);
    cargarNombreMarca(marcaMasVendida,idMarcaMasVendida);
    cargarNombreMarca(marcaMenosVendida,idMarcaMenosVendida);
    mostrarEstadisticasVentas(marcaMasVendida,marcaMenosVendida,ventaMasCara,ventaMasBarata,miUsuario,porcentajeVentas,porcentajeGanancias);
}

void contadorMarcasMasYMenosVendidas (int idMarca,int arregloDeContadores[])
{
    switch(idMarca)
    {
    case 0:
        arregloDeContadores[0]=arregloDeContadores[0]+1;
        break;
    case 1:
        arregloDeContadores[1]=arregloDeContadores[1]+1;
        break;
    case 2:
        arregloDeContadores[2]=arregloDeContadores[2]+1;
        break;
    case 3:
        arregloDeContadores[3]=arregloDeContadores[3]+1;
        break;
    case 4:
        arregloDeContadores[4]=arregloDeContadores[4]+1;
        break;
    case 5:
        arregloDeContadores[5]=arregloDeContadores[5]+1;
        break;
    case 6:
        arregloDeContadores[6]=arregloDeContadores[6]+1;
        break;
    }
}

void retornarIdMarcasMasYMenosVendidas (int arregloDeContadores[],int * idMarcaMasVendida,int * idMarcaMenosVendida)
{
    int i,cantidadMarcaMasVendida=0,cantidadMarcaMenosVendida=999999;
    for (i=0; i<7; i++)
    {
        if (arregloDeContadores[i]>cantidadMarcaMasVendida)
        {
            cantidadMarcaMasVendida=arregloDeContadores[i];
            (*idMarcaMasVendida)=i;
        }
        if (arregloDeContadores[i]<cantidadMarcaMenosVendida)
        {
            cantidadMarcaMenosVendida=arregloDeContadores[i];
            (*idMarcaMenosVendida)=i;
        }
    }
}

void mostrarEstadisticasVentas (char marcaMasVendida[],char marcaMenosVendida[],venta ventaMasCara,venta ventaMasBarata,usuario miUsuario,float porcentajeVentas,float porcentajeGanancias)
{
    textcolor(10);
    retornarVentasUsuario(&miUsuario);
    printf("\n%c %s - Reporte de estadisticas de mis ventas",254,miUsuario.nombre);
    textcolor(15);
    printf("\n\n%c Ventas: %i",205,miUsuario.ventas);
    printf("\n\n%c%c> En porcentaje con respecto a todo el concesionario: %%%0.2f",192,196,porcentajeVentas);
    printf("\n\n%c Suma total de las ganancias de las ventas: $%0.2f",205,miUsuario.sumaVentas);
    printf("\n\n%c%c> En porcentaje con respecto a todo el concesionario: %%%0.2f",192,196,porcentajeGanancias);
    printf("\n\n%c Marca mas vendida: %s",205,marcaMasVendida);
    printf("\n\n%c Marca menos vendida: %s",205,marcaMenosVendida);
    printf("\n\n>Venta de mayor precio:\n");
    mostrarVenta(ventaMasCara);
    printf("\n\n>Venta de menor precio:\n");
    mostrarVenta(ventaMasBarata);
    printf("\n\n");
}

void retornarVentasUsuario (usuario * miUsuario)
{
    usuario usuarioArchivo;
    int rta=0;
    FILE * archi=fopen(nombreArchivo,"rb");
    if (archi!=NULL)
    {
        while(rta==0 && fread(&usuarioArchivo,sizeof(usuario),1,archi)>0)
        {
            if (strcmp(usuarioArchivo.nombre,(*miUsuario).nombre)==0)
            {
                (*miUsuario).ventas=usuarioArchivo.ventas;
                (*miUsuario).sumaVentas=usuarioArchivo.sumaVentas;
                rta=1;
            }
        }
        fclose(archi);
    }
}

//--->ESTADISTICAS DIA

void estadisticasVentasDia (nodoVenta * listaVentas,usuario miUsuario,int dia,int mes,int anio)
{
    system("cls");
    encabezadoSubMenuEstadisticas();
    printf("\n");
    nodoVenta * seg=listaVentas;
    //Marca mas vendida. Marca menos vendida.
    int arregloDeContadores[7]= {0},idMarcaMasVendida,idMarcaMenosVendida;
    char marcaMasVendida[a_dim],marcaMenosVendida[a_dim];
    //Venta de mayor precio. Venta de menor precio.
    float precioVentaMasCara=0,precioVentaMasBarata=seg->miVenta.miProducto.precio;
    venta ventaMasCara,ventaMasBarata;
    //Porcentaje de mis ventas/mis ganancias con respecto al total
    float porcentajeVentas=0,porcentajeGanancias=0,gananciasMisVentas=0,gananciasTotalVentas=0;
    int contadorMisVentas=0,contadorTotalVentas=0;
    while (seg!=NULL)
    {
        if (seg->miVenta.anio==anio && seg->miVenta.mes==mes && seg->miVenta.dia==dia)
        {
            contadorTotalVentas++;
            gananciasTotalVentas=gananciasTotalVentas+seg->miVenta.miProducto.precio;
            if (strcmp(seg->miVenta.nombreUsuario,miUsuario.nombre)==0)
            {
                contadorMisVentas++;
                gananciasMisVentas=gananciasMisVentas+seg->miVenta.miProducto.precio;
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
        }
        seg=seg->sig;
    }
    if (contadorTotalVentas!=0)
        porcentajeVentas=(contadorMisVentas*100)/contadorTotalVentas;
    if (gananciasTotalVentas!=0)
        porcentajeGanancias=(gananciasMisVentas*100)/gananciasTotalVentas;
    retornarIdMarcasMasYMenosVendidas(arregloDeContadores,&idMarcaMasVendida,&idMarcaMenosVendida);
    cargarNombreMarca(marcaMasVendida,idMarcaMasVendida);
    cargarNombreMarca(marcaMenosVendida,idMarcaMenosVendida);
    mostrarEstadisticasVentasDia(listaVentas,marcaMasVendida,marcaMenosVendida,ventaMasCara,ventaMasBarata,miUsuario,porcentajeVentas,porcentajeGanancias,dia,mes,anio);
}

void mostrarEstadisticasVentasDia (nodoVenta * listaVentas,char marcaMasVendida[],char marcaMenosVendida[],venta ventaMasCara,venta ventaMasBarata,usuario miUsuario,float porcentajeVentas,float porcentajeGanancias,int dia,int mes,int anio)
{
    textcolor(10);
    retornarVentasUsuarioDia(listaVentas,&miUsuario,dia,mes,anio);
    if (miUsuario.ventas!=0)
    {
        printf("\n%c %s - Reporte de estadisticas de mis ventas - %i/%i/%i",254,miUsuario.nombre,dia,mes,anio);
        textcolor(15);
        printf("\n\n%c Ventas: %i",205,miUsuario.ventas);
        printf("\n\n%c%c> En porcentaje con respecto a todo el concesionario: %%%0.2f",192,196,porcentajeVentas);
        printf("\n\n%c Suma total de las ganancias de las ventas: $%0.2f",205,miUsuario.sumaVentas);
        printf("\n\n%c%c> En porcentaje con respecto a todo el concesionario: %%%0.2f",192,196,porcentajeGanancias);
        printf("\n\n%c Marca mas vendida: %s",205,marcaMasVendida);
        printf("\n\n%c Marca menos vendida: %s",205,marcaMenosVendida);
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

void retornarVentasUsuarioDia (nodoVenta * listaVentas,usuario * miUsuario,int dia,int mes,int anio)
{
    int contadorVentas=0;
    float acumuladorGanancias=0;
    nodoVenta * seg=listaVentas;
    while (seg!=NULL)
    {
        if (strcmp(seg->miVenta.nombreUsuario,(*miUsuario).nombre)==0 && seg->miVenta.anio==anio && seg->miVenta.mes==mes && seg->miVenta.dia==dia)
        {
            contadorVentas++;
            acumuladorGanancias=acumuladorGanancias+seg->miVenta.miProducto.precio;
        }
        seg=seg->sig;
    }
    (*miUsuario).sumaVentas=acumuladorGanancias;
    (*miUsuario).ventas=contadorVentas;
}

//--->ESTADISTICAS MES

void estadisticasVentasMes (nodoVenta * listaVentas,usuario miUsuario,int anio,int mes)
{
    system("cls");
    encabezadoSubMenuEstadisticas();
    printf("\n");
    nodoVenta * seg=listaVentas;
    //Marca mas vendida. Marca menos vendida.
    int arregloDeContadores[7]= {0},idMarcaMasVendida,idMarcaMenosVendida;
    char marcaMasVendida[a_dim],marcaMenosVendida[a_dim];
    //Venta de mayor precio. Venta de menor precio.
    float precioVentaMasCara=0,precioVentaMasBarata=seg->miVenta.miProducto.precio;
    venta ventaMasCara,ventaMasBarata;
    //Porcentaje de mis ventas/mis ganancias con respecto al total
    float porcentajeVentas=0,porcentajeGanancias=0,gananciasMisVentas=0,gananciasTotalVentas=0;
    int contadorMisVentas=0,contadorTotalVentas=0;
    while (seg!=NULL)
    {
        if (seg->miVenta.anio==anio && seg->miVenta.mes==mes)
        {
            contadorTotalVentas++;
            gananciasTotalVentas=gananciasTotalVentas+seg->miVenta.miProducto.precio;
            if (strcmp(seg->miVenta.nombreUsuario,miUsuario.nombre)==0)
            {
                contadorMisVentas++;
                gananciasMisVentas=gananciasMisVentas+seg->miVenta.miProducto.precio;
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
        }
        seg=seg->sig;
    }
    if (contadorTotalVentas!=0)
        porcentajeVentas=(contadorMisVentas*100)/contadorTotalVentas;
    if (gananciasTotalVentas!=0)
        porcentajeGanancias=(gananciasMisVentas*100)/gananciasTotalVentas;
    retornarIdMarcasMasYMenosVendidas(arregloDeContadores,&idMarcaMasVendida,&idMarcaMenosVendida);
    cargarNombreMarca(marcaMasVendida,idMarcaMasVendida);
    cargarNombreMarca(marcaMenosVendida,idMarcaMenosVendida);
    mostrarEstadisticasVentasMes(listaVentas,marcaMasVendida,marcaMenosVendida,ventaMasCara,ventaMasBarata,miUsuario,porcentajeVentas,porcentajeGanancias,anio,mes);
}

void mostrarEstadisticasVentasMes (nodoVenta * listaVentas,char marcaMasVendida[],char marcaMenosVendida[],venta ventaMasCara,venta ventaMasBarata,usuario miUsuario,float porcentajeVentas,float porcentajeGanancias,int anio,int mes)
{
    textcolor(10);
    retornarVentasUsuarioMes(listaVentas,&miUsuario,anio,mes);
    if (miUsuario.ventas!=0)
    {
        printf("\n%c %s - Reporte de estadisticas de mis ventas - %i/%i",254,miUsuario.nombre,mes,anio);
        textcolor(15);
        printf("\n\n%c Ventas: %i",205,miUsuario.ventas);
        printf("\n\n%c%c> En porcentaje con respecto a todo el concesionario: %%%0.2f",192,196,porcentajeVentas);
        printf("\n\n%c Suma total de las ganancias de las ventas: $%0.2f",205,miUsuario.sumaVentas);
        printf("\n\n%c%c> En porcentaje con respecto a todo el concesionario: %%%0.2f",192,196,porcentajeGanancias);
        printf("\n\n%c Marca mas vendida: %s",205,marcaMasVendida);
        printf("\n\n%c Marca menos vendida: %s",205,marcaMenosVendida);
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

void retornarVentasUsuarioMes (nodoVenta * listaVentas,usuario * miUsuario,int anio,int mes)
{
    int contadorVentas=0;
    float acumuladorGanancias=0;
    nodoVenta * seg=listaVentas;
    while (seg!=NULL)
    {
        if (strcmp(seg->miVenta.nombreUsuario,(*miUsuario).nombre)==0 && seg->miVenta.anio==anio && seg->miVenta.mes==mes)
        {
            contadorVentas++;
            acumuladorGanancias=acumuladorGanancias+seg->miVenta.miProducto.precio;
        }
        seg=seg->sig;
    }
    (*miUsuario).sumaVentas=acumuladorGanancias;
    (*miUsuario).ventas=contadorVentas;
}

//--->ESTADISTICAS AÑO

void estadisticasVentasAnio (nodoVenta * listaVentas,usuario miUsuario,int anio)
{
    system("cls");
    encabezadoSubMenuEstadisticas();
    printf("\n");
    nodoVenta * seg=listaVentas;
    //Marca mas vendida. Marca menos vendida.
    int arregloDeContadores[7]= {0},idMarcaMasVendida,idMarcaMenosVendida;
    char marcaMasVendida[a_dim],marcaMenosVendida[a_dim];
    //Venta de mayor precio. Venta de menor precio.
    float precioVentaMasCara=0,precioVentaMasBarata=seg->miVenta.miProducto.precio;
    venta ventaMasCara,ventaMasBarata;
    //Porcentaje de mis ventas/mis ganancias con respecto al total
    float porcentajeVentas=0,porcentajeGanancias=0,gananciasMisVentas=0,gananciasTotalVentas=0;
    int contadorMisVentas=0,contadorTotalVentas=0;
    while (seg!=NULL)
    {
        if (seg->miVenta.anio==anio)
        {
            contadorTotalVentas++;
            gananciasTotalVentas=gananciasTotalVentas+seg->miVenta.miProducto.precio;
            if (strcmp(seg->miVenta.nombreUsuario,miUsuario.nombre)==0)
            {
                contadorMisVentas++;
                gananciasMisVentas=gananciasMisVentas+seg->miVenta.miProducto.precio;
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
        }
        seg=seg->sig;
    }
    if (contadorTotalVentas!=0)
        porcentajeVentas=(contadorMisVentas*100)/contadorTotalVentas;
    if (gananciasTotalVentas!=0)
        porcentajeGanancias=(gananciasMisVentas*100)/gananciasTotalVentas;
    retornarIdMarcasMasYMenosVendidas(arregloDeContadores,&idMarcaMasVendida,&idMarcaMenosVendida);
    cargarNombreMarca(marcaMasVendida,idMarcaMasVendida);
    cargarNombreMarca(marcaMenosVendida,idMarcaMenosVendida);
    mostrarEstadisticasVentasAnio(listaVentas,marcaMasVendida,marcaMenosVendida,ventaMasCara,ventaMasBarata,miUsuario,porcentajeVentas,porcentajeGanancias,anio);
}

void mostrarEstadisticasVentasAnio (nodoVenta * listaVentas,char marcaMasVendida[],char marcaMenosVendida[],venta ventaMasCara,venta ventaMasBarata,usuario miUsuario,float porcentajeVentas,float porcentajeGanancias,int anio)
{
    textcolor(10);
    retornarVentasUsuarioAnio(listaVentas,&miUsuario,anio);
    if (miUsuario.ventas!=0)
    {
        printf("\n%c %s - Reporte de estadisticas de mis ventas - %i",254,miUsuario.nombre,anio);
        textcolor(15);
        printf("\n\n%c Ventas: %i",205,miUsuario.ventas);
        printf("\n\n%c%c> En porcentaje con respecto a todo el concesionario: %%%0.2f",192,196,porcentajeVentas);
        printf("\n\n%c Suma total de las ganancias de las ventas: $%0.2f",205,miUsuario.sumaVentas);
        printf("\n\n%c%c> En porcentaje con respecto a todo el concesionario: %%%0.2f",192,196,porcentajeGanancias);
        printf("\n\n%c Marca mas vendida: %s",205,marcaMasVendida);
        printf("\n\n%c Marca menos vendida: %s",205,marcaMenosVendida);
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

void retornarVentasUsuarioAnio (nodoVenta * listaVentas,usuario * miUsuario,int anio)
{
    int contadorVentas=0;
    float acumuladorGanancias=0;
    nodoVenta * seg=listaVentas;
    while (seg!=NULL)
    {
        if (strcmp(seg->miVenta.nombreUsuario,(*miUsuario).nombre)==0 && seg->miVenta.anio==anio)
        {
            contadorVentas++;
            acumuladorGanancias=acumuladorGanancias+seg->miVenta.miProducto.precio;
        }
        seg=seg->sig;
    }
    (*miUsuario).sumaVentas=acumuladorGanancias;
    (*miUsuario).ventas=contadorVentas;
}
