/*
Teoria de Colas
Ing. Sergio Chimal
Modelo M/M/1
Markoviana Tipo Poisson(Distribucion de Llegadas)
Markoviana Tipo Exponencial (Distribucion de los Tiempos de Servicio)
1 Servidor

Ing. Abel Pech

Una doctora pasa en promedio 20 minutos con sus pacientes.
Si el tiempo estimado de llegada de cada cliente es de 30 minutos, calcular:

a) Numero promedio de pacientes en el sistema
b) Tiempo total que consume un paciente en el consultorio
c) Factor de uso del sistema
d) Numero promedio de pacientes haciendo fila
e) Probabilidad de que el consultorio este vacio

Landa = 30 minutos o .5hr
Miu = 20 minutos o .33 hr
																																																																							https://www.youtube.com/watch?v=t3x2KinUqAA
Referencia: https://en.wikipedia.org/wiki/M/M/c_queue

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Prototipos de Funcion
void menu(float landa, float miu);
float tiempoEntreLlegadas(float landa);
float tiempoEntreServicios(float miu);
float numeroUnidadesSistema(float landa, float miu);
float tiempoUnidadEnElSistema(float landa, float miu);
float numeroPromedioUnidadesEsperandoFila(float landa, float miu);
float tiempoUnidadEsperaFila(float landa, float miu);
float factorUsoSistema(float landa, float miu);
void probabilidadZeroUnidadSistema(float factor);


int main(){
	float landa =0, miu =0;
	printf("Teoria de Colas\n\n");
	printf("Ejemplo!!!!\n\n");
	printf("Un doctor pasa en promedio 20 minutos con sus pacientes.\nSi el tiempo estimado de llegada de cada cliente es de 30 minutos, calcular:\na) Numero promedio de pacientes en el sistema \nb) Tiempo total que consume un paciente en el consultorio\nc) Factor de uso del sistema\nd) Numero promedio de pacientes haciendo fila\ne) Probabilidad de que el consultorio este vacio\n\n");
	printf("Landa ^ es la Velocidad de Llegadas\n");
	printf("Ingrese el valor de Landa ^ en Minutos: \n");
	scanf("%f", &landa);
	printf("\nMiu u es la Velocidad de Servicio\n");
	printf("Ingrese el valor de Miu u en Minutos: \n");
	scanf("%f", &miu);
	printf("\nConvirtiendo de Velocidad a Tiempo en Hr\n");
	printf("\nTiempo entre Llegadas: %3.3f\n", tiempoEntreLlegadas(landa/60));
	printf("Tiempo entre Servicios: %3.3f\n", tiempoEntreServicios(miu)*60);
	system("cls");
	menu(tiempoEntreLlegadas(landa/60), tiempoEntreServicios(miu)*60);
	return 0;
}

//Menu
void menu(float landa, float miu){
	int opcion = 0;
	
	do{
		printf("\nSeleccione una opcion:\n\n");
		printf("1) Landa\n2) Miu\n3) Ls\n4) Ws\n5) Lq\n6) Wq\n7) p\n8) Salir\nPara salir presione 0 u opcion 8: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf("\nLanda ^: %3.2f\n", landa);
				break;
			case 2:
				printf("\nMiu u: %3.2f\n", miu);
				break;
			case 3:
				printf("\nNumero de Unidades en el Sistema - Ls: %3.3f\n", numeroUnidadesSistema(landa,miu));
				break;
			case 4:
				printf("\nTiempo en el cual una Unidad esta en el Sistema - Ws: %3.3f\n", tiempoUnidadEnElSistema(landa,miu));
				break;	
			case 5:
				printf("\nNumero Promedio de Unidades esperando en la Fila - Lq: %3.3f\n", numeroPromedioUnidadesEsperandoFila(landa,miu));
				break;
			case 6:
				printf("\nTiempo en que una Unidad espera en la Fila - Wq: %3.3f\n", tiempoUnidadEsperaFila(landa,miu));
				break;
			case 7: 
				printf("\nFactor de Uso del Sistema - p: %3.3f  \n", factorUsoSistema(landa,miu)*100);
				break;	
			case 8:
				return;		
			case 0:
				printf("\nSalir\n");
				break;
			default:
				printf("\nSeleccione una opcion valida\n");
				break;
		}
			
	}while(opcion!=0);
}

//Funciones que regresan el resultado de las formulas para M/M/1

float tiempoEntreLlegadas(float landa){
	return 1/landa;
}

float tiempoEntreServicios(float miu){
	return 1/miu;
}

float numeroUnidadesSistema(float landa, float miu){
	return landa / (miu - landa);
}

float tiempoUnidadEnElSistema(float landa, float miu){
	return (1/(miu-landa));
}

float numeroPromedioUnidadesEsperandoFila(float landa, float miu){
	return ((landa*landa)/ (miu *(miu - landa)));
}

float tiempoUnidadEsperaFila(float landa, float miu){
	return ((landa)/ (miu *(miu - landa)));
}

float factorUsoSistema(float landa, float miu){
	float factor =  0;
	factor = landa / miu;
	probabilidadZeroUnidadSistema(factor);
	return factor ;
}

void probabilidadZeroUnidadSistema(float factor){
	printf("\nProbabilidad de que Ninguna Unidad se encuentre en el Sistema - Po: %3.3f \n", (1-factor)*100);
}
