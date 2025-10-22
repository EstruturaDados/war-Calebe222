#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

void cadastrarTerritorios(struct Territorio* t, int qtd) {
    printf("\n==== Cadastro ====\n");
    for (int i = 0; i < qtd; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf("Nome: "); scanf("%29s", t[i].nome);
        printf("Cor: "); scanf("%9s", t[i].cor);
        printf("Tropas: "); scanf("%d", &t[i].tropas);
    }
}

void exibirTerritorios(struct Territorio* t, int qtd) {
    printf("\n=== TERRITORIOS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s (%s) - %d tropas\n",
               i + 1, t[i].nome, t[i].cor, t[i].tropas);
    }
}

void atacar(struct Territorio* a, struct Territorio* d) {
    printf("\n=== ATAQUE ===\n");
    printf("%s (%s) -> %s (%s)\n", a->nome, a->cor, d->nome, d->cor);

    int dadoA = (rand() % 6) + 1;
    int dadoD = (rand() % 6) + 1;
    printf("Dados: Atacante=%d, Defensor=%d\n", dadoA, dadoD);

    if (dadoA > dadoD) {
        printf("Vitória do atacante\n");
        d->tropas -= 2;
        if (d->tropas < 0) d->tropas = 0;
        strcpy(d->cor, a->cor);
    } else if (dadoD > dadoA) {
        printf("Vitória do defensor!!\n");
        a->tropas -= 2;
        if (a->tropas < 0) a->tropas = 0;
    } else {
        printf("Empate!\n");
    }

    printf("Resultado: %s (%d tropas), %s (%d tropas)\n",
           a->nome, a->tropas, d->nome, d->tropas);
}

int main(void) {
    srand((unsigned)time(NULL));

    int qtd;
    printf("Quantos Territórios? ");
    if (scanf("%d", &qtd) != 1 || qtd <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    struct Territorio* territorios = malloc(qtd * sizeof *territorios);
    if (!territorios) {
        perror("malloc");
        return 1;
    }

    cadastrarTerritorios(territorios, qtd);

    int opcao;
    do {
        printf("\n1. Exibir\n2. Atacar\n3. Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) {
            /* limpa entrada inválida */
            int c; while ((c = getchar()) != EOF && c != '\n');
            opcao = 0;
        }

        if (opcao == 1) {
            exibirTerritorios(territorios, qtd);
        } else if (opcao == 2) {
            exibirTerritorios(territorios, qtd);
            int a, d;
            printf("\nAtacante (1-%d): ", qtd); scanf("%d", &a);
            printf("Defensor (1-%d): ", qtd); scanf("%d", &d);

            if (a >= 1 && a <= qtd && d >= 1 && d <= qtd && a != d) {
                atacar(&territorios[a-1], &territorios[d-1]);
            } else {
                printf("Indices invalidos!\n");
            }
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    free(territorios);
    printf("Jogo encerrado!\n");
    return 0;
}