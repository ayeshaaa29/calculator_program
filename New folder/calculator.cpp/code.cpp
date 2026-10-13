#include <iostream>
#include <limits> // Required for input validation

using namespace std;

// Function declarations
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int modulus(int a, int b);

int main() {
    char choice;
    
    do {
        displayMenu();
        
        int operation;
        cout << "Enter your choice (1-6): ";
        
        // Input validation for menu choice
        if (!(cin >> operation)) {
            cout << "Invalid input. Please enter a number between 1 and 6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Exit condition
        if (operation == 6) {
            cout << "Exiting calculator. Goodbye!\n";
            break;
        }

        if (operation < 1 || operation > 6) {
            cout << "Invalid choice! Please select a valid option from the menu.\n\n";
            continue;
        }

        // Variables for inputs and result
        double num1, num2, result;
        int intNum1, intNum2;

        // Special handling for Modulus (requires integers)
        if (operation == 5) {
            cout << "Enter two integers (a % b): ";
            if (!(cin >> intNum1 >> intNum2)) {
                cout << "Invalid integer input.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (intNum2 == 0) {
                cout << "Error: Division/Modulus by zero is not allowed.\n\n";
                continue;
            }
            cout << "Result: " << intNum1 << " % " << intNum2 << " = " << (intNum1 % intNum2) << "\n\n";
        } 
        else {
            // Standard arithmetic inputs
            cout << "Enter first number: ";
            while (!(cin >> num1)) {
                cout << "Invalid input. Enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter second number: ";
            while (!(cin >> num2)) {
                cout << "Invalid input. Enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Perform operation based on user choice
            switch (operation) {
                case 1:
                    result = add(num1, num2);
                    cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n\n";
                    break;
                case 2:
                    result = subtract(num1, num2);
                    cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n\n";
                    break;
                case 3:
                    result = multiply(num1, num2);
                    cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n\n";
                    break;
                case 4:
                    if (num2 == 0) {
                        cout << "Error: Division by zero is undefined.\n\n";
                    } else {
                        result = divide(num1, num2);
                        cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n\n";
                    }
                    break;
            }
        }

        // Prompt to continue
        cout << "Would you like to perform another calculation? (y/n): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the C++ Calculator!\n";
    return 0;
}

// Function definitions
void displayMenu() {
    cout << "===========================\n";
    cout << "      C++ CALCULATOR       \n";
    cout << "===========================\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%) [Integers only]\n";
    cout << "6. Exit\n";
    cout << "---------------------------\n";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}