#include <stdlib.h>
#include <stdio.h>

int lerVetor(int *A, int y){
	for(int i=0; i<y; i++){
		printf("[%d] ", A[i]);
	}
	printf("\n");
}

int recebeVetor(int *A, int valores){
	for(int i=0; i<valores; i++){
		scanf("%d", &A[i]);
	}
}

void selsort(int *A, int tam){
	int i, j, temp;
	for(i = 0; i<tam; i++){
		for(j = 0; j<tam; j++){
			if(A[i]<=A[j]){
				temp = A[i];
				A[i] = A[j];
				A[j]=temp;
			}
		}
	}
}
	

int main(){
	int tam;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	int A[tam];
	recebeVetor(A, tam);
	lerVetor(A, tam);
	selsort(A, tam);
	lerVetor(A, tam);
}
