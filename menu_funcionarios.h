#ifndef MENU_FUNCIONARIOS_H_INCLUDED
#define MENU_FUNCIONARIOS_H_INCLUDED


void cadastraFuncionario()
{
    FUNCIONARIO func;
    int opcao;
    FILE* arquivo;
    char  confirmaSenha [30];

    desenhaJanela(APP_NAME);


    arquivo = fopen("funcionarios.bin","ab");  // escrita e binário
    if(arquivo == NULL)
    {
        printf("Problema ao tentar abrir o arquivo. \n");

    }
    else
        do
        {

            dicaDeTela("<ENTER> = Proximo campo  - Para desistir, tecle <ENTER> sem preencher o campo atual ",37);

            gotoxy(45,12);
            printf("                                                                          "); //NOME
            gotoxy(45,13);
            printf("                                                                          "); //LIMPA USUARIO
            gotoxy(45,14);
            printf("                                                                          "); //LIMPA SENHA
            gotoxy(45,15);
            printf("                                                                          "); //LIMPA CONFIRMAÇÃO DE SENHA
            gotoxy(45,17);
            printf("                                                                          "); //Limpa a linha 17
            gotoxy(45,18);
            printf("                                                                          "); //Limpa a linha 18
            gotoxy(45,19);
            printf("                                                                           "); //Limpa a linha 19
            gotoxy(45,20);
            printf("                                                                           "); //Limpa a linha 20
            fflush(stdin);

            desenha(20,9,135,0);
            gotoxy(20,8);
            printf(" CADASTRAR FUNCIONARIO ");
            gotoxy(25,12);
            printf("Nome completo: ");
            gotoxy(25,13);
            printf("Usuario: ");
            gotoxy(25,14);
            printf("Senha (letras): ");
            gotoxy(25,15);
            printf("Repita a senha: ");
            gotoxy(45,12); //VAI PARA CAMPO NOME E AGUARDA DIGITAÇÃO

            fflush(stdin);
            gets(func.nome);
            if (strcmp(func.nome,"")==0) break; // se não digitar nada então saia
            gotoxy(45,13);
            fflush(stdin);
            gets(func.login);
            if (strcmp(func.login,"")==0) break; // se não digitar nada então saia
            gotoxy(45,14);
            fflush(stdin);
            pegaSenha(func.senha);
            if (strcmp(func.senha,"")==0) break; // se não digitar nada então saia
            gotoxy(45,15);
            fflush(stdin);
            pegaSenha(confirmaSenha);
            if (strcmp(confirmaSenha,"")==0) break; // se não digitar nada então saia
            //Verifica se a senha é igual a confirmação de senha
            //para garantir que o usuário digitou a senha que realmente desejava
            if (strcmp(confirmaSenha,func.senha)==0)
            {

                //TUDO OK ESCREVE NO ARQUIVO
                fwrite(&func, sizeof(FUNCIONARIO),1,arquivo);
                gotoxy(45,17);
                printf(" ---- CADASTRADO COM SUCESSO! DESEJA CONTINUAR CADASTRANDO ? ----- ");
                gotoxy(45,18);
                printf("      0 = NAO      ");
                gotoxy(45,19);
                printf("      1 = SIM      ");
                gotoxy(45,20);
            }
            else
            {
                gotoxy(45,17);
                printf("!!!!!  A SENHA nao corresponde a CONFIRMACAO DE SENHA  !!!!!");
                gotoxy(45,18);
                printf("      Digite qualquer tecla para tentar novamente ou 0 para sair      ");

            }
            fflush(stdin);
            scanf("%d",&opcao);

        }
        while(opcao != 0);
    fclose(arquivo); //Cadastro concluído, feche o arquivo



}

void listaFuncionarios()
{
    FUNCIONARIO func;
    int opcao,x;
    FILE* arquivo;
    char  confirmaSenha [30];



    system("cls");


    arquivo = fopen("funcionarios.bin","rb");  // leitura e binário
    if(arquivo == NULL)
    {
        printf("Problema ao tentar abrir o arquivo. \n");

    }
    else
    {
        desenhaJanela(APP_NAME);
        gotoxy(20,5);
        printf(" LISTA DE FUNCIONARIOS ");
        gotoxy(20,6);
        printf(" (Pressione qualquer tecla para VOLTAR) ");
        x=12; //LINHA DA TELA ONDE SERA IMPRESSO CADA FUNCIONARIO
        gotoxy(20,x);

        int indice =0;
        while(fread(&func, sizeof(FUNCIONARIO),1,arquivo)==1)
        {
            gotoxy(20,x++);
            printf("----------------------------------------------");
            gotoxy(20,x++);
            printf("#: %d\n",indice);
            gotoxy(20,x++);
            printf("Nome:  %s\n",func.nome);


            indice++;
        }
        fclose(arquivo);
        system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO

    }
}




void removeFuncionarios()
{
    FILE* arq;
    FILE* temp;
    FUNCIONARIO func;
    char login[30];
    arq = fopen("funcionarios.bin","rb");//abrir em modo rb leitura binaria
    temp = fopen("tmp.bin","wb");//abrir em modo wb ele limpa e grava binario

    system("cls");
    if(arq==NULL&&temp==NULL)
    {
        printf("Problemas na abertura do arquivo!\n");
        getch();
    }
    else
    {
        desenhaJanela(APP_NAME);

        gotoxy(20,6);
        fflush(stdin);
        printf("Digite o login do funcionario a deletar: ");
        gets(login);
        while(fread(&func,sizeof(FUNCIONARIO),1,arq)==1)
        {
            if(strcmp(login,func.login)==0)
            {
                gotoxy(20,8);
                printf("Nome: %s\n",func.nome);
                gotoxy(20,9);
                printf("Login: %s\n",func.login);
                gotoxy(20,10);
                printf("-------------------------------------------------\n");
            }
            else
            {
                fwrite(&func,sizeof(FUNCIONARIO),1,temp);//gravando os dados no arquivo temp
            }
        }
        fclose(arq);//fechar o arq
        fclose(temp);//fechar o temp
        fflush(stdin);
        gotoxy(20,20);
        printf("Deseja deletar (s/n)? ");
        if(getche()=='s')
        {
            //vamos remover o arquivo "funcionarios.bin" e renomear o arquivo "tmp.bin" para "funcionarios.bin"
            if(remove("funcionarios.bin")==0&&rename("tmp.bin","funcionarios.bin")==0) //verifica se as operacoes foram realizadas com sucesso!
            {
                gotoxy(20,22);
                printf("\nOperacao realizada com sucesso!");
                system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO
            }
            else
            {
                remove("tmp.bin");//remover o arquivo tmp se acondicao foi "n" na hora de deletar
                printf("\nUsuario nao foi removido!");
                system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO
            }
        }
        fclose(temp);
        fclose(arq);
        getch();
    }
}


void menuFuncionarios()
{
    int opcao;
    do
    {
        desenhaJanela(APP_NAME);
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR",37);

        desenha(50,8,100,20);
        gotoxy(53,8);
        printf(" MENU FUNCIONARIOS ");
        gotoxy(53,10);
        printf(" 1 - Cadastrar Funcionario");
        gotoxy(53,11);
        printf(" 2 - Listar Funcionarios");
        gotoxy(53,12);
        printf(" 3 - Remover Funcionario");
        gotoxy(53,13);
        printf(" 0 - Voltar");

        //desenha(50,22,100,8);
        gotoxy(50,21);
        printf(" Digite uma opcao: ");

        scanf("%d",&opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 0:
            //FAZ NADA
            break;

        case 1:

            cadastraFuncionario();
            break;

        case 2:
            listaFuncionarios();
            break;

        case 3:
            removeFuncionarios();
            break;
        }



    }
    while (opcao !=0);
}


#endif // MENU_FUNCIONARIOS_H_INCLUDED
