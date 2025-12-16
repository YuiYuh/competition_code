#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    vector<int> a(10);
    for(int i = m; i <= n; i++){
        string s = to_string(i);
        for(int j = 0; j < s.size(); j++){
            a[s[j] - '0']++;
        }
    }
    for(auto p : a){
        cout << p << ' ';
    }
    cout << '\n';
    return 0;
}