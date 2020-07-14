#include <stdio.h>


struct student{
	char *firstname;
	char *lastname;
	int age;
	char *career;
};

void printStruct(struct student *Student);

int main(){
	
	struct student Student1;
	Student1.firstname = "Abel";
	Student1.lastname ="Pech";
	Student1.age = 30;
	Student1.career ="Software Development Engineering";
	
	struct student Student;
	Student.firstname = "Abel";
	Student.lastname ="Pech";
	Student.age = 30;
	Student.career ="Software Development Engineering";
	
	printStruct(&Student);
		
	return 0;
}

void printStruct(struct student *Student){
	printf("Firstname: %s\n", Student->firstname);
	printf("Lastname: %s\n", Student->lastname);
	printf("Age: %d\n", Student->age);
	printf("Career: %s\n", Student->career);
}
