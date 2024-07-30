#include<stdio.h>
#include<conio.h>
#define NUMBER 5

//#if:-
/*void main() {
clrscr();
#if (NUMBER==0)
printf("Value of Number is: %d",NUMBER);
#endif
getch();
}

//#else:-
void main() {
clrscr();
#if NUMBER==0
printf("Value of Number is: %d",NUMBER);
#else
printf("Value of Number is non-zero");
#endif
getch();
}            */



//elif:-
void main() {
clrscr();
#if (NUMBER==0)
printf("Value of Number is: %d",NUMBER);
#elif NUMBER==1
printf("Value of Number is 1");
#else
printf("Value of Number is non-zero and not 1");
#endif
getch();
}