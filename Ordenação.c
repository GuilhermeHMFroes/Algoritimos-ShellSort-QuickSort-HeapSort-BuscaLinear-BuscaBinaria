#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//================================	FUNCAO Shell Sort	==================================

void shellsort(int tam){
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

//================================	FUNCAO PRINCIPAL	==================================

int main(){

	int tam;
	printf("Digite o Tamanho do Vetor: ");
	scanf("%d", &tam);
	printf("\n");
	
	shellsort(tam);
	quicksort(tam);
	heapsort(tam);
	
	}
