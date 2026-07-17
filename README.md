# Portafolio de Programación Estructurada (Lenguaje C)

Soy Ángel Santiago Novelo Uc, actual estudiante de Ingeniería en Software en la UADY. Este repositorio contiene mis proyectos destacados desarrollados durante la materia de Programación Estructurada. El objetivo de estos sistemas es demostrar el dominio de la lógica de programación, manejo de memoria, y arquitectura de software en C.

## 📓 Proyecto 1: My Daily Note (Diario Inteligente con Análisis de Riesgo)
Un sistema de registro personal que analiza las entradas de texto del usuario para detectar indicadores de riesgo psicológico o violencia.
* **Equipo de Desarrollo:** Santiago, Emmanuel y Ángel.

* **Características técnicas destacadas:**
  * **Memoria Dinámica:** Uso de punteros y `realloc` para la captura de texto de longitud variable, optimizando el uso de RAM.
  * **Análisis de Cadenas:** Implementación de un algoritmo de búsqueda iterativa sobre un diccionario de 76 palabras clave para la detección de anomalías.
  * **Persistencia de Datos:** Manejo de archivos externos (`.txt`) para el almacenamiento de edades y lectura/escritura de los diarios generados.
  * **Lógica Condicional:** Evaluación de riesgo adaptativa basada en el rango de edad del usuario (niños vs. adolescentes).

## ✈️ Proyecto 2: Gestor de Aeropuerto (Sistema CRUD Modular)
Un sistema de gestión que simula el control aéreo de un aeropuerto para facilitar la administración de vuelos diarios de forma rápida y eficaz. Este proyecto fue desarrollado como la fase final para la asignatura de Programación Estructurada de la Licenciatura en Ingeniería de Software en la Facultad de Matemáticas de la Universidad Autónoma de Yucatán.

* **Equipo de Desarrollo:** Ángel Santiago Novelo Uc (50%) y Leonardo Ariel San Martín López (50%).

* **Características técnicas y funcionalidades destacadas:**
  * **Arquitectura Modular:** El sistema está construido bajo un enfoque de programación estructurada y diseño modular. Se divide estratégicamente en 6 módulos principales: Menú (1.0), Estadísticas (2.0), Registrar Vuelos (3.0), Actualizar vuelo (4.0), Cancelar vuelos (5.0) y Ver vuelos (6.0).
  * **Operaciones CRUD:** 
    * **Altas (Create):** Permite registrar nuevos vuelos solicitando número de vuelo, aerolínea, tipo (llegada o salida) y hora programada.
    * **Consultas (Read):** Despliega una tabla ordenada con todos los vuelos registrados y permite buscar la información de un vuelo en específico mediante su número.
    * **Modificaciones (Update):** El operador puede actualizar el estado de un vuelo (ej. cambiarlo a "Retrasado") o asignarle una pista de aterrizaje.
    * **Bajas (Delete):** Se pueden eliminar vuelos del sistema en caso de ser cancelados o haber concluido su ruta.
  * **Módulo de Estadísticas:** Realiza cálculos matemáticos con los datos guardados para mostrar el porcentaje de vuelos abordando, programados, despegando o con retrasos, ayudando a aligerar la saturación del aeropuerto.
  * **Validación mediante Pruebas de Caja Negra:** El sistema superó múltiples casos de prueba documentados para evaluar las salidas esperadas, incluyendo la prevención de identificadores duplicados y la confirmación de transiciones correctas en la máquina de estados de los vuelos.

---
*Proyectos desarrollados colaborativamente como parte de la formación académica en la UADY.*
