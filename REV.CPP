#include <stdio.h>
#include<conio.h>
#define N 1000
int main() {
    int arr[N];
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter an array: ");
    for (i = 0; i< n; i++){
        scanf("%d", &arr[i]);}
    printf("Reversed array: ");
    for (i = n-1; i>=0; i--){
	printf("%d ", arr[i]);}
   getch();
   return 0;
}
