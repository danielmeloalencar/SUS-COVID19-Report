#ifndef JANELA_H_INCLUDED
#define JANELA_H_INCLUDED

#include <windows.h> necessário para COORD e STD_OUTPUT_HANDLE

COORD coord={0,0}; // Variavel global, topo esquerda


void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int desenha_janela(char titulo[],char subtitulo[],int posX, int largura_janela, int altura_janela)

{

//intializations

// maximiza
ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);


//Não permite redimensionar
SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

system("cls");
 system("COLOR 0B");

int i;

//exceptions

if(strlen(titulo) > 75) return 1;

//corners

gotoxy(posX, 1);printf("%c", 201);  //╔

gotoxy(largura_janela, 1);printf("%c", 187); //╗

gotoxy(posX, altura_janela);printf("%c", 200); //╚

gotoxy(largura_janela,altura_janela);printf("%c", 188); //╝

//Linhas horizontais

for (i = posX + 1; i < largura_janela; i++)

{

gotoxy(i, 1);printf("%c", 205);

gotoxy(i, altura_janela);printf("%c", 205);

}




//Linha verticais

for (i = 1 + 1; i < altura_janela; i++)

{

gotoxy(posX, i);printf("%c", 186);

gotoxy(largura_janela, i);printf("%c", 186);

}

//Imprime o título

gotoxy((largura_janela/2)-(strlen(titulo)/2),2);

printf("%s",titulo);


//Imprime o subttítulo

gotoxy((largura_janela/2)-(strlen(subtitulo)/2),3);

printf("%s",subtitulo);

//making divider

gotoxy(posX,4);

printf("%c",204); //╠

for(i = posX+1 ; i < largura_janela ; i++)
printf("%c",205);//═

printf("%c",185);  //╣

return 0;

}


#endif // JANELA_H_INCLUDED
