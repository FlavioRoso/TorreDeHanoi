#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

struct TpMenu
{
	char nome[25];
};
void Construtor(int CI,int LI,int CF,int LF)
{
	textcolor(15);
	int i;
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);

		printf("%c",186);
	}
}
void linhaHorizontal(int linha ,int CI,int CF)
{
	textcolor(15);
	int i;
	for(i=CI;i<CF;i++)
	{
		gotoxy(i,linha);
		printf("%c",196);
	}
}
void linhaVertical(int coluna,int LI, int LF)
{
	textcolor(15);
	int i;
	for(i=LI;i<LF;i++)
	{
		gotoxy(coluna,i);
		printf("%c",179);
	}
}
void limpatela()
{
	int CI =3, LI = 7, CF = 56, LF = 25;
	
	
	for(int i=LI;i<LF;i++)
	{
		for(int j=CI;j<CF;j++)
		{
			gotoxy(j,i);printf(" ");
		}
	} 
}
void limpalinha(int CI,int LI,int CF)
{
	gotoxy(CI,LI);
	for(int i=CI;i<CF;i++)
	{
		printf(" ");
	} 
}
void Quadro (int CI , int LI ,int CF, int LF, int cortexto , int corfundo)
{
	int i;
	textcolor(cortexto);textbackground(corfundo);
	
	gotoxy(CI,LI);printf ("%c",201);
	gotoxy(CF,LI);printf ("%c",187);
	gotoxy(CI,LF);printf ("%c",200);
	gotoxy(CF,LF);printf ("%c",188);
	
	for (i=CI+1;i<CF;i++)
	{
		gotoxy (i,LI);printf("%c",205);
		gotoxy (i,LF);printf("%c",205);
	}
	
	for (i=LI+1;i<LF;i++)
	{
		gotoxy (CI,i);printf("%c",186);
		gotoxy (CF,i);printf("%c",186);
	}
	textcolor(11);textbackground(0);
	
}
void grafic(int c, int l, int aux)
{
	textcolor(aux);
	if(aux >1)
		aux = aux*2-1 ;
	c = c-(aux-1)/2+1;
	gotoxy(c,l);
	for(int i=0;i<aux;i++)
	{
		printf("%c",219);
	}
}
void montaast()
{
	textcolor(15);
	int l=21,c1=10,c2=33,c3=57;
	for(int k=0;k<14;k++)
	{
		gotoxy(c1,l);printf("%c",220);
		gotoxy(c2,l);printf("%c",220);
		gotoxy(c3,l);printf("%c",220);
		
		c1++;c2++;c3++;
	}
	l=20,c1=16,c2=40,c3=64;
	for(int m=0;m<13;m++)
	{
		gotoxy(c1,l);printf("%c",186);
		gotoxy(c2,l);printf("%c",186);
		gotoxy(c3,l);printf("%c",186);
		
		l--;
	}
	textcolor(15);
}
void FormularioMenu (void)
{
	gotoxy(16,22);printf("A");
	gotoxy(40,22);printf("B");
	gotoxy(64,22);printf("C");
	Quadro(1,1,80,25,7,7);
}
void limpatela2()
{
	int CI =2, LI = 2, CF = 79, LF = 24;
	for(int i=LI;i<LF-2;i++)
	{
		gotoxy(CI,i);printf("                                                                         ");
	} 
}
void Box_Titulo(char msg[50])
{
	int CI = 1, LI = 1, CF = 79, LF = 5;
	Construtor(CI,LI,CF,LF);
	gotoxy((CI+CF)/2 - strlen(msg)/2,(LI+LF)/2);
	printf("%s",msg);
}
void Box_Nav(void)
{
	char msg0[50]="** Como usar **",
		 msg1[50]="Navegacao",
	     msg2[50]="[ENTER] Selecionar",
	     msg3[50]="[ESC] Sair",
	     linha[21] ="--------------------";
	     			 
	int CI =58, LI = 6, CF = 79, LF = 25;
	Construtor(CI,LI,CF,LF);
	gotoxy((CI+CF)/2 - strlen(msg0)/2,LI+2);
	printf("%s",msg0);
	gotoxy(CI+1,LI+4);
	printf("%s",linha);
	gotoxy(CI+2,LI+6);
	printf("%c%c %s",24,25,msg1);
	gotoxy(CI+2,LI+10);
	printf("%s",msg2);
	gotoxy(CI+2,LI+14);
	printf("%s",msg3);
}
void Box_Main(void)
{
	int CI =1, LI = 6, CF = 56, LF = 25;
	Construtor(CI,LI,CF,LF);
}
void Layout(char titulo[100])
{
	textbackground(0);
	system("cls");
	Box_Titulo(titulo);
	Box_Main();
	Box_Nav();
}
void println(char str[256],int &cont)
{
	gotoxy(3,8+cont++);
	printf("%s",str);
}
void ExibeMenu(char msg[100],int cor,int x,int y)
{
	textbackground(cor);
	gotoxy(x,y);
	puts(msg);
}
 int menu(TpMenu menu[10],int tl)
 {
 	int tecla,i,j,pos=0;
 	do
 	{
 		textcolor(15);
 		
 		j=0;
 		for(i=0;i<tl;i++)
 		{
 			ExibeMenu(menu[i].nome,0,5,9+j);
 			j+=2;
 		}
 		
 		ExibeMenu(menu[pos].nome,1,5,9+pos*2);
 		gotoxy(3,9+pos*2);
 		fflush(stdin);
 		tecla = getch();
		if(tecla == -58 || tecla == -32 || tecla == 256 || tecla == 224 )
		{
			tecla = getch();
			if(tecla==KEY_DOWN)
			{
				if(pos<tl-1)
					pos++;
				else
					pos=0;	
			}
			if(tecla== KEY_UP)
			{
				if(pos>0)
					pos--;
				else
					pos=tl-1;	
			}
		}
	}while(tecla!=KEY_ESC && tecla!=KEY_ENTER);
	if(tecla==13)
	{
		return pos;
	}
	return -1;
 }
