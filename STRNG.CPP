# include<stdio.h>
#include<conio.h>
#include<string.h>
int main( )
{
//gets() and puts()
/*char name[ 25 ] ;
printf ( "Enter your full name: " ) ;
gets ( name ) ;
puts ( "Hello!" ) ;
puts ( name ) ;*/

//counting length of characters in strings
/*char arr[ ] = "C Program" ;
int len=0;
len = strlen ( arr );  //counts no. of characters in string(counts space also
printf ( " length = %d",len ) ;*/

//reverse a string
/*char str[20];
clrscr();
printf("Enter string: ");
gets(str);//reads string from console
printf("String is: %s",str);
printf("\nReverse String is: %s",strrev(str));  */

//copying one string into another
/*char copythis[ ] = "Program" ;
char copyin[ 20 ] ;
strcpy ( copyin ,copythis ) ;//will copy one string in another
printf ( "copy string = %s\n", copythis ) ;
printf ( "copyin string = %s\n", copyin ) ;*/

//copy nth characters of strings into another
/*char copythis[ ] = "Program" ;
char copyin[ 20 ] ;
strncpy(copyin ,copythis ,3) //3 is no. of characters from starting
printf ( "copy string = %s\n", copythis ) ;
printf ( "copyin string = %s\n", copyin ) ;*/

//joins or concatenates one string after other
/*char source[ ] = "C" ;
char target[ 30 ] = "Program" ;
strcat ( target, source ) ;
printf ( "source string = %s\n", source ) ;
printf ( "target string = %s\n", target ) ; */

//compares one string from another
/*char a[]="c";
char b[]="d";
int i,j;
clrscr();
i=strcmp(b,a);
j=strcmp(a,b);
printf("%d\n%d",i,j); */

//compares nth character only
/*char a[]="khushi";
char b[]="khushichadha";
int i,j;
clrscr();
i=strncmp(b,a,7);
j=strncmp(a,b,3);
printf("%d\n%d",i,j);*/

//finds one string from other
char str[30]="my name is khushi chadha";
char *sub;
sub=strstr(str,"name");
puts(sub);
getch();
return 0 ;
}