/*
You are a software engineer in times of coronavirus and currently you are trying to know how
many days will it take for all the people in a region to get infected, if 1 means that a person is
infected with the virus and 0 means that a person is not infected/.
Consider this: 
1 can infect 0 in [up, down, left, right]
It takes 1 day for 1 to infect 0 .
How many days will it take to infect all the region?

Example:
[ 1, 0, 0 ]
[ 1, 1, 1 ]
[ 0, 0, 0 ]

Example:
[ 0, 0, 0 ]
[ 0, 1, 0 ]
[ 0, 0, 0 ]

M, N
00					01(axisX-1, axisY)	02
10(axisX, axisY-1)	11					12 (axisX, axisY+1)
20					21(axisX+1, axisY)	22

*/

#include <stdio.h>
#include <string.h>

const int M = 3; 
const int N = 3;

void coronavirus();
void testVirus(int arrayTest[M][N]);
void spreadingVirus(int arrayTest[M][N]);
void printVirus(int arrayTest[M][N]);

int main(){
	printf("Welcome Software Engineer\n");
	printf("Determine infections of CoronaVirus for this Quarantine\n");
	coronavirus();
	
	return 0;
}

void coronavirus(){
	int axisX = 0, axisY = 0;
	int arrayTest[3][3]={ {0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	printf("Printing Initial Sample\n");
	for(axisX = 0; axisX < 3; axisX++){
		for(axisY = 0; axisY< 3; axisY++){
			printf("%d\t", arrayTest[axisX][axisY]);	
		}
		printf("\n");
	}
	spreadingVirus(arrayTest);
}

void spreadingVirus(int arrayTest[M][N]){
	int axisX = 0, axisY = 0;
	static int changes = 0, days = 0;
	
	for(axisX = 1; axisX < M; axisX++){
		for(axisY = 1; axisY< N; axisY++){
			if(arrayTest[axisX][axisY] != 0){
				
				if((arrayTest[axisX-1][axisY] == 0) && (axisX>0)){
					arrayTest[axisX-1][axisY]= 1;	
					changes++;
				}
				if((arrayTest[axisX+1][axisY] == 0) && (axisX<=M-2)){
					arrayTest[axisX+1][axisY]= 1;	
					changes++;
				}
				if((arrayTest[axisX][axisY-1] == 0) && (axisY>0)){
					arrayTest[axisX][axisY-1]= 1;	
					changes++;
				}
				if((arrayTest[axisX][axisY+1] == 0) && (axisY<=N-2)){
					arrayTest[axisX][axisY+1]= 1;	
					changes++;
				}
			}
		}		
	}
	
	days++;
	
	printf("Changes Made : %d\n", changes);
	printf("Days : %d\n", days);	
	printVirus(arrayTest);	
}

void printVirus(int arrayTest[M][N]){
	int axisX = 0, axisY = 0;	
	printf("Printing Virus Spreading:\n");
	for(axisX = 0; axisX < M; axisX++){
		for(axisY = 0; axisY< N; axisY++){
			printf("%d\t", arrayTest[axisX][axisY]);			
		}
		printf("\n");
	}	
}
