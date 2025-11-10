# 3.2.17 LAB: Exceptions: checking strings

## Descripción del Ejercicio

El objetivo de este laboratorio es practicar el lanzamiento de excepciones tanto desde un constructor como desde un método para validar entradas. El código implementa una clase `IpAddress` cuyo constructor recibe una dirección IP como `std::string` y la valida rigurosamente.

El constructor lanza `std::invalid_argument` si la IP no tiene exactamente cuatro octetos, si un octeto está vacío, si contiene caracteres no numéricos, o si un valor está fuera del rango 0-255.

Además, la clase tiene un método `printSubnet()` que también valida su propio argumento (la máscara de subred), lanzando una excepción si el número no es una potencia de dos o es mayor a 256. La función `main` envuelve la creación del objeto y la llamada al método en un solo bloque `try...catch` para manejar cualquiera de estos errores.

## Salida del Programa

A continuación se muestra una simulación de tres ejecuciones distintas, demostrando una entrada válida, un error en el constructor y un error en el método.

```console
# --- Ejecución con entrada válida ---
192.168.1.150
32
192.168.1.128

# --- Ejecución con IP inválida (Constructor) ---
192.168.1.256
32
invalid input, the octet is out of the valid range: 0-255

# --- Ejecución con Máscara inválida (Método) ---
192.168.1.150
30
invalid input, subnet is not a power of two
