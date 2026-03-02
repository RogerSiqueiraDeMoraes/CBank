#ifndef HELPERS_H
#define HELPERS_H

#include "sqlite3.h"

void criar_conta(sqlite3 *db);
void depositar(sqlite3 *db);
void listar_contas(sqlite3 *db);

#endif