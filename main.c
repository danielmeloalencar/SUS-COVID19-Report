#include <stdio.h>
#include <windows.h> //PARA DATA
#include"string.h"; //Para comparar strings
#include "unistd.h"; //Para usar access e checar se arquivo existe
#include "ctype.h"; //isAlpha
#include "utilidades.h";
#include "funcionarios.h"; //Estrutura do arquivo funcionarios
#include "pacientes.h"; //Estrutura do arquivo pacientes

//#include"locale.h"; // Para usar setlocale


char admin='0';
char usuarioLogado[30]="";
const char APP_NAME[100] = "SUS CODIV-19 REPORT - Universidade Paulista";
#include "design.h";
#include "telaCadastro.h"
#include "telaLogin.h";
#include "menuPacientes.h";
#include "menu_principal.h";


int main(void)
{
    FILE* arquivo;
    int tamanhoArquivo;
    //Muda para o idioma padrão do sistema operacional (SE descomentar irá mudar os caracteres, causando assim  um problema no desenho das janelas
    //setlocale(LC_ALL,"");
    ajustaJanela();
    if( access( "funcionarios.bin", F_OK ) != -1 )
    {
        //ARQUIVO EXISTE, MAS PRECISAMOS GARANTIR QUE JÁ FOI FEITO O PRIMEIRO CADASTRO
        //PARA ISSO VERIFICAMOS SEU TAMANHO
        arquivo = fopen("funcionarios.bin","rb");
        fseek(arquivo, 0, SEEK_END);  // Vai para o fim do arquivo
        tamanhoArquivo = ftell(arquivo); // pega o ponteiro atual
        fclose(arquivo);
        if(tamanhoArquivo >0)
        {
            //OK, ARQUIVO EXISTE E FOI FEITO O CADASTRO DE PELO MENOS 1 FUNCIONARIO
            desenhaLogin();
        }

        else
        {
            //ARQUIVO EXISTE MAS NÃO TEM USUARIOS CADASTRADOS
            desenhaCadastro();
        }

    }
    else
    {    //ARQUIVO NÃO EXISTE
         desenhaCadastro();
    }



    system("cls");

    system("COLOR 0F");  //VOLTA AS CORES PARA O PADRÃO (FUNDO PRETO, LETRAS BRANCAS)
    printf("PRESSIONE QUALQUER TECLA PARA SAIR");
    system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO
    return 0;
}
