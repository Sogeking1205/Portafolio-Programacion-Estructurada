# Portafolio de Programación Estructurada (Lenguaje C)

Este repositorio contiene mis proyectos destacados desarrollados durante la materia de Programación Estructurada. El objetivo de estos sistemas es demostrar el dominio de la lógica de programación, manejo de memoria, y arquitectura de software en C.

## 📓 Proyecto 1: My Daily Note (Diario Inteligente con Análisis de Riesgo)
Un sistema de registro personal que analiza las entradas de texto del usuario para detectar indicadores de riesgo psicológico o violencia.

* **Características técnicas destacadas:**
  * **Memoria Dinámica:** Uso de punteros y `realloc` para la captura de texto de longitud variable, optimizando el uso de RAM.
  * **Análisis de Cadenas:** Implementación de un algoritmo de búsqueda iterativa sobre un diccionario de 76 palabras clave para la detección de anomalías.
  * **Persistencia de Datos:** Manejo de archivos externos (`.txt`) para el almacenamiento de edades y lectura/escritura de los diarios generados.
  * **Lógica Condicional:** Evaluación de riesgo adaptativa basada en el rango de edad del usuario (niños vs. adolescentes).

## ✈️ Proyecto 2: Gestor de Aeropuerto (Sistema CRUD Modular)
Un sistema de gestión operativa para el control de pistas y estados de vuelos del Aeropuerto de Mérida.

* **Características técnicas destacadas:**
  * **Arquitectura Modular:** Separación de responsabilidades mediante archivos de cabecera (`.h`) y múltiples archivos fuente (`.c`), facilitando el mantenimiento y la escalabilidad del código.
  * **Estructuras de Datos:** Modelado de entidades complejas utilizando `structs` y arreglos paralelos para la relación entre Vuelos y Pistas.
  * **Operaciones CRUD:** Implementación completa de un ciclo de vida de datos (Registro, Consulta, Modificación y Cancelación).
  * **Reglas de Negocio:** Validación estricta en el cambio de estados de vuelo (Programado, Abordando, Despegando, Aterrizado, Retrasado) previniendo flujos de error en el sistema.

---
*Desarrollado por Santiago como parte de la formación en Ingeniería de Software.*
