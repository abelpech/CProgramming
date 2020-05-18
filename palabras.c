/*
First C Program
*/
#include <stdio.h>
#include <string.h>
int main(){
	//cuadricula();
	//palabras();
return 0;
}

void palabras(){
	char palabra1[30];
	char palabra2[30];
	printf("Palabra 1: ");
	scanf("%s", &palabra1);
	printf("Palabra 2: ");
	scanf("%s", &palabra2);
	int tamano1 = strlen(palabra1);
	int tamano2 = strlen(palabra2);
	if(tamano1 > tamano2){
		printf("La palabra %s es mas grande por %d letras\n", palabra1, tamano1-tamano2);
	}
	else{
		printf("La palabra %s es mas grande por %d letras\n", palabra2, tamano2-tamano1);
	}	
}
void cuadricula(){
	int i = 0, j = 0;
	
	for ( i = 1; i <= 5; i++) {
		for ( j = 1; j <= 10; j++) {
		printf("%d \t", i * j );
		}
		printf("\n");
	}
}


