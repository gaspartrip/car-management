#ifndef MENUPRODUCTOSCLIENTESVENTAS_H_INCLUDED
#define MENUPRODUCTOSCLIENTESVENTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define a_dim 50 //Dimension por defecto de los arreglos de char mas usados en las estructuras

const char nombreArchivoProductos[15];
const char nombreArchivoClientes[15];
const char nombreArchivoVentas[15];
const char nombreArchivo[15];

//--------------------------------REGISTROS--------------------------------

//->USUARIO

typedef struct
{
    char nombre[a_dim];
    char pass[a_dim];
    int ventas;
    float sumaVentas;
} usuario;

//->PRODUCTO

typedef struct
{
    int idProducto;
    int idMarca;
    char nombre[a_dim];
    float km;
    float precio;
} producto;

typedef struct
{
    producto miProducto;
    struct nodoArbolProducto * izq;
    struct nodoArbolProducto * der;
} nodoArbolProducto;

//->CLIENTE

typedef struct
{
    int idCliente;
    char nombreYApellido[a_dim];
    char telefono[a_dim];
    char dni[a_dim];
} cliente;

typedef struct
{
    cliente miCliente;
    struct nodoCliente * sig;
} nodoCliente;

//->VENTA

typedef struct
{
    int idVenta;
    cliente miCliente;
    producto miProducto;
    char nombreUsuario[a_dim];
    int dia;
    int mes;
    int anio;
} venta;

typedef struct
{
    venta miVenta;
    struct nodoVenta * sig;
} nodoVenta;


//--------------------------------FUNCIONES--------------------------------


//->PRODUCTOS - Forma de trabajo: Estructura compuesta mediante el uso de un arreglo de arboles binarios.

//MENU Y ENCABEZADOS
void menuProductos ();
void encabezadoMenuProductos ();
void encabezadoSubMenuProductos ();
//ALTA DE NODOS
void inicArregloArbolesProductos (nodoArbolProducto *[],int);
void cargarArregloArbolesProductos (nodoArbolProducto **,int);
int cargarProducto (producto *,nodoArbolProducto *[],int,int*);
int retornarIdMasGrande_Producto ();
int buscarNodoEnArbolProductos_PorId (nodoArbolProducto *,int);
void crearNodoProducto (nodoArbolProducto **,producto);
nodoArbolProducto * insertarUnNodoAlArbolProductos (nodoArbolProducto *,nodoArbolProducto *);
//CARGA Y GUARDADO EN ARCHIVO
void guardarProductosEnArchivo (nodoArbolProducto *[],int);
void guardarProductosEnArchivoNuevo (nodoArbolProducto *[],int);
void cargarArregloArbolesProductosDeArchivo (nodoArbolProducto *[]);
//ELIMINACION Y MODIFICACION
int arregloVacio (nodoArbolProducto *[],int);
void borrarArregloArbolesProductos_PorIdProducto (nodoArbolProducto *[],int);
void iniciarBorrarNodoEnArregloArbolesProductos (nodoArbolProducto *[],int);
int borrarNodoEnArregloArbolesProductos_PorIdProducto (nodoArbolProducto *[],int,int);
nodoArbolProducto * borrarNodoEnArbolProductos_PorIdProducto (nodoArbolProducto *,int);
nodoArbolProducto * NMD (nodoArbolProducto *);
nodoArbolProducto * NMI (nodoArbolProducto *);
void iniciarModificarNodoEnArregloArbolesProductos (nodoArbolProducto *[],int);
int modificarNodoEnArregloArbolesProductos_PorIdProducto (nodoArbolProducto *[],int,int);
nodoArbolProducto * modificarNodoEnArbolProductos_PorIdProducto (nodoArbolProducto *,int);
producto modificarProducto (producto);
//MUESTRA
void iniciarMostrarArregloArbolesProductos (nodoArbolProducto *[],int);
void mostrarArregloArbolesProductos (nodoArbolProducto *[],int);
void cargarNombreMarca (char[],int);
void preOrden (nodoArbolProducto *);
void mostrarProducto (producto);

//->CLIENTES - Forma de trabajo: Lista enlazadada simple. Las funciones solo usan punteros dobles.

//MENU Y ENCABEZADOS
void menuClientes ();
void encabezadoMenuClientes ();
void encabezadoSubMenuClientes ();
//ALTA DE NODOS
void inicListaClientes (nodoCliente **);
void cargarListaClientes (nodoCliente **);
int cargarCliente (cliente *,nodoCliente **,int*);
int retornarIdMasGrande_Cliente ();
int comprobarNoRepeticionDNIClienteEnArchivo (char[]);
int comprobarNoRepeticionDNIClienteEnLista (nodoCliente *,char[]);
void crearNodoCliente (nodoCliente **,cliente);
void agregarUnNodoClienteAlFinal (nodoCliente **,nodoCliente *);
void buscarUltimoNodoCliente (nodoCliente **,nodoCliente **);
//CARGA Y GUARDADO EN ARCHIVO
void guardarClientesEnArchivo (nodoCliente **);
void guardarClientesEnArchivoNuevo (nodoCliente **);
void cargarListaClientesDeArchivo (nodoCliente **);
//ELIMINACION Y MODIFICACION
void borrarListaClientes (nodoCliente **);
void iniciarBorrarNodoEnListaClientes (nodoCliente **);
int borrarNodoCliente (nodoCliente **,int);
void iniciarModificarNodoEnListaClientes (nodoCliente **);
int modificarNodoCliente (nodoCliente **,int);
cliente modificarCliente (cliente);
//MUESTRA
void iniciarMostrarListaClientes (nodoCliente **);
void mostrarListaClientes (nodoCliente *);
void mostrarCliente (cliente);

//->VENTAS - Forma de trabajo: Lista enlazadada simple. Las funciones solo usan punteros dobles.

//MENU Y ENCABEZADOS
void menuVentas (usuario);
void encabezadoMenuVentas ();
void encabezadoSubMenuVentas ();
//ALTA DE NODOS
void inicListaVentas (nodoVenta **);
void cargarListaVentas (nodoVenta **,usuario);
int comprobacionExistenciaClientesYProductos ();
int cargarVenta (venta *,nodoVenta **,usuario,int*);
void borrarProductoPostVenta (int);
int retornarIdMasGrande_Venta ();
void mostrarClientesDelArchivo ();
void mostrarProductosDelArchivo ();
int comprobarNoRepeticionIdClienteEnArchivo (int);
int comprobarProductoDeVenta (int);
producto retornarProductoVenta (int);
cliente retornarClienteVenta (int);
void crearNodoVenta (nodoVenta **,venta);
void agregarUnNodoVentaAlFinal (nodoVenta **,nodoVenta *);
void buscarUltimoNodoVenta (nodoVenta **,nodoVenta **);
//CARGA Y GUARDADO EN ARCHIVO
void guardarVentasEnArchivo (nodoVenta **,usuario);
void guardarVentaDeUsuario (usuario,float);
void guardarVentasEnArchivoNuevo (nodoVenta **);
void cargarListaVentasDeArchivo (nodoVenta **);
int verificarVentasDelUsuario (nodoVenta *,usuario);
//ELIMINACION
void borrarListaVentas (nodoVenta **);
void iniciarBorrarNodoEnListaVentas (nodoVenta **,usuario);
int borrarNodoVenta (nodoVenta **,int,usuario);
void devolverDisponibilidadAProducto (venta);
void quitarVentaAUsuario (usuario,float);
//MUESTRA
void iniciarMostrarListaVentas (nodoVenta **,usuario);
void mostrarListaVentas (nodoVenta *,usuario);
void mostrarVenta (venta);
//ESTADISTICAS
void iniciarEstadisticasVentas (nodoVenta **,usuario);
void encabezadoEstadisticas ();
void encabezadoSubMenuEstadisticas ();
//--->ESTADISTICAS SIEMPRE
void estadisticasVentas (nodoVenta *,usuario);
void contadorMarcasMasYMenosVendidas (int,int[]);
void retornarIdMarcasMasYMenosVendidas (int[],int *,int *);
void mostrarEstadisticasVentas (char[],char[],venta,venta,usuario,float,float);
void retornarVentasUsuario (usuario *);
//--->ESTADISTICAS DIA
void estadisticasVentasDia (nodoVenta *,usuario,int,int,int);
void mostrarEstadisticasVentasDia (nodoVenta *,char[],char[],venta,venta,usuario,float,float,int,int,int);
void retornarVentasUsuarioDia (nodoVenta *,usuario *,int,int,int);
//--->ESTADISTICAS MES
void estadisticasVentasMes (nodoVenta *,usuario,int,int);
void mostrarEstadisticasVentasMes (nodoVenta *,char[],char[],venta,venta,usuario,float,float,int,int);
void retornarVentasUsuarioMes (nodoVenta *,usuario *,int,int);
//--->ESTADISTICAS AÑO
void estadisticasVentasAnio (nodoVenta *,usuario,int);
void mostrarEstadisticasVentasAnio (nodoVenta *,char[],char[],venta,venta,usuario,float,float,int);
void retornarVentasUsuarioAnio (nodoVenta *,usuario *,int);

#endif // MENUPRODUCTOSCLIENTESVENTAS_H_INCLUDED
