#include <stdio.h>
#include<conio.h>
void main()
{
 int choice;
 printf("\nchoose from below:");
 printf("\n1.factorial of a number:- ");
 printf("\n2.fibonacci series:- ");
 printf("\nenter your choice : 1/2 :  ");
 scanf("%d",&choice);
 if(choice==1)
 {
    int n, i;
    int fact=1;
    printf("\nEnter an integer: ");
    scanf("%d", &n);
    if (n < 0)
	printf("\nError! Factorial of a negative number doesn't exist.");
    else
    {
     for (i = 1; i <= n; i++)
     {
      fact *= i;
     }
     printf("Factorial of %d = %d", n, fact);
    }
 }
 else if(choice==2)
 {
   int first_number = 0, second_number = 1, third_number, i, number;
   printf("\nEnter the number for fibonacci series:");
   scanf("%d",&number);
   printf("\nFibonacci Series for a given number:");
   printf("\n%d %d", first_number, second_number);
   for(i = 2; i < number; i++)
   {
    third_number = first_number + second_number;
    printf(" %d", third_number);
    first_number = second_number;
    second_number = third_number;
   }
 }
 else
 {
   printf("invalid choice !! ");
 }
getch();
}
