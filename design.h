#ifndef DESIGN_H_INCLUDED
#define DESIGN_H_INCLUDED
#include <windows.h> necessário para COORD e STD_OUTPUT_HANDLE






COORD coord={0,0}; // Variavel global, X(Esquerda) e Y(TOPO)


//POSICIONA O CURSOR NAS COORDENADAS X,Y DA TELA
void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void ajustaJanela()
{

// maximiza
    ShowWindow( GetConsoleWindow(), SW_MAXIMIZE);

//Não permite redimensionar
    SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

}



//RESPONSÁVEL POR DESENHAR CONTORNOS DA TELA SIMULANDO JANELA
void desenha(int x, int y, int largura, int altura)
{

//LINHAS HORIZONTAIS
    int i;
    for(i=x+1; i<largura; i++)
    {
        gotoxy(i,y);
        printf("%c",205); // 205 é o caractere correspondente a linhas  horizontais na tabela ASCII
       // if(altura !=0){
        // gotoxy(i,altura);
        //  printf("%c",205);
        //}
    }
    //LINHAS VERTICAIS
    for(i=y+1; i<altura; i++)
    {
        gotoxy(x,i);
        printf("%c",186);  //186 é o caractere correspondente a linhas verticais na tabela ASCII
        gotoxy(largura,i);
        printf("%c",186);
    }

    /*cantos*/
   gotoxy(largura,y);
   printf("%c",187);
   // gotoxy(x,altura);
   // printf("%c",200);
   //  gotoxy(largura,altura);
   //  printf("%c",188);
   gotoxy(x,y);
   printf("%c",201);

}




void desenhaJanela(char titulo[])
{
system("cls");
desenha(10,0,150,40); //Container
/*BARRA DE TITULO */
desenha(10,0,150,2);

gotoxy(10,3);
printf("%c",186);
//gotoxy(150,2);
//printf("%c",186);
gotoxy((150/2)-(strlen(titulo)/2),1);
printf("%s",titulo);


}

void dicaDeTela(char dica[], int posY)
{
desenha(10,35,150,35);
gotoxy(12,35);
printf(" AJUDA ");
 gotoxy(11, posY);

printf(" %s",dica);
}

#endif // DESIGN_H_INCLUDED
