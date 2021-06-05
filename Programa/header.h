/* ============================ */
/* header - arquivo header.h */
/* ============================ */

#define TAM 49

/* Struct principal */
	typedef struct _pib{
		int ano;
		float indice;
}Pib;

/* declaracoes das funcoes utilizando com o tipo de dado Pib: */
void inicializaVetor(Pib *ponteiro); //Inicializa o vetor de struct e recebe os valores do txt
void imprime(Pib *ponteiro); //imprime o vetor de struct
void ordena(Pib *ponteiro, int esq, int dir); //ordena o vetor de struct

