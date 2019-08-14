#include<stdio.h>

void somme(int a[], int b[], int resultat[], int n){
	int c;

	for (c = 0; c < n; c++) {
		resultat[c] = a[c] + b[c];
	}
}

void lecture(int tab[], int n){
	int c;

	for (c = 0; c < n; c++) {
		printf("%d ", tab[c]);
	}
	printf("\n");
}

void ecriture(int tab[], int n){
	int c;

	for(c = 0; c < n; c++) {
	    printf(" element %d : ", c + 1);
		scanf("%d", &tab[c]);
	}
}

int main(){
	int n;

	printf("Taille tableau: ");
	scanf("%d", &n);

	int a[n];
	int b[n];
	int resultat[n];

	printf("Valeurs tableau 1:\n");
	ecriture(a, n);
	printf("Valeurs tableau 2:\n");
	ecriture(b, n);
	somme(a, b, resultat, n);
	lecture(resultat, n);

	return 0;
}
