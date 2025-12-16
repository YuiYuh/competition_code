#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> r(n);
    r[0] = 0;
    for(int i = 1; i <= n; i++){
        r[i] = v[i - 1] + r[i - 1];
    }
    cin >> m;
    while(m--){
        int x,y,res;
        cin >> x >> y;
        res = r[y] - r[x - 1];
        cout << res << endl;
    }
    
    return 0;
}