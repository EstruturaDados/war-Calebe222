#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

struct Missao {
    char descricao[100];
    int tipo;
    char alvo[10];
    int quantidade;
};

// Funções principais
void inicializarTerritorios(struct Territorio territorios[], int tamanho) {
    char nomes[][30] = {"Brasil", "Argentina", "Chile", "Peru", "Colombia"};
    char cores[][10] = {"Verde", "Azul", "Vermelho", "Amarelo", "Roxo"};

    for (int i = 0; i < tamanho; i++) {
        strcpy(territorios[i].nome, nomes[i % 5]);
        strcpy(territorios[i].cor, cores[i % 5]);
        territorios[i].tropas = 8 + (rand() % 8);
    }
}

void criarMissao(struct Missao* m) {
    m->tipo = (rand() % 2) + 1;

    if (m->tipo == 1) {
        char cores[][10] = {"Verde", "Azul", "Vermelho", "Amarelo", "Roxo"};
        strcpy(m->alvo, cores[rand() % 5]);
        sprintf(m->descricao, "Destruir o exercito %s", m->alvo);
    } else {
        m->quantidade = 3;
        sprintf(m->descricao, "Conquistar %d territorios", m->quantidade);
    }
}

void atacar(struct Territorio* a, struct Territorio* d) {
    printf("\n%s (%s) -> %s (%s)\n", a->nome, a->cor, d->nome, d->cor);

    int dadoA = (rand() % 6) + 1;
    int dadoD = (rand() % 6) + 1;
    printf("Dados: %d vs %d - ", dadoA, dadoD);

    if (dadoA > dadoD) {
        printf("Atacante vence!\n");
        d->tropas -= 2;
        if (d->tropas < 0) d->tropas = 0;
        strcpy(d->cor, a->cor);
    } else if (dadoA < dadoD) {
        printf("Defensor vence!\n");
        a->tropas -= 2;
        if (a->tropas < 0) a->tropas = 0;
    } else {
        printf("Empate!\n");
    }
}

int verificarMissao(const struct Missao* m, const struct Territorio* t, int qtd, const char* minhaCor) {
    if (m->tipo == 1) {
        // Verificar se exército alvo foi destruído
        for (int i = 0; i < qtd; i++) {
            if (strcmp(t[i].cor, m->alvo) == 0 && t[i].tropas > 0) {
                return 0; // Missão não cumprida
            }
        }
        return 1; // Missão cumprida
    } else {
        // Verificar territórios conquistados
        int conquistados = 0;
        for (int i = 0; i < qtd; i++) {
            if (strcmp(t[i].cor, minhaCor) == 0) {
                conquistados++;
            }
        }
        return conquistados >= m->quantidade;
    }
}

void exibirTerritorios(const struct Territorio* t, int qtd) {
    printf("\n=== TERRITORIOS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s (%s) - %d tropas\n", i+1, t[i].nome, t[i].cor, t[i].tropas);
    }
}

int main() {
    srand((unsigned)time(NULL));

    int qtd = 5;
    struct Territorio* territorios = malloc(qtd * sizeof(struct Territorio));
    if (!territorios) {
        perror("malloc");
        return 1;
    }

    struct Missao missao;
    char minhaCor[10] = "Verde";

    inicializarTerritorios(territorios, qtd);
    strcpy(territorios[0].cor, minhaCor);
    criarMissao(&missao);

    printf("=== WAR - SISTEMA DE MISSOES ===\n");
    printf("Missao: %s\n", missao.descricao);
    printf("Sua cor: %s\n\n", minhaCor);

    int opcao;
    do {
        printf("1. Atacar\n2. Verificar Missao\n3. Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) {
            int c; while ((c = getchar()) != EOF && c != '\n');
            opcao = 0;
        }

        if (opcao == 1) {
            exibirTerritorios(territorios, qtd);

            int a, d;
            printf("\nAtacante (1-%d): ", qtd); scanf("%d", &a);
            printf("Defensor (1-%d): ", qtd); scanf("%d", &d);

            if (a >= 1 && a <= qtd && d >= 1 && d <= qtd && a != d) {
                atacar(&territorios[a-1], &territorios[d-1]);
            } else {
                printf("Indices invalidos!\n");
            }
        } else if (opcao == 2) {
            if (verificarMissao(&missao, territorios, qtd, minhaCor)) {
                printf("\nMISSAO CUMPRIDA! %s\n", missao.descricao);
            } else {
                printf("\nMissao em andamento: %s\n", missao.descricao);
            }
        }
    } while (opcao != 3);

    free(territorios);
    printf("Jogo encerrado!\n");

    return 0;
}