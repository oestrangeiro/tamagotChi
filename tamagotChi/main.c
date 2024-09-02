/*
  Tamagotchi desenvolvido como um simples passa tempo em C.
  Desde criança sempre quis ter um, mas nunca havia tido condições para tal.
  Então que programemos o nosso!.

  Projeto iniciado em 02 de Setembro de 2024.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int vida, humor, fome, saude;
    
}Tamagotchi;

void exibirStatus(Tamagotchi *p){
    printf("Vida: %d\n", p->vida);
    printf("Humor: %d\n", p->humor);
    printf("Fome: %d\n", p->fome);
    printf("Saúde: %d\n", p->saude);
}

int gerarNumeroAleatorio(){
    srand(time(0));
    int n = rand() % 2+1;
    return n;
}

void timerParaAMaquinaDeEstado(int t){
    sleep(t);
}

void exibirBarraDeVida(Tamagotchi *p){
    int n = p->vida;
    printf("[");
    for(int i = 0; i < n; i++){
        printf("#");
    }
    printf("]");
    //printf("\n");
}

void matar(Tamagotchi *p, int numeroAleatorioDeDano){
    p->vida = p->vida - numeroAleatorioDeDano;
}

void inicializarPet(Tamagotchi *p){
    srand(time(0));
    int humor = rand() % 4+1;
    int fome = rand() % 7+1;
    int saude = rand() % 6+1;

    p->humor = humor;
    p->fome = fome;
    p->saude = saude;
}

int main() {

    Tamagotchi pet;
    pet.vida = 10;
    inicializarPet(&pet);
    exibirStatus(&pet);


    int idx = 0;
    while(idx < 10){
        //system("clear");
        // int n = gerarNumeroAleatorio();
        // exibirBarraDeVida(&pet);
        // matar(&pet, n);
        // if(pet.vida <= 0){
        //     printf("Pet morreu!\n");
        //     break;
        // }
        //timerParaAMaquinaDeEstado(3);
        idx++;
    }
    
       
    
    return 0;
}
