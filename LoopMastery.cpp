//************************************************************************
//Author.....: Danielle Wimberley
//Assignment.: Loop Mastery Project
//Description: This program practices using loops for repeated tasks
//
//************************************************************************

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Function to calculate factorial
void factorialCalculator() {
    int num;
    cout << "Enter a positive integer: ";
    while (true) {
        cin >> num;
        if (cin.fail() || num < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer: ";
        } else {
            break;
        }
    }

    long long factorial = 1;
    int temp = num;

    while (temp > 1) {
        factorial *= temp;
        temp--;
    }

    cout << "Factorial of " << num << " is: " << factorial << endl;
}

// Function to display number pyramid
void numberPyramid() {
    int rows;
    cout << "Enter the number of rows: ";
    while (true) {
        cin >> rows;
        if (cin.fail() || rows <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number of rows: ";
        } else {
            break;
        }
    }

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }
        cout << endl;
    }
}

// Function to calculate sum of even or odd numbers
void sumEvenOddNumbers() {
    int choice, upperLimit, sum = 0;
    cout << "Enter 1 for sum of even numbers or 2 for sum of odd numbers: ";
    while (true) {
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter 1 or 2: ";
        } else {
            break;
        }
    }

    cout << "Enter an upper limit: ";
    while (true) {
        cin >> upperLimit;
        if (cin.fail() || upperLimit <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
        } else {
            break;
        }
    }

    int i = (choice == 1) ? 2 : 1; // Start with 2 for even numbers, 1 for odd
    do {
        if (choice == 1 && i % 2 == 0) {
            sum += i;
        } else if (choice == 2 && i % 2 != 0) {
            sum += i;
        }
        i++;
    } while (i <= upperLimit);

    cout << "Sum is: " << sum << endl;
}

// Function to reverse a string
void reverseString() {
    string str;
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, str);

    int length = str.length();
    int start = 0;
    int end = length - 1;
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }

    cout << "Reversed string: " << str << endl;
}

int main() {
    int choice;
    do {
        // Displaying the menu
        cout << "========= Interactive Utility Program =========\n";
        cout << "1. Factorial Calculator\n";
        cout << "2. Number Pyramid\n";
        cout << "3. Sum of Even or Odd Numbers\n";
        cout << "4. Reverse a String\n";
        cout << "5. Exit\n";
        cout << "==============================================\n";
        cout << "Enter your choice: ";
        
        while (true) {
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter a number between 1 and 5: ";
            } else {
                break;
            }
        }

        // Call the corresponding function based on user choice
        switch (choice) {
            case 1:
                factorialCalculator();
                break;
            case 2:
                numberPyramid();
                break;
            case 3:
                sumEvenOddNumbers();
                break;
            case 4:
                reverseString();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
