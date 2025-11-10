# 3.4.12 LAB: Exceptions: including information in exceptions

## Descripción del Ejercicio

El objetivo de este laboratorio es practicar el lanzamiento de excepciones desde un constructor, asegurando que la excepción contenga información útil y específica sobre el error. El código implementa una clase `IpHeader` que, a su vez, se compone de dos objetos `IpAddress` (origen y destino).

La validación se delega al constructor de `IpAddress`, que ha sido modificado para aceptar un segundo argumento (`ipType`: "source" o "destination"). Si la validación de una IP falla, el constructor de `IpAddress` lanza una `std::invalid_argument`, pero ahora prefija el mensaje de error con el tipo de IP. Esto permite que el `try...catch` en `main` capture un mensaje que informa al usuario exactamente qué dirección IP fue la incorrecta.

## Salida del Programa

A continuación se muestra una simulación de tres ejecuciones distintas, demostrando el caso de éxito y los dos tipos de error.

```console
# --- Ejecución con entradas válidas ---
input a source and destination address: 192.168.1.1 10.0.0.1
Ip header succesfully created!

# --- Ejecución con IP de origen inválida ---
input a source and destination address: 192.168.999.1 10.0.0.1
source: invalid input, the octet is out of the valid range: 0-255

# --- Ejecución con IP de destino inválida ---
input a source and destination address: 192.168.1.1 10.0.0
destination: invalid input, ip address has less than four octets
