# 3.0.9 LAB: Exceptions: divide by zero

## Descripción del Ejercicio

Este laboratorio tiene como objetivo implementar un manejo de excepciones más formal y robusto. El código define una clase de excepción personalizada, `divide_by_zero`, que hereda de la clase base `std::exception` y sobrescribe el método `what()` para devolver un mensaje de error específico.

Dentro de un bloque `try`, el programa solicita al usuario un dividendo y un divisor. Si el divisor es cero, lanza (`throw`) una instancia de la excepción personalizada. El bloque `catch` está diseñado para capturar específicamente esta excepción (`divide_by_zero&`), permitiendo al programa manejar el error aritmético de forma controlada e informar al usuario llamando al método `e.what()`.

## Salida del Programa

A continuación se muestra una simulación de dos ejecuciones: una con una entrada válida y otra que lanza la excepción.

```console
# --- Ejecución con entrada válida ---
Input a dividend: 10
Input a divisor: 4
2.5

# --- Ejecución con entrada inválida ---
Input a dividend: 10
Input a divisor: 0
invalid input: you can't divide by zero.
