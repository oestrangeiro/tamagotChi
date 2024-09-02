/*
  Tamagotchi desenvolvido como um simples passa tempo em C.
  Desde criança sempre quis ter um, mas nuunca havia tido condições para tal.
  Então que programemos o nosso!.

  Projeto iniciado em 02 de Setembro de 2024.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int vida;
    
}Tamagotchi;

void exibirStatus(Tamagotchi *p){
    printf("Vida de pet: %d", p->vida);
}

int gerarNumeroAleatorio(){
    srand(time(NULL));
    int n = rand() % 2+1;
    return n;
}

void timerParaAMaquinaDeEstado(int t){
    sleep(t);
}

void exibirBarraDeVida(Tamagotchi *p){
    int n = p->vida;
    // printf("Barra: %d\n", n);
    printf("[");
    for(int i = 0; i < n; i++){
        printf("#");
    }
    printf("]");
}

void matar(Tamagotchi *p, int numeroAleatorioDeDano){
    p->vida = p->vida - numeroAleatorioDeDano;
}

int main() {

    Tamagotchi pet;
    pet.vida = 10;
    while(1){
        exibirStatus(&pet);
        int n = gerarNumeroAleatorio();
        printf("\n n: %d\n", n);
        exibirBarraDeVida(&pet);
        matar(&pet, n);
        timerParaAMaquinaDeEstado(5);
        
    }
    
    
    return 0;
}
