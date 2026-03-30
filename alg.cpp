#include <map>
#include <string>
#include <iostream>
using namespace std;
int main() {
    map<string, int> ds;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op,num;
        string name;
        cin >> op;
        if (op == 1) {
            cin>>name>>num;
            ds[name] = num;
            if (ds.find(name)!=ds.end()) cout <<"ok"<<endl;
        }
        else if (op == 2) {
            cin>>name;
            if (ds.find(name)!=ds.end()) cout <<ds[name]<<endl;
            else cout <<"Not found"<<endl;
        }
        else if (op == 3) {
            cin>>name;
            if (ds.find(name)!=ds.end()) {
                ds.erase(name);
                cout <<"Deleted successfully"<<endl;
            }
            else cout <<"Not found"<<endl;
        }
        else if (op == 4) {
            cout <<ds.size()<<endl;
        }
    }
    return 0;
}
