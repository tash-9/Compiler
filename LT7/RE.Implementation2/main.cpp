#include <iostream>
#include <string>

using namespace std;

bool DFA(string s)
{
    int state = 0;

    for (char c:s)
    {
        if (c!= 'a' && c!= 'b')
            return false;


        switch (state)
        {
            //{q0, q2}
            case 0:
                if (c=='a') state= 1;
                else if (c=='b') state= 2;
                break;


            case 1: //{q3}
                if (c=='a') state= 1;
                else if (c=='b') state= 3;
                break;

            case 2: //{q1, q2}
                if (c== 'a') state= 4;
                else if (c== 'b') state= 5;
                break;

            case 3: //{q4}
                if (c== 'a') state= 6;
                else if (c== 'b') state= -1;
                break;

            case 4: //{q0,q2,q3}
                if (c== 'a') state= 1;
                else if (c== 'b') state= 7;
                break;

            case 5: //{q2}
                if (c== 'a') state= 1;
                else if (c== 'b') state= 5;
                break;

            case 6: //{q5}
                if (c== 'a') state= 1;
                else if (c== 'b') state= 1;
                break;

            case 7: //{q1,q2,q4}
                if (c== 'a') state= 8;
                else if (c== 'b') state= 5;
                break;

            case 8: //{q0,q2,q3,q5}
                if (c== 'a') state= 1;
                else if (c== 'b') state= 9;
                break;

            case 9: //{q1,q2,q3,q4}
                if (c== 'a') state= 8;
                else if (c== 'b') state= 10;
                break;

            case 10: //{q2,q4}
                if (c== 'a') state= 11;
                else if (c== 'b') state= 5;
                break;

            case 11: //{q3,q5}
                if (c== 'a') state= 1;
                else if (c== 'b') state= 12;
                break;

            case 12://{q3,q4}
                if (c== 'a') state= 11;
                else if (c== 'b') state= 3;
                break;

            default:
                return false;
        }
    }
    return (state== 1 || state== 4 || state== 8 || state== 9 || state== 11 || state== 12);
}

int main() {

    while (true){
    string input;
    cout << "Enter a string consisting of as & bs: ";
    cin >> input;

    if (DFA(input))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";}

    return 0;
}
