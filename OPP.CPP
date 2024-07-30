#include <stdio.h>
#include<conio.h>
int main()
{   float num1, num2;    // Normal variables
    float *ptr1, *ptr2;  // Pointer variables
    float sum, diff, mult, div;
    ptr1 = &num1; // ptr1 stores the address of num1
    ptr2 = &num2; // ptr2 stores the address of num2
    printf("Enter any two real numbers: ");
    scanf("%f%f", ptr1, ptr2);
    sum  = (*ptr1) + (*ptr2);
    diff = (*ptr1) - (*ptr2);
    mult = (*ptr1) * (*ptr2);
    div  = (*ptr1) / (*ptr2);
    printf("Sum = %.2f\n", sum);
    printf("Difference = %.2f\n", diff);
    printf("Product = %.2f\n", mult);
    printf("Quotient = %.2f\n", div);
    getch();
    return 0;
}