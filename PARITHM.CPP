#include<stdio.h>
#include<conio.h>  
int main(){  
int number=50;
int *p;//pointer to int
p=&number;//stores the address of number variable
printf("Address of p variable is %u \n",p);
p=p-3;
printf("After increment: Address of p variable is %u \n",p);
 /* 2 bytes for int and 4 bytes for float 1 byte for char
 and 8 bytes for double */
getch();     
return 0;  
}