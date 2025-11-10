# 3.1.11 LAB: Exceptions: simple checks, part 2

## Descripción del Ejercicio

El objetivo de este laboratorio es implementar una clase que gestione un valor numérico dentro de unos límites definidos, utilizando excepciones para controlar desbordamientos. El código define una clase `Number` que almacena un valor junto con un límite superior y uno inferior.

La clase proporciona los métodos `add` y `subtract`. Antes de modificar el valor, cada método comprueba si el resultado de la operación excedería los límites establecidos. Si la operación es insegura (es decir, el valor resultante estaría fuera del rango permitido), el método lanza (`throw`) una excepción `std::runtime_error`. La función `main` prueba esta funcionalidad creando dos objetos `Number` y realizando operaciones en ellos, cada una envuelta en su propio bloque `try...catch` para manejar los posibles errores de límites.

## Salida del Programa

A continuación se muestra una simulación de una sesión interactiva donde se prueban los límites de los objetos.

```console
input a starting number, lower limit and upper limit, ex: 0 0 10
0 0 10
input another starting number, lower limit and upper limit, ex: 0 0 10
5 0 5
input a value to sum: 5
input a value to sum: 1
Value could exceed limit.
input a value to subtract: 2
input a value to subtract: 6
Value could exceed limit.
