#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool isAlphabet(const string &s) {
    if (s.empty()) return false;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
            return false;
    }
    return true;
}

bool isDigit(const string s) {
    if (s.empty())
        return false;

    for (int i = 0; i < s.length(); ++i) {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

bool isAlphanumeric(const string s) {
    if (s.empty()) return false;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))
            return false;
    }
    return true;
}

bool isIdentifier(const string s) {
    if (s.empty()) return false;

    char first = s[0];
    if (!((first >= 'A' && first <= 'Z') || first == '_' || (first >= 'a' && first <= 'z') ))
        return false;

    for (int i = 1; i < s.length(); ++i) {
        char c = s[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))
            return false;
    }

    return true;
}

bool isKeyword (const string s){
    if (s.empty()) return false;
    string keywords[]={"int", "char","float","double","bool","void","long","short","if","else","switch","case","const","static","default","for","while","do","break","try","catch", "class","private","protect","public","throw", "using"};

    for ( string kw : keywords) {
        if (s == kw)
            return true;
    }
    return false;
}

bool isStringLiteral(const string &s) {
    return s.length() >= 2 && s.front() == '"' && s.back() == '"';
}

bool isOperator (const string s){
    if (s.empty()) return false;
    string operators[]={"+","<<",">>",">","<","-","*","/","%","++","--","==","!=",">=","<=","||","!","=","+=","-=","*=","/=","%="};

    for ( string op : operators) {
        if (s == op)
            return true;
    }
    return false;
}

bool isPreprocessor(const string &s)
{
    return !s.empty() && s[0] == '#';
}

bool isRealConstant(const string &s) {
    if (s.empty()) return false;

    bool hasDigits = false;
    bool hasDot = false;
    int start = 0;

    if (s[0] == '+' || s[0] == '-') start = 1;
    for (int i= start; i<s.length(); ++i) {
        char c = s[i];
        if (isdigit(c)) {
            hasDigits = true;}
        else if (c == '.')
        {
            if (hasDot) return false;
            hasDot = true;
        }
        else {
            return false;
        }
    }
     return hasDigits;
    /*if (!hasDot) return false;
    if (s == "." || s == "+." || s == "-.") return false;

    return true;*/
}


bool isConstant(const string s) {
    if (s.empty()) return false;

    int dotCount = 0;
    int start = 0;

    if (s[0] == '+' || s[0] == '-')
        start = 1;
    for (int i = start; i < s.length(); ++i) {
            char c= s[i];
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) return false;
        }
        else if (!(c >= '0' && c <= '9')) {
            return false;
        }
    }
    return true;
}

bool isPunctuation(const string s)
{
    string punc = ";,.(){}[]:?";

    if (s.length()!= 1)
        return false;

    for (int i = 0; i < punc.length(); ++i) {
        if (s[0] == punc[i])
            return true;
    }

    return false;
}

bool isDelimiter(const string &s) {
    string delimiters[] = { ";", ",", "(", ")", "{", "}", "[", "]" };
    for (string d : delimiters) {
        if (s == d)
            return true;
    }
    return false;
}



int main() {

    string input;
    cout << "Enter a string: "<< endl;
    //cin >> input;
    getline(cin, input);

    string spacedInput;
    string strLiteral;

    for (size_t i = 0; i < input.size(); ++i) {
    char c = input[i];

    if (c== '"'){
        spacedInput += ' ';
        strLiteral += c;
        ++i;
    while (i<input.size() && input[i] !='"') {
            strLiteral += input[i];
            ++i;
        }
        if (i < input.size()) {
            strLiteral += '"';
        }
        spacedInput += ' ';}

    else if (ispunct(c) && c != '"') {
        spacedInput += ' ';
        spacedInput += c;
        spacedInput += ' ';
    }
    else if (isdigit(c) || (c == '.' && i+1 < input.size() && isdigit(input[i+1]))) {
        while (i < input.size() && (isdigit(input[i]) || input[i] == '.')) {
            spacedInput += input[i];
            ++i;
        }
        --i;
    }
    else if ((c == '-' || c == '+') && (i == 0 || isspace(input[i-1]) || ispunct(input[i-1]))) {
        spacedInput += ' ';
        spacedInput += c;
        spacedInput += ' ';}


    else {
        spacedInput += c;
    }
    }

    stringstream ss(spacedInput);
    string token;


    if (!input.empty() && input[0] == '#')
    {
    string token = input;
    cout << "Preprocessor Directive" << endl;
    return 0;
    }

     while (ss >> token)
    {
    if (isPreprocessor(token))
        cout << token << ": Preprocessor Directive" << endl;
    if (isKeyword(token))
        cout << token << ": Valid Keyword" << endl;

    else if (isIdentifier(token))
        cout << token << ": Valid Identifier" << endl;
    else if (isOperator(token))
        cout << token << ": Valid Operator" << endl;
    else if (isRealConstant(token))
        cout << token << ": Valid Real Constant" << endl;
    else if (isConstant(token))
        cout << token << ": Valid Constant" << endl;

    /*else if (!isIdentifier(token) && isAlphanumeric(token)) {
    cout << token << ": Invalid Identifier" << endl;}*/

    else if (isStringLiteral(token))
        cout << token << ": Valid String Literal" << endl;
    else if (isDelimiter(token))
    cout << token << ": Valid Delimiter" << endl;
    else if (isPunctuation(token))
    cout << token << ": Valid Punctuation" << endl;
    else if (isAlphabet(token))
        cout << token << ": Valid Alphabet" << endl;
    else if (isDigit(token))
        cout << token << ": Valid Digit" << endl;

    else cout<< token << ": Invalid entry"<<endl;
     }

    return 0;
}
