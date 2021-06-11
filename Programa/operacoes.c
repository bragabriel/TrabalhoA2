/* ============================ */
/* operações - arquivo operacoes.c */
/* ============================ */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"


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
		fscanf(arqEnt,"%d %f", &p[i].ano, &p[i].indice);	//Atribuindo os dados do txt para variaveis aqui no programa
	}//fim for
} 
/*		Fim da Funcao - Inicializa o Vetor 	   */
/*---------------------------------------------*/



/*-------------------------------------------*/
/*		Funcao - imprime o Vetor de Struct 	*/		
void imprime(Pib *p){
	
	int i;

	//Exibindo os dados
	printf("\t\tDados sendo exibidos...\n\n");
	printf("\t\tANO: \t\tINDICE:\n\n");	
	
	for(i=0; i<TAM; i++){
		printf("\t\t%d \t\t%.2f\n\n", p[i].ano, p[i].indice);
	}
}
/*		Fim da Funcao - imprime o Vetor de Struct		 */
/* ------------------------------------------------------*/



/*-------------------------------------------*/
/*		Funcao - imprime Relatorio	*/
void relatorio(Pib *p){
	
	int i;

	//Limpando a tela, evitando assim o acúmulo de informações indesejadas. 
	system("cls");
	
	//Alterando a cor do plano de fundo e letra para:
	//Plano de fundo: 8(Cinza) | Letra: F(branco)
	system("color 8F");
	
	//Exibindo o relatorio
	printf("[----------------------------------------------------------------------]\n");
	printf("\t Relatorio:\n\n");
	printf("\t\t10 MAIORES PIB'S E SEUS ANOS:\n\n");
	printf("\t\t\tINDICE: \t\tANO:\n\n");	
	
	for(i=49; i>=40; i--){
		printf("\t\t\t%.2f \t\t\t %.d\n\n", p[i].indice, p[i].ano);
	}
	
	printf("\n");
	printf("\t\t10 MENORES PIB'S E SEUS ANOS:\n\n");
	printf("\t\t\tINDICE: \t\tANO:\n\n");	
	
	for(i=0; i<=9; i++){
		printf("\t\t\t%.2f \t\t\t %.d\n\n", p[i].indice, p[i].ano);
	}
	
	printf("[----------------------------------------------------------------------]\n\n");
}
/*		Fim da Funcao - imprime Relatorio		 */
/* ------------------------------------------------------*/



/*-----------------------------------------*/
/*		Funcao - Ordena ANO com ShellSort	   */				
void ordenaAno(Pib *vetor, int N){ 

 int k, i, j;
 Pib aux;
 
 for(k=0; k<N; k++){
 	
 	for(i=k; i<N; i++){
 		
 		aux = vetor[i];
 		
 		for(j=i-k; j>=0 && vetor[j].ano > aux.ano; j-=k){
 			
 			vetor[j+k] = vetor[j];
		 }
		 
	vetor[j+k] = aux;
	}
 }
}
/*		Fim da Funcao - Ordena ANO com ShellSort		 */
/*---------------------------------------------------*/



/*-----------------------------------------*/
/*		Funcao - Ordena PIB com ShellSort	   */				
void ordenaPib(Pib *vetor, int N){ 

 int k, i, j;
 Pib aux;
 
 for(k=0; k<N; k++){
 	
 	for(i=k; i<N; i++){
 		
 		aux = vetor[i];
 		
 		for(j=i-k; j>=0 && vetor[j].indice > aux.indice; j-=k){
 			
 			vetor[j+k] = vetor[j];
		 }
		 
	vetor[j+k] = aux;
	}
 }
}
/*		Fim da Funcao - Ordena PIB com ShellSort		 */
/*---------------------------------------------------*/



/*-----------------------------------------*/
/*			Funcao - Busca Binaria	      */	
int buscaBinaria(Pib *dadosPib, int inicio, int fim, int busca) {
  
	int i, meio;
	
	meio = (int) (inicio+fim)/2;
	
	if(dadosPib[meio].ano == busca)
	return meio;
	
	if(inicio >= fim)
	return -1; //representa que não encontrou o ANO buscado na estrutura
	
	if(busca < dadosPib[meio].ano){	
		buscaBinaria(dadosPib, inicio, meio-1, busca);
	}
	else{
		buscaBinaria(dadosPib, meio+1, fim, busca);
	}
}
/*	    	Fim da Funcao - Busca Binaria  		 */
/*-----------------------------------------------*/



/*--------------------------------------*/
/*		Funcao - inicializa a LISTA 	*/	
void inicializaLista (Pib **lista) {

    *lista = NULL;

}
/*		Fim da Funcao - inicializa a LISTA		 */
/*-----------------------------------------------*/



/*---------------------------------------------------*/
/*		Funcao - verifica se a LISTA esta vazia 	*/	
int listaVazia (Pib *lista) {

    if (lista == NULL)
        return 1;

    return 0;

}
/*		Fim da Funcao - verifica se a LISTA esta vazia		 */
/*-----------------------------------------------------------*/



/*------------------------------------------------------*/
/*		Funcao - insere elemento no inicio da LISTA 	*/	
void insereInicio (Pib **lista, int ano) {
    
    Pib *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (Pib*) malloc (sizeof(Pib));
    novo->ano = ano;

    /* se a lista estiver vazia, novo noh aponta para NULL */
    if (listaVazia(*lista))
        novo->proximo = NULL;

    /* caso contrario, novo noh aponta para o inicio da lista */
    else
        novo->proximo = *lista;

    /* novo noh passa a ser o inicio da lista */
    *lista = novo;

}
/*		Fim da Funcao - insere elemento no inicio da LISTA		 */
/*---------------------------------------------------------------*/



/*----------------------------------*/
/*		Funcao - imprime a LISTA 	*/	
void imprimeLista(Pib *lista){  //*lista = inicio
	
	Pib *atual = lista; //ponteiro auxiliar para andar na lista
	
	if(listaVazia(lista)){ 
		printf("A lista esta vazia!\n");
		return;
	}
	
	printf("[------------------------------------------------------------]\n\n");
	printf("\t\tLISTA sendo exibida...\n");
	printf("Lista: [ ");
	while(atual != NULL){
		printf("%d ", atual->ano);
		atual = atual->proximo;
	}	
	printf("]\n\n");
	printf("[------------------------------------------------------------]\n\n\n");
}
/*		Fim da Funcao - imprime a LISTA		 */
/*-------------------------------------------*/
