// C Program to demonstrate the use of fseek()
#include <stdio.h>
#include<conio.h>
void main()
{
	FILE *fp;
	fp = fopen("CHAR.txt", "w+");
	fputs("my name is bca",fp);
	// Moving pointer to end
	fseek(fp, 11, SEEK_SET);
	fputs("khushi",fp);
	fclose(fp);
	getch();
}
