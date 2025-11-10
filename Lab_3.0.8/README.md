# 3.0.8 LAB: Exceptions: input validation

## Descripción del Ejercicio

El objetivo de este laboratorio es introducir el manejo básico de excepciones en C++ para la validación de entradas. El programa solicita al usuario que ingrese un número para usarlo como divisor. El código implementa un bloque `try...catch` para gestionar posibles errores. Si el usuario introduce un `0`, el programa utiliza explícitamente la palabra clave `throw` para lanzar una excepción con un mensaje de error. Esta excepción es capturada por el bloque `catch`, que imprime el mensaje de error y finaliza el programa de forma controlada, evitando un error de división por cero.

## Salida del Programa

A continuación se muestra una simulación de dos ejecuciones diferentes: una con una entrada válida y otra con la entrada que provoca la excepción.

```console
# --- Ejecución con entrada válida ---
4
2

# --- Ejecución con entrada inválida ---
0
Invalid input: you can't divide by zero
