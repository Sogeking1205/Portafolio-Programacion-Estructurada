/* ==========================================================
ARCHIVO: CreateUpdate.h
Descripcion: Archivo de cabecera que define las estructuras de datos 
(Pista y Vuelo) y declara las funciones correspondientes a los 
modulos de registro (Create), actualizacion (Update) y el menu principal.
========================================================== */

/* Evita que este archivo se abra mas de una vez y choque el programa */
#ifndef CREATEUPDATE_H
#define CREATEUPDATE_H

#include <stdio.h>
#include <string.h>

#define MAX_PISTAS 20
#define MAX_VUELOS MAX_PISTAS
// Estructura para guardar los datos de la pista de aterrizaje
typedef struct {
	int id_pista;
	int estadoPista;
} Pista;
// Estructura para guardar los datos de cada vuelo
typedef struct {
	char aerolinea[15];
	char origenDestino[30];
	char horaLlegadaSalida[30];
	int estadoVuelo; // 0: programado, 1: abordando, 2: despegando, 3: aterrizado, 4: retrasado 
	int id_pistaAsignada;
	char id_vuelo[30];
} Vuelo;

void MenuPrincipal(Vuelo vuelos[], Pista pistas[]);

void IntroducirDatos(Vuelo vuelos[], Pista pistas[]);
void ImprimirPistas(Pista pistas[]);
int BuscarVuelo(Vuelo vuelos[], char Id_vuelo[]);
int BuscarEspacio(Vuelo vuelos[]);

void AsignarAerolinea(Vuelo *vueloTemp);
void AsignarHoraLlegadaSalida(Vuelo *vueloTemp);
void AsignarOrigenDestino(Vuelo *vueloTemp);
void AsignarPista(Vuelo *vueloTemp, Pista pistas[]);
void GenerarIdVuelo(Vuelo *vueloTemp, Vuelo vuelos[]);
void AsignarEstadoVuelo(Vuelo *vueloTemp);

void CambiarDatos(Vuelo vuelos[], Pista pistas[]);

void ActualizarPista(Vuelo *vueloActualizar, Pista pistas[]);
void IdentificarEstadoVuelo(Vuelo *vueloActualizar);
void CambiarEstadoVuelo(Vuelo *vueloActualizar);
void MenuActualizarDatos(Vuelo vuelos[], int indice, Pista pistas[]);

#endif
