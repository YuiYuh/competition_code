#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
vector<int> g1;
vector<int> g2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int temp;
    while(cin >> temp){
        auto it1 = upper_bound(g1.begin(), g1.end(), temp, greater<int>());
        if(it1 == g1.end()){
            g1.push_back(temp);
        }else{
            *it1 = temp;
        }

        auto it2 = lower_bound(g2.begin(), g2.end(), temp);
        if(it2 == g2.end()){
            g2.push_back(temp);
        }else{
            *it2 = temp;
        }
    }

    cout << g1.size() << '\n';
    cout << g2.size() << '\n';

    return 0;
}