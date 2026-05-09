#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXK = 105;
typedef pair<int, int> PII;
int m, n;
long long dp[MAXN];
vector<PII> arr[MAXK];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> m >> n;
	int max_group = -1; 
	for(int i = 1; i <= n; ++ i){
		int a, b, c;
		cin >> a >> b >> c;
		arr[c].push_back({a, b});
		max_group = max(max_group, c);
	}
	
	for(int g = 1; g <= max_group; ++ g){
		for(int j = m; j >= 0; -- j){
			for(const auto &i : arr[g]){
				if(j >= i.first){
					dp[j] = max(dp[j], dp[j - i.first] + i.second);
				}
			}
		}
	}
	cout << dp[m] << '\n'; 
	return 0;
}
 
