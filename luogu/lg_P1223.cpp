#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
using namespace std;
bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        mp[i + 1] = tmp;
    }
    vector<pair<int,int>> v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),cmp);
    vector<int> v1;
    for(auto &p : v){
        cout << p.first << ' ';
        v1.push_back(p.second);
    }
    double sum = 0.0;
    vector<int> v2(n);
    v2[0] = 0;
    for(int i = 1; i < n; i++){
        v2[i] = v2[i - 1]+ v1[i - 1];
    }
    for(int i = 0; i < n; i++){
        sum += v2[i];
    }
    sum = sum / n;
    cout << '\n' << fixed << setprecision(2) << sum;
    return 0;
}