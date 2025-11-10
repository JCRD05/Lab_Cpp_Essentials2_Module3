# 3.2.16 LAB: Exceptions: file checks

## Descripción del Ejercicio

El objetivo de este laboratorio es practicar el manejo de excepciones relacionadas con operaciones de archivos. El código define una clase `Matrix` (para una matriz de 2x2) que incluye dos métodos: `loadFromFile` y `writeToFile`.

Ambos métodos intentan abrir un archivo (`std::ifstream` y `std::ofstream`, respectivamente) y comprueban si la apertura fue exitosa usando `is_open()`. Si el archivo no se puede abrir (por ejemplo, no existe o no hay permisos), el método lanza (`throw`) una `std::runtime_error`. La función `main` simula estos dos escenarios de error (intentando cargar un archivo inexistente y guardar en un directorio protegido) y utiliza bloques `try...catch` para capturar e imprimir los mensajes de error.

## Salida del Programa

A continuación se muestra una simulación de la salida del programa al encontrar los errores de archivo esperados.

```console
error trying to open file: nonexistent_file.txt

error trying to open file: protected_directory/matrix.txt
