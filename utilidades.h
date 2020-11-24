#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

void pegaSenha(char *senha)

{
    char c ;
    int i=0;
    do
    {
        c = getch(); // pega o caractere digitado pelo usuario
        if(isalpha(c)!=0 || c==32) //se for uma letra
        {
            senha[i] = c; //armazena no vetor
            i++;
            printf("*"); //mascara o que foi digitado
        }
        else if (c==8&&i) // se for pressionado backspace e ouver caracteres ja digitados
        {
            senha[i] ='\0'; // o indice atual do vetor recebe terminação de string
            i--; // o indice do vetor de caracteres é decrementado
            printf("\b \b");  // o caractere digitado é apagado da tela
        }
    }
    while (c!=13);
 senha[i] ='\0';

}


void pegaLetras(char *letras)
{
    char c ;
    int i=0;
    do
    {
        c = getch(); // pega o caractere digitado pelo usuario
        if(isalpha(c)!=0 || c==32) //se for uma letra
        {

            letras[i] = c; //armazena no vetor
            i++;
            printf("%c", c); //exibe na tela o que foi digitado
        }
        else if (c==8&&i) // se for pressionado backspace e ouver caracteres ja digitados
        {
            letras[i] ='\0'; // o indice atual do vetor recebe terminação de string
            i--; // o indice do vetor de caracteres é decrementado
            printf("\b \b");  // o caractere digitado é apagado da tela
        }
    }
    while (c!=13)  ;   //executa o loop até que seja pressionado ENTER
     letras[i] ='\0';
}

void pegaDigito(char *digito)

{
    char c ;
    int i=0;
    do
    {
        c = getch(); // pega o caractere digitado pelo usuario
        if(isdigit(c)) //se for numero
        {
            digito[i] = c; //armazena no vetor
            i++;
            printf("%c", c); //exibe na tela o que foi digitado
        }
        else if (c==8&&i) // se for pressionado backspace e ouver caracteres ja digitados
        {
            digito[i] ='\0'; // o indice atual do vetor recebe terminação de string
            i--; // o indice do vetor de caracteres é decrementado
            printf("\b \b");  // o caractere digitado é apagado da tela
        }
    }
    while (c!=13);
 digito[i] ='\0';


}

void pegaLetraseDigitos(char *letras)
{
    char c ;
    int i=0;
    do
    {
        c = getch(); // pega o caractere digitado pelo usuario
        if(isalpha(c)!=0 || c==32 ||  isdigit(c)) //se for, letra, numero ou espaço
        {

            letras[i] = c; //armazena no vetor
            i++;
            printf("%c", c); //exibe na tela o que foi digitado
        }
        else if (c==8&&i) // se for pressionado backspace e ouver caracteres ja digitados
        {
            letras[i] ='\0'; // o indice atual do vetor recebe terminação de string
            i--; // o indice do vetor de caracteres é decrementado
            printf("\b \b");  // o caractere digitado é apagado da tela
        }
    }
    while (c!=13)  ;   //executa o loop até que seja pressionado ENTER
     letras[i] ='\0';
}


void pegaEmail(char *letras)
{
    char c ;
    int i=0;
    do
    {
        c = getch(); // pega o caractere digitado pelo usuario
        if(isalpha(c)!=0 ||  isdigit(c) || c==95 || c==45 || c==64 || c==46 ) //se for letra, numero, -, . ,_, @
        {

            letras[i] = c; //armazena no vetor
            i++;
            printf("%c", c); //exibe na tela o que foi digitado
        }
        else if (c==8&&i) // se for pressionado backspace e ouver caracteres ja digitados
        {
            letras[i] ='\0'; // o indice atual do vetor recebe terminação de string
            i--; // o indice do vetor de caracteres é decrementado
            printf("\b \b");  // o caractere digitado é apagado da tela
        }
    }
    while (c!=13)  ;   //executa o loop até que seja pressionado ENTER
     letras[i] ='\0';
}



void pegaData(char *letras)
{
    char c ;
    int i=0;
    do
    {
        c = getch(); // pega o caractere digitado pelo usuario
        if( isdigit(c) || c==47  ) //se for numero ou /
        {

            letras[i] = c; //armazena no vetor
            i++;
            printf("%c", c); //exibe na tela o que foi digitado
        }
        else if (c==8&&i) // se for pressionado backspace e ouver caracteres ja digitados
        {
            letras[i] ='\0'; // o indice atual do vetor recebe terminação de string
            i--; // o indice do vetor de caracteres é decrementado
            printf("\b \b");  // o caractere digitado é apagado da tela
        }
    }
    while (c!=13)  ;   //executa o loop até que seja pressionado ENTER
     letras[i] ='\0';
}

#endif // UTILIDADES_H_INCLUDED
