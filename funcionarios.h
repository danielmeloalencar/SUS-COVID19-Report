#ifndef FUNCIONARIOS_H_INCLUDED
#define FUNCIONARIOS_H_INCLUDED

typedef struct funcionario FUNCIONARIO;
struct funcionario
{
    char nome[50];
    char login[30];
    char senha[30];
    char admin;

};

#endif // FUNCIONARIOS_H_INCLUDED
