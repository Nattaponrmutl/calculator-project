#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

void displayHeader() {
    cout << "\n================================" << endl;
    cout << "    เครื่องคิดเลข   " << endl;
    cout << "================================" << endl;
    cout << " [1] บวก(+)" << endl;
    cout << " [2] ลบ (-)" << endl;
    cout << " [3] คูณ (*)" << endl;
    cout << " [4] หาร (/)" << endl;
    cout << " [5] Exit Program" << endl;
    cout << "--------------------------------" << endl;
    cout << "Select option (1-5): ";
}

double executeMath(double n1, double n2, int op) {
    if (op == 1) return n1 + n2;
    if (op == 2) return n1 - n2;
    if (op == 3) return n1 * n2;
    if (op == 4) {
        if (n2 == 0) return -999999; 
        return n1 / n2;
    }
    return 0;
}

int main() {
    int userChoice;
    double val1, val2, output;
    
    cout << "--- C++ Calculator System Activated ---" << endl;

    // เปลี่ยนมาใช้ do-while loop แทน while ธรรมดา
    do {
        displayHeader();
        
        // รับค่าและตรวจสอบ Error ของ Input
        if (!(cin >> userChoice)) {
            cout << ">> Error: Please enter numbers only!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (userChoice == 5) {
            cout << "\nSystem shutting down. Goodbye!" << endl;
            break;
        }

        if (userChoice < 1 || userChoice > 5) {
            cout << ">> Invalid choice. Try again (1-5)." << endl;
            continue;
        }

        // รับค่าตัวเลข
        cout << "Enter 1st number: ";
        while (!(cin >> val1)) {
            cout << "Invalid input. Enter 1st number again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter 2nd number: ";
        while (!(cin >> val2)) {
            cout << "Invalid input. Enter 2nd number again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // ประมวลผลและแสดงผลลัพธ์
        output = executeMath(val1, val2, userChoice);

        if (userChoice == 4 && val2 == 0) {
            cout << "\n[!] Math Error: Cannot divide by zero." << endl;
        } else {
            string ops[] = {"", "+", "-", "*", "/"};
            cout << fixed << setprecision(4);
            cout << "\n>>> RESULT: " << val1 << " " << ops[userChoice] << " " << val2 << " = " << output << endl;
        }

        cout << "--------------------------------" << endl;

    } while (userChoice != 5);

    return 0;
}
