#include <queue>
#include <iostream>
using namespace std;
int main() {
     queue<int> student;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n+1;i++) {
        student.push(i);
    }
    int count=0;
    int current;
    while(!student.empty()) {
        current=student.front();
        student.pop();
        count++;
        if(count%m) {
            student.push(current);
        }
        else {
            cout <<current<< " ";
        }
    }
return 0;
}