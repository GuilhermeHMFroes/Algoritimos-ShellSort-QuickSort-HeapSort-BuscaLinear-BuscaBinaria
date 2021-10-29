#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//================================	FUNCAO Shell Sort	==================================

void shellsort(int tam){
	
	//Complexidade: Melhor Caso{ f(n) = O(n log n) }, Pior Caso{ f(n) = O(n^2) }
	
	printf("> Shell Sort");
	
	//==================================================================
	//							CRIAÇÃO VETOR
	
	int a;
	
	int vet[tam];
	
	int cont = 0;
	do{
		a = rand() % (tam * 10);
		
		if(a > 0){
			vet[cont] = a;
			cont++;
			
			}
		
		}while(cont < tam);
	
	printf("\n\t.Vetor Desordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	//==================================================================
	//							Ordenação
	
	int h, i, j;
	int troca;
	
	for(h = 1; h < tam; h = h * 3 + 1);
	
	while(h > 0){
		h = (h - 1) / 3;
		
		//printf("\n%d", h);
		
		for(i = h; i < tam; i++){
			troca = vet[i];
			j = i;
			
			while(vet[j - h] > troca){
				vet[j] = vet[j - h];
				j -= h;
				
				if(j < h)
					break;
				
				}
				
				vet[j] = troca;
			
			}
		
		}
	
	printf("\t.Vetor Ordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n\n");
	
	}

//================================	FUNCAO Quick Sort	==================================

int qparticao(int vet[], int esq, int dir){
	int meio = (esq + dir) / 2;
	int pivot = vet[meio];
	int i = esq - 1;
	int j = dir + 1;
	
	do{
		do{
			i++;
			
			}while(vet[i] < pivot);
		
		do{
			j--;
			
			}while(vet[j] > pivot);
		
		if(i >= j){
			return j;
			
			}
		
		int aux = vet[i];
		vet[i] = vet[j];
		vet[j] = aux;
		
	}while(1);
	
}

void qesqdir(int vet[], int esq, int dir){
	
	if(esq < dir){
		int p = qparticao(vet, esq, dir);
		qesqdir(vet, esq, p);
		qesqdir(vet, p + 1, dir);
		
		}
	
	}

void quicksort(int tam){
	
	//Complexidade: Melhor Caso{ f(n) = O(n log n) }, Pior Caso{ f(n) = O(n^2) }
	
	printf("> Quick Sort");
	
	//==================================================================
	//							CRIAÇÃO VETOR
	
	int a;
	
	int vet[tam];
	
	int cont = 0;
	do{
		a = rand() % (tam * 10);
		
		if(a > 0){
			vet[cont] = a;
			cont++;
			
			}
		
		}while(cont < tam);
	
	printf("\n\t.Vetor Desordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	//==================================================================
	//							Ordenação
	
	qesqdir(vet, 0, tam - 1);
	
	printf("\t.Vetor Ordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n\n");
	
	}

//================================	FUNCAO Heap Sort	==================================

void aplicarHeap(int vet[], int tam, int i){
	int raiz = i;
	int esq = 2 * i + 1;
	int dir = 2 * i + 2;
	
	if(esq < tam && vet[esq] > vet[raiz]){
		raiz = esq;
		
		}
	
	if(dir < tam && vet[dir] > vet[raiz]){
		raiz = dir;
		
		}
	
	if(raiz != i){
		int aux = vet[i];
		
		vet[i] = vet[raiz];
		vet[raiz] = aux;
		
		aplicarHeap(vet, tam, raiz);
		
		}
	
	}

void heapsort(int tam){
	
	//Complexidade: f(n) = O(n log n)
	
	printf("> Heap Sort");
	
	//==================================================================
	//							CRIAÇÃO VETOR
	
	int a;
	
	int vet[tam];
	
	int cont = 0;
	do{
		a = rand() % (tam * 10);
		
		if(a > 0){
			vet[cont] = a;
			cont++;
			
			}
		
		}while(cont < tam);
	
	printf("\n\t.Vetor Desordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	//==================================================================
	//							Ordenação
	
	for(int i = tam / 2 - 1; i >= 0; i--){
		aplicarHeap(vet, tam, i);
		
		}
	
	for(int i = tam - 1; i > 0; i--){
		int aux = vet[0];
		
		vet[0] = vet[i];
		vet[i] = aux;
		
		aplicarHeap(vet, i, 0);
		
		}
	
	printf("\t.Vetor Ordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n\n");
	
	
	}

//================================	  Busca Linear	    ==================================

void buscalinear(int tam){
	
	//Complexidade: f(x) = O(n)
	
	printf("> Busca Linear");
	
	//==================================================================
	//							CRIAÇÃO VETOR
	
	int a;
	
	int vet[tam];
	
	int cont = 0;
	do{
		a = rand() % (tam * 10);
		
		if(a > 0){
			vet[cont] = a;
			cont++;
			
			}
		
		}while(cont < tam);
	
	printf("\n\t.Vetor Desordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	//==================================================================
	//							Busca
	
	printf("\t. Qual número você busca: ");
	int buscado;
	scanf("%d", &buscado);
	
	int verifica = 0;
	for(int i = 0; i <= tam - 1; i++){
		if(vet[i] == buscado){
			verifica = 1;
			break;
			
			}
		
		}
	
	if(verifica == 1){
		printf("\t\tNúmero encontrado");
		
		}else{
			printf("\t\tNúmero não encontrado\n\n");
			
			}
	
	}

//================================	  Busca Binária	    ==================================

void buscabinaria(int tam){
	
	// Necessário Ordenação prévia do vetor
	
	//Complexidade: f(n) = O(log n)
	
	printf("\n\n> Busca Binária");
	
	//==================================================================
	//							CRIAÇÃO VETOR
	
	int vet[tam];
	
	for(int i = 0; i < tam; i++){
		vet[i] = i * 2;
		
		}
	
	printf("\n\t.Vetor Desordenado: [ ");
	for(int i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("]\n");
	
	//==================================================================
	//							Busca
	
	printf("\t. Qual número você busca: ");
	int buscado;
	scanf("%d", &buscado);
	
	
	int achou = 0;
	int inicio = 0, fim = tam - 1, meio;
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		
		if(vet[meio] == buscado){
			achou = 1;
			break;
			
			}
		
		if(vet[meio] < buscado)
			inicio = meio + 1;
			
		if(vet[meio] > buscado)
			fim = meio - 1;
		
		//printf("\n%d", meio);
		
		
		}
	
	if(achou == 1){
		printf("\t\tNúmero encontrado");
		
		}else{
			printf("\t\tNúmero não encontrado\n\n");
			
			}
	
	}

//================================	FUNCAO PRINCIPAL	==================================

int main(){

	int tam;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	printf("\n");
	
	shellsort(tam);
	quicksort(tam);
	heapsort(tam);
	buscalinear(tam);
	buscabinaria(tam);
	
	}
