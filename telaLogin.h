#ifndef TELALOGIN_H_INCLUDED
#define TELALOGIN_H_INCLUDED
void desenhaLogin()
{
    FUNCIONARIO func;
    FILE* arquivo;
    char usuario[30];
    char senha[30];


    arquivo = fopen("funcionarios.bin","rb");  // leitura e binário

    if(arquivo == NULL)
    {

        system("cls");
        printf("Problema ao tentar abrir o arquivo de funcionarios. \n");
        system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO

    }
    else

        do
        {

            desenhaJanela(APP_NAME);
            gotoxy(42, 6);
            printf(" LOGIN  ");
            gotoxy(35, 11);

            desenha(40,5,120,20); //Container Login

            gotoxy(43, 9);
            printf(" Por favor, informe suas credenciais para acessar o sistema");
            gotoxy(43, 10);
            printf(" -----------------------------------------------------------");
            gotoxy(43, 13);
            printf(" Usuario: ");
            gotoxy(43, 15);
            printf(" Senha: ");

            gotoxy(53, 13); // aponta para campo usuario
            fflush(stdin);
            scanf("%s",&usuario);
            gotoxy(53, 15); //aponta para campo senha
           fflush(stdin);
////////////////////OCULTA SENHA DIGITADA
            pegaSenha(senha);


            while(fread(&func, sizeof(FUNCIONARIO),1,arquivo)==1)
            {
                if(strcmp(usuario, func.login) ==0)
                    if (strcmp(senha, func.senha)==0)
                    {
                        strcpy(usuarioLogado,func.login); //coloca o nome de usuario na variavel usuarioLogado
                        admin = func.admin;               //ADMIN (1) ou Não (0)
                        fclose(arquivo); // feche o arquivo
                        menuPrincipal();
                    }
            }
            rewind(arquivo);//aponta cursor para o inicio do arquivo para a proxima tentativa


        }
        while( strcmp(usuarioLogado,"")==0);
        fclose(arquivo); // feche o arquivo
}


#endif // TELALOGIN_H_INCLUDED
