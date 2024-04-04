#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool StrongPassword(const string& password) {
    bool Lowercase = false;
    bool Uppercase = false;
    bool Numbers = false;
    bool Specialchar = false;

    for (char c : password) {
        if (islower(c)) {
            Lowercase = true;
        }
        else if (isupper(c)) {
            Uppercase = true;
        }
        else if (isdigit(c)) {
            Numbers = true;
        }
        else {
            Specialchar = true;
        }
    }

    return password.length() >= 8 && Lowercase && Uppercase && Numbers && Specialchar;
}

bool LessStrongPassword(const string& password) {
    bool Lowercase = false;
    bool Uppercase = false;
    bool Numbers = false;

    for (char c : password) {
        if (islower(c)) {
            Lowercase = true;
        }
        else if (isupper(c)) {
            Uppercase = true;
        }
        else if (isdigit(c)) {
            Numbers = true;
        }
    }

    return password.length() >= 6 && Lowercase && Uppercase && Numbers;
}

bool WeakPassword(const string& password) {
    bool Lowercase = false;
    bool Uppercase = false;

    for (char c : password) {
        if (islower(c)) {
            Lowercase = true;
        }
        else if (isupper(c)) {
            Uppercase = true;
        }
    }

    return password.length() >= 4 && Lowercase && Uppercase;
}

int main() {
    string password;
    char choice;

    do {
        cout << "Enter your password: ";
        cin >> password;

        if (StrongPassword(password)) {
            cout << "Congrats! Your password is very strong." << endl;
        }
        else if (LessStrongPassword(password)) {
            cout << "Password is less strong." << endl;
        }
        else if (WeakPassword(password)) {
            cout << "Password is weak." << endl;
        }
        else {
            cout << "Your password is not a strong password." << endl;
        }

        cout << "Do you want to check another password? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}