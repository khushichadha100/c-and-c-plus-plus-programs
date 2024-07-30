#include<stdio.h>
#include<conio.h>
void swap1(int,int);
void swap2(int*,int*);
void main()
{
int a=10,b=20;
swap1(a,b);
printf("Value of a and b is %d and %d",a,b);
swap2(&a,&b);
printf("Value of a and value of b is %d and %d",a,b);
getch();
}
void swap1(int a, int b)
{
int temp;
temp=a;
a=b;
b=temp;
}
void swap2(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}