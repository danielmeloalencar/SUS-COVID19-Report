#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED

#include "menu_funcionarios.h";

void menuPrincipal()
{

    int opcao;
    do
    {
        system("COLOR 0B");
        desenhaJanela(APP_NAME);
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR",37);

        desenha(50,8,100,20);
        gotoxy(53,8);
        printf(" MENU PRINCIPAL");
        gotoxy(53,10);
        printf(" 1 - Pacientes");
        gotoxy(53,11);
        printf(" 2 - Salvar Grupo de Risco");
      if (admin=='1'){
        gotoxy(53,12);
        printf(" 3 - Funcionarios");
      }
        gotoxy(53,13);
        printf(" 0 - Sair");

        //desenha(50,22,100,8);
        gotoxy(50,21);
        printf(" Digite uma opcao: ");

        scanf("%d",&opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 0:
            system("cls");
            gotoxy(53,21);
            system("COLOR 3F");
            printf("ENCERRADO!");
            system("pause > NULL");
            break;

        case 1:
            menuPacientes();
            break;

        case 2:
            grupoDeRisco();
            break;


        case 3:
             if (admin=='1'){
            menuFuncionarios();
             }
            break;
        }

    }
    while (opcao !=0);
}

#endif // MENU_PRINCIPAL_H_INCLUDED
