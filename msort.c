#include <stdlib.h>
#include <stdio.h>

int lerVetor(int *A, int y);
int recebeVetor(int *A, int valores);
void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);

int main(){
	int valor;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &valor);
	int v[valor];
	recebeVetor(v, valor);
	printf("\nValores Originais:\n");
	lerVetor(v, valor);
	mergesort(v,valor);
	printf("\nValores Ordenados:\n");
	lerVetor(v, valor);
}

void mergesort(int *v, int n){
	int *c = malloc(sizeof(int)*n);
	sort(v, c, 0, n-1);
	free(c);
}

void sort(int *v, int *c, int i, int f){
	if(i>=f){
		 return;
	}

	int m = (i+f)/2;
	
	sort(v,c,i,m);
	sort(v,c,m+1,f);

	if (v[m] <= v[m+1]){
		return;
	}
	
	merge(v,c,i,m,f);
}

void merge(int *v, int *c, int i, int m, int f){
	int z, iv = i, ic = m+1;

	for(z=i; z <= f; z++){
		c[z] = v[z];
	}
	z = i;

	while(iv <=m && ic <= f){
		if(c[iv] < c[ic]){
			v[z++] = c[iv++];
		}else{
			v[z++] = c[ic++];
		}
	}

	while(iv <= m){
		v[z++] = c[iv++];
	}

	while(ic <= f){
		v[z++] = c[ic++];
	}
}

int recebeVetor(int *A, int valores){
	for(int i=0; i<valores; i++){
		scanf("%d", &A[i]);
	}
}

int lerVetor(int *A, int y){
	for(int i=0; i<y; i++){
		printf("[%d] ", A[i]);
	}
	printf("\n");
}
