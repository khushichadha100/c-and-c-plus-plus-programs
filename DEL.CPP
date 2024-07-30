#include <stdio.h>
#include<conio.h>
void main() {
   int ARR[] = {2,4,6,8,9};
   int k = 2, n = 5;
   int i, j;
   printf("The original array of elements are :\n");
   for(i = 0; i<n; i++) {
      printf("ARR[%d] = %d \n", i, ARR[i]);}
    j = k;
   while( j < n) {
      ARR[j-1] = ARR[j];
      j = j + 1;}
     n = n -1;
     printf("The array elements after deleting the element:\n");
     for(i = 0; i<n; i++) {
      printf("ARR[%d] = %d \n", i, ARR[i]); }
      getch();
}