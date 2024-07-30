#include<stdio.h>
#include<conio.h>
int checkArmstrong(int num)
  {
   int temp,r,sum=0;
   temp = num;
   while (temp!= 0)
   {
    r= temp% 10;
    sum = sum + (r*r*r);
    temp/= 10;
   }
   if (sum == num)
   return 1;
   else
   return 0;
  }
void main()
{
 clrscr();
 int choice;
 printf("enter your choice from bellow:");
 printf("\n1.Armstrong numbers between 1 to n:-");
 printf("\n2.prime numbers between given range:-");
 printf("\n3.reverse an integer:-");
 printf("\nenter your choice : 1/2/3 :- ");
 scanf("%d",&choice);
 if(choice==1)
 {
   int i, n;
   printf("\nEnter the value of N:");
   scanf("%d",&n);
   printf("\nAll Armstrong numbers from 1 to %d are: \n", n);
   for (i = 1; i<= n; i++)
   {
    if (checkArmstrong(i))
    printf("%d\n", i);
   }
  }
  else if(choice==2)
  {
   int n1,n2,i,j;
   printf("\nenter the range:");
   printf("\nenter number from where to start: ");
   scanf("%d",&n1);
   printf("\nenter the end number: ");
   scanf("%d",&n2);
   for(i=n1;i<=n2;i++)
   {
    for(j=2;j<=i;j++)
    {
     if(i%j==0)
     break;
    }
    if(i==j)
    printf("%d\n",j);
   }
  }
  else if(choice==3)
  {
   int n,r;
   printf("\nenter any number which you want to reverse: ");
   scanf("%d",&n);
   printf("\n your entered number was = %d ",n);
   printf("\n the reversed number is : ");
   while(n>0)
   {
    r=n%10;
    printf("%d",r);
    n=n/10;
   }
  }
  else
  {
   printf("invalid choice !! ");
  }
getch();
}