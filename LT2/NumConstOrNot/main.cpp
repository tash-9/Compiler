#include <iostream>
#include <string>

using namespace std;


bool isNumericConstant(const string s)
    {


        for (char c : s)
            {
                if (c < '0' || c > '9' )
                return false;
            }
            return true;
  }

int main()
{

    cout<<"Enter number: ";

    string input;
    cin>>input;

    if (isNumericConstant(input))
        cout <<"numeric constant";
    else cout<<"not numeric";

    //cout << "Hello world!" << endl;
    return 0;
}

