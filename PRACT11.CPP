#include<stdio.h>
#include<conio.h>
void main()
{
 int a,b,choice,total;
 clrscr();
 printf("\nenter number 1: ");
 scanf("%d",&a);
 printf("\nenter number 2: ");
 scanf("%d",&b);
 printf("\n select the operation from bellow:");
 printf("\n1.Addition") ;
 printf("\n2.Subtraction");
 printf("\n3.Multiplication");
 printf("\n4.Division");
 printf("\n5.Average");
 printf("\n6.Percentage");
 printf("\n Enter your choice: ");
 scanf("%d",&choice);
 if(choice==1)
 {
  printf("Addition of %d and %d is : %d",a,b,a+b);
 }
 else if(choice==2)
 {
  printf("Subtraction of %d and %d is : %d",a,b,a-b);
 }
 else if(choice==3)
 {
  printf("Multiplication of %d and %d is : %d ", a,b,a*b);
 }
 else if(choice==4)
 {
  printf("Division of %d and %d is : %d",a,b,a/b);
 }
 else if(choice==5)
 {
  printf("Average of %d and %d is : %d",a,b,a+b/2);
 }
 else if(choice==6)
 {
  printf("Enter total : %d " );
  scanf("%d",&total);
  printf("Percentage of %d and %d is : %d",a,b,(a+b/total)*100);
 }
 else
  printf("wrong choice");
getch();
}
