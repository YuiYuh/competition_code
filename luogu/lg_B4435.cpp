#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    unordered_map<string,int> preCnt;
    unordered_map<string,int> surCnt;
    for(int i = 0; i < n; i++){
        int L = s[i].size();
        for(int len = 1; len <= L; ++len){
            preCnt[s[i].substr(0,len)]++;
        }
        for(int len = 1; len <= L; ++len){
            surCnt[s[i].substr(L - len, len)]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int L = s[i].size();
        bool ok = false;
        for(int cut = 1; cut <= L - 1; cut++){
            string p = s[i].substr(0 ,cut);
            string q = s[i].substr(cut);
        
            if(preCnt[p] - 1 > 0 && surCnt[q] - 1 > 0){
                ok = true;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << '\n';
    return 0;
}