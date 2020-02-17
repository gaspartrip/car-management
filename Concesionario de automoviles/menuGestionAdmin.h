#ifndef MENUGESTIONADMIN_H_INCLUDED
#define MENUGESTIONADMIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "menuProductosClientesVentas.h"

//->MODO ADMINISTRADOR

//MENU Y ENCABEZADOS
void menuGestionAdmin ();
void encabezadoMenuVentasAdmin ();
void encabezadoSubMenuVentasAdmin ();
//MUESTRA DE TODAS LAS VENTAS
void iniciarMostrarListaVentasAdmin (nodoVenta **);
void mostrarListaVentasAdmin (nodoVenta *);
void mostrarVentaAdmin (venta);
//ELIMINACION DE UNA VENTA
void iniciarBorrarNodoEnListaVentasAdmin (nodoVenta **);
int borrarNodoVentaAdmin (nodoVenta **,int);
void quitarVentaAUsuarioAdmin (char[],float);

//ESTADISTICAS
void iniciarEstadisticasVentas_Admin (nodoVenta **);
void datosUsuarios (nodoVenta *,char[],int *,char[],int *,int,int,int);
int retornarCantidadVentasUsuario (nodoVenta *,char[],int,int,int);
//--->ESTADISTICAS SIEMPRE
void estadisticasVentas_Admin (nodoVenta * listaVentas);
void mostrarEstadisticasVentas_Admin (char[],char[],venta,venta,int,float,char[],int,char[],int);
//--->ESTADISTICAS DIA
void estadisticasVentasDia_Admin (nodoVenta *,int,int,int);
void mostrarEstadisticasVentasDia_Admin (nodoVenta *,char[],char[],venta,venta,int,float,char[],int,char[],int,int,int,int);
//--->ESTADISTICAS MES
void estadisticasVentasMes_Admin (nodoVenta *,int,int);
void mostrarEstadisticasVentasMes_Admin (nodoVenta *,char[],char[],venta,venta,int,float,char[],int,char[],int,int,int);
//--->ESTADISTICAS AÑO
void estadisticasVentasAnio_Admin (nodoVenta * listaVentas,int anio);
void mostrarEstadisticasVentasAnio_Admin (nodoVenta *,char[],char[],venta,venta,int,float,char[],int,char[],int,int);
//MUESTRA DE TODOS LOS USUARIOS
void iniciarMostrarUsuarios ();
int comprobarExistenciaUsuarios ();
void mostrarUsuario (usuario);
//ELIMINACION DE UN USUARIO
void iniciarBorrarUsuario ();
int contarCantidadUsuarios ();
void cargarListaUsuariosNueva (usuario[],int);

#endif // MENUGESTIONADMIN_H_INCLUDED
