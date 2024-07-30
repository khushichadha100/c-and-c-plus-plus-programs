#include <iostream>

class Temperature {
private:
    double celsius;

public:
    // Simplified constructor to initialize Temperature in Celsius
    Temperature(double celsius) : celsius(celsius) {}
  
    operator char() {
        if (celsius>=100) return 'h';
        else if (celsius>=90) return 'm';
        else return 'l';
        // Implicit conversion to float
    }

    // Conversion function to convert Temperature to float
    operator int() {
        return celsius;  // Implicit conversion to float
    }
};

int main() {
    // Create a Temperature object and implicitly convert it to float
    int intconvertedValue = Temperature(25.5);
    char charconvertedValue = Temperature(95.784);
    // Display the converted value
    std::cout << "Converted temperature in Celsius to int: " << intconvertedValue << " degrees Celsius" << std::endl;
    std::cout << "Converted temperature in Celsius to char: " << charconvertedValue << " degrees Celsius" << std::endl;

    return 0;
}