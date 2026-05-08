#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e4 + 5;
const int MAXM = 28;
long long dp[MAXN];
int w[MAXM], v[MAXM];
//long long sum;
int n, m;

//struct object{
//	int cost;
//	int importance;
//	bool operator < (const object& other) const {
//		if(importance != other.importance){
//			return importance < other.importance;
//		}if(importance == other.importance){
//			return cost < other.cost;
//		}
//	}
//};


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; ++ i){
		int a, b;
		cin >> a >> b;
		w[i] = a;
		v[i] = a * b; 
	}
	
//	sort(a + 1, a + m + 1);
	
	for(int i = 1; i <= m; ++ i){
		for(int j = n; j >= w[i]; -- j){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}
