#include "ReadDelete.h"
#include <stdio.h>
#include <string.h>

#define MAX_PISTAS 20
#define MAX_VUELOS MAX_PISTAS


/* ==========================================================
MODULO 4: Actualizar Vuelo (Update)
Flujo: MenuActualizaDatos -> IntroducirDatos / AsignarAerolinea / AsignarHoraLlegadaSalida / AsignarOrigenDestino / AsignarPista / GenerarId
========================================================== */

/* * ---------------------------------------------------------- 
* Funcion: MenuActualizarDatos 
* Descripcion: Submodulo 4.1.3 - Despliega los datos del vuelo como opciones especificas a modificar
* Parametros: 
* vuelos (Vuelo[]) arreglo de estructuras de los vuelos 
* indice (int) posicion especifica del vuelo a modificar
* pistas (Pista[]) arreglo de estructuras de las pistas 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void MenuActualizarDatos(Vuelo vuelos[], int indice, Pista pistas[]) {
	int opcion = 0;
	do {
		printf("\n\t--- EDITANDO VUELO: %s ---\n\n", vuelos[indice].id_vuelo);
		printf("\t1. Cambiar Aerolinea\n");
		printf("\t2. Cambiar Origen y Destino\n");
		printf("\t3. Cambiar Hora de Llegada/Salida\n");
		printf("\t4. Cambiar Pista Asignada\n");
		printf("\t5. Cambiar Estado del Vuelo\n");
		printf("\t6. Regresar al Menu Principal\n");
		printf("\tSeleccione el dato a modificar: ");
		scanf("%i", &opcion);
		
		switch(opcion) {
		case 1: 
			AsignarAerolinea(&vuelos[indice]); 
			break;
		case 2: 
			AsignarOrigenDestino(&vuelos[indice]); 
			break;
		case 3: 
			AsignarHoraLlegadaSalida(&vuelos[indice]); 
			break;
		case 4: 
			ActualizarPista(&vuelos[indice], pistas); 
			break;
		case 5: 
			CambiarEstadoVuelo(&vuelos[indice]); 
			break;
		case 6: printf("\tRegresando...\n"); break;
		default: printf("\tOpcion invalida.\n"); break;
		}
	} while (opcion != 6);
}

/* * ---------------------------------------------------------- 
* Funcion: CambiarDatos 
* Descripcion: Submodulo 4.1 - Despliega los vuelos registrados para buscar y cambiar datos del vuelo elegido por el usuario
* Parametros: 
* vuelos (Vuelo[]) arreglo de estructuras de los vuelos 
* pistas (Pista[]) arreglo de estructuras de las pistas 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void CambiarDatos(Vuelo vuelos[], Pista pistas[]) {
	char idBusqueda[30];
	
	printf("Ingrese el ID del vuelo a modificar: ");
	scanf("%s", idBusqueda);
	
	int indice = BuscarVuelo(vuelos, idBusqueda);
	
	if (indice == -1) {
		printf("\n\tError: El vuelo '%s' no existe en el sistema.\n", idBusqueda);
	} else {
		MenuActualizarDatos(vuelos, indice, pistas);
	}
}

/* * ---------------------------------------------------------- 
* Funcion: ActualizarPista 
* Descripcion: Submodulo 4.1.3.4 - Imprime las pistas disponibles y le pide al usuario el Id de la pista para asignarla al vuelo
* Parametros: 
* vueloActualizar (Vuelo*) puntero a la estructura del vuelo a modificar
* pistas (Pista[]) arreglo de estructuras de las pistas 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void ActualizarPista(Vuelo *vueloActualizar, Pista pistas[]) {
	if (vueloActualizar->id_pistaAsignada > 0 && vueloActualizar->id_pistaAsignada <= MAX_PISTAS) {
		pistas[vueloActualizar->id_pistaAsignada - 1].estadoPista = 0;
	}
	AsignarPista(vueloActualizar, pistas);
}

/* * ---------------------------------------------------------- 
* Funcion: IdentificarEstadoVuelo 
* Descripcion: Submodulo 4.1.3.5.1 - Identifica el estado actual del vuelo elegido
* Parametros: 
* vueloActualizar (Vuelo*) puntero a la estructura del vuelo a evaluar
* Retorna: void 
* ---------------------------------------------------------- 
*/
void IdentificarEstadoVuelo(Vuelo *vueloActualizar) {
	char textoEstado[20];
	switch(vueloActualizar->estadoVuelo) {
	case 0: 
		strcpy(textoEstado, "Programado"); 
		break;
	case 1: 
		strcpy(textoEstado, "Abordando"); 
		break;
	case 2: 
		strcpy(textoEstado, "Despegando"); 
		break;
	case 3: 
		strcpy(textoEstado, "Aterrizado"); 
		break;
	case 4: 
		strcpy(textoEstado, "Retrasado"); 
		break;
	default: 
		strcpy(textoEstado, "Desconocido"); 
		break;
	}
	printf("\n\tEstado actual del vuelo: %s\n", textoEstado);
}

/* * ---------------------------------------------------------- 
* Funcion: CambiarEstadoVuelo 
* Descripcion: Submodulo 4.1.3.5.2 - Dependiendo del estado actual del vuelo despliega las opciones de estado y lo cambia
* Parametros: 
* vueloActualizar (Vuelo*) puntero a la estructura del vuelo a modificar
* Retorna: void 
* ---------------------------------------------------------- 
*/
void CambiarEstadoVuelo(Vuelo *vueloActualizar) {
	int nuevoEstado = -1;
	int estadoValido = 0;
	int estadoActual = vueloActualizar->estadoVuelo;
	
	IdentificarEstadoVuelo(vueloActualizar);
	
	/* Si el vuelo ya aterriza, bloqueamos mas cambios*/
	if (estadoActual == 3) {
		printf("\tEl vuelo ya ha aterrizado. No es posible realizar mas cambios de estado.\n");
		return;
	}
	
	printf("\tOpciones permitidas para este vuelo:\n");
	
	// Mostrar opciones según el estado actual
	switch (estadoActual) {
	case 0:
		printf("\t1 - Abordando\n\t4 - Retrasado\n");
		break;
	case 1:
		printf("\t2 - Despegando\n\t4 - Retrasado\n");
		break;
	case 2:
		printf("\t3 - Aterrizado\n");
		break;
	case 4:
		printf("\t0 - Programado\n\t1 - Abordando\n");
		break;
	}
	
	do {
		printf("\tIngrese el nuevo estado del vuelo: ");
		scanf("%i", &nuevoEstado);
		
		/* Reglas de validacion de flujo */
		if (estadoActual == 0 && (nuevoEstado == 1 || nuevoEstado == 4)) estadoValido = 1;
		else if (estadoActual == 1 && (nuevoEstado == 2 || nuevoEstado == 4)) {
			estadoValido = 1;
		}
		else if (estadoActual == 2 && (nuevoEstado == 3)) {
			estadoValido = 1;
		}
		else if (estadoActual == 4 && (nuevoEstado == 0 || nuevoEstado == 1)) {
			estadoValido = 1;
		}
		if (!estadoValido) {
			printf("\tEstado invalido. Intente nuevamente.\n");
		}
		
	} while(!estadoValido);
	
	vueloActualizar->estadoVuelo = nuevoEstado;
	printf("\tEstado actualizado exitosamente.\n");
}
// ---------------------------------------------------

/* ==========================================================
MODULO 3: Menu Principal (control de opciones)
Flujo: Ver estadisticas / Registrar Vuelo / Actualizar Vuelo / Cancelar Vuelo / Ver Vuelos / Salir
========================================================== */

/* * ---------------------------------------------------------- 
* Funcion: MenuPrincipal 
* Descripcion: Submodulo 1.0 - Controlador de la interfaz que imprime las opciones del sistema hacia alguno de los 5 modulos principales
* Parametros: 
* vuelos (Vuelo[]) arreglo de estructuras de los vuelos 
* pistas (Pista[]) arreglo de estructuras de las pistas 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void MenuPrincipal(Vuelo vuelos[], Pista pistas[]){
	int selector= 0;
	printf("\t - Bienvenido al gestor de vuelos del aeropuerto de Merida\n");
	printf("\t1 - Ver estadisticas\n");
	printf("\t2 - Registrar vuelo\n");
	printf("\t3 - Actualizar Vuelo\n");
	printf("\t4 - Cancelar Vuelos\n");
	printf("\t5 - Ver vuelos\n");
	printf("\t6 - Salir\n");
	scanf("%i", &selector);
	
	switch (selector) {
	case 1:
		printf("\tEstadisticas\n");
		VerEstadisticas(vuelos);
		printf("\tpresione cualquier tecla para volver al menu\n");
		getchar(); 
		getchar();
		MenuPrincipal(vuelos, pistas); 
		break;
	case 2:
		printf("\tResgistrar vuelo\n");
		IntroducirDatos(vuelos, pistas);
		printf("\tpresione cualquier tecla para volver al menu\n");
		getchar(); 
		getchar();
		MenuPrincipal(vuelos, pistas); 
		break;
	case 3:
		printf("\tActualizar vuelo\n");
		ImprimirDatosVuelos(vuelos); /* Se cambio VerVuelos por ImprimirDatosVuelos para saltar el menu */
		CambiarDatos(vuelos, pistas);
		printf("\tpresione cualquier tecla para volver al menu\n");
		getchar(); 
		getchar();
		MenuPrincipal(vuelos, pistas); 
		break;
	case 4:
		printf("\tCancelar vuelo\n");
		CancelarVuelos(vuelos,  pistas);
		printf("\tpresione cualquier tecla para volver al menu\n");
		getchar(); 
		getchar();
		MenuPrincipal(vuelos, pistas); 
		break;
	case 5:
		printf("\tVer vuelos\n");
		VerVuelos(vuelos);
		printf("\tpresione cualquier tecla para volver al menu\n");
		getchar(); 
		getchar();
		MenuPrincipal(vuelos, pistas); 
		break;
	case 6:
		printf("\tSaliendo del programa\n");
		break;
	default:
		printf("\tIngrese una opcion valida...\n");
		printf("\tpresione cualquier tecla para volver al menu\n");
		getchar(); 
		getchar();
		MenuPrincipal(vuelos, pistas); 
		break;
	}
}
	
/* * ---------------------------------------------------------- 
* Funcion: ImprimirPistas 
* Descripcion: Funcion auxiliar que imprime el estado actual de las pistas del aeropuerto para facilitar la asignacion visual
* Parametros: 
* pistas (Pista[]) arreglo de estructuras de las pistas 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void ImprimirPistas(Pista pistas[]) {
	printf("-------------------------------------------\n");
	printf("|                 PISTAS                  |\n");
	printf("-------------------------------------------\n");
	printf("| Pista | Estado  |  | Pista | Estado  |\n");
	printf("-------------------  -------------------\n");
	
	/* Crea dos indices de ayuda con en indice i: uno de 0-9 y otro del 10-20 */
	for (int i = 0; i <(MAX_PISTAS/2); i++) {
		int izq = i;           
		int der = i + (MAX_PISTAS/2);   
		
		/* dependiendo del estado de la pista copia "libre" u "ocupada" a la variable estadoIzq */
		char estadoIzq[10];
		if (pistas[izq].estadoPista == 0) {
			strcpy(estadoIzq, "Libre  "); 
		} else {
			strcpy(estadoIzq, "Ocupada");
		}
		
		/* dependiendo del estado de la pista copia "libre" u "ocupada" a la variable estadoDer */
		char estadoDer[10];
		if (pistas[der].estadoPista == 0) {
			strcpy(estadoDer, "Libre  ");
		} else {
			strcpy(estadoDer, "Ocupado");
		}
		
		/* Imprime las pistas simulaneamente y sus estados */
		printf("|  %2d   | %s |  |  %2d   | %s |\n", 
			   izq+1, estadoIzq, der+1, estadoDer);
	}
	printf("-------------------------------------------\n\n");
}


/* ==========================================================
MODULO 3: Registrar vuelo (Create)
Flujo: IntroducirDatos -> AsignarAerolinea -> AsignarHoraLlegadaSalida -> AsignarOrigenDestino -> AsignarPista -> GenerarId
========================================================== */


/* * ---------------------------------------------------------- 
* Funcion: IntroducirDatos 
* Descripcion: Submodulo 3.1 - Interfaz que captura los datos que el usuario ingrese.
* Parametros: 
* vuelos (Vuelo[]) arreglo de estructuras de los vuelos 
* pistas (Pista[]) arreglo de estructuras de las pistas 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void IntroducirDatos(Vuelo vuelos[], Pista pistas[]) {
	int espacioLibre = BuscarEspacio(vuelos);
	
	if (espacioLibre == -1) {
		printf("\tEl aeropuerto esta a su maxima capacidad\n");
		return;
	}
	
	/* inicializa un nuevo Vuelo temporal donde alojar los datos*/
	Vuelo vueloTemp = {0};
	AsignarAerolinea(&vueloTemp);
	AsignarHoraLlegadaSalida(&vueloTemp);
	AsignarOrigenDestino(&vueloTemp);
	AsignarPista(&vueloTemp, pistas);
	GenerarIdVuelo(&vueloTemp, vuelos); /* Se agrego el arreglo para la busqueda */
	AsignarEstadoVuelo(&vueloTemp);
	
	vuelos[espacioLibre] = vueloTemp;
	printf("\n\tRegistro exitoso. Vuelo %s guardado en la posicion %d.\n", vuelos[espacioLibre].id_vuelo, espacioLibre);
}

/* * ---------------------------------------------------------- 
* Funcion: AsignarPista 
* Descripcion: Submodulo 3.1.5 - Imprime las pistas disponibles y le pide al usuario el Id de la pista para asignarla al vuelo
* Parametros: 
* vueloTemp (Vuelo*) puntero a la estructura del vuelo temporal 
* pistas (Pista[]) arreglo de estructuras de las pistas 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void AsignarPista(Vuelo *vueloTemp, Pista pistas[]) {
	int numPista;
	ImprimirPistas(pistas);
	
	do {
		printf("Ingrese el numero de pista para asignar al vuelo: ");
		scanf("%i", &numPista);
		
		if (numPista < 1 || numPista > MAX_PISTAS) {
			printf("\tPista invalida. ");
			
		} 
		/* si el estado de la pista es ocupado pide que elija otra y cambia el valor a -1 para volver a preguntar */
		else if (pistas[numPista-1].estadoPista == 1) {
			printf("\tLa pista esta ocupada. Elija otra.\n");
			numPista = -1; 
		}
		
	} while (numPista < 1 || numPista > MAX_PISTAS);
	
	/* Asigna la pista y cambia el estado de la pista a ocupada */
	vueloTemp->id_pistaAsignada = numPista;
	pistas[numPista - 1].estadoPista = 1;
	printf("\nPista asignada: %i\n", vueloTemp->id_pistaAsignada);
}

/* * ---------------------------------------------------------- 
* Funcion: AsignarAerolinea 
* Descripcion: Submodulo 3.1.2 - Le pide al usuario el nombre de la aerolinea y lo guarda
* Parametros: 
* vueloTemp (Vuelo*) puntero a la estructura del vuelo temporal 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void AsignarAerolinea(Vuelo *vueloTemp) {
	printf("\tIngrese el nombre de la aerolinea (ej. Volaris): ");
	scanf("%s", vueloTemp->aerolinea);
	printf("\tAerolinea: %s\n", vueloTemp->aerolinea);
}

/* * ---------------------------------------------------------- 
* Funcion: GenerarIdVuelo 
* Descripcion: Submodulo 3.1.6 - Pide al usuario el Id del vuelo, verifica si existe para despues asignarlo o rechazarlo
* Parametros: 
* vueloTemp (Vuelo*) puntero a la estructura del vuelo temporal 
* vuelos (Vuelo[]) arreglo de estructuras de los vuelos
* Retorna: void 
* ---------------------------------------------------------- 
*/
void GenerarIdVuelo(Vuelo *vueloTemp, Vuelo vuelos[]) {
	int existe = -1;
	do {
		printf("\tIngrese el Id para registrar el vuelo (ej. UAD123): ");
		scanf("%s", vueloTemp->id_vuelo);
		
		/* Verificar si el ID ya existe en el arreglo usando la funcion BuscarVuelo */
		existe = BuscarVuelo(vuelos, vueloTemp->id_vuelo);
		
		if (existe != -1) {
			printf("\tError: El ID '%s' ya esta registrado. Ingrese uno diferente.\n", vueloTemp->id_vuelo);
		}
	} while (existe != -1);
	
	printf("\tId del vuelo: %s\n", vueloTemp->id_vuelo);
}

/* * ---------------------------------------------------------- 
* Funcion: AsignarHoraLlegadaSalida 
* Descripcion: Submodulo 3.1.3 - Le pide al usuario la hora de llegada y salida (cadenas) y las guarda
* Parametros: 
* vueloTemp (Vuelo*) puntero a la estructura del vuelo temporal 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void AsignarHoraLlegadaSalida(Vuelo *vueloTemp) {
	printf("\tIngrese la hora de llegada salida (ej. 14:00-16:00): ");
	scanf("%s", vueloTemp->horaLlegadaSalida);
	printf("\tHora llegada y salida: %s\n", vueloTemp->horaLlegadaSalida);
}

/* * ---------------------------------------------------------- 
* Funcion: AsignarOrigenDestino 
* Descripcion: Submodulo 3.1.4 - Le pide al usuario el origen y el destino del vuelo y los guarda
* Parametros: 
* vueloTemp (Vuelo*) puntero a la estructura del vuelo temporal 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void AsignarOrigenDestino(Vuelo *vueloTemp) {
	printf("\tIngrese el origen y el destino (ej. MID/MEX): ");
	scanf("%s", vueloTemp->origenDestino);
	printf("\tOrigen y destino: %s\n", vueloTemp->origenDestino);
}

/* * ---------------------------------------------------------- 
* Funcion: BuscarVuelo 
* Descripcion: Submodulo 4.1.2 - Busca si existe el vuelo para poder cambiar los datos
* Parametros: 
* vuelos (Vuelo[]) arreglo de estructuras de los vuelos 
* Id_vuelo (char[]) identificador del vuelo a buscar
* Retorna: int 
* ---------------------------------------------------------- 
*/
int BuscarVuelo(Vuelo vuelos[], char Id_vuelo[]) {
	/* Compara si el id del vuelo es vacio y si el id ingresado coincide con alguno del arreglo */
	for (int i = 0; i < MAX_VUELOS; i++) {
		if (vuelos[i].id_vuelo[0] != '\0' && strcmp(vuelos[i].id_vuelo, Id_vuelo) == 0) {
			return i; /* retorna la posicion donde esta el vuelo */
		}
	}
	return -1; 
}

/* * ---------------------------------------------------------- 
* Funcion: BuscarEspacio 
* Descripcion: Funcion auxiliar que busca un espacio disponible en el arreglo de vuelos para registrar uno nuevo
* Parametros: 
* vuelos (Vuelo[]) arreglo de estructuras de los vuelos 
* Retorna: int 
* ---------------------------------------------------------- 
*/
int BuscarEspacio(Vuelo vuelos[]) {
	/* busca dentro del arreglo de los vuelos si hay algun espacio libre donde asignarlo */
	for (int i = 0; i < MAX_VUELOS; i++) {
		if (vuelos[i].id_vuelo[0] == '\0') {
			return i;  /* retorna la posicion del espacio libre*/
		}
	}
	return -1; 
}

/* * ---------------------------------------------------------- 
* Funcion: AsignarEstadoVuelo 
* Descripcion: Submodulo 3.1.7 - Le pide al usuario el estado del vuelo, es decir, si esta programado (registro reciente) o esta retrasado
* Parametros: 
* vueloTemp (Vuelo*) puntero a la estructura del vuelo temporal 
* Retorna: void 
* ---------------------------------------------------------- 
*/
void AsignarEstadoVuelo(Vuelo *vueloTemp) {
	int estadoVuelo = -1;
	printf("\n\t - Estados disponibles al registrar\n");
	printf("\t0 - programado (vuelo de salida)\n");
	printf("\t4 - retrasado (problema de horario)\n"); 
	printf("\tIngrese el numero del estado a elegir: \n");
	
	do {
		scanf("%i", &estadoVuelo);
		if (estadoVuelo != 0 && estadoVuelo != 4) {
			printf("\tOpcion invalida. Ingrese solo 0 o 4: ");
		}
	} while (estadoVuelo != 0 && estadoVuelo != 4);
	
	vueloTemp->estadoVuelo = estadoVuelo;
	
	switch (estadoVuelo) {
	case 0: printf("\tEstado del vuelo: Programado\n"); break;
	case 4: printf("\tEstado del vuelo: Retrasado\n"); break; 
	}
}
