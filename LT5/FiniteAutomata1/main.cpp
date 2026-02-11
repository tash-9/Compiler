#include <iostream>
#include <string>

using namespace std;
//a(a+b)*
int main()
{
    string input;
    cout << "Enter a string with 'a' and 'b': ";
    cin >> input;


    if (input.length()== 0)//not empty
    {
        cout << "REJECT\n";
        return 0;
    }

    if (input[0]!= 'a')//if !a at 1stthen rej
    {
        cout << "REJECT\n";
        return 0;
    }

    for (size_t i=1; i<input.length(); i++)// any other alp rej
    {
        if (input[i]!= 'a' && input[i]!= 'b')
        {
            cout << "REJECT\n";
            return 0;
        }
    }
         cout << "ACCEPT\n";//(a+b)*

return 0;
}

