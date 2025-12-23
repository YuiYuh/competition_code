#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,a,b;
    cin >> i;
    char status;
    string s;
    while(i--){
        getline(cin,s);
        istringstream iss(s);
        string first;
        iss >> first;
        if(isdigit(first[0])){
            a = stoi(first);
            iss >> b;
        }else{
            status = first[0];
            iss >> a >> b;
        }
        string res;
        if(status == 'a'){
            res = to_string(a) + '+' + to_string(b) + '=' + to_string(a + b);
            cout << res << '\n'; 
            cout << res.size() << '\n';
        }else if(status == 'b'){
            res = to_string(a) + '-' + to_string(b) + '=' + to_string(a - b);
            cout << res << '\n';
            cout << res.size() << '\n';
        }else if(status == 'c'){
            res = to_string(a) + '*' + to_string(b) + '=' + to_string(a * b);
            cout << res << '\n';
            cout << res.size() << '\n';
        }
    }
    
    return 0;
}