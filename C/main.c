#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include "helpers.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int options = 0;
    printf("Opções:\n1 - Acessar conta\n2 - Criar conta\n3 - Sair\n");
    while (options != 3) {
        printf("Digite a opção desejada: ");
        scanf("%d", &options);
        switch (options) 
        {
            case 1:
                criar_conta(NULL);
                break;
            case 2:
                // Criar conta
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}