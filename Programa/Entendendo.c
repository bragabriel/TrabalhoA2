#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "operacoes.c"


#define TAM 50
/* ************* */
/* ** header - arquivo header.h  ** */
/* ************* */

/* Struct principal */
	typedef struct _pib{
		int ano;
		float indice;
}Pib;

/* declaracoes das funcoes utilizando com o tipo de dado Pib: */
void inicializaVetor(Pib *ponteiro); //Inicializa o vetor de struct e recebe os valores do txt
void imprime(Pib *ponteiro); //imprime o vetor de struct
void ordena(Pib *ponteiro, int esq, int dir); //ordena o vetor de struct


/* ************** */
/* ** operações - arquivo operacoes.c  ** */
/* ************** */
//#include <stdio.h>
//#include <stdlib.h>
//#include "header.h"
//#define TAM 23

/* /--------------------------------------------------------------------------------------/*/
//								funcao que inicializa o Vetor 							
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
		
		//Calculando meu indice
	//	p[i].indice = p[i].taxa20 + p[i].taxa21 + p[i].taxa22; 
		
	}//fim for
} 
 						//	fim da funcao inicializaVetor								 
/*/--------------------------------------------------------------------------------------/*/


/* /--------------------------------------------------------------------------------------/*/
//						funcao que imprime o vetor de struct 							
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
		//				fim da funcao que imprime o vetor de struct 					
/*/--------------------------------------------------------------------------------------/*/


/*/--------------------------------------------------------------------------------------/*/
 		//				funcao que ordena usando o metodo QuickSort 					

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
		//			fim da funcao que ordena usando o metodo QuickSort					
/* /--------------------------------------------------------------------------------------/ */


/* ****************** */
/* ** main - arquivo de utilização do usuario  ** */
/* ****************** */

//#include <stdio.h>
//#include "operacoes.c"

int main () {

	Pib dadosPib[TAM]; //dadosPib é um vetor do tipo Pib

    inicializaVetor(&dadosPib[TAM]); //inicializando o vetor de Struct, e recebendo os valores do txt
    
    imprime(&dadosPib[TAM]); //imprimindo o vetor de Struct
    
    printf("---------------------------------------------------------------------\n");
	  printf("\t\t Dados ordenados utilizando QuickSort:\n");
    ordena(&dadosPib[TAM], 0, TAM-1);//ordenando usando o QuickSort, de acordo com o indice

	imprime(&dadosPib[TAM]); //imprimindo o vetor de Struct após a ordenação
    
    return 0;

} /* fim da funcao main */