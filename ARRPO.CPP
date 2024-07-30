#include<stdio.h>
#include<conio.h>
void main()
{
int myNumbers[4] = {25, 50, 75, 100};
clrscr();

// Get the memory address of the myNumbers array
printf("%u\n", myNumbers);

// Get the memory address of the first array element
printf("%u\n", &myNumbers[0]);

getch();
}