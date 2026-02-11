#include <iostream>

using namespace std;

int main()
{
    string fname, lname;

    cout<<"Enter first name: ";
    cin>>fname;
    cout<<endl;

    cout<<"Enter last name: ";
    cin>>lname;

    string name = fname.substr(0,2) + lname.substr(0,2);
    cout<<name;
    //cout << "Hello world!" << endl;
    return 0;
}
