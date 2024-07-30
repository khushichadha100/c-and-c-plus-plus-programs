//C Program to demonstrate the use of ftell()
#include <stdio.h>
#include <conio.h>  
void main (){  
   FILE *fp;  
   int length;  
   clrscr();  
   fp = fopen("file.txt", "r");  
   fseek(fp, 0, SEEK_END);  
  
   length = ftell(fp);  
  
   fclose(fp);  
   printf("Size of file: %d bytes", length);  
   getch();  
}  