// Step A：读入 n
// Step B：读入三角形 a（可以用二维数组或 vector）
// Step C：准备 dp（用一维 vector dp(n+2)）
// Step D：初始化 dp 为最后一行
// Step E：从 i = n-1 到 1
// 	•	内层 j = 1 到 i
// 	•	dp[j] = a[i][j] + max(dp[j], dp[j+1])
// Step F：输出 dp[1]

#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<long long>> a(n + 1, vector<long long>(n + 1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }
    vector<long long> dp(n + 2, 0);
    for(int j = 1; j <= n; j++){
        dp[j] = a[n][j];
    }
    for(int i = n - 1; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            dp[j] = a[i][j] + max(dp[j],dp[j + 1]);
        }
    }
    cout << dp[1] << '\n';
    return 0;
}//改个名字
