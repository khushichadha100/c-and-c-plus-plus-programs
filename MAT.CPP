#include<stdio.h>
#include<conio.h>
#define MAX_SIZE 100

typedef struct
{
    int row;
    int col;
    int value;
} Triplet;

void convertToTriplet(int matrix[][MAX_SIZE],int rows,int cols, Triplet *tripletMatrix)
{
    int count = 1;
    tripletMatrix[0].row = rows;
    tripletMatrix[0].col = cols;
    tripletMatrix[0].value = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                tripletMatrix[count].row = i;
                tripletMatrix[count].col = j;
                tripletMatrix[count].value = matrix[i][j];
                count++;
            }
        }
    }

    tripletMatrix[0].value = count - 1;
}

int isSparseMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    int zeroCount = 0;
    int nonZeroCount = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroCount++;
            }
            else
            {
                nonZeroCount++;
            }
        }
    }

    return zeroCount > nonZeroCount;
}

void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void displayTripletMatrix(Triplet *tripletMatrix)
{
    int count = tripletMatrix[0].value;

    printf("Triplet Matrix:\n");
    printf("Row\tColumn\tValue\n");
    printf("%d\t%d\t%d\n", tripletMatrix[0].row,
    tripletMatrix[0].col, count);

    for (int i = 1; i <= count; i++)
    {
	printf("%d\t%d\t%d\n", tripletMatrix[i].row,
	tripletMatrix[i].col, tripletMatrix[i].value);
    }
    printf("\n");
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    clrscr();
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	{
            scanf("%d", &matrix[i][j]);
        }
    }

    displayMatrix(matrix, rows, cols);

    if (isSparseMatrix(matrix, rows, cols))
    {
        printf("The matrix is sparse.\n");
    }
    else
    {
        printf("The matrix is not sparse.\n");
    }

    Triplet tripletMatrix[MAX_SIZE * MAX_SIZE];
    convertToTriplet(matrix, rows, cols, tripletMatrix);
    displayTripletMatrix(tripletMatrix);
    getch();
    return 0;
}
