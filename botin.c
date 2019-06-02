#include<stdio.h>
#include<string.h>
#define BITS 5     // numero de bits

int a[BITS] = {};
int q0=0;
int print_bin(int x[]);
int soma_bin(int x[],int y[]);
int arth_shift(int x[],int y[]);
int compm[BITS],m[BITS],q[BITS];
int cvtbin(int x, int *bin);
int cvtneg(int *x);
int somaum(int *x);
int conv_dec(int *x);


int main(){
	int bin1[BITS] = {}, bin2[BITS] = {}, res[2*BITS] = {}; 
	int multiplicando = 0;
	int multiplicador = 0;
	int i, v;

	printf("Insira o multiplicador (Decimal): ");
	scanf("%d", &multiplicador);
	cvtbin(multiplicador, bin1);

	printf("Insira o multiplicando (Decimal): ");
	scanf("%d", &multiplicando);
	cvtbin(multiplicando, bin2);
	soma_bin(bin1,bin2);
	print_bin(a);
	v = conv_dec(a);
	printf("%d", v);

//		printf("\n");
//	for(int i=0; i<BITS;i++){
//		printf("%d", bin2[i]);
//	}
//		printf("\n");

//	for(i=0;i<BITS;i++){
//		if(q[BITS-1]==0 && q0==1){
//			soma_bin(a,compm);
//			arth_shift(a,q);
//		}
//		else if(q[BITS-1]==1 && q0==0){
//			soma_bin(a,m);
//			arth_shift(a,q);
//		}
//		else{
//			arth_shift(a,q);
//		}
//	printf("Round %d \n",i);
//	printf("A------>");
//	print_bin(a);
//	printf("Q------>");
//	print_bin(q);

}

int cvtbin(int x, int *bin){
    int neg=0;
    int resto;
    int i;
    int aux = x;

    if(x<0){
	aux = x*-1;
	neg = 1;
   }
   for(int i = BITS-1; i>0; i--){
	if (x==0){
		bin[1] == 0;
		i = 0;
	}else{
		resto = aux % 2;
        	aux /=  2;
        	bin[i] = resto;
	}
    }
	if(neg == 1){
		cvtneg(bin);
	}
}

int cvtneg(int *x){
	int i;
	for(i = BITS-1; i>=0; i--){
		if(x[i] == 1){
			x[i] = 0;
		}else{
			x[i] = 1;
		}
	}

	int vaium = 1;

	for(i = BITS-1;i>0;i--){
		if(x[i]==0 && vaium==0){
			x[i] = 0;
			vaium = 0;
		}
		else if(x[i]==0 && vaium==1){
                        x[i] = 1;
                        vaium = 0;
                }
		else if(x[i]==1 && vaium==0){
			x[i] = 1;
			vaium = 0;
		}
		else if(x[i]==1 && vaium==1){
                        x[i] = 0;
                        vaium = 1;
                }
	}
}

int soma_bin(int x[],int y[]){
	int i,vaium=0;
	for(i = BITS-1;i>=0;i--){
		if(x[i]==0 && y[i]==0 && vaium==0){
			a[i] = 0;
			vaium = 0;
		}
		else if(x[i]==0 && y[i]==0 && vaium==1){
                        a[i] = 1;
                        vaium = 0;
                }
		else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && vaium==0){
			a[i] = 1;
			vaium = 0;
		}
		else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && vaium==1){
                        a[i] = 0;
                        vaium = 1;
                }
		else if(x[i]==1 && y[i]==1 && vaium==0){
			a[i] = 0;
			vaium = 1;
		}
		else if(x[i]==1 && y[i]==1 && vaium==1){
                        a[i] = 1;
                        vaium = 1;
                }
	}
	
}

int conv_dec(int *x){
	int aux = 0;
	for(int i = 0; i<10;i++){
		aux = aux + x[i]*(2^i);
	}
	return aux;
}

int print_bin(int x[]){
	int i;
	printf("[");
	for(i=0;i<BITS;i++){
		printf("%d",x[i]);
	}
	printf("]");
	printf("\n");

}

int arth_shift(int x[],int y[]){
	int i,lastOfy;
	lastOfy = y[BITS-1];
	q0 = x[BITS-1];
     	for(i=3;i>=1;i--){
        	x[i] = x[i-1];
    	}
	for(i=3;i>=1;i--){
        	y[i] = y[i-1];
    	}
	y[0] = q0;
	q0 = lastOfy;
}
