#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int *vet, int n) {
	int i,j,info;
	int x = 1;

	while (x < n) {
		x = 3*x + 1;
	}
	while (x > 1) {
		x /= 3;
		for (i = x; i < n; i++) {
			info = vet[i];
			j = i - x;
			while (j >= 0 && info < vet[j]) {
				vet[j+x] = vet[j];
				j -= x;
			}
			vet[j+x] = info;
		}
	}
}

int main() {
	int i,j = 0,escolha,k = 0,n = 1000,l = 0;
	float inicio,tempoGasto = 0,tempoTotal = 0,tm[6];
	FILE *fp;
	int *vet;
	printf("0 - Crescente\n1 - Decrescente\n2 - Aleatório\n");
	scanf("%d",&escolha);
	//vet = (int*)malloc(n*sizeof(int));
	fp = fopen("shellsort.txt","w");
	while (k < 6) {
		printf("n = %d\n",n);
		vet = (int*)malloc(n*sizeof(int));
		tempoTotal = 0;
		while (j < 10) {
			if (escolha == 0) {
				for (i = 0; i < n; i++) {
					vet[i] = i;
				}
				inicio = clock();
				shellSort(vet,n);
				//tempoGasto = ((float)clock() - inicio)/CLOCKS_PER_SEC; //EM SEGUNDOS
				tempoGasto = ((float)clock() - inicio)/(CLOCKS_PER_SEC/1000); // EM MILISEGUNDOS
				printf("Tempo gasto: %f\n",tempoGasto);
				/*for (i = 0; i < n; i++) {
					printf("%d\n",vet[i]);
				}*/
			}
			if (escolha == 1) {
				for (i = 0; i < n; i++) {
					vet[i] = n + 100 - i;
				}
				inicio = clock();
				shellSort(vet,n);
				//tempoGasto = ((float)clock() - inicio)/CLOCKS_PER_SEC; //EM SEGUNDOS
				tempoGasto = ((float)clock() - inicio)/(CLOCKS_PER_SEC/1000); // EM MILISEGUNDOS
				printf("Tempo gasto: %f\n",tempoGasto);
				/*for (i = 0; i < n; i++) {
					printf("%d\n",vet[i]);
				}*/
			}
			if (escolha == 2) {
				srand((unsigned)time(NULL));
				for (i = 0; i < n; i++) {
					vet[i] = rand();
				}
				inicio = clock();
				shellSort(vet,n);
				//tempoGasto = ((float)clock() - inicio)/CLOCKS_PER_SEC; //EM SEGUNDOS
				tempoGasto = ((float)clock() - inicio)/(CLOCKS_PER_SEC/1000); // EM MILISEGUNDOS
				printf("Tempo gasto: %f\n",tempoGasto);
				/*for (i = 0; i < n; i++) {
					printf("%d\n",vet[i]);
				}*/
			}
			tempoTotal = tempoTotal + tempoGasto; 
			j++;
		}
		printf("Tempo total gasto em %d execuções: %f\n",j,tempoTotal);
		printf("Tempo médio por execução: %f\n",tempoTotal/j);
		tm[l] = tempoTotal/j; 
		l++;
		if (n == 1000)
			n = n + 4000;
		else
			n = n + 5000;
		k++;
		j = 0;
	}
	
	if (fp == NULL) {
		printf("Erro abrindo arquivo\n");
		return 0;
	}

	fprintf(fp,"%d %f\n%d %f\n%d %f\n%d %f\n%d %f\n%d %f\n",1000,tm[0],5000,tm[1],10000,tm[2],15000,tm[3],20000,tm[4],25000,tm[5]);
	fclose(fp);
	return 0;
}


