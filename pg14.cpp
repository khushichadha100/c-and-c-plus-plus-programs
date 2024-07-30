#include <iostream>
#include <fstream>
#include <cctype> // for isdigit and isalpha functions
#include <conio.h>
int main() {
    clrscr();
    std::ifstream inputFile("input.txt"); // Open the input file
    if (!inputFile) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    char ch;
    int digitCount = 0, alphabetCount = 0, spaceCount = 0;

    // Read characters from the file and count digits, alphabets, and spaces
    while (inputFile.get(ch)) {
        if (isdigit(ch)) {
            digitCount++;
        } else if (isalpha(ch)) {
            alphabetCount++;
        } else if (isspace(ch)) {
            spaceCount++;
        }
    }

    // Close the file
    inputFile.close();

    // Display the counts
    std::cout << "Number of digits: " << digitCount << std::endl;
    std::cout << "Number of alphabets: " << alphabetCount << std::endl;
    std::cout << "Number of spaces: " << spaceCount << std::endl;
    getch();
    return 0;
}