# 3.1.9 LAB: Exceptions: catch block

## Descripción del Ejercicio

El objetivo de este laboratorio es crear y utilizar una clase de excepción personalizada que pueda transmitir información adicional al bloque `catch`. El programa define la clase `negative_area`, que hereda de `std::runtime_error`, permitiéndole pasar un mensaje de error en su constructor.

El programa calcula el área de un cuadrado (`squareArea`) y un rectángulo (`rectangleArea`). Ambas funciones validan sus argumentos; si alguna dimensión es menor o igual a cero, lanzan (`throw`) una excepción `negative_area` con un mensaje descriptivo. La función `main` envuelve las llamadas a estas funciones en un bloque `try` y captura la excepción, usando `e.what()` para imprimir el mensaje de error específico proporcionado por la función que falló.

## Salida del Programa

A continuación se muestra una simulación de tres ejecuciones distintas, demostrando la validación para cada caso.

```console
# --- Ejecución con entrada válida ---
input the square side: 5
input the base of the rectangle: 10
input the height of the rectangle: 4
square area: 25
rectangle area: 40

# --- Ejecución con lado del cuadrado inválido ---
input the square side: -2
input the base of the rectangle: 10
input the height of the rectangle: 4
Your input is not valid. The area can't be negative.

# --- Ejecución con base del rectángulo inválida ---
input the square side: 5
input the base of the rectangle: 0
input the height of the rectangle: 4
Your input is not valid. The area can't be negative.
