#include <stdio.h>
#include<conio.h>
#define MAX 5
void main() {
   int arr[MAX] = {40,50,60,80};
   int N = 4;        // number of elements in arr
   int i = 0;        // loop variable
   int index = 3;    // index location to insert new value
   int value = 70;    // new data element to be inserted
   printf("Printing arr before inserting the element -\n");
   for(i = 0; i < N; i++) {
      printf("arr[%d] = %d \n", i, arr[i]);}
   for(i = N; i >= index; i--) {
      arr[i+1] = arr[i];}
   arr[index] = value;
   N++;
   printf("Printing arr after inserting the element -\n");
   for(i = 0; i < N; i++) {
      printf("arr[%d] = %d\n", i, arr[i]);}
   getch();
}