#ifndef MENUPACIENTES_H_INCLUDED
#define MENUPACIENTES_H_INCLUDED




void cadastraPaciente()
{
    PACIENTE pacie;
    int opcao;
    FILE* arquivo;


    arquivo = fopen("pacientes.bin","ab");  // escrita e binário
    if(arquivo == NULL)
    {
        printf("Problema ao tentar abrir o arquivo. \n");

    }
    else
        do
        {
            system("CLS");
            desenhaJanela(APP_NAME);
            dicaDeTela("<ENTER> = Proximo campo  - Para desistir, tecle <ENTER> sem preencher o campo atual ",37);


            fflush(stdin);

            desenha(20,9,135,0);
            gotoxy(20,8);
            printf(" CADASTRAR PACIENTE ");
            gotoxy(25,12);
            printf("Nome completo: ");
            gotoxy(25,13);
            printf("CPF: ");
            gotoxy(25,14);
            printf("Telefone: ");
            gotoxy(25,15);
            printf("Rua: ");
            gotoxy(25,16);
            printf("Numero: ");
            gotoxy(25,17);
            printf("Bairro: ");
            gotoxy(25,18);
            printf("Cidade: ");
            gotoxy(25,19);
            printf("Estado (UF): ");
            gotoxy(25,20);
            printf("CEP: ");
            gotoxy(25,21);
            printf("NASC. (dd/mm/aaaa): ");
            gotoxy(25,22);
            printf("Email: ");
            gotoxy(25,23);
            printf("Data do Diagnostico: ");
            gotoxy(25,24);
            printf("Comorbidade <ENTER> para nenhuma: ");
            gotoxy(70,12);

            fflush(stdin);
            pegaLetras(pacie.nome);
            if (strcmp(pacie.nome,"")==0) break; // se não digitar nada então saia
            gotoxy(70,13);

            fflush(stdin);
            pegaDigito(pacie.cpf);
            if (strcmp(pacie.cpf,"")==0) break; // se não digitar nada então saia
            gotoxy(70,14);

            fflush(stdin);
            pegaDigito(pacie.telefone);
            if (strcmp(pacie.telefone,"")==0) break; // se não digitar nada então saia
            gotoxy(70,15);

            fflush(stdin);
            pegaLetraseDigitos(pacie.rua);
            if (strcmp(pacie.rua,"")==0) break; // se não digitar nada então saia
            gotoxy(70,16);

            fflush(stdin);
            pegaDigito(pacie.numero);
            if (strcmp(pacie.numero,"")==0) break; // se não digitar nada então saia
            gotoxy(70,17);

            fflush(stdin);
            pegaLetraseDigitos(pacie.bairro);
            if (strcmp(pacie.bairro,"")==0) break; // se não digitar nada então saia
            gotoxy(70,18);

            fflush(stdin);
            pegaLetraseDigitos(pacie.cidade);
            if (strcmp(pacie.cidade,"")==0) break; // se não digitar nada então saia
            gotoxy(70,19);

            fflush(stdin);
            pegaLetraseDigitos(pacie.estado);
            if (strcmp(pacie.estado,"")==0) break; // se não digitar nada então saia
            gotoxy(70,20);

            fflush(stdin);
            pegaDigito(pacie.cep);
            if (strcmp(pacie.cep,"")==0) break; // se não digitar nada então saia
            gotoxy(70,21);

            fflush(stdin);
            scanf("%d/%d/%d",&pacie.nascimento.dia,&pacie.nascimento.mes,&pacie.nascimento.ano);

            gotoxy(70,22);

            fflush(stdin);
            pegaEmail(pacie.email);
            if (strcmp(pacie.email,"")==0) break; // se não digitar nada então saia
            gotoxy(70,23);

            fflush(stdin);
            pegaData(pacie.dataDiagnostico);
            if (strcmp(pacie.dataDiagnostico,"")==0) break; // se não digitar nada então saia
            gotoxy(70,24);

            fflush(stdin);
            gets(pacie.comorbidades);  //Pode deixar em branco caso não possua comorbidade

            {

                //TUDO OK ESCREVE NO ARQUIVO
                fwrite(&pacie, sizeof(PACIENTE),1,arquivo);
                gotoxy(70,30);
                printf(" ---- CADASTRADO COM SUCESSO! DESEJA CONTINUAR CADASTRANDO ? ----- ");
                gotoxy(70,31);
                printf("      0 = NAO      ");
                gotoxy(70,32);
                printf("      1 = SIM      ");
                gotoxy(70,33);
            }

            fflush(stdin);
            scanf("%d",&opcao);

        }
        while(opcao != 0);
    fclose(arquivo); //Cadastro concluído, feche o arquivo



}


void grupoDeRisco()
{
    PACIENTE pacie;
    int opcao,x;
    FILE* arquivo;
    FILE *fp; //Para grupo de risco
    char nomeArquivo[25] = "GrupoDeRisco.txt";

    system("cls");
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);

    int anoAtual = str_t.wYear;

    arquivo = fopen("pacientes.bin","rb");  // leitura e binário
    if(arquivo == NULL)
    {
        printf("Problema ao tentar abrir o arquivo. \n");

    }
    else
    {
        desenhaJanela(APP_NAME);
        gotoxy(20,5);
        printf(" GRUPO DE RISCO ");
        gotoxy(20,6);
        printf(" (Pressione qualquer tecla para VOLTAR) ");
        x=12; //LINHA DA TELA ONDE SERA IMPRESSO CADA PACIENTE
        gotoxy(20,x);

        int indice =0;
        if (fp = fopen(nomeArquivo, "w") != NULL)
        {
            fp = fopen(nomeArquivo, "w");




            while(fread(&pacie, sizeof(PACIENTE),1,arquivo)==1)
            {
                if (anoAtual - pacie.nascimento.ano > 65 || strcmp(pacie.comorbidades,"")!=0)
                {
                    gotoxy(20,x++);
                    printf("-----------------SALVANDO EM ARQUIVO (GrupoDeRisco.txt)-----------------------------");
                    gotoxy(20,x++);
                    printf("#:                  %d",indice);
                    gotoxy(20,x++);
                    printf("IDADE:              %d", anoAtual - pacie.nascimento.ano);
                    gotoxy(20,x++);
                    printf("CEP:                %s",pacie.cep);
                    fprintf(fp,"Idade: %d \n",anoAtual - pacie.nascimento.ano);
                    fprintf(fp,"CEP: %s \n",pacie.cep);
                }

                indice++;
            }
            gotoxy(20,x++);
            printf("----------------- Processo finalizado arquivo salvo em GrupoDeRisco.txt -----------------------------");
        }
        else
        {
            system("CLS");
            printf("Nao foi possivel salvar o arquivo GrupoDeRisco.txt \n Verifique se ele esta em uso por outro programa");
            //Não conseguiu criar o arquivo


        }
        system("pause > null");
        fclose(arquivo);
        fclose(fp);
        system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO

    }
}


void listaPacientes()
{
    PACIENTE pacie;
    int opcao,x;
    FILE* arquivo;


    system("cls");
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);

    int anoAtual = str_t.wYear;

    arquivo = fopen("pacientes.bin","rb");  // leitura e binário
    if(arquivo == NULL)
    {
        printf("Problema ao tentar abrir o arquivo. \n");

    }
    else
    {
        desenhaJanela(APP_NAME);
        gotoxy(20,5);
        printf(" LISTA DE PACIENTES ");
        gotoxy(20,6);
        printf(" (Pressione qualquer tecla para VOLTAR) ");
        x=12; //LINHA DA TELA ONDE SERA IMPRESSO CADA PACIENTE
        gotoxy(20,x);

        int indice =0;
        while(fread(&pacie, sizeof(PACIENTE),1,arquivo)==1)
        {
            gotoxy(20,x++);
            printf("----------------------------------------------");
            gotoxy(20,x++);
            printf("#:                  %d",indice);
            gotoxy(20,x++);
            printf("DIAGNOSTICADO EM:   %s", pacie.dataDiagnostico);
            gotoxy(20,x++);
            printf("Comorbidades:       %s", pacie.comorbidades);
            gotoxy(20,x++);
            printf("Nome:               %s", pacie.nome);
            gotoxy(20,x++);
            printf("IDADE:              %d", anoAtual - pacie.nascimento.ano);

            gotoxy(20,x++);
            printf("CPF:                %s", pacie.cpf);
            gotoxy(20,x++);
            printf("NASC:               %d/%d/%d", pacie.nascimento.dia, pacie.nascimento.mes,  pacie.nascimento.ano);
            gotoxy(20,x++);
            printf("TELEFONE:           %s", pacie.telefone);
            gotoxy(20,x++);
            printf("EMAIL:              %s", pacie.email);
            gotoxy(20,x++);
            printf("ENDERECO:           %s, %s, %s, %s - %s - CEP:%s", pacie.rua, pacie.numero, pacie.bairro, pacie.cidade, pacie.estado, pacie.cep);
            indice++;
        }
        fclose(arquivo);
        system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO

    }
}



void removePaciente()
{
    FILE* arq;
    FILE* temp;
    PACIENTE pacie;
    char cpf[30];
    arq = fopen("pacientes.bin","rb");//abrir em modo rb leitura binaria
    temp = fopen("tmp_pct.bin","wb");//abrir em modo wb ele limpa e grava binario

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
        printf("Digite o CPF do paciente a deletar: ");
        gets(cpf);
        while(fread(&pacie,sizeof(PACIENTE),1,arq)==1)
        {
            if(strcmp(cpf,pacie.cpf)==0)
            {
                gotoxy(20,8);
                printf("Nome: %s\n",pacie.nome);
                gotoxy(20,9);
                printf("CPF: %s\n",pacie.cpf);
                gotoxy(20,10);
                printf("-------------------------------------------------\n");
            }
            else
            {
                fwrite(&pacie,sizeof(PACIENTE),1,temp);//gravando os dados no arquivo temp
            }
        }
        fclose(arq);//fechar o arq
        fclose(temp);//fechar o temp
        fflush(stdin);
        gotoxy(20,20);
        printf("Deseja deletar (s/n)? ");
        if(getche()=='s')
        {

            if(remove("pacientes.bin")==0&&rename("tmp_pct.bin","pacientes.bin")==0) //verifica se as operacoes foram realizadas com sucesso!
            {
                gotoxy(20,22);
                printf("\nOperacao realizada com sucesso!");
                system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO
            }
            else
            {
                remove("tmp_pct.bin");//remover o arquivo tmp se acondicao foi "n" na hora de deletar
                printf("\nPaciente nao foi removido!");
                system("pause > null");  //PAUSA O PROGRAMA PARA EVITAR QUE SEJA FINALIZADO
            }
        }
        fclose(temp);
        fclose(arq);
        getch();
    }
}




void menuPacientes()
{
    int opcao;
    do
    {
        system("COLOR 0E");
        desenhaJanela(APP_NAME);
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR",37);

        desenha(50,8,100,20);
        gotoxy(53,8);
        printf(" MENU PACIENTES ");
        gotoxy(53,10);
        printf(" 1 - Cadastrar Paciente");
        gotoxy(53,11);
        printf(" 2 - Listar Pacientes");
        gotoxy(53,12);
        printf(" 3 - Remover Paciente");
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
            cadastraPaciente();

            break;

        case 2:
            listaPacientes();
            break;

        case 3:
            removePaciente();
            break;
        }



    }
    while (opcao !=0);
}

#endif // MENUPACIENTES_H_INCLUDED
