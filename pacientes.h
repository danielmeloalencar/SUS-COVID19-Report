#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
typedef struct data DATA;
struct data{
    int dia;
    int mes;
    int ano;
};


typedef struct paciente PACIENTE;
struct paciente
{
    char nome[50];
    char cpf[15]; //SOMENTE NUMEROS
    char telefone [15];
    char rua[250];
    char numero[10];
    char bairro [50];
    char cidade [100];
    char estado [50];
    char cep    [15];
    DATA nascimento;
    char dataDiagnostico [50];
    char email[100];
    char comorbidades[100];

};


#endif // PACIENTES_H_INCLUDED
