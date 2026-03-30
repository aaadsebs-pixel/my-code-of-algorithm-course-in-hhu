#include <vector>
#include <iostream>
using namespace std;
int main() {
    vector<int> student;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        student.push_back(a);
    }
    for(int i=0;i<m;i++) {
        int x;
        cin>>x;
        cout<<student[x-1]<<endl;
    }
return 0;
}