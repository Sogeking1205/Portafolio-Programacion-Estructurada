#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>//Aqui se incluyen realloc y free

char *leerTexto(){//Puntero vacio para guardar el texto ingresado
	char *texto=NULL;
	int c, tam = 0; 
	while((c = getchar()) != '\n' && (c != EOF)){//c == getchar guarda el identificador numerico ASCII de cada caracter leido en c
		texto= realloc(texto, tam + 2);//realloc agranda y reserva la memoria nueva segun se agreguen caracteres, se agregan 2 porque es el caracter obtenido y el fin de linea '\0'
		texto[tam++] = (char) c;//convierte en arreglo a texto usando el 'tama�o' y guarda en la posicion actual de tama�o el identificador numerico ASCII a caracter 
		texto[tam] = '\0';// indica el final de la linea
	}
	return texto; //Regresamos la posicion donde se guardo el texto ingresado
}
	
	//Funci�n para las preguntas
	int hacerPregunta(char pregunta[]){
		int op;
		printf("\n%s\n", pregunta);
		printf("1. Nunca\n2. A veces\n3. Muchas veces\n");
		printf("Respuesta: ");
		scanf("%d", &op);
		//Regresa un valor segun la opcion 
		switch(op){
		case 1: return 0;
		case 2: return 1;
		case 3: return 2;
		default: return 0;
		}
	}
		//Evaluar el riesgo
		void evaluar(int total){
			printf("\nPuntaje total: %d\n", total);
			
			if(total <= 5)
				printf("Riesgo BAJO\n");
			else if(total <= 15)
				printf("Riesgo MEDIO\n");
			else
				printf("Riesgo ALTO\n");
		}
			
			//Retroalimentacion
			void retroalimentacion(int total, int edad){
				printf("\n--- Retroalimentaci�n ---\n\n");
				
				if(edad >= 6 && edad <= 9){
					// NIÑOS
					
					if(total <= 5){
						printf("Parece que en general te sientes bien en tu d�a a d�a.\n");
						printf("Eso es algo muy positivo, ya que significa que la mayor�a de las cosas a tu alrededor te hacen sentir tranquilo o feliz.\n\n");
						
						printf("Aun as�, es importante que sigas prestando atenci�n a c�mo te sientes.\n");
						printf("Si en alg�n momento algo te hace sentir triste, enojado o confundido, recuerda que puedes hablar con alguien de confianza.\n\n");
						
						printf("Puede ser tu mam�, pap�, un maestro o alg�n adulto que te haga sentir seguro.\n");
						printf("Hablar sobre lo que sientes siempre es una buena idea.\n");
					}
					else if(total <= 15){
						printf("Tus respuestas muestran que hay algunas cosas que podr�an estar haci�ndote sentir mal o inc�modo.\n");
						printf("Esto no significa que todo est� mal, pero s� es importante prestar atenci�n a lo que est�s viviendo.\n\n");
						
						printf("A veces, cuando alguien nos molesta, nos grita o nos hace sentir mal, podemos pensar que es normal, pero no lo es.\n");
						printf("T� mereces sentirte seguro, escuchado y respetado.\n\n");
						
						printf("Ser�a muy bueno que hables con un adulto de confianza sobre lo que est� pasando.\n");
						printf("No tienes que guardarte las cosas.\n");
						printf("Contar lo que sientes puede ayudarte mucho.\n");
					}
					else{
						printf("Tus respuestas indican que podr�as estar pasando por situaciones dif�ciles.\n");
						printf("Es posible que haya cosas que te est�n haciendo sentir miedo, tristeza o incomodidad.\n\n");
						
						printf("Es muy importante que sepas que lo que sientes es v�lido.\n");
						printf("Nadie deber�a lastimarte, asustarte o hacerte sentir mal.\n\n");
						
						printf("No tienes que enfrentar esto solo.\n");
						printf("Busca ayuda con un adulto en quien conf�es, como tus pap�s, un maestro o alguien cercano.\n");
						printf("Hablar de lo que pasa es el primer paso para sentirte mejor y estar m�s seguro.\n");
					}
				}
				else if(edad >= 10 && edad <= 15){
					// ADOLESCENTES
					
					if(total <= 5){
						printf("De acuerdo con tus respuestas, no se detectan se�ales fuertes de riesgo en este momento.\n");
						printf("Esto sugiere que, en general, tu entorno es estable y no presenta situaciones graves.\n\n");
						
						printf("Sin embargo, es importante recordar que tu bienestar emocional es algo que debes seguir cuidando.\n");
						printf("Incluso en situaciones normales, es v�lido sentirse mal en algunos momentos.\n\n");
						
						printf("Hablar con personas de confianza, expresar lo que sientes y cuidar tu salud emocional son h�bitos importantes.\n");
					}
					else if(total <= 15){
						printf("Tus respuestas indican que podr�as estar atravesando algunas situaciones complicadas.\n");
						printf("Puede tratarse de conflictos, incomodidad o experiencias que est�n afectando tu bienestar.\n\n");
						
						printf("Este tipo de situaciones no deben ignorarse.\n");
						printf("Aunque a veces parezcan peque�as o normales, pueden tener un impacto importante con el tiempo.\n\n");
						
						printf("Es recomendable que hables con alguien de confianza.\n");
						printf("Puede ser un familiar, un amigo cercano, un profesor o un orientador.\n");
						printf("Compartir lo que est�s viviendo puede ayudarte a entender mejor la situaci�n y encontrar apoyo.\n");
					}
					else{
						printf("Tus respuestas muestran se�ales importantes de riesgo que no deben ser ignoradas.\n");
						printf("Es posible que est�s viviendo situaciones de agresi�n, presi�n o maltrato que est�n afectando tu bienestar.\n\n");
						
						printf("Es importante que tengas claro que no es tu culpa.\n");
						printf("Nadie merece ser tratado de forma violenta o injusta.\n\n");
						
						printf("Buscar ayuda es fundamental en este momento.\n");
						printf("Habla con un adulto de confianza, un familiar, un profesor o un profesional.\n");
						printf("Tambi�n puedes acudir a servicios de apoyo si los tienes disponibles.\n\n");
						
						printf("Pedir ayuda no es una debilidad, es una forma de protegerte.\n");
					}
				}
			}
				
				//cuestionario Para ni�os
				int cuestionarioNinos(){
					char *preguntas[] = {
						//Arreglo de preguntas que se recorrer� con un ciclo
						"�Te sientes preocupado cuando est�s en tu casa?",
							"�Alguien en casa te grita o se enoja mucho contigo?",
							"�Te han empujado o lastimado en casa?",
							"�Tienes miedo en tu casa?",
							"�Te gusta ir a la escuela?",
							"�Alguien te molesta o se burla de ti?",
							"�Te han pegado en la escuela?",
							"�Te sientes triste sin raz�n?",
							"�Te sientes solo?",
							"�Te da miedo contar lo que te pasa?"
					};
					
					int total = 0;//Acumulador de respuestas del cuestionario
					for(int i=0; i<10; i++){//Recorre todas las preguntas
						total += hacerPregunta(preguntas[i]);//Suma el valor de cada respuesta
					}
					
					evaluar(total);//Se evalua el nivel de riesgo segun el total
					return total;
				}
					
					// Cuestionario para adolescentes
					int cuestionarioAdolescentes(){
						char *preguntas[] = {
							//Arreglo de preguntas para adolescentes
							"�Te sientes inseguro en tu casa?",
								"�Te insultan en casa?",
								"�Has sido lastimado f�sicamente?",
								"�Evitas hablar por miedo?",
								"�Te han humillado en la escuela?",
								"�Te han excluido?",
								"�Has sufrido agresiones?",
								"�Te han quitado cosas?",
								"�Te insultan en redes?",
								"�Te sientes ansioso?",
								"�Te sientes solo?",
								"�Te sientes triste frecuentemente?"
						};
						
						int total = 0;//Acumulador de respuestas
						for(int i=0; i<12; i++){//Recorre todas las preguntas
							total += hacerPregunta(preguntas[i]);
						}
						
						evaluar(total);//Se evalua el riesgo
						return total;
					}
						int main(int argc, char *argv[]) {
							//Diccionario de palabras clave que se buscar�n dentro del texto del usuario
							char diccionario[76][25]={
								"peg","golp","empuj","jal","mord","pate","cachete","lastim",
									"tonto","feo","gordo","burro","menso","bobo","ridiculo","lloron",
									"no jugar","exclu","ignorar","dejar afuera","quitar cosas","esconder juguetes",
									"miedo","susto","llorar","escond","pena",
									"romper cosas","aventar","jalonear","idiota","estupido","inutil","perdedor","fracasado","me insult","pobre",
									"humill","burl","hacer memes","quitar pertenencias","rob","molestar",
									"insultar en redes","publicar fotos","comentarios feos","bloquear","hackear",
									"ansiedad","nervioso","terror","verguenza",
									"agred","amena","abuso","romp","vandali","acoso","me golp",
									"maldito","imbecil","basura","malnacido","me pate","me amena",
									"difam","hacer chismes","inventar cosas","manipula",
									"ciberacoso","agred","mal de mi","me empuj","me intimid",
									"depresion","soledad"};
							
							int i, alarma = 0;//alarma cuenta cuantas palabras de riesgo se detectan
							FILE * edadA = fopen("edad.txt", "rb");//Se intenta abrir archivo para leer edad
							int edad;
							int verific;//variable para validar lectura correcta
							char menu;
							menu = 'X';//Se inicializa para entrar al ciclo
							char nombre[50];
							char busqueda[50];
							
							if (edadA == NULL){
								do{
									printf("Ingrese su edad: \n");
									verific= scanf("%d", &edad);
									if (verific != 1){
										printf("Error en la lectura, debe ingresar un numero\n");
										while(getchar() != '\n');//Limpia buffer en caso de error
									}
								} while(verific != 1);
								edadA = fopen("edad.txt", "wb");
								fprintf(edadA, "%d", edad);//Guarda la edad en archivo
								fclose(edadA);
								printf("EDAD GUARDADA CON EXITO\n");
							}
							else{
								fscanf(edadA, "%d", &edad);//Lee la edad guardada previamente
								fclose(edadA);
							}
							getchar();//Limpia buffer
							
							while(menu != 'C' && menu != 'c'){//Ciclo principal del programa
								
								printf("%-20s\n", "�QUE DESEAS HACER?");
								printf("%-20s \n", "A: Explorar mis hojas");
								printf("%-20s \n", "B: Escribir un nuevo dia");
								printf("%-20s \n", "C: Salir");
								scanf(" %c", &menu);
								getchar();//Limpia buffer
								
								switch(menu){
								case 'a':
								case 'A':
									printf("\n====== MIS DIARIOS ======\n");
									
									FILE *lista = fopen("lista_diarios.txt", "r");
									
									if(lista == NULL){
										printf("Aun no hay diarios guardados\n");
									}
									else{
										char nombreLista[50];
										
										while(fgets(nombreLista, 50, lista) != NULL){
											printf("- %s", nombreLista);
										}
										
										fclose(lista);
									}
									
									printf("\nIngresa el nombre del diario que deseas abrir:\n");
									fgets(busqueda, 50, stdin);
									busqueda[strcspn(busqueda, "\n")] = '\0';
									FILE * encontrado = fopen(busqueda, "r");//Abre el archivo buscado
									if (encontrado==NULL){
										perror("registro no encontrado");
									}
									else{
										char letra;
										while((letra = fgetc(encontrado)) != EOF){
											printf("%c", letra);
										}
										fclose(encontrado);
									}
									scanf("%s", &busqueda);
									break;
									
								case 'b':
								case 'B':
									alarma = 0;//Reinicia el contador de alarmas
									
									printf("Ponle nombrea tu d�a: (maximo 20 caracteres)\n");
									fgets (nombre, 50, stdin);
									nombre [strcspn(nombre, "\n")] = '\0';//Elimina salto de linea
									FILE * dia = fopen(nombre , "w");//Crea archivo
									//Guardar el nombre del diario en una lista
									FILE *listaDiario = fopen("lista_diarios.txt", "a");
									
									if(listaDiario != NULL){
										fprintf(listaDiario, "%s\n", nombre);
										fclose(listaDiario);
									}
									if(dia == NULL){
										perror("UPS... Algo salio mal :(\n");
									}
									
									printf("\n\n�HOLA! �C�mo estuvo tu d�a? escribe fin en una linea aparte para terminar\n");
									
									char *diario = leerTexto();//Lee primera linea
									while(strcmp(diario,"fin") != 0){//Mientras no sea "fin"
										
										fprintf(dia, "%s\n", diario);//Guarda en archivo
										
										for (i=0; i<76; i++){//Busca palabras del diccionario
											if (strstr(diario, diccionario[i]) != NULL){
												alarma++;
												printf("Alarma: %s detectado\n", diccionario[i]);
											}
										}
										
										printf("Tu d�a fue: %s\n", diario);
										free(diario);//Libera memoria
										diario = leerTexto();//Lee siguiente linea
									}
									
									free(diario);//Libera memoria final
									fclose(dia);//Cierra archivo
									
									if(alarma > 0){//Si hubo palabras detectadas
										printf("\n Se detectaron palabras de riesgo\n");
										
										int total;
										
										if(edad >= 6 && edad <= 9){
											total = cuestionarioNinos();
											retroalimentacion(total, edad);
										}
										else if(edad >= 10 && edad <= 15){
											total = cuestionarioAdolescentes();
											retroalimentacion(total, edad);
										}
										else{
											printf("Edad fuera de rango\n");
										}
									}
									break;
									
								case 'c':
								case 'C':
									printf("Saliendo del programa...\n");
									break;
									
								default:
									printf("Opcion invalida\n");
								}
							} 
							
							return 0;
						}
