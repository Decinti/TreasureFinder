#include <stdlib.h>
#include <stdio.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
int numDeBombas = 0; //Variable para llevar la cuenta de cuantas bombas hay
void IniciarTablero(int n){
    // Su codigo
    tablero = malloc(n * sizeof(void**));
    for (int i=0; i<n; i++){
        tablero[i] = malloc(n * sizeof(void*));
    }
    int probabilidad = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            probabilidad = (rand() % 99);
            tablero[i][j] = (void*) malloc(sizeof(Tierra));
            ((Tierra*)tablero[i][j])->vida = (rand() % 3) + 1;
            if (probabilidad > 4) {
                ((Tierra*)tablero[i][j])->es_tesoro = 0; // 0 -> No tiene tesoro
            }else{
                ((Tierra*)tablero[i][j])->es_tesoro = 1; // 1-> Si tiene tesoro
            }
        }
    }
    return;
}


void PasarTurno(){
    // Su codigo
    return;
}


void ColocarBomba(Bomba* b, int fila, int columna){
    // Su codigo
    tablero[fila][columna] = b;
    printf("contador_turnos: %d", tablero[fila][columna])
    return;
}


void MostrarTablero(){
    // Su codigo
    for (int i=0; i<dimension; i++){
        printf("\n");
        for (int j=0; j<dimension; j++){
            printf(" %d |",((Tierra*)tablero[i][j])->vida);
        }
    }
    printf("\n\n");
    return;
}

void MostrarBombas(){
    // Su codigo
    return;
}


void VerTesoros(){
    // Su codigo
    for (int i=0; i<dimension; i++){
        printf("\n");
        for (int j=0; j<dimension; j++){
            if (((Tierra*)tablero[i][j])->es_tesoro == 1){   
                printf(" * |");
            }else{
                printf(" %d |",((Tierra*)tablero[i][j])->vida);
            }
        }
    }
    printf("\n\n");
    return;
}


void BorrarTablero(){
    // Su codigo
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){
            free(tablero[i][j]);
            tablero[i][j] = NULL;
        }
        free(tablero[i]);
        tablero[i] = NULL;
    }
    free(tablero);
    tablero = NULL;
    return;
}