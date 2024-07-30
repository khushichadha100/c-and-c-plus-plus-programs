#include <iostream.h>
#include<conio.h>
class Number {
private:
    int value;

public:
    // Constructor
    Number(int val) : value(val) {}

    // Function to modify the value using call by reference
    void modifyValue(int &newValue) {
        value = newValue;
    }

    // Function to get the value using return by reference
    int &getValue() {
        return value;
    }
};

int main() {
    // Create an object of the Number class
    Number numObj(42);

    cout << "Initial value: " << numObj.getValue();

    // Modify the value using call by reference
    int newValue = 100;
    numObj.modifyValue(newValue);
    cout << "Value after modification using call by reference: " << numObj.getValue();

    // Modify the value using return by reference
    numObj.getValue() = 200;
    cout << "Value after modification using return by reference: " << numObj.getValue();
    getch();
    return 0;
}
