#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include <unistd.h> //un extra para que paresca que esta cargando el inicio del juego
void*** tablero = NULL;
int dimension = 0;
//ACUERDATE AGREGAR EL VALGRIND AL MAKEFILE

int main(int argc, char const *argv[]){
    // Su codigo
    (void)argc;
    (void)argv;

    printf("¡Bienvenido a TreasureFinder!\n Indique el tamaño del tablero a jugar:\n 1. 7x7  2.10x10  3. 12x12\n");
    scanf("%d", &dimension); //lee la opcion elegida (1, 2 o 3)
    switch(dimension){
        case 1: //tablero 7x7
            dimension = 7;
            IniciarTablero(7);
            break;
        case 2: //tablero 10x10
            dimension = 10;
            IniciarTablero(10);
            break;
        case 3: //tablero 12x12
            dimension = 12;
            IniciarTablero(12);
            break;
        default:
            printf("Opcion invalida\n");
            exit(0);
    }
    srand(time(0)); //Setea la seed del random.
    
    printf("Empezando juego...\n");
    printf("¡Listo!\n");

    int option = 0; // guarda la opcion elegida por el jugador
    int exit = 0; //variable para salir del while (para terminar el juego)
    int counter = 1; //contador de turnos
    while ( exit == 0){
        printf("Tablero (Turno %d)\n", counter); // cantidad de turnos
        MostrarTablero();
        int z = 0;
        while (z == 0){ //Esto representa el turno actual
            z = 0;
            printf("Seleccione una accion:\n\n1.Colocar Bomba  2.Mostrar Bombas  3.Mostrar Tesoros  4.Salir \n\n");
            printf("Escoga una opcion: ");
            scanf("%d", &option);
            switch(option){ //procesa la opcion elegida
                case 1: //Colocar Bomba  -- Esto hace pasar de turno
                    //codigo
                    printf("Indique coordenadas de la bomba\n");
                    printf("Fila: ");
                    int fila;
                    scanf("%d", &fila);
                    printf("\nColumna: ");
                    int columna;
                    scanf("%d", &columna);
                    int bombatipo; // 2 -> bomba X  | 1 -> bomba punto
                    printf("Indique forma en que explota la bomba\n1.Punto  2.X\nSu input: ");
                    scanf("%d", &bombatipo);
                    Bomba* bomba = malloc(sizeof(Bomba));
                    bomba->tierra_debajo = tablero[i][j];
                    if (bombatipo == 1){
                        bomba->contador_turnos = 1;
                        bomba->explotar = ExplosionPunto;
                    }else {
                        bomba->contador_turnos = 3;
                        bomba->explotar = ExplosionX;
                    }
                    ColocarBomba(bomba, fila, columna);
                
                    //Bomba bomba1;
                    //if (bombatipo == 1){
                        
                    
                    //PasarTurno()  --> recorre tablero intentando explotar las bombas
                    break;
                case 2: //Mostrar Bombas
                    //codigo

                    break;
                case 3: //Mostrar Tesoros
                    //codigo
                    VerTesoros();
                    break;
                case 4: //salir
                    exit = 1;
                    z = 1;
                    break;
                default:
                    break;
            }
        }

    }
        counter++;
    printf("\nFin del juego\n");
    BorrarTablero();
    return 0;
}

/* EJEMPLOS DE RANDOM PARA FACILITAR SU USO.
*
*   srand(time(0)); // Setea la seed del random.
*   int ejemplo_vida = (rand() % 3) + 1; // Obtiene al azar la vida de Tierra a asignar.
*/