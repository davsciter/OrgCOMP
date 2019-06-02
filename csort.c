#include <stdio.h>
#include <stdlib.h>

void csort(int *vetor, int x, int y);
void recebevetor(int *v, int x);
int lerVetor(int *A, int y);

int main(){
	int tam;
	printf("Digite o tamanho do vetor:");
	scanf("%d", &tam);
	int v[tam];
	recebevetor(v, tam);
	lerVetor(v, tam);
	csort(v, tam, tam);
	lerVetor(v, tam);
}

int lerVetor(int *A, int y){
	for(int i=0; i<y; i++){
		printf("[%d] ", A[i]);
	}
	printf("\n");
}

void recebevetor(int *v, int x){
	for(int i=0; i<x; i++){
		scanf("%d", &v[i]);
		printf("\n");
	}	
} 

void csort(int *vetor, int x, int y){
	int i;
	int *Aux, *C;
	
	C = calloc(x+1, sizeof(int));
	Aux = calloc(y, sizeof(int));

	for(i=0; i<y; i++){
		C[vetor[i]]++;
	}
	for(i=1; i<=x; i++){
		C[i] += C[i-1];
	}
	for(i=y-1; i>=0; i--){
		Aux[C[vetor[i]]-1] = vetor[i];
		C[vetor[i]]--;
	}
	for(i=0; i<y; i++){
		vetor[i] = Aux[i];
	}
}
	
