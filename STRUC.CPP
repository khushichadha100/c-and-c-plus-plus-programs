#include<stdio.h> 
#include <string.h> 
#include<conio.h>
struct employee{
int id;
char name[10];
int age;
char address[15];
char department[10];
int salary;
}; 
int main(){ 
int i;
clrscr();
struct employee emp[5];
printf("Enter Records of 5 employees");
for(i=0;i<5;i++){
printf("\nEnter id:");
scanf("%d",&emp[i].id);
printf("\nEnter Name:");
scanf("%s",&emp[i].name);
printf("\nEnter Age:");
scanf("%d",&emp[i].age);
printf("\nEnter department:");
scanf("%s",&emp[i].department);
printf("\nEnter salary:");
scanf("%d",&emp[i].salary);
}
printf("\nEmployee details:");
for(i=0;i<5;i++){
printf("\nid: %d, Name: %s, age: %d, department: %s, salary: %d"
,emp[i].id,emp[i].name,emp[i].age,emp[i].department,emp[i].salary);
} 
 getch();
 return 0; 
}
