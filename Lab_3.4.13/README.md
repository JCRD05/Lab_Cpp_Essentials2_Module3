# 3.4.13 LAB: Exceptions: using in program

## Descripción del Ejercicio

El objetivo de este laboratorio es implementar un sistema de manejo de excepciones robusto en un programa interactivo: el juego de las Torres de Hanói. El código modela el juego usando una clase `Stack` (implementada como una lista enlazada) para cada una de las tres torres.

Se definen tres clases de excepción personalizadas para gestionar la lógica del juego y los errores del usuario:
1.  **`InvalidTowerException`**: Se lanza si el usuario introduce un número de torre fuera del rango 1-3.
2.  **`EmptyTowerException`**: Se lanza si la torre de origen seleccionada está vacía.
3.  **`IllegalMoveException`**: Se lanza si se intenta mover un disco grande sobre uno más pequeño.

Estas excepciones se lanzan (`throw`) desde la lógica del juego (en las clases `Game` y `Tower`) y se capturan (`catch`) en el bucle principal (`GameLoop`), lo que permite informar al usuario del error específico sin interrumpir la ejecución del programa.

## Salida del Programa

A continuación se muestra una simulación de la salida del programa, que primero demuestra la solución automática de 7 movimientos y luego muestra una sesión de juego interactiva donde se provocan las tres excepciones.

```console
--- Demonstrating 3-Disk Solution (7 moves) ---
Initial state:
  Tower 1: 3 2 1 ;
  Tower 2: empty;
  Tower 3: empty;
---------------------------------
Move Tower 1 -> Tower 3
  Tower 1: 3 2 ;
  Tower 2: empty;
  Tower 3: 1 ;
---------------------------------
Move Tower 1 -> Tower 2
  Tower 1: 3 ;
  Tower 2: 2 ;
  Tower 3: 1 ;
---------------------------------
... (4 moves omitted for brevity) ...
Move Tower 1 -> Tower 3
  Tower 1: empty;
  Tower 2: empty;
  Tower 3: 3 2 1 ;
---------------------------------
--- Solution Complete ---

Now, you play.
Press Enter To Start...

Enter The Number Of Disks: 3

Starting manual game:
  Tower 1: 3 2 1 ;
  Tower 2: empty;
  Tower 3: empty;
---------------------------------
Enter move (from to, e.g., 1 2. Enter 0 0 to exit): 1 2
Move Tower 1 -> Tower 2
  Tower 1: 3 2 ;
  Tower 2: 1 ;
  Tower 3: empty;
---------------------------------
Enter move (from to, e.g., 1 2. Enter 0 0 to exit): 1 2
Error: Move Error: Cannot place a larger disk onto a smaller disk.
Please try a different move.
Enter move (from to, e.g., 1 2. Enter 0 0 to exit): 4 1
Error: Input Error: Tower must be in the range 1-3.
Please try a different move.
Enter move (from to, e.g., 1 2. Enter 0 0 to exit): 3 1
Error: Move Error: Source tower is empty.
Please try a different move.
Enter move (from to, e.g., 1 2. Enter 0 0 to exit): 0 0
Thanks For Playing!
