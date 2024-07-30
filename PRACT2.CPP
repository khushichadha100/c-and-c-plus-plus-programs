#include<stdio.h>
#include<conio.h>
void main()
{
 int a,b,c;
 clrscr();
 printf("enter number 1:");
 scanf("%d",&a);
 printf("\nenter number 2:");
 scanf("%d",&b);
 printf("\nenter number 3:");
 scanf("%d",&c);
 if(a>b && a>c)
 {
  printf("%d is gratest ",a);
 }
 else if(b>a && b>c)
 {
  printf("%d is greatest ", b);
 }
 else
 {
 printf("%d is greatest ", c);
 }
getch();
}