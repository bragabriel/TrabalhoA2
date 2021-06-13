/* ================================== */
/* 		main 		 */
/* ================================== */

#include <stdio.h>
#include "operacoes.c"

int main (){

  	int anoPesq, anoPesquisado, i, op;
  
    Pib *inicio, *aux;

    inicializaLista(&inicio); //inicializando a LISTA
    
    Pib dadosPib[TAM]; //dadosPib é um vetor do tipo Pib

    inicializaVetor(dadosPib); //inicializando o VETOR de Struct, e recebendo os valores do txt
    
	for(i=0; i<TAM; i++){
   	 	insereInicio(&inicio, dadosPib[i].ano); //Inserindo os dados na LISTA (passando do vetor para a lista)
	}
	
	imprimeLista(inicio);
    
    printf("[------------------------------------------------------------]\n");
	printf("\t Dados ordenados por: 'ANO'\n");
	printf("\t utilizando o metodo: 'ShellSort'\n\n");
    ordenaAno(dadosPib, TAM);//ordenando usando o ShellSort, de acordo com o ANO

	imprime(dadosPib); //imprimindo o vetor de Struct após a ordenação

	printf("[------------------------------------------------------------]\n\n");
	
	do{
		//Alterando a cor do plano de fundo e letra para:
		//Plano de fundo: 3(verde-agua) | Letra: F(branco)
		system("color 3F");
		
		printf("\n");
		printf("\tInforme o ano para pesquisar o PIB: ");
		scanf("%d", &anoPesq); //Ano que será pesquisado na Busca Binária

		anoPesquisado = buscaBinaria(dadosPib, 0, TAM-1, anoPesq); //Realizando a Busca Binária

		//Limpando a tela, evitando assim o acúmulo de informações indesejadas. 
		system("cls"); 

		if(anoPesquisado == -1){
			printf("\n\t -> Nao possuimos o dado desse ano. <- \n");		
		}
		else{
			printf("\n\t -> Em %d, o PIB brasileiro foi de: %.2f <-\n", dadosPib[anoPesquisado].ano, dadosPib[anoPesquisado].indice);
		}
		
		printf("\n\n");
		printf("\tVoce deseja pesquisar o dado de outro ano?\n");
		printf("\t\tSe SIM, digite: 1\n");
		printf("\t\tSe NAO, digite: 9\n");
		printf("\tResposta: ");
		scanf("%d", &op);
		
	} while (op == 1); //Fim 'do_while'
	
	relatorioTXTpt1(dadosPib);
	
	ordenaPib(dadosPib, TAM);
	relatorio(dadosPib);
	
	relatorioTXTpt2(dadosPib);
	
    
    return 0;
}
/*	    	Fim da Funcao - Main  		 */
/*---------------------------------------*/
