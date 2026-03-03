#include "helpers.h"
void acessar_conta(sqlite3 *db)
{
    int rc = sqlite3_open("database/banco.db", &db);
    printf("CPF: ");
    scanf("%s", CPF);
    printf("Senha: ");
    scanf("%s", senha);

    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM usuarios WHERE CPF = ? AND senha = ?;";

    sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, CPF, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, senha, -1, SQLITE_TRANSIENT);

    if(sqlite3_step(stmt) == SQLITE_ROW) {
        printf("Acesso concedido.\n");
    } else {
        printf("CPF ou senha incorretos.\n");
    }

    sqlite3_finalize(stmt);
}
void criar_conta(sqlite3 *db) {
    int rc = sqlite3_open("banco.db", &db);
    printf("CPF: ");
    scanf("%s", CPF);
    printf("Senha: ");
    scanf("%s", senha);

    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO contas (CPF, senha) VALUES (?, ?);";

    sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, CPF, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, senha, -1, SQLITE_TRANSIENT);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        printf("Erro ao criar conta!\n");
    } else {
        printf("Conta criada com sucesso!\n");
    }

    sqlite3_finalize(stmt);
}
void listar_contas(sqlite3 *db);