#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<double> result;
    for(int i = 0; i < n; i++){
        vector<int> v(m);
        for(int j = 0; j < m; j++){
            cin >> v[j];
        }
            sort(v.begin(),v.end());
            int sum = 0;
            for(int j = 1; j < m - 1; j++){
                sum += v[j];
            }
            double res = 1.0 * sum / (m - 2);
            result.push_back(res);
        
    }
    sort(result.begin(),result.end());
    cout << fixed << setprecision(2) << result.back() << '\n';
    return 0;
}