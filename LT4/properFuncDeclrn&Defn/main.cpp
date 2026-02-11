#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool isIdentifier(const string &s) {
    if (s.empty()) return false;
    if (!(isalpha(s[0]) || s[0] == '_')) return false;
    for (size_t i = 1; i < s.length(); ++i)
        if (!isalnum(s[i])) return false;
    return true;
}

bool isType(const string s)
{
    const string types[] = {"int","char","float","double","bool","void","long","short"};
    for (int i = 0; i < 9; i++)
        if (s == types[i]) return true;
    return false;
}

bool isNumber(string s)
{
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-') i = 1;
    for (; i < s.length(); ++i)
        if (!isdigit(s[i])) return false;
    return true;
}

bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

string trim(string s) {
    int start=0, end=(int)s.size()-1;
    while(start<=end && isSpace(s[start])) start++;
    while(end>=start && isSpace(s[end])) end--;
    if(start>end) return "";
    return s.substr(start,end-start+1);
}

string removeComment(string s) {
    for(int i=0;i<(int)s.size()-1;i++)
        if(s[i]=='/' && s[i+1]=='/') return s.substr(0,i);
    return s;
}

int tokenize(const string &input, string tokens[], int maxTokens) {
    string spaced;
    for (int i = 0; i < (int)input.length(); i++) {
        char c = input[i];
        if (c == '(' || c == ')' || c == ',' || c == ';' || c == '=' || c == '{' || c == '}') {
            spaced += ' ';
            spaced += c;
            spaced += ' ';
        } else {
            spaced += c;
        }
    }

    stringstream ss(spaced);
    string token;
    int count = 0;
    while (ss >> token && count < maxTokens) {
        tokens[count++] = token;
    }
    return count;
}

bool isVariableDeclaration(string tokens[], int n) {
    if (n < 3) return false;
    if (!isType(tokens[0])) return false;
    if (!isIdentifier(tokens[1])) return false;
    if (n == 3 && tokens[2] == ";") return true;
    if (n == 5 && tokens[2] == "=" && (isNumber(tokens[3]) || isIdentifier(tokens[3])) && tokens[4] == ";") return true;
    return false;
}

bool isFunctionDeclaration(string tokens[], int n) {
    if (n < 4) return false;
    if (!isType(tokens[0])) return false;
    if (!isIdentifier(tokens[1])) return false;
    if (tokens[2] != "(") return false;

    int i = 3;
    while (i < n && tokens[i] != ")") {
        if (!isType(tokens[i]) && !isIdentifier(tokens[i]) && tokens[i] != ",") return false;
        i++;
    }
    if (i >= n || tokens[i] != ")") return false;

    return (i + 1 < n && tokens[i + 1] == ";");
}

bool isFunctionDefinition(string tokens[], int n) {
    if (n < 4) return false;
    if (!isType(tokens[0])) return false;
    if (!isIdentifier(tokens[1])) return false;
    if (tokens[2] != "(") return false;

    int i = 3;
    while (i < n && tokens[i] != ")") {
        if (!isType(tokens[i]) && !isIdentifier(tokens[i]) && tokens[i] != ",") return false;
        i++;
    }
    if (i >= n || tokens[i] != ")") return false;
    return (i + 1 < n && tokens[i + 1] == "{");
}

int main() {
    ifstream file("Texttest.txt");
    if (!file.is_open()) {
        cout << "Unable to open file!" << endl;
        return 0;
    }

    string line, statement;
    const int maxTokens = 100;
    bool inFunctionBody = false;

    while (getline(file, line)) {
        line = removeComment(line);
        line = trim(line);
        if (line.empty()) continue;

        statement += " " + line;
        statement = trim(statement);

    if (inFunctionBody) {
    bool foundClosingBrace = false;
    for (int i = 0; i < (int)line.length(); i++) {
        if (line[i] == '}') {
            foundClosingBrace = true;
            break;
        }
    }

    if (foundClosingBrace) {
        cout << statement << " is Valid Function Definition" << endl;
        statement = "";
        cout << endl;
        inFunctionBody = false;
    }
    continue;
}
        if (!statement.empty()) {
            string tokens[maxTokens];
            int n = tokenize(statement, tokens, maxTokens);

            if (n == 0) {
                statement = "";
                continue;
            }

            if (isVariableDeclaration(tokens, n)) {
                cout << statement << " is Valid Variable Declaration/Definition" << endl;
                statement = "";
                cout<<endl;
            }
            else if (isFunctionDeclaration(tokens, n)) {
                cout << statement << " is Valid Function Declaration" << endl;
                statement = "";
                cout<<endl;
            }
            else if (isFunctionDefinition(tokens, n)) {
                inFunctionBody = true;
            }
            else {

    int len = (int)statement.length();
    int start = 0;
    bool allValid = true;

    for (int i = 0; i < len; i++) {
        if (statement[i] == ';') {
            string part = trim(statement.substr(start, i - start + 1));
            string tokensPart[maxTokens];
            int n = tokenize(part, tokensPart, maxTokens);

            bool isValid = false;

            if (isVariableDeclaration(tokensPart, n))
                isValid = true;
            else if (n >= 2 && tokensPart[0] == "return" && tokensPart[n - 1] == ";")
                isValid = true;
            else
                isValid = false;

            if (!isValid) {
                allValid = false;
                break;
            }

            start = i + 1;
        }
    }

    if (len > 0 && statement[len - 1] != ';' && statement[len - 1] != '}')
        allValid = false;

    if (allValid && len > 0)
        cout << statement << " is Valid Function Definition" << endl << endl;
    else
        cout << statement << " is Invalid Declaration/Definition" << endl << endl;

    statement = "";
}

        }
    }

    file.close();
    return 0;
}
