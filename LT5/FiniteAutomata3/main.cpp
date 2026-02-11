#include <iostream>
#include <string>

using namespace std;
//a(a+b)* +b*
int main()
{
    string input;
    cout << "Enter a string with 'a' and 'b': ";
    cin >> input;

    if (input.length() == 0)
    {
        cout << "REJECTT\n";
        return 0;
    }

    if (input[0] == 'a')
    {//a(a+b)*
        for (size_t i = 1; i< input.length(); i++)
        {
            if (input[i]!='a' && input[i]!= 'b')
            {
                cout << "REJECT\n";
                return 0;
            }
        }
        cout << "ACCEPT\n";
        return 0;
    }

    if (input[0] == 'b')
    {//!b at 1st but will have b at finale
        for (size_t i = 1; i < input.length(); i++)
        {
            if (input[i]!= 'b')
            {
                cout << "REJECT\n";
                return 0;
            }
        }
        cout << "ACCEPT\n";
        return 0;
    }

    cout << "REJECT\n";
return 0;
}
