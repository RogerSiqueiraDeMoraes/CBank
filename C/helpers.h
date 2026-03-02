#ifndef HELPERS_H
#define HELPERS_H
#include "sqlite3.h"

char usuario[50];
char senha[50];

void acessar_conta(sqlite3 *db);
void criar_conta(sqlite3 *db);

#endif