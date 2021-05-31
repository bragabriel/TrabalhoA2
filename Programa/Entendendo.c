#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "operacoes.c"


#define TAM 49
/* ***** */
/* header - arquivo header.h */
/* ***** */

/* Struct principal */
	typedef struct _pib{
		int ano;
		float indice;
}Pib;

/* declaracoes das funcoes utilizando com o tipo de dado Pib: */
void inicializaVetor(Pib *ponteiro); //Inicializa o vetor de struct e recebe os valores do txt
void imprime(Pib *ponteiro); //imprime o vetor de struct
void ordena(Pib *ponteiro, int esq, int dir); //ordena o vetor de struct



/* ****** */
/* operações - arquivo operacoes.c */
/* ****** */
//#include <stdio.h>
//#include <stdlib.h>
//#include "header.h"
//#define TAM 23


/*------------------------------------------------*/
/*			Funcao - Inicializa o Vetor 		  */
					
void inicializaVetor(Pib *p){
			// *p = ponteiro para dadosPib
    
    int i;
			
	//Abrindo arquivo txt para a leitura dos dados
	FILE *arqEnt;
	arqEnt = fopen("economia.txt", "r");
	
	//Nao existe o arquivo economia.txt, ou nao foi encontrado:
	if(arqEnt == NULL){
		printf("Nao foi possivel abrir o arquivo economia.txt \n");
		getchar();
		exit(0);
	}
			
	for(i=0; i<TAM; i++){
		
		//Lendo arquivos do txt
		fscanf(arqEnt, "%d %f", &p[i].ano, &p[i].indice); //Atribuindo os dados do txt para variaveis aqui no programa
				
	}//fim for
} 
/*		Fim da Funcao - Inicializa o Vetor 	   */
/*---------------------------------------------*/



/*-------------------------------------------*/
/*		Funcao - imprime o Vetor de Struct 	*/		
void imprime(Pib *p){
	
	int i;

	//Exibindo os dados
	printf("---------------------------------------------------------------------\n");
	printf("\t\t Dados sendo exibidos...\n");
	printf("---------------------------------------------------------------------\n\n");
	printf("ANO:\t INDICE:\n\n");	
	
	for(i=0; i<TAM; i++){
		printf(" %d \t %.1f\n\n\n", p[i].ano, p[i].indice);
	}
}
/*		Fim da Funcao - imprime o Vetor de Struct		 */
/* ------------------------------------------------------*/



/*-----------------------------------------*/
/*		Funcao - Ordena com QuickSort	   */				

void ordena(Pib *vetor, int esquerda, int direita){
	
	int i, j;
	int pivo;
	Pib aux;
	
	i = esquerda;
	j = direita;
	
	//Se os dados já estão um pouco ordenados:
	//Eh melhor começar do meio.
	pivo = (esquerda + direita) / 2 ; //usando indice do meio como pivo
	

	while(i <= j){
		while(vetor[i].indice < vetor[pivo].indice && i < direita){
			i++;
		}
		
		while(vetor[j].indice > vetor[pivo].indice && j > esquerda){
			j--;
		}
		
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;	
			i++;
			j--;
		}
	}
	
	if (j > esquerda){
		ordena(vetor, esquerda, j);
	}
	
	if(i < direita){
		ordena(vetor, i, direita);
	}
}
/*		Fim da Funcao - Ordena com QuickSort		 */
/*---------------------------------------------------*/



/*-----------------------------------------*/
/*			Funcao - Busca Binaria	      */	

int buscaBinaria(Pib *dadosPib, int inicio, int fim, int busca) {
  
	int i, meio;
	
	meio = (int)(inicio+fim)/2;
	
	if(dadosPib[meio].ano == busca)
		return meio;
	
	if (inicio >= fim) 
		return -1;
	
	if(busca < dadosPib[meio].ano)
		buscaBinaria(dadosPib, inicio, meio-1, busca);
	
	if (busca > dadosPib[meio].ano)
		buscaBinaria(dadosPib, meio+1, fim, busca);
}
/*	    	Fim da Funcao - Busca Binaria  		 */
/*-----------------------------------------------*/



/*-----------------------------------------------*/
/* * main - arquivo de utilização do usuario  * */

//#include <stdio.h>
//#include "operacoes.c"

int main (){

  int anoPesq, anoPesquisado;
	
	Pib dadosPib[TAM]; //dadosPib é um vetor do tipo Pib

    inicializaVetor(dadosPib); //inicializando o vetor de Struct, e recebendo os valores do txt
    
    imprime(dadosPib); //imprimindo o vetor de Struct
    
    printf("---------------------------------------------------------------------\n");
	printf("\t\t Dados ordenados utilizando QuickSort:\n");
    ordena(dadosPib, 0, TAM-1);//ordenando usando o QuickSort, de acordo com o indice

	imprime(dadosPib); //imprimindo o vetor de Struct após a ordenação

	printf("Informe o ano para pesquisar o PIB: ");
	scanf("%d", &anoPesq);

	anoPesquisado = buscaBinaria(dadosPib, 0, TAM-1, anoPesq);

	if(anoPesquisado == -1)
		printf("Nao possuimos o dado desse ano.");
	else
		printf("Em %d, o PIB brasileiro foi no valor de: %d\n", dadosPib[anoPesquisado].ano, dadosPib[anoPesquisado].indice);
    
    return 0;
}
/*	    	Fim da Funcao - Main  		 */
/*---------------------------------------*/
