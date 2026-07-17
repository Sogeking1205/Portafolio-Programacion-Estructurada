/* ==========================================================
ARCHIVO: ReadDelete.h
Descripcion: Archivo de cabecera que declara las funciones correspondientes 
a los modulos de lectura (Read), eliminacion de vuelos (Delete) y estadisticas.
========================================================== */

/* Evita que este archivo se abra mas de una vez y choque el programa */
#ifndef READDELETE_H
#define READDELETE_H

#include "CreateUpdate.h"

int MostrarMenuVerVuelos();
void ConsultarVueloEspecifico(Vuelo vuelos[MAX_VUELOS]);

void ImprimirDatosVuelos(Vuelo vuelos[MAX_VUELOS]);
void VerVuelos(Vuelo vuelos[MAX_VUELOS]);
void ImprimirVuelos(Vuelo vuelos[MAX_VUELOS]);
void BorrarVuelo(Vuelo vuelos[MAX_VUELOS], int indice, Pista pistas[MAX_PISTAS]);
void CancelarVuelos(Vuelo vuelos[MAX_VUELOS], Pista pistas[MAX_PISTAS]);
int CalcularEstadisticas(Vuelo vuelos[MAX_VUELOS], float porcentajes[5]);
void DesplegarEstadisticas(float porcentajes[5], int totalActivos);
void VerEstadisticas(Vuelo vuelos[MAX_VUELOS]) ;

#endif
