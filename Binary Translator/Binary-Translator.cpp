#include <iostream>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

char op;
int num, binaryNum, decimalNum, base;

void decimalToBinary() {
    system("cls");

    string bin = "";
    cout << endl << "Type a number: ";
    cin >> num;

    // Checks if the input is valid
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please enter a valid number." << endl;
        return; // Stop further execution
    }

    if (num < 0) {
        cout << "Please enter a positive number." << endl;
        return; // Stop further execution
    }

    int originalNum = num;
    while (num > 0) {
        bin = to_string(num % 2) + bin;
        num /= 2;
    }

    cout << endl << originalNum << " in binary: " << bin << endl;
    cout << "Press [ENTER] to continue...";
    cin.ignore();
    cin.get();
}

void binaryToDecimal() {
    system("cls");

    decimalNum = 0;
    base = 1;

    cout << endl << "Type a binary number: ";
    cin >> binaryNum;

    // Checks if the input is valid
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please enter a valid binary number." << endl;
        return; // Stop further execution
    }

    int originalBinary = binaryNum;
    bool isValidBinary = true;

    while (binaryNum > 0) {
        int lastDigit = binaryNum % 10;

        if (lastDigit != 0 && lastDigit != 1) {
            cout << "Invalid binary number! Please enter a valid binary number." << endl;
            isValidBinary = false;
            break;
        }

        decimalNum += lastDigit * base;
        base *= 2;
        binaryNum /= 10;
    }

    if (isValidBinary) {
        cout << endl << originalBinary << " in decimal: " << decimalNum << endl;
    }

    cout << "Press [ENTER] to continue...";
    cin.ignore();
    cin.get();
}

int main() {
    do {
        system("cls");

        cout << "Select an operation: \n";
        cout << "[1] Decimal to Binary \n";
        cout << "[2] Binary to Decimal \n";
        cout << "[0] Close program \n\n";
        cout << "A.: ";
        cin >> op;

        // Checks if the input is valid
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Invalid input, please select a valid option." << endl;
            continue;
        }

        if (op == '1') {
            decimalToBinary();
        }
        else if (op == '2') {
            binaryToDecimal();
        }

    } while (op != '0');

    return 0;
}