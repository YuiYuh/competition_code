#include <iostream>
#include <vector>
#include<iomanip>
#include<iterator>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<int> v1;
    vector<double> result;
    while(n--){
        while(m--){
            int tem;
            int sum = 0;
            double res = 0;
            cin >> tem;
            v1.push_back(tem);
            for(auto p = next(v1.begin()); p != prev(v1.end()); p++){
                sum += *p;
            }
            res = double(sum) / (m - 2);
            result.push_back(res);
        }
    }
    cout << fixed << setprecision(2) << *(result.end()-1) << '\n';
    return 0;
}