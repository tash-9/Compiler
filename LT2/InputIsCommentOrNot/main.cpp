#include <iostream>
#include <string>

using namespace std;

int main()
{
    string code;
    cout<<"Enter a code: ";
    //cin>>code;
    getline(cin, code);
    //cout<<endl;



    if( (code[0]=='/') && (code[1]=='*'&& code.find("*/")!= -1))
        cout<< "multiple line comment";
    else if ((code[0]=='/')&& (code[1]=='/'))
        cout<< "single line comment";
    else cout<<"Not a comment";

    //cout << "Hello world!" << endl;
    return 0;
}
