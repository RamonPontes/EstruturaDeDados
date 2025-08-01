#include <stdio.h>
#include <malloc.h>

struct arv
{
    char info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* cria(char c) {
    Arv* a = (Arv*) malloc(sizeof(Arv));
    a->info = c;
    a->dir = NULL;
    a->esq = NULL;
    
    return a;
}

Arv* libera(Arv* a) {
    if (a != NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }

    return NULL;
}

Arv* insere(Arv* a, char elem) {
    Arv* s;
    if (a != NULL) {
        if (elem < a->info) {
            s = insere(a->esq, elem);
            a->esq = s;
        } else {
            s = insere(a->dir, elem);
            a->dir = s;
        }
    } else
        a = cria(elem);
    return a;
}

void pre(Arv* a) {
    if (a != NULL) {
        printf(" %c", a->info);
        pre(a->esq);
        pre(a->dir);
    }
}

void pos(Arv* a) {
    if (a != NULL) {
        pos(a->esq);
        pos(a->dir);
        printf(" %c", a->info);
    }
}

void in(Arv* a) {
    if (a != NULL) {
        in(a->esq);
        printf(" %c", a->info);
        in(a->dir);
    }
}

void dne(Arv* a) {
    if (a != NULL) {
        in(a->dir);
        printf(" %c", a->info);
        in(a->esq);
    }
}

void edn(Arv* a) {
    if (a != NULL) {
        in(a->esq);
        in(a->dir);
        printf(" %c", a->info);
    }
}

void nde(Arv* a) {
    if (a != NULL) {
        printf(" %c", a->info);
        in(a->dir);
        in(a->esq);
    }
}

int busca(Arv *a, char elem) {
    if (a == NULL)
        return 0;
    else 
        if (a->info > elem)
            return busca(a->esq, elem);
        else 
            if (a->info < elem)
                return busca(a->dir, elem);
            else
                return 1;
}

int main() {
    Arv* a = NULL;
    int opcao = -1;
    int b;
    char elem;
    while (opcao != 0) {
        printf("\n1-Insere\n2-Mostra pré-ordem");
        printf("\n3-Mostra in-ordem\n4-Mostra pós-ordem");
        printf("\n5-Mostra em DNE\n6-Mostra em EDN");
        printf("\n7-Mostra em NDE\n8-Busca\n0-Sair");
        printf("\nDigite sua opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite elemento a incluir ");
                scanf(" %c", &elem);
                a = insere(a, elem);
                break;
            case 2:
                pre(a);
                break;
            case 3:
                in(a);
                break;
            case 4:
                pos(a);
                break;
            case 5:
                dne(a);
                break;            
            case 6:
                edn(a);
                break;            
            case 7:
                nde(a);
                break;
            case 8:
                printf("Digite elemento a incluir ");
                scanf(" %c", &elem);

                b = busca(a, elem);

                if (b == 1) printf("Elemento existente\n");
                else printf("Elemento inexistente\n");

                break;
            case 0:
                break;
            default:
                printf("\nOpção inexistente!");
                break;
        }
    }

    libera(a);
}