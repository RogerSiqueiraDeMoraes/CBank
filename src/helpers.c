#include "helpers.h"
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

void acessar_conta(sqlite3 *db)
{
    // Se db for NULL, abre a conexão
    int precisa_fechar = 0;
    if (db == NULL) {
        int rc = sqlite3_open("..\\database\\banco.db", &db);
        if (rc != SQLITE_OK) {
            printf("Erro ao abrir banco de dados: %s\n", sqlite3_errmsg(db));
            return;
        }
        precisa_fechar = 1;
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
        if (precisa_fechar) sqlite3_close(db);
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
    
    // Fecha a conexão se foi aberta aqui
    if (precisa_fechar) {
        sqlite3_close(db);
    }
}

void criar_conta(sqlite3 *db) {
    // Se db for NULL, abre a conexão
    int precisa_fechar = 0;
    if (db == NULL) {
        int rc = sqlite3_open("..\\database\\banco.db", &db);
        if (rc != SQLITE_OK) {
            printf("Erro ao abrir banco de dados: %s\n", sqlite3_errmsg(db));
            return;
        }
        precisa_fechar = 1;
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
        if (precisa_fechar) sqlite3_close(db);
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
    
    // Fecha a conexão se foi aberta aqui
    if (precisa_fechar) {
        sqlite3_close(db);
    }
}