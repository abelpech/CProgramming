#include <stdio.h>

/*
Structure Definition
*/
struct employee{
		char *firstname;
		char *lastname;
	};
	
int main(){
	
	struct employee Emp1;
	
	Emp1.firstname = "Abel";
	Emp1.lastname = "Pech";
	
	struct employee *employeePtr;
	employeePtr = &Emp1;
	
	
	printf("Firstname: %s\n", Emp1.firstname);
	printf("Lastname: %s\n", Emp1.lastname);
	printf("Firstname: %s\n", employeePtr->firstname);
	printf("Lastname: %s\n", employeePtr->lastname);
	printf("Firstname: %s\n", (*employeePtr).firstname);
	printf("Lastname: %s\n", (*employeePtr).lastname);
	
	typedef struct employee Empleados;
	Empleados empleado;
	empleado.firstname ="Aura";
	empleado.lastname="Martinez";
	
	printf("Firstname: %s\n", empleado.firstname);
	printf("Lastname: %s\n", empleado.lastname);
	
	return 0;
	
}


void pointers(){
		//Declaring variable X
	int x = 10;
	//xPtr points to X and initialized with NULL
	int *xPtr = NULL;
	//Assigning address of variable X to xPtr
	xPtr = &x;
	
	//Printing variable X both by directly printing variable X and thru pointer to X
	printf("X = %d \t XPTR = %d \n ", x, *xPtr);
	*xPtr = 12;
	
	printf("X = %d \t XPTR = %d \n ", x, *xPtr);
	
	int **xPtr2 = NULL;
	xPtr2 = &xPtr;
	
	printf("xPtr = %p xPtr2 = %p\n", xPtr, xPtr2);
	printf("xPtr = %d xPtr2 = %d\n", *xPtr, **xPtr2);
	
}
