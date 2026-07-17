/* ==========================================================
ARCHIVO: main.c
Descripcion: Archivo principal del programa. Inicializa las bases de 
datos (arreglos) en cero y llama al controlador del Menu Principal 
para arrancar el sistema.

Instrucciones de compilacion (GCC):
gcc main.c CreateUpdate.c readDelete.c -o sistema_vuelos

Instrucciones de ejecucion:
Windows: .\sistema_vuelos.exe
Mac/Linux: ./sistema_vuelos
========================================================== */

#include "CreateUpdate.h"

int main(){
	
	Pista pistasAeropuerto[MAX_PISTAS] = {0};
	
	Vuelo vuelosAeropuerto[MAX_VUELOS] = {0};
	
	MenuPrincipal(vuelosAeropuerto, pistasAeropuerto);
	
	return 0;
	
}
