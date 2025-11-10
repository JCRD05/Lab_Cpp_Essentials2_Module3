# 3.1.8 LAB: Exceptions: input validation

## Descripción del Ejercicio

El objetivo de este laboratorio es refactorizar un programa para utilizar excepciones en lugar de valores de retorno para el manejo de errores. El código compara dos estrategias de implementación:

1.  **`divisionA`**: Una función que implementa un manejo de excepciones interno. Lanza (`throw`) la excepción de división por cero y la captura (`catch`) dentro de sí misma, imprimiendo el error pero ocultando la excepción al código que la llamó.
2.  **`divisionB`**: Una función que solo se encarga de lanzar la excepción si el divisor es cero, delegando la responsabilidad de la captura al código que la invoca (en este caso, la función `main`).

La función `main` demuestra ambas técnicas, llamando a `divisionA` directamente y envolviendo la llamada a `divisionB` en un bloque `try...catch`, lo que ilustra la diferencia entre el manejo de errores interno y el delegado.

## Salida del Programa

A continuación se muestra una simulación de dos ejecuciones: una con entradas válidas y otra con una división por cero.

```console
# --- Ejecución con entrada válida ---
input a dividend: 10
input a divisor: 4

2.5
2.5

# --- Ejecución con entrada inválida ---
input a dividend: 10
input a divisor: 0
Are you kidding me?
Your input is not valid.You can't divide by zero.
0
Are you kidding me?
Your input is not valid.You can't divide by zero.
