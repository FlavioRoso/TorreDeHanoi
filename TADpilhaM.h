#define MAXPILHA 30
#include "TADVisual.h"
struct TpPilhaM
{
	int base[MAXPILHA],topo[MAXPILHA],pilha[MAXPILHA];
};
void inicializa(TpPilhaM &pm,int qtde)
{
	int tam = MAXPILHA/qtde,i;
	for(i=0;i<=qtde;i++)
	{
		pm.base[i] = i*tam;
		pm.topo[i] = pm.base[i] - 1;
	}
}
int pmcheia(TpPilhaM &pm,int np)
{
	return pm.topo[np]+1 == pm.topo[np+1];
}
int pmvazia(TpPilhaM &pm,int np)
{
	return  pm.base[np] > pm.topo[np];
}
void insere(TpPilhaM &pm,int elem,int np)
{
	pm.pilha[++pm.topo[np]] = elem;
}
int retira(TpPilhaM &pm,int np)
{
	return pm.pilha[pm.topo[np]--];
}
int elemtopo(TpPilhaM pm,int np)
{
	return pm.pilha[pm.topo[np]];
}
int exibe(int c,int l,TpPilhaM pm,int np)
{
	int aux;
	while(!pmvazia(pm,np))
		{
			aux=retira(pm,np);
			grafic(c,l--,aux);
		}
}
