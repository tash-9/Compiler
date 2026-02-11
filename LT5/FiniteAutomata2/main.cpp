#include <iostream>
#include <string>

using namespace std;
//a(a+b)
int main()
{
    string input;
    cout << "Enter a string with 'a' and 'b': ";
    cin >> input;

    if (input.length()== 0)//not emoty
    {
        cout << "REJECT\n";
        return 0;
    }

    if (input.length()!= 2)//(a+b)
    {
        cout << "REJECT\n";
        return 0;
    }

    if (input[0]!= 'a')//if at 1st !a then rej
    {
        cout << "REJECT\n";
        return 0;
    }

    if (input[1]!= 'a' && input[1]!= 'b')//if 2nd not (a+b)* then reject
    {
        cout << "REJECT\n";
        return 0;
    }

    cout << "ACCEPT\n";
    return 0;
}
