#include <iostream>
#include <string>

using namespace std;

bool isIdentifier(const string s) {
    char first = s[0];
    if (!((first >= 'A' && first <= 'Z') || (first >= 'a' && first <= 'z') || (first == '_')))
        return false;

    for (int i = 1; i < s.length(); ++i) {
        char c = s[i];
        if (!((c >='A' && c <='Z') || (c >= 'a' && c <='z') || (c =='_') || (c >='0' && c <='9')))
            return false;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isIdentifier(input))
        cout << "Valid Identifier" << endl;
    else
        cout << "Invalid Identifier" << endl;

    return 0;
}

