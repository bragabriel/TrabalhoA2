/* ============================ */
/* header - arquivo header.h */
/* ============================ */

//Se não foi definido LISTA_H:
#ifndef LISTA_H

#define LISTA_H
/* estrutura do noh da lista */

#define TAM 50

/* Struct principal */
	typedef struct _pib{
		int ano;
		float indice;
		struct _pib *proximo;
}Pib;

/* Declaração das funções: */
void inicializaVetor(Pib *ponteiro); // Inicializa o vetor de struct e recebe os valores do txt
void imprime(Pib *ponteiro); // Imprime o vetor de struct

void ordenaAno(Pib *ponteiro, int tam); // Ordena de acordo com os 'anos'; utilizando o metodo ShellSort
void ordenaPib(Pib *ponteiro, int tam); // Ordena de acordo com os 'pibs'; utilizando o metodo ShellSort

int buscaBinaria(Pib *ponteiro, int start, int end, int search); // Realiza a Busca Binária

void relatorio(Pib *ponteiro); // Imprime o relatório
void relatorioTXTpt1(Pib *ponteiro); // Cria um "Relatorio.txt" com os dados dos 50 anos ordenados
void relatorioTXTpt2(Pib *ponteiro); // Adiciona no "Relatorio.txt" os dados dos 10 maiores e menores PIB's e seus respectivos anos.


/* Declaração das funções para a utilização da 'LISTA' */
void inicializaLista(Pib**);
int listaVazia(Pib*);
void imprimeLista(Pib*);
void insereInicio(Pib**, int);

#endif
