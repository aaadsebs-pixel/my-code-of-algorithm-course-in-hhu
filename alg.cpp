#include <stack>
#include <string>
#include <iostream>
using namespace std;
char tans(char c) {
    if(c=='(') return ')';
    if(c=='[') return ']';
    if(c=='{') return '}';
    return ' ';
}
int main() {
     stack<char>bracket;
    int n;
    cin>>n;
    string line;
    cin.ignore();
    while(getline(cin,line)) {
        while(!bracket.empty())  bracket.pop();
        for(int k=0; k<line.size(); k++){
            if (bracket.empty()) {
                bracket.push(line[k]);
            }
            else if (line[k]==tans(bracket.top())) {
                bracket.pop();
            }
            else {
                bracket.push(line[k]);
            }
        }
        if(bracket.empty()) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
return 0;
}