#include<stdio.h>
#define BITS 8     // numero de bits
int q0=0;
int a[BITS] = {};
int take_bin(int x[]);
int print_bin(int x[]);
int add_bin(int x[],int y[]);
int arth_shift(int x[],int y[]);
int compm[BITS],m[BITS],q[BITS];
int cvtbin(int x);

int main(){
	int i;
	printf("Insira o multiplicando (coloque espaços entre cada bit): ");
	take_bin(m);
	printf("Enter -M (space between each bit): ");
	take_bin(compm);
	printf("Insira o ): ");
	take_bin(q);
	for(i=0;i<BITS;i++){
		if(q[BITS-1]==0 && q0==1){
			add_bin(a,compm);
			arth_shift(a,q);
		}
		else if(q[BITS-1]==1 && q0==0){
			add_bin(a,m);
			arth_shift(a,q);
		}
		else{
			arth_shift(a,q);
		}
	printf("Round %d \n",i);
	printf("A------>");
	print_bin(a);
	printf("Q------>");
	print_bin(q);
	}
	return 0;
}
int take_bin(int x[]){
	int i;
	for(i=0;i<BITS;i++){
		scanf("%d",&x[i]);
	}

}
int print_bin(int x[]){
	int i;
	for(i=0;i<BITS;i++){
		printf("%d",x[i]);
	}
	printf("\n");

}
int add_bin(int x[],int y[]){
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

int cvtbin(int x){
	    int resto;
    long bin = 0;
    int i = 1;

    while( dec != 0 )
    {
        resto = dec % 2;
        dec /=  2;
        bin += resto * i;
        i *= 10;
    }

    return bin;	
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
