/* ================================== */
/* main - arquivo de utilização do usuario */
/* ================================== */

#include <stdio.h>
#include "operacoes.c"

int main (){

  int anoPesq, anoPesquisado;
	
	Pib dadosPib[TAM]; //dadosPib é um vetor do tipo Pib

    inicializaVetor(dadosPib); //inicializando o vetor de Struct, e recebendo os valores do txt
    
    imprime(dadosPib); //imprimindo o vetor de Struct
    
    printf("------------------------------------------------------\n");
	printf("\t Dados ordenados utilizando QuickSort:\n");
    ordena(dadosPib, 0, TAM-1);//ordenando usando o QuickSort, de acordo com o indice

	imprime(dadosPib); //imprimindo o vetor de Struct após a ordenação

	printf("Informe o ano para pesquisar o PIB: ");
	scanf("%d", &anoPesq);

	anoPesquisado = buscaBinaria(dadosPib, 0, TAM-1, anoPesq);

	if(anoPesquisado == -1){
		printf("\nNao possuimos o dado desse ano.");
	}
	else{
		printf("\nEm %d, o PIB brasileiro foi no valor de: %.2f\n", dadosPib[anoPesquisado].ano, dadosPib[anoPesquisado].indice);
	}
    
    return 0;
}
/*	    	Fim da Funcao - Main  		 */
/*---------------------------------------*/
