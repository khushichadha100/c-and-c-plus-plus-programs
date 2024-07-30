# include<stdio.h>
#include<conio.h>
#define Area(x) x*x
#define Costpaint(x,y,z) (z*y + Area (x))
void main()
{
int A = 8, B= 6, C = 4;
clrscr();
printf("The area of square= %d\n", Area(A));
printf("Cost of paint= %d\n", Costpaint(A,B,C));
}
/*# define UPPER 25
int main( )
{ 
int i ;
for ( i = 1 ; i <= UPPER ; i++ )
printf ( "%d\n", i ) ; 
printf("File :%s\n", __FILE__ );
printf("Date :%s\n", __DATE__ );
printf("Time :%s\n", __TIME__ );
printf("Line :%d\n", __LINE__ );*/
getch();
return 0 ;
}