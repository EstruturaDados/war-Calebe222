#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Esta estrutura agrupa dados relacionados a um território no jogo War
struct Territorio {
    char nome[30];      // Nome do território (até 29 caracteres + '\0')
    char cor[10];       // Cor do exército que ocupa o território
    int tropas;         // Número de tropas no território
};

int main() {
    // Declaração do vetor de structs para armazenar 5 territórios
    struct Territorio territorios[5];
    
    printf("=== SISTEMA DE CADASTRO DE TERRITORIOS - WAR ===\n\n");
    
    // Entrada de dados: cadastro dos 5 territórios
    printf("CADASTRO DE TERRITORIOS:\n");
    printf("------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        
        // Entrada do nome do território
        printf("Digite o nome do territorio: ");
        scanf("%29s", territorios[i].nome);
        
        // Entrada da cor do exército
        printf("Digite a cor do exercito: ");
        scanf("%9s", territorios[i].cor);
        
        // Entrada do número de tropas
        printf("Digite o numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        
        // Limpa o buffer do teclado para evitar problemas na próxima leitura
        while (getchar() != '\n');
    }
    
    // Exibição dos dados cadastrados
    printf("\n\n=== TERRITORIOS CADASTRADOS ===\n");
    printf("--------------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }
    
    printf("\n=== CADASTRO CONCLUIDO ===\n");
    
    return 0;
}