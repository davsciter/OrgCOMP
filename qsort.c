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

int partition (int *A, int p, int r){
	int pivot = A[r];
	int i = (p-1), temp;
	
	for(int j = p; j <= r-1; j++){
		if(A[j] <= pivot){
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	return(i+1);
}

void quicksort(int *A, int p, int r){
	if(p<r){
		int q;
	
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1,r);
	}
}

int main(){
	int valores;
	scanf("%d", &valores);
	int A[valores];
	recebeVetor(A, valores);
	lerVetor(A, valores);
	quicksort(A, 0, valores);
	lerVetor(A, valores);
}
