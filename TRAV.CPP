#include <stdio.h>
#include<conio.h>
void main()
{
   int ARR[] = {3, 5, 7, 9, 10};
   int i, n = 5;
   clrscr();

   printf("The elements of the array are:\n");


   for(i = 0; i < n; i++)
   {
      printf("ARR[%d] = %d \n", i, ARR[i]);
   }
   getch();
}