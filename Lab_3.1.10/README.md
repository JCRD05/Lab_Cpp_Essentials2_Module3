# 3.1.10 LAB: Exceptions: simple checks

## Descripción del Ejercicio

El objetivo de este laboratorio es construir una clase `Matrix` que utilice el manejo de excepciones para garantizar la validez de los datos y las operaciones. La clase implementa una excepción personalizada, `matrix_exception` (derivada de `std::runtime_error`), para errores de lógica de operaciones, y también utiliza excepciones estándar de C++ como `std::invalid_argument` (para dimensiones de constructor no válidas) y `std::out_of_range` (para acceso a índices fuera de los límites).

El código principal (`main`) prueba esta funcionalidad creando tres matrices: dos con dimensiones idénticas (3x3) y una tercera con dimensiones diferentes (2x2). Todas las operaciones se realizan dentro de un bloque `try...catch`. El programa suma exitosamente las dos matrices de 3x3, pero al intentar sumar una matriz de 3x3 con una de 2x2, la clase lanza la `matrix_exception`. Esta es capturada por el bloque `catch`, que imprime el mensaje de error y finaliza la ejecución de forma segura.

## Salida del Programa

A continuación se muestra una simulación de la salida del programa. Los valores de las matrices son aleatorios, pero el flujo de la operación y el error final son representativos.

```console
# Salida de matrix1 (3x3)
2	1	7	
5	8	3	
9	1	1	

# Salida de matrix2 (3x3)
6	3	0	
4	4	5	
1	2	8	

# Salida de matrix3 (2x2)
9	3	
2	7	

# Salida de (matrix1 + matrix2)
8	4	7	
9	12	8	
10	3	9	

# El intento de (matrix1 + matrix3) lanza la excepción
different matrices dimensions
