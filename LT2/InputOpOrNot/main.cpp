#include <iostream>

using namespace std;



int main()
{
    cout<<"Enter any operator: ";

    char op;
    cin>>op;

    cout<<endl;



    switch(op)
    {
    case '=':
        cout<<"operaor: =";
    case '+':
        cout<<"operator: +";
        break;

     case '-':
        cout<<"operator: -";
        break;

     case '*':
        cout<<"operator: *";
        break;

     case '/':
        cout<<"operator: /";
        break;

     case '%':
        cout<<"operator= %";
        break;

     default:
        cout<<"Error. Pls re-enter an operator;";
    }

    //cout << "Hello world!" << endl;
    return 0;
}


