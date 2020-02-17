#ifndef MENUSESIONUSUARIO_H_INCLUDED
#define MENUSESIONUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "menuGestion.h"

//ENCABEZADO - [1] Iniciar sesion [2] Crear una cuenta [3] Salir
void menuPrincipal ();
//INICIO SESION
void menuInicioSesionUsuario ();
void encabezadoMenuInicioSesionUsuario ();
int comprobarDatosUsuario (usuario);
//CREACION CUENTA
void menuCreacionUsuario ();
void encabezadoMenuCreacionUsuario ();
int comprobarExistenciaUsuario (usuario);

#endif // MENUSESIONUSUARIO_H_INCLUDED
