#include<stdio.h>
#include<conio2.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<math.h>
#include "TADpilhaM.h"

#define P_COLUNA 15
#define QTDE_T 3
#define DELAY 30
#define tmp -100

/* Integrantes:
	Flavio Roso Gonçalves
	Paulo Henrique Vieira Barreto
*/

struct TpTorre
{
	int origem,aux,destino,qtde;
};
void musica()
{
	Beep(493,500+tmp);
	Beep(369,250+tmp);
	Beep(391,250+tmp);
	Beep(440,500+tmp) ;
	Beep(391,250+tmp);
	Beep(369,250+tmp);
	Beep(329,550+tmp) ;
	Beep(329,250+tmp) ;
	Beep(391,250+tmp);
	Beep(493,550+tmp);
	Beep(440,250+tmp);
	Beep(391,250+tmp);
	Beep(369,550+tmp);
	Beep(369,250+tmp);
	Beep(391,250+tmp);
	Beep(440,500+tmp);
	Beep(493,500+tmp);
	Beep(391,500+tmp);
	Beep(329,700+tmp);
	Beep(440,500+tmp) ;
	Beep(440,300+tmp) ;
	Beep(523,250+tmp);
	Beep(659,500+tmp);
	Beep(587,250+tmp);
	Beep(523,250+tmp);
	Beep(493,500+tmp);
	Beep(493,250+tmp);
	Beep(391,250+tmp);
	Beep(493,500+tmp);
	Beep(440,300+tmp);
	Beep(391,250+tmp);
	Beep(369,500+tmp);
	Beep(369,250+tmp);
	Beep(391,250+tmp);
	Beep(440,500+tmp);
	Beep(493,500+tmp);
	Beep(391,500+tmp);
	Beep(329,600+tmp);

}
int getTorre(TpTorre &t)
{
	int linha=0;
	char origem,destino;
	println("Quantidade de discos(MAX:10): ",linha);
	scanf("%d",&t.qtde);
	fflush(stdin);
	println("Pilha de inicio: ",linha);
	scanf("%c",&origem);
	fflush(stdin);
	println("Pilha de destino: ",linha);
	scanf("%c",&destino);
	
	t.origem = toupper(origem) - 65;
	t.destino = toupper(destino) - 65;
	if(t.origem>=0 && t.origem<=2 && t.destino>=0 && t.destino<=2)
		if(t.origem != t.destino && t.qtde>=3 && t.qtde<=10)
		{
			t.aux = 0;
			while(t.aux == t.origem || t.aux == t.destino)
				t.aux++;
			return 1;
		}
		return 0;
}
int rotacionaTorre(TpTorre &t,int orienta)
{
	int aux;

	aux = t.origem;
	t.origem = t.destino;
	t.destino = t.aux;
	t.aux = aux;

}

void criaBase(TpPilhaM pm,int vet[])
{
	TpPilhaM aux;
	int c=15,l=20;
	inicializa(aux,3);
	for(int i =0;i<QTDE_T;i++)
		while(!pmvazia(pm,i))
		{
			insere(aux,retira(pm,i),i);
			vet[i]++;
		}
	limpatela2();
	montaast();
	
	exibe(c,l,aux,0);
	
	c+=24;	
	exibe(c,l,aux,1);
	
	c+=24;
	exibe(c,l,aux,2);
}

void criaBase(TpPilhaM pm)
{
	TpPilhaM aux;
	int c=15,l=20;
	inicializa(aux,3);
	for(int i =0;i<QTDE_T;i++)
		while(!pmvazia(pm,i))
		{
			insere(aux,retira(pm,i),i);
		}
	limpatela2();
	montaast();
	
	exibe(c,l,aux,0);
	
	c+=24;	
	exibe(c,l,aux,1);
	
	c+=24;
	exibe(c,l,aux,2);
}
void sobe(int c,int l,int pos,int topo)
{
	int inicio = l-pos;
	
	for(int i=inicio;i>5;i--)
	{
		grafic(c,i,topo);
		_sleep(DELAY);
		textcolor(0);
		limpalinha(c-11,i+1,c+11);
		textcolor(WHITE);
		gotoxy(c+1,i+1);
		printf("%c",186);
		
	}
	gotoxy(c+1,7);
	printf(" ");
}

void desce(int c,int l,int pos,int topo)
{

	int inicio = l-pos;
	
	for(int i=7;i<inicio+1;i++)
	{
		
		_sleep(DELAY);
		textcolor(0);
		limpalinha(c-11,i-1,c+11);
		textcolor(WHITE);
		gotoxy(c+1,i-1);
		if(i>8)
			printf("%c",186);
		grafic(c,i,topo);
		
	}
	gotoxy(c+1,7);
	printf(" ");
}

void anda(int origem,int destino,int topo)
{
	int c = P_COLUNA,posOrigem,posDestino;
	posOrigem = c+24*origem+1;
	posDestino = c+24*destino+1;
	if(origem<destino)
	{
		for(int i=posOrigem;i<posDestino;i++)
		{
			limpalinha(3,6,65);
			grafic(i,6,topo);
			_sleep(DELAY-10);
		}
	}
	else
	{
		for(int i=posOrigem-1;i>posDestino-2;i--)
		{
			grafic(i,6,topo);
			_sleep(DELAY-10);
			limpalinha(3,6,70);
			
		}
		
	}
		
	
}
void exibeTroca(TpPilhaM pm,int origem,int destino)//grafico
{
	TpPilhaM aux;
	int c=P_COLUNA,l=20,vet[3] = {0,0,0},i=0,posOrigem,posDestino;
	inicializa(aux,QTDE_T);
	posOrigem = c+24*origem;
	posDestino = c+24*destino;
	criaBase(pm,vet);

	sobe(posOrigem,l,vet[origem],elemtopo(pm,origem));
	anda(origem,destino,elemtopo(pm,origem));
	desce(posDestino,l,vet[destino],elemtopo(pm,origem));
	
}
void exibeTrocaInvalida(TpPilhaM pm,int origem,int destino)//grafico
{
	TpPilhaM aux;
	int c=P_COLUNA,l=20,vet[3] = {0,0,0},i=0,posOrigem,posDestino;
	inicializa(aux,QTDE_T);
	posOrigem = c+24*origem;
	posDestino = c+24*destino;
	criaBase(pm,vet);

	sobe(posOrigem,l,vet[origem],elemtopo(pm,origem));
	anda(origem,destino,elemtopo(pm,origem));
	textcolor(RED);
	gotoxy(posDestino+2,5);printf("X");
	Beep(400,1000);
	limpalinha(3,5,70);
	anda(destino,origem,elemtopo(pm,origem));
	desce(posOrigem,l,vet[origem]-1,elemtopo(pm,origem));
	
}
void trocaTorre(TpPilhaM &pm,int origem,int destino)
{
	exibeTroca(pm,origem,destino);
	insere(pm,retira(pm,origem),destino);
	criaBase(pm);
	
}
void automatico()
{
	int i,tam,orienta,contMovimentos=0,linha=0;
	TpPilhaM pm;
	inicializa(pm,QTDE_T);
	TpTorre t;
	Layout("Modo Automatico");
	if(!getTorre(t))
	{
		limpatela();
		println("Erro: quantidade nao aceita ou inicio/destino iguais!",linha);
		getch();
	}
	else
	{
		system("cls");
		FormularioMenu();
		tam = pow(2,t.qtde-2);
		orienta = t.qtde%2;
		if(orienta)
		{
			t.aux = t.aux + t.destino;
			t.destino = t.aux - t.destino;
			t.aux = t.aux - t.destino;
		}
		for(i=t.qtde;i>0;i--)
			insere(pm,i,t.origem);
		criaBase(pm);
		for(i=0;i<tam;i++)
		{

			trocaTorre(pm,t.origem,t.aux);
			trocaTorre(pm,t.origem,t.destino);
			trocaTorre(pm,t.aux,t.destino);

			if(!pmvazia(pm,t.origem))
			{
				if(!pmvazia(pm,t.aux))
				{
					if(elemtopo(pm,t.aux)<elemtopo(pm,t.origem))
					{
						trocaTorre(pm,t.aux,t.origem);
					}
						
					else
					{
						trocaTorre(pm,t.origem,t.aux);
					}
						
				}
				else
				{
					trocaTorre(pm,t.origem,t.aux);
				}
			}
			else
			{
				if(!pmvazia(pm,t.aux))
				{
					
					trocaTorre(pm,t.aux,t.origem);

				}
					
			}
			
			rotacionaTorre(t,orienta);
			contMovimentos +=4;
		}
		gotoxy(3,23);
		textcolor(WHITE);
		printf("Movimentos: %d",contMovimentos-1);
		getch();
	}
}
void manual()
{
	TpPilhaM pm;
	int linha=0;
	int origem,destino,movimento=0;
	TpTorre t;
	inicializa(pm,QTDE_T);
	Layout("Modo Manual");
	if(!getTorre(t))
	{
		limpatela();
		println("Erro: quantidade nao aceita ou inicio/destino iguais!",linha);
		getch();
	}
	else
	{

		for(int i=t.qtde;i>0;i--)
			insere(pm,i,t.origem);
		
		system("cls");
		FormularioMenu();
		criaBase(pm);
		while(!pmvazia(pm,t.origem) || !pmvazia(pm,t.aux))
		{
			gotoxy(3,3);
			textcolor(WHITE);
			printf("Objetivo empilhar na torre: %c",t.destino+65);
			gotoxy(4,24);
			textcolor(WHITE);
			printf("Digite o caminho(EX: a %c b):     ",175);
			printf("\b\b\b\b\b");
			origem = getche();
			printf(" %c ",175);
			destino = getche();
			origem = toupper(origem) - 65;
			destino = toupper(destino) - 65;
			if(origem>=0 && origem<=2 && destino>=0 && destino<=2)
			{
				
			
				if(!pmvazia(pm,origem))
				{
					if(!pmvazia(pm,destino))
					{
						if(elemtopo(pm,origem)<elemtopo(pm,destino))
						{
							trocaTorre(pm,origem,destino);
							movimento++;
						}
						else
						{
							exibeTrocaInvalida(pm,origem,destino);
						}
							
					}
					else
					{
						movimento++;
						trocaTorre(pm,origem,destino);
					}
						
				}
				else
				{
					textcolor(RED);
					gotoxy(3,23);printf("Movimento invalido, a pilha nao contem discos!");
					Sleep(3000);
					gotoxy(3,23);printf("                                               ");
				}
				
				
			}
			
		}
		int qntd=pow(2,t.qtde)-1;
		Layout("Modo Manual");
		println("YOU WIN!!",linha);
		println("Numero de movimentos realizados: ",linha);
		printf("%d",movimento);
		println("Numero minimo de movimentos possiveis: ",linha);
		printf("%d",qntd);
		musica();
	}
	getch();
}
int main()
{
	textcolor(15);
	TpMenu m[2];
	int op=0;
	strcpy(m[0].nome,"Modo automatico");
	strcpy(m[1].nome,"Modo Manual");
	while(op!=-1)
	{
		Layout("TORRE DE HANOI");
		op = menu(m,2);
		switch(op)
		{
			case 0: automatico();break;
			case 1: manual();break;
		}
	}
	
}
