#ifndef TELACADASTRO_H_INCLUDED
#define TELACADASTRO_H_INCLUDED


void desenhaCadastro()
{
    FUNCIONARIO func;
    int opcao;
    FILE* arquivo;
    char  confirmaSenha [30];
    system("COLOR 0B");

    desenhaJanela(APP_NAME);
      arquivo = fopen("funcionarios.bin","ab");  // escrita e binário
    if(arquivo == NULL)
    {
        printf("Problema ao tentar abrir o arquivo de funcionarios. \n");

    }
 else {

    dicaDeTela("Para SAIR, tecle <ENTER> sem preencher o campo atual",37);
    gotoxy(42, 6);
    printf(" CADASTRAR FUNCIONARIO ");
    gotoxy(35, 11);

    desenha(40,5,120,20); //Container Login

    gotoxy(43, 9);
    printf(" Seja bem-vindo. Por favor, crie um usuario com poder de Administrador.");
    gotoxy(43, 10);
    printf(" Este usuario podera listar e excluir funcionarios.");
    gotoxy(43, 11);
    printf(" -----------------------------------------------------------");
    gotoxy(43, 13);
    printf("Nome completo: ");
    gotoxy(43,14);
    printf("Login: ");
    gotoxy(43,15);
    printf("Senha: ");
    gotoxy(43,16);
    printf("Repita a senha: ");
    gotoxy(60,13); //VAI PARA CAMPO NOME E AGUARDA DIGITAÇÃO
    fflush(stdin);
    gets(func.nome);
    if (strcmp(func.nome,"")==0) return; // se não digitar nada então saia
    gotoxy(60,14); //VAI PARA CAMPO LOGIN E AGUARDA DIGITAÇÃO
    fflush(stdin);
    gets(func.login);
    if (strcmp(func.login,"")==0) return; // se não digitar nada então saia
    gotoxy(60,15); //VAI PARA CAMPO SENHA E AGUARDA DIGITAÇÃO
    fflush(stdin);
    pegaSenha(func.senha);
    if (strcmp(func.senha,"")==0) return; // se não digitar nada então saia
    gotoxy(60,16); //VAI PARA CAMPO REPTITA SENHA E AGUARDA DIGITAÇÃO
    fflush(stdin);
   pegaSenha(confirmaSenha);
    if (strcmp(confirmaSenha,"")==0) return; // se não digitar nada então saia
    if (strcmp(confirmaSenha,func.senha)==0)
    {
         func.admin='1'; //DEFINE COMO ADMINISTRADOR
        //TUDO OK ESCREVE NO ARQUIVO
        fwrite(&func, sizeof(FUNCIONARIO),1,arquivo);
        fclose(arquivo); //Cadastro concluído, feche o arquivo
        system("cls");
        gotoxy(45,17);
        printf(" ---- CADASTRADO COM SUCESSO!  Voce ja pode fazer login <ENTER>----- ");
        system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO
        system("cls");
        desenhaLogin();


    } else
    {
        system("cls");
        gotoxy(45,17);
        printf(" ---- ERRO! Sua senha esta diferente da confirmacao de senha ----- ");
       system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO
    }

 }
}


#endif // TELACADASTRO_H_INCLUDED
