#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,a,b;
    cin >> n;
    vector<int>v(n);
    vector<int>p(n);
    int presum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        presum += v[i];
        p[i] = presum;
    }

    while(cin >> a >> b){
        int sum = 0;
        if(a == 0) sum = p[b];
        else sum = p[b] - p[a-1];
        cout << sum << endl;
    }


    return 0;
}
