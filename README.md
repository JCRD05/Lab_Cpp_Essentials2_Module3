# Lab_Cpp_Essentials2_Module3

## Contexto del Proyecto

Este repositorio agrupa las soluciones a todos los laboratorios prácticos del **Módulo 3: "Exceptions"**, correspondiente al curso **"C++ Essentials 2"** de Cisco Networking Academy.

El objetivo principal es aplicar de forma práctica los conceptos de manejo de errores, aprendiendo a capturar, lanzar y crear excepciones personalizadas para construir programas robustos.

## Contenido del Repositorio

A continuación se listan los proyectos y ejercicios contenidos en este repositorio:

* **3.0.8:** Exceptions: input validation
* **3.0.9:** Exceptions: divide by zero
* **3.1.8:** Exceptions: input validation (Refactoring)
* **3.1.9:** Exceptions: catch block
* **3.1.10:** Exceptions: simple checks (Matrix class)
* **3.1.11:** Exceptions: simple checks, part 2 (Number class)
* **3.2.16:** Exceptions: file checks
* **3.2.17:** Exceptions: checking strings (IpAddress class)
* **3.4.12:** Exceptions: including information in exceptions (IpHeader class)
* **3.4.13:** Exceptions: using in program (Tower of Hanoi)

---

## Herramientas Utilizadas

* **Lenguaje:** C++
* **Compilador:** Compatible con g++, Clang, o MSVC (se recomienda C++17 o superior).
* **Librerías:** Biblioteca Estándar de C++ (`iostream`, `stdexcept`, `fstream`, `vector`, etc.).

---

## Compilación y Ejecución

El código de cada laboratorio es autocontenido. Para compilar y ejecutar cualquiera de los ejercicios, se puede utilizar un compilador de C++ estándar como g++.

**Ejemplo de compilación con g++:**
```bash
# Para un proyecto con varios archivos .cpp
g++ main.cpp Clase1.cpp Clase2.cpp -o ejecutable
```

# Para un proyecto simple
g++ main.cpp -o ejecutable

## Conceptos Clave Practicados

A lo largo de estos laboratorios, se aplican los siguientes conceptos clave del manejo de excepciones:

* **Manejo Básico:** Uso de los bloques `try` y `catch` para capturar errores en tiempo de ejecución.
* **Lanzamiento de Excepciones:** Uso de la palabra clave `throw` para señalar una condición de error.
* **Excepciones Estándar:** Captura de excepciones de la biblioteca estándar, como `std::invalid_argument`, `std::out_of_range` y `std::runtime_error`.
* **Excepciones Personalizadas:** Creación de clases de excepción propias (ej. `divide_by_zero`, `IllegalMoveException`) heredando de `std::exception`.
* **Validación en Constructores:** Lanzar excepciones desde el constructor para prevenir la creación de objetos en estado inválido.
* **Manejo de Errores de I/O:** Gestión de errores relacionados con operaciones de archivos (ej. `is_open()`).
* **Propagación de Excepciones:** Entender cómo una excepción no capturada se propaga hacia arriba en la pila de llamadas.
