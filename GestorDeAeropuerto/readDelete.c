#include "CreateUpdate.h"

/* ==========================================================
MODULO 6: Ver vuelos (Read)
Flujo: Ver Vuelos -> Mostrar Menu Ver Vuelos -> Imprimir Datos Vuelos / Consultar Vuelo Especifico
========================================================== */

/*
* ----------------------------------------------------------
* Funcion: MostrarMenuVerVuelos
* Descripcion: Submodulo 6.1 - Despliega el menu de opciones para la visualizacion.
* Parametros: Ninguno
* Retorna: int - La opcion seleccionada por el usuario
* ----------------------------------------------------------
*/
int MostrarMenuVerVuelos() { /* Inicia funcion MostrarMenuVerVuelos */
	int opcion;
	
	printf("\n\t--- MENU DE VISUALIZACION DE VUELOS ---\n");
	printf("\t1. Listado General Operativo (Todos los vuelos)\n");
	printf("\t2. Consulta Especifica (Buscar por ID)\n");
	printf("\t3. Regresar al Menu Principal\n");
	printf("\tSeleccione una opcion: ");
	scanf("%d", &opcion);
	
	return opcion;
} /* fin funcion MostrarMenuVerVuelos */


/*
* ----------------------------------------------------------
* Funcion: ImprimirDatosVuelos
* Descripcion: Submodulo 6.1.1 - Despliega una tabla completa con toda la informacion de los vuelos.
* Parametros:
* vuelos (Vuelo[MAX_VUELOS]) arreglo de estructuras con los datos a imprimir
* Retorna: void
* ----------------------------------------------------------
*/
void ImprimirDatosVuelos(Vuelo vuelos[MAX_VUELOS]) { /* Inicia funcion ImprimirDatosVuelos */
	int i;
	int contador = 0;
	char textoEstado[15];
	
	/* imprimir encabezado de tabla general */
	printf("\n\t--- LISTA GENERAL DE VUELOS ---\n");
	printf("------------------------------------------------------------------------------------------\n");
	printf("| ID Vuelo | Aerolinea       | Origen/Destino  | Horario         | Pista | Estado       |\n");
	printf("------------------------------------------------------------------------------------------\n");
	
	/* recorrer todo el arreglo */
	for (i = 0; i < MAX_VUELOS; i++) {
		
		/* verificamos que la ID no empiece con un fin de linea, para ignorar los vuelos vacios o borrados */
		if (vuelos[i].id_vuelo[0] != '\0') {
			
			/* determinar texto del estado para impresion */
			switch(vuelos[i].estadoVuelo) {
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
			
			printf("| %-8s | %-15s | %-15s | %-15s | %-5d | %-12s |\n", vuelos[i].id_vuelo, vuelos[i].aerolinea, vuelos[i].origenDestino, vuelos[i].horaLlegadaSalida, vuelos[i].id_pistaAsignada, textoEstado);
			contador++;
		}
	}
	
	/* validacion por si no hay ningun vuelo guardado */
	if (contador == 0) {
		printf("| No hay vuelos registrados en el sistema en este momento.                               |\n");
	}
	printf("------------------------------------------------------------------------------------------\n");
} /* fin funcion ImprimirDatosVuelos */


/*
* ----------------------------------------------------------
* Funcion: ConsultarVueloEspecifico
* Descripcion: Submodulo 6.1.2 - Busca un solo vuelo por ID y despliega sus detalles.
* Parametros:
* vuelos (Vuelo[MAX_VUELOS]) arreglo de estructuras con los datos
* Retorna: void
* ----------------------------------------------------------
*/
void ConsultarVueloEspecifico(Vuelo vuelos[MAX_VUELOS]) { /* Inicia funcion ConsultarVueloEspecifico */
	char idBusqueda[30];
	int indice;
	char textoEstado[15];
	
	printf("\n\t--- CONSULTA ESPECIFICA DE VUELO ---\n");
	printf("\tIngrese el ID del vuelo a buscar: ");
	scanf("%s", idBusqueda);
	
	/* Reutilizamos la funcion de busqueda, mandando la direccion del arreglo */
	indice = BuscarVuelo(vuelos, idBusqueda);
	
	/* si regresa algo diferente a -1, el vuelo si existe en el arreglo */
	if (indice != -1) {
		
		/* determinar texto del estado para impresion */
		switch(vuelos[indice].estadoVuelo) {
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
		
		/* imprimimos la informacion solo de ese vuelo */
		printf("\n\t Vuelo encontrado con exito:\n");
		printf("\t--------------------------------------\n");
		printf("\tID del Vuelo    : %s\n", vuelos[indice].id_vuelo);
		printf("\tAerolinea       : %s\n", vuelos[indice].aerolinea);
		printf("\tOrigen / Destino: %s\n", vuelos[indice].origenDestino);
		printf("\tHorario         : %s\n", vuelos[indice].horaLlegadaSalida);
		printf("\tPista Asignada  : %d\n", vuelos[indice].id_pistaAsignada);
		printf("\tEstado Actual   : %s\n", textoEstado);
		printf("\t--------------------------------------\n");
		
	} else {
		printf("\tError: El vuelo '%s' no esta registrado o fue cancelado.\n", idBusqueda);
	}
} /* fin funcion ConsultarVueloEspecifico */


/*
* ----------------------------------------------------------
* Funcion: VerVuelos
* Descripcion: Modulo 6.0 - Controlador del modulo de lectura de vuelos.
* Parametros:
* vuelos (Vuelo[MAX_VUELOS]) arreglo de estructuras de los vuelos
* Retorna: void
* ----------------------------------------------------------
*/
void VerVuelos(Vuelo vuelos[MAX_VUELOS]) { /* Inicia funcion VerVuelos */
	int opcion;
	
	/* Llamada al submodulo 6.1 para obtener la opcion */
	opcion = MostrarMenuVerVuelos();
	
	/* El controlador direcciona a la funcion correspondiente segun la eleccion */
	switch (opcion) {
	case 1:
		/* Llamada al submodulo 6.1.1 */
		ImprimirDatosVuelos(vuelos);
		break;
	case 2:
		/* Llamada al submodulo 6.1.2 */
		ConsultarVueloEspecifico(vuelos);
		break;
	case 3:
		/* No hace nada, devuelve al menu principal de main.c */
		break;
	default:
		printf("\tOpcion no valida. Intente de nuevo.\n");
		break;
	}
} /* fin funcion VerVuelos */
/* ==========================================================
MODULO 5: Cancelar vuelos (Delete)
Flujo: Cancelar Vuelos -> Imprimir Vuelos -> Buscar Vuelo -> Borrar Vuelo
========================================================== */

/*
* ----------------------------------------------------------
* Funcion: ImprimirVuelos
* Descripcion: Submodulo 5.1 - Despliega los vuelos registrados para poder seleccionarlos.
* Parametros:
* vuelos (Vuelo[MAX_VUELOS]) arreglo de estructuras con los vuelos
* Retorna: void
* ----------------------------------------------------------
*/
void ImprimirVuelos(Vuelo vuelos[MAX_VUELOS]) { /* Inicia funcion ImprimirVuelos */
	int i;
	int contador = 0;
	
	printf("\n\t--- VUELOS DISPONIBLES ---\n");
	
	/* recorrer todo el arreglo */
	for (i = 0; i < MAX_VUELOS; i++) {
		
		/* verificamos que la ID no empiece con un fin de linea, para ignorar los vuelos vacios o borrados */
		if (vuelos[i].id_vuelo[0] != '\0') {
			printf("\tID: %-10s | Aerolinea: %s\n", vuelos[i].id_vuelo, vuelos[i].aerolinea);
			contador++;
		}
	}
	
	/* validacion por si no hay vuelos guardados */
	if (contador == 0) {
		printf("\tNo hay vuelos para mostrar.\n");
	}
} /* fin funcion ImprimirVuelos */


/*
* ----------------------------------------------------------
* Funcion: BorrarVuelo
* Descripcion: Submodulo 5.3 - Elimina el vuelo de los registros y libera la pista.
* Parametros:
* vuelos (Vuelo[MAX_VUELOS]) arreglo de estructuras de los vuelos
* indice (int) posicion exacta del vuelo a borrar
* pistas (Pista[MAX_PISTAS]) arreglo de estructuras de las pistas
* Retorna: void
* ----------------------------------------------------------
*/
void BorrarVuelo(Vuelo vuelos[MAX_VUELOS], int indice, Pista pistas[MAX_PISTAS]) { /* Inicia funcion BorrarVuelo */
	int pistaAsignada;
	
	/* guardar la pista antes de borrar */
	pistaAsignada = vuelos[indice].id_pistaAsignada;
	
	/* liberar la pista si es un numero valido */
	if (pistaAsignada > 0 && pistaAsignada <= MAX_PISTAS) {
		pistas[pistaAsignada - 1].estadoPista = 0;
	}
	
	/* Cambiamos el primer caracter de la ID por un fin de linea para que el programa lo lea como vacio.
	Simulando un borrado logico para optimizar el programa */
	vuelos[indice].id_vuelo[0] = '\0';
	
	printf("\tEl vuelo ha sido eliminado y la pista liberada.\n");
} /* fin funcion BorrarVuelo */


/*
* ----------------------------------------------------------
* Funcion: CancelarVuelos
* Descripcion: Modulo 5.0 - Controlador principal para dar de baja un vuelo.
* Parametros:
* vuelos (Vuelo[MAX_VUELOS]) arreglo de estructuras de los vuelos
* pistas (Pista[MAX_PISTAS]) arreglo de estructuras de las pistas
* Retorna: void
* ----------------------------------------------------------
*/
void CancelarVuelos(Vuelo vuelos[MAX_VUELOS], Pista pistas[MAX_PISTAS]) { /* Inicia funcion CancelarVuelos */
	char idBusqueda[30];
	int indice;
	char confirmacion;
	
	printf("\n\t--- CANCELAR VUELOS ---\n");
	
	/* Llamada al submodulo 5.1 */
	ImprimirVuelos(vuelos);
	
	printf("\n\tIngrese el ID del vuelo a cancelar: ");
	scanf("%s", idBusqueda);
	
	/* Llamada al submodulo 5.2 (Funcion BuscarVuelo) */
	indice = BuscarVuelo(vuelos, idBusqueda);
	
	/* verificar que el vuelo se encontro en el arreglo */
	if (indice != -1) {
		printf("\tEsta seguro que desea eliminar el vuelo %s? (S - Si, N - No): ", idBusqueda);
		
		/* el espacio antes del %c es para que no se salte el scanf por el enter anterior */
		scanf(" %c", &confirmacion);
		
		/* validar confirmacion */
		if (confirmacion == 'S' || confirmacion == 's') {
			
			/* Llamada al submodulo 5.3 */
			BorrarVuelo(vuelos, indice, pistas);
			
		} else {
			printf("\tOperacion cancelada.\n");
		}
	} else {
		printf("\tError: El vuelo '%s' no existe en el sistema.\n", idBusqueda);
	}
} /* fin funcion CancelarVuelos */

/* ==========================================================
MODULO 2: Ver estadisticas
Flujo: Ver Estadisticas -> Calcular Estadisticas -> Desplegar Estadisticas
========================================================== */

/*
* ----------------------------------------------------------
* Funcion: CalcularEstadisticas
* Descripcion: Submodulo 2.1 - Realiza los calculos de los estados de los vuelos.
* Parametros:
* vuelos (Vuelo[MAX_VUELOS]) arreglo con los datos
* porcentajes (float[5]) arreglo para guardar los resultados
* Retorna: int - El numero total de vuelos activos encontrados
* ----------------------------------------------------------
*/
int CalcularEstadisticas(Vuelo vuelos[MAX_VUELOS], float porcentajes[5]) { /* Inicia funcion CalcularEstadisticas */
	int i;
	int contadores[5] = {0};
	int totalActivos = 0;
	
	/* recorrer todo el arreglo */
	for (i = 0; i < MAX_VUELOS; i++) {
		
		/* verificamos que la ID no empiece con un fin de linea, para ignorar los vuelos vacios o borrados */
		if (vuelos[i].id_vuelo[0] != '\0') {
			totalActivos++;
			
			/* sumar al contador correspondiente segun el estado */
			if (vuelos[i].estadoVuelo >= 0 && vuelos[i].estadoVuelo <= 4) {
				contadores[vuelos[i].estadoVuelo]++;
			}
		}
	}
	
	/* calcular los porcentajes si hay vuelos registrados */
	if (totalActivos > 0) {
		for (i = 0; i < 5; i++) {
			/* le ponemos (float) al contador para que la division no de un resultado entero */
			porcentajes[i] = ((float)contadores[i] / totalActivos) * 100;
		}
	}
	
	/* regresamos el numero de vuelos encontrados */
	return totalActivos;
} /* fin funcion CalcularEstadisticas */

/*
* ----------------------------------------------------------
* Funcion: DesplegarEstadisticas
* Descripcion: Submodulo 2.2 - Imprime los resultados en pantalla.
* Parametros:
* porcentajes (float[5]) arreglo con los porcentajes ya calculados
* totalActivos (int) cantidad de vuelos validos
* Retorna: void
* ----------------------------------------------------------
*/
void DesplegarEstadisticas(float porcentajes[5], int totalActivos) { /* Inicia funcion DesplegarEstadisticas */
	
	printf("\n\t--- ESTADISTICAS DEL AEROPUERTO ---\n");
	
	/* validacion por si no hay vuelos en el sistema */
	if (totalActivos == 0) {
		printf("\tNo hay vuelos registrados para calcular estadisticas.\n");
	} else {
		printf("\tTotal de vuelos activos: %d\n\n", totalActivos);
		printf("\tVuelos Programados : %.2f %%\n", porcentajes[0]);
		printf("\tVuelos Abordando   : %.2f %%\n", porcentajes[1]);
		printf("\tVuelos Despegando  : %.2f %%\n", porcentajes[2]);
		printf("\tVuelos Aterrizados : %.2f %%\n", porcentajes[3]);
		printf("\tVuelos Retrasados  : %.2f %%\n", porcentajes[4]);
	}
} /* fin funcion DesplegarEstadisticas */

/*
* ----------------------------------------------------------
* Funcion: VerEstadisticas
* Descripcion: Modulo 2.0 - Controlador principal del apartado de estadisticas.
* Parametros:
* vuelos (Vuelo[MAX_VUELOS]) arreglo de estructuras
* Retorna: void
* ----------------------------------------------------------
*/
void VerEstadisticas(Vuelo vuelos[MAX_VUELOS]) { /* Inicia funcion VerEstadisticas */
	/* Se declara aqui el arreglo de porcentajes para pasarlo como parametro por referencia a la funcion y que modifique los valores originales */
	float porcentajes[5] = {0.0};
	int totalActivos = 0;
	
	/* Llamada al submodulo 2.1. Guardamos lo que nos regrese en la variable totalActivos */
	totalActivos = CalcularEstadisticas(vuelos, porcentajes);
	
	/* Llamada al submodulo 2.2 para imprimir la informacion */
	DesplegarEstadisticas(porcentajes, totalActivos);
	
} /* fin funcion VerEstadisticas */
