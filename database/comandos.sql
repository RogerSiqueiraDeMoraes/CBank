SELECT * from usuarios;

drop TABLE usuarios;

CREATE TABLE contas (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    cpf TEXT UNIQUE NOT NULL,
    senha_hash TEXT NOT NULL,
    salt TEXT NOT NULL,
    saldo REAL DEFAULT 0,
    tentativas INTEGER DEFAULT 0
)

