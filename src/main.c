#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include "helpers.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    sqlite3 *db;
    int rc = sqlite3_open("..\\database\\banco.db", &db);
    if (rc != SQLITE_OK) {
        printf("Erro ao abrir banco de dados: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    int options = 0;
    printf("Opções:\n1 - Acessar conta\n2 - Criar conta\n3 - Sair\n");
    
    while (options != 3) {
        printf("Digite a opção desejada: ");
        scanf("%d", &options);
        
        switch (options) 
        {
            case 1:
                acessar_conta(db);  
                break;
            case 2:
                criar_conta(db);     
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    
    sqlite3_close(db);
    return 0;
}