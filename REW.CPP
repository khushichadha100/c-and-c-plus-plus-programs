//C Program to demonstrate the use of rewind()
#include<stdio.h>
#include<conio.h>
void main(){  
FILE *fp;
char c;  
clrscr();
fp=fopen("file.txt","r");
  
while((c=fgetc(fp))!=EOF){
 printf("%c",c);
}  
rewind(fp);
while((c=fgetc(fp))!=EOF){
 printf("%c",c);
}  

fclose(fp);
getch();    
}  