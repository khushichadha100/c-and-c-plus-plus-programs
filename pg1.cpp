#include <iostream>
#include<conio.h>

// Inline function definition
inline int square(int num) {
    return num * num;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    // Call the inline function
    int result = square(num);

    std::cout << "Square of " << num << " is: " << result << std::endl;
    getch();
    return 0;
}
