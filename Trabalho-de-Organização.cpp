#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define Vazio 0

/* ////////////////////////////////////////////////////////////////////////////////////////////////

Alunos: Adilson
	Davi Daniel Lourenço Sena 118314
	Prícilla Karen Suzano 116505	
							
//////////////////////////////////////////////////////////////////////////////////////////////// */
    
/* TC = Tamanho da Cache; TA = Tamanho da entrada de Acessos; SA = Sequencia de Acessos		*/

/* FIFO (First-In-First-Out): FIFO se resume a uma fila qualquer. A linha que a mais tempo esta 
armazenada na cache será substituída, independentemente se a CPU estiver usando ou não. 	*/
												
void FIFO(int TC, int TA, int SA[]){
	int HIT=0, MISS=0, Cont=0, ContFIFO=0;
	int Cache[TC]; // Vetor usado como cache
	
	for(int i = 0; i < TC; i++){
		Cache[i] = Vazio;
	}
	
	while(Cont < TA){ // Varia de acordo com o tamanho da sequencia de acessos
		for(int i = 0; i < TC; i++){ // Varia de acordo com o tamanho da cache
			
			if(Cache[i] == SA[Cont]){ // Valor já está na cache
				HIT++;
				i = TC;
			}
			
			else if(Cache[i] == Vazio){ // Se tiver espaço vazio no vetor e não achou o valor
				Cache[i] = SA[Cont];
				MISS++;
				i = TC;
			}
			
			else if(i == (TC-1)){ // Chegou no final da cache e não encontrou o valor
				MISS++;
				Cache[ContFIFO] = SA[Cont];
				if(ContFIFO < (TC-1)){
					ContFIFO++;
				}
				else{
					ContFIFO = 0;
				}
			}
		}
		Cont++;
	}
	cout << "HIT: " << HIT << endl;
	cout << "MISS: " << MISS << endl;
	cout << "Cache: " << endl;
	for(int i = 0; i < TC; i++){
		cout << "      Linha[" << i << "]: " << Cache[i] << endl;
	}
	cout << endl;
}

/* LRU (Least Recently Used): Este algoritmo escolhe a linha que está a mais tempo
 sem uso pela CPU e substitui pela nova linha. 							*/

void LRU(int TC, int TA, int SA[]){
	int HIT=0, MISS=0, Cont=0, Pos=0;
	int Cache[TC][2]; // Matriz usada como cache e para armazenar os contadores de cada linha
	int MaiorCont=0; // Valor do maior contador das linha da cache
	int Poslinha=0; // Posicao da linha que esta a mais tempo sem ser acessada

	for(int i = 0; i < TC; i++){
		Cache[i][1] = Vazio;
		Cache[i][2] = Vazio;
	}
	
	while(Cont < TA){ // Varia de acordo com o tamanho da sequencia de acessos
		for(int i = 0; i < TC; i++){ // Varia de acordo com o tamanho da cache

			if(Cache[i][2] > MaiorCont){ // Encontra o maior valor do contador
				MaiorCont = Cache[i][2];
				Poslinha = i;
			}
			
			if(Cache[i][1] == SA[Cont]){ // Valor já está na cache
				HIT++;
				Pos = i;
				i = TC;
			}
		
			else if(Cache[i][1] == Vazio){ // Se tiver espaço vazio no vetor e não achou o valor
				Cache[i][1] = SA[Cont];
				MISS++;
				Pos = i;
				i = TC;
			}
			
			else if(i == (TC-1)){ // Chegou no final e não tem o valor
				MISS++;
				Cache[Poslinha][1] = SA[Cont];
				Pos = Poslinha;
			}
		}
		for(int j = 0; j < TC; j++){
				if(Cache[j][1] == Vazio){
					Cache[j][2] = 0;
				}
				else if(j == Pos){
					Cache[j][2] = 0;
				}
				else{
					Cache[j][2] = Cache[j][2] + 1;
				}
		}
		MaiorCont =  0;
		Cont++;
	}
	cout << "HIT: " << HIT << endl;
	cout << "MISS: " << MISS << endl << endl;
	cout << "Cache: " << endl;
	for(int i = 0; i < TC; i++){
		cout << "      Linha[" << i << "]: " << Cache[i][1] << endl;
	}
	cout << endl;
}

/* LFU (Least Frequently Used ): O algoritmo escolhe a linha de acordo com a sua referência,
ou seja, a linha que tiver menos acessos por parte da CPU vai ser a escolhida para substituição. */

void LFU(int TC, int TA, int SA[]){
	int HIT=0, MISS=0, Cont=0, Pos=0;
	int Cache[TC][2]; // Matriz usada como cache e para armazenar os contadores de cada linha
	int MenorCont=500; // Valor do menor contador das linha da cache
	int Poslinha=0; // Posicao da linha que esta a mais tempo sem ser acessada

	for(int i = 0; i < TC; i++){
		Cache[i][1] = Vazio;
		Cache[i][2] = Vazio;
	}
	
	while(Cont < TA){ // Varia de acordo com o tamanho da sequencia de acessos
		for(int i = 0; i < TC; i++){ // Varia de acordo com o tamanho da cache

			for(int k = 0; k < TC; k++){
				if(Cache[i][2] < MenorCont){ // Encontra o menor valor do contador
					MenorCont = Cache[i][2];
					Poslinha = i;
				}
			}		

			if(Cache[i][1] == SA[Cont]){ // Valor já está na CACHE
				HIT++;
				Pos = i;
				Cache[i][2] = Cache[i][2] + 1;
				i = TC;
			}
		
			else if(Cache[i][1] == Vazio){ // Se tiver espaço vazio no vetor e não achou o valor
				Cache[i][1] = SA[Cont];
				MISS++;
				Pos = i;
				Cache[i][2] = Cache[i][2] + 1;	
				i = TC;			
			}
			
			else if(i == (TC-1)){ // Chegou no final e não tem o valor
				MISS++;
				Cache[Poslinha][1] = SA[Cont];
				Pos = Poslinha;
				Cache[Poslinha][2]==1;
				
			}
		}
		MenorCont =  500;
		Cont++;
	}
	cout << "HIT: " << HIT << endl;
	cout << "MISS: " << MISS << endl << endl;
	cout << "Cache: " << endl;
	for(int i = 0; i < TC; i++){
		cout << "      Linha[" << i << "]: " << Cache[i][1] << endl;
	}
	cout << endl;
}
/* Escolha Aleatória: O sistema de controle da memória Cache escolhe aleatoriamente 
o bloco que será removido.									 */

void Aleatorio(int TC, int TA, int SA[]){
	int HIT=0, MISS=0, Cont=0;

	int Cache[TC]; // Vetor usado como cache
	
	for(int i = 0; i < TC; i++){
		Cache[i] = Vazio;
	}
	srand(time(NULL));
	while(Cont < TA){ // Varia de acordo com o tamanho da sequencia de acessos
		for(int i = 0; i < TC; i++){ // Varia de acordo com o tamanho da cache
			int aleatorio = rand() % (TC);
			if(Cache[i] == SA[Cont]){ // Valor já está na cache
				HIT++;
				i = TC;
			}
			
			else if(Cache[i] == Vazio){ // Se tiver espaço vazio no vetor e não achou o valor
				Cache[i] = SA[Cont];
				MISS++;
				i = TC;
			}
			
			else if(i == (TC-1)){ // Chegou no final da cache e não encontrou o valor
				MISS++;
				Cache[aleatorio] = SA[Cont];	
			}
		}
		Cont++;
	}
	cout << "HIT: " << HIT << endl;
	cout << "MISS: " << MISS << endl;
	cout << "Cache: " << endl;
	for(int i = 0; i < TC; i++){
		cout << "      Linha[" << i << "]: " << Cache[i] << endl;
	}
	cout << endl;
}
int main(){
	int TA; // Quantidade de acessos aos blocos
	int TC; // Tamanho de linhas da cache 

	cout << "Informe quantos acessos aos blocos serão realizados: ";
	cin >> TA;
	cout << endl;
	cout << "Informe o tamanho de linhas da cache: ";
	cin >> TC;
	cout << endl;
	
	int SA[TA]; // Vetor usado para armazenar a sequencia de acessos aos blocos
	
	cout << "Digite as sequencias de acessos a blocos: ";
	for(int i = 0; i < TA; i++){
		cin >> SA[i];
	}	
	cout << endl;

	cout << "-------------------------------------" << endl;
	cout << "FIFO: " << endl;
	FIFO(TC, TA, SA);
	cout << "-------------------------------------" << endl;
	cout << "LRU: " << endl;
	LRU(TC, TA, SA);
	cout << "-------------------------------------" << endl;
	cout << "LFU: " << endl;
	LFU(TC, TA, SA);
	cout << "-------------------------------------" << endl;
	cout << "Aleatorio: " << endl;
	Aleatorio(TC, TA, SA);
	cout << "-------------------------------------" << endl;
}
