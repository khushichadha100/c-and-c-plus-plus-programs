#include<stdio.h>
#include<conio.h>
void main()
{
 float fahren,celsius;
 clrscr();
 printf("enter temprature in
  fahrenhite:",fahren);
 scanf("%f",&fahren);
 celsius=(fahren-32)*5/9;
 printf("temprature in celsius is:
  %f",celsius);
 getch();
}