#include <stdio.h>
#include <conio.h>
struct Student
{
  char Student_Name[50];
  int C_Marks;
  int DataBase_Marks;
  int CPlus_Marks;
  int English_Marks;
};

int main()
{
  int i;
  clrscr();
  struct Student Students[4] =
                {
                 {"Suresh", 80, 70, 60, 70},
                 {"Tutorial", 85, 82, 65, 68},
                 {"Gateway", 75, 70, 89, 82},
                 {"Mike", 70, 65, 69, 92}
                 };
  
  printf(".....Student Details....");
  for(i=0; i<4; i++)
  {
    printf("\n Student Name = %s", Students[i].Student_Name);
    printf("\n First Year Marks = %d", Students[i].C_Marks);
    printf("\n Second Year Marks = %d", Students[i].DataBase_Marks);
    printf("\n First Year Marks = %d", Students[i].CPlus_Marks);
    printf("\n Second Year Marks = %d", Students[i].English_Marks);
  }    
 getch();
 return 0;
}