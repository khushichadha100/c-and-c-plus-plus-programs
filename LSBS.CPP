#include <stdio.h>
#include<conio.h>
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 10, 14, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    clrscr();
    printf("Enter the element to search: ");
    scanf("%d", &target);

    int linearIndex = linear_search(arr, size, target);
    int binaryIndex = binary_search(arr, size, target);

    if (linearIndex != -1) {
	printf("Element found at index %d using linear search.\n",linearIndex);
    } else {
	printf("Element not found using linear search.\n");
    }

    if (binaryIndex != -1) {
	printf("Element found at index %d using binary search.\n",binaryIndex);
    } else {
        printf("Element not found using binary search.\n");
    }
    getch();
    return 0;
}
