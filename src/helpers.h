#ifndef HELPERS_H
#define HELPERS_H
#include "sqlite3.h"

char CPF[50];
char senha[50];


int garantir_conexao(sqlite3 **db);
void acessar_conta(sqlite3 *db);
void criar_conta(sqlite3 *db);

#endif