/* ============================ */
/* header - arquivo header.h */
/* ============================ */

//Se não foi definido LISTA_H:
#ifndef LISTA_H

#define LISTA_H
/* estrutura do noh da lista */

#define TAM 49

/* Struct principal */
	typedef struct _pib{
		int ano;
		float indice;
		struct _pib *proximo;
}Pib;

/* declaracoes das funcoes utilizando com o tipo de dado Pib: */
void inicializaVetor(Pib *ponteiro); //Inicializa o vetor de struct e recebe os valores do txt
void imprime(Pib *ponteiro); //imprime o vetor de struct
void ordena(Pib *ponteiro, int esq, int dir); //ordena o vetor de struct


/* declaracoes das funcoes de lista */
void inicializaLista(Pib**);
int listaVazia(Pib*);
void imprimeLista(Pib*);
void insereInicio(Pib**, int);

#endif
