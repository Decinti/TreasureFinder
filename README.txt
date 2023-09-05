Nombre: Bruno Alonso Decinti Villarroel 
Rol: 201911524-3
Instrucciones o Consideraciones:

1. La version de gcc usada es la 11.3.0 (gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0)

2. En el archivo "Tablero.c" se añadio la linea "typedef struct Bomba Bomba;" para solucionar un error
Tablero.h:9:19: error: unknown type name ‘Bomba’
    9 | void ColocarBomba(Bomba* b, int fila, int columna);
      |                   ^~~~~

3. En el archivo "Tablero.c" se añadio "#include <stdlib.h>" y "#include <stdio.h>"

4. se declara "void*** tablero = NULL;" y "int dimension = 0;" en "TreasureFinder.c" para inicializarlos

5.
