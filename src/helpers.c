#include "helpers.h"
#include <stdio.h>
#include <string.h>

int garantir_conexao(sqlite3 **db) {
    if (*db != NULL) {
        return 0; 
    }
    
    int rc = sqlite3_open("..\\database\\banco.db", db);
    if (rc != SQLITE_OK) {
        printf("Erro ao abrir banco de dados: %s\n", sqlite3_errmsg(*db));
        return -1; 
    }
    
    return 1; 
}

void acessar_conta(sqlite3 *db)
{
    int status = garantir_conexao(&db);
    if (status == -1) {
        return;
    }
    
    printf("CPF: ");
    scanf("%49s", CPF);
    printf("Senha: ");
    scanf("%49s", senha);

    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM usuarios WHERE CPF = ? AND senha = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printf("Erro ao preparar consulta: %s\n", sqlite3_errmsg(db));
        if (status == 1) sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, CPF, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, senha, -1, SQLITE_STATIC);

    if(sqlite3_step(stmt) == SQLITE_ROW) {
        printf("Acesso concedido.\n");
    } else {
        printf("CPF ou senha incorretos.\n");
    }

    sqlite3_finalize(stmt);
    
    if (status == 1) {
        sqlite3_close(db);
    }
}

void criar_conta(sqlite3 *db) {
    int status = garantir_conexao(&db);
    if (status == -1) {
        return;
    }

    printf("CPF: ");
    scanf("%49s", CPF);
    printf("Senha: ");
    scanf("%49s", senha);

    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO usuarios (CPF, senha) VALUES (?, ?);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printf("Erro ao preparar inserção: %s\n", sqlite3_errmsg(db));
        if (status == 1) sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, CPF, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, senha, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if(rc != SQLITE_DONE) {
        printf("Erro ao criar conta: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Conta criada com sucesso.\n");
    }

    sqlite3_finalize(stmt);
    
    if (status == 1) {
        sqlite3_close(db);
    }
}