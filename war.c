#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Esta estrutura agrupa dados relacionados a um território no jogo War

struct Territorio {
    char nome[30];
    char cor[30];
    int tropas;
};

int main() {
    // Declaração do vetor de structs para armazenar 5 territórios
    struct Territorio territorios[5];

    printf("=== SISTEMA DE CADASTRO DE TERRITORIOS - WAR ===\n\n");

    // Entrada de dados: cadastro dos 5 territórios
    printf("CADASTRO DE TERRITORIOS:\n");
    printf("------------------------------");

     for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d: \n", i + 1);

        printf("Digite o nome do território: ");
        scanf("29s", territorios[i].nome);

        // Entrada da cor do exército
        printf("Digite a cor do exército: ");
        scanf("9s", territorios[i].cor);
      
        // Entrada do número de tropas
        printf("Digite o número de tropas: ");
        scanf("%d", &territorios[i].tropas);

        // Limpar o Buffer do teclado para evitar problemas na próxima leitura
        while (getchar() != '\n');
     };

        // Exibição dos dados cadastrados
        printf("\n\n=== TERRITORIOS CADASTRADOS ===\n");
        printf("------------------------------\n");

        for (int i = 0; i < 5; i++) {
            printf("Território %d:\n", i + 1);
            printf("Nome: %s\n", territorios[i].nome);
            printf("Cor do Exército: %s\n", territorios[i].cor);
            printf("Número de Tropas: %d\n", territorios[i].tropas);
            printf("------------------------------\n");
        }

        printf("\n=== Cadastro Concluído ===\n");

        return 0;
}