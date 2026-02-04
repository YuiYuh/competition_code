#include <iostream>
using namespace std;
bool isPrime(int x){
    if (x <= 1) return false;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin,s);
    int maxn = 0;
    int minn = 100;
    int cnt[26] = {0};
    for(char c : s) cnt[c - 'a']++;
    for(int i = 0; i < 26; i++){
        if(cnt[i] > 0){
            maxn = max(maxn,cnt[i]);
            minn = min(minn,cnt[i]);
        }
    }
    int a = maxn - minn;
    if(isPrime(a)){
        cout << "Lucky Word\n" << a << '\n';
    }else{
        cout << "No Answer\n" << a << '\n';
    }
    return 0;
}