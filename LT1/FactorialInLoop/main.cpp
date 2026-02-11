#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter a number: ";
    int n;
    long long factorial= 1;

    cin>>n;

    if (n<0)
        {cout<<"Factorial not p[ossible for negative nubmer"<<endl;
        return 1;}
    else
    {
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
    }
    cout<<"Factorial of: " <<n<< "is " <<factorial;

    //cout << "Hello world!" << endl;
    return 0;
}
