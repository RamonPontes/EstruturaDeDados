#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct fila {
    int ini, fim;
    float vet[100];
};

typedef struct fila Fila;

Fila *cria() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->ini = f->fim = 0;
    return f;
}

int incr(int i) {
    if (i == 99) {
        return 0;
    } else {
        return i + 1;
    }
}

void insere(Fila *f, float v) {
    if (incr(f->fim) == f->ini) {
        printf("Capacidade de fila estourou!!!\n");
        exit(1);
    }

    f->vet[f->fim] = v;
    f->fim = incr(f->fim);
}

float retira(Fila *f) {
    float v;
    if (f->ini == f->fim) {
        printf("Fila vazia!!!\n");
        exit(1);
    }
    v = f->vet[f->ini];
    f->ini = incr(f->ini);

    return v;
}

void libera(Fila *f) {
    free(f);
}

void mostrafila(Fila *f) {
    int n = f->ini;
    while (n < f->fim) {
        if (n == f->ini)
            printf("INICIO ->");
        else 
            printf("       ->");
        printf("%f\n", f->vet[n]);
        n = incr(n);
    }
}

int main() {
    Fila *f = cria();
    float elem;
    int opcao = 0;

    while (opcao != 4) {
        printf("\n1-Insere na fila\n2-Retira da fila\n3-Mostra fila\n4-Fim\n");
        printf("Selecione sua opção (1-41): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a inserir: ");
                scanf("%f", &elem);
                insere(f, elem);
                break;
            case 2:
                printf("Elemento retirado: %f", retira(f));
                break;
            case 3:
                mostrafila(f);
                break;
            case 4:
                break;
            default:
                printf("Opção inválida");
        }
    }
    
    libera(f);
}