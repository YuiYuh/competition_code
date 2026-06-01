#include<bits/stdc++.h>
using namespace std;

const int MAXW = 40005;
long long dp[MAXW];

struct Item{
	int v, w;
};
vector<Item> items;
int n, W;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> W;
	for(int i = 1; i <= n; ++ i){
		int v, w, m;
		cin >> v >> w >> m;
		
		
		int k = 1;
		while(m >= k){
			items.push_back({v * k, w * k});
			m -= k;
			k *= 2;
		}
		if(m > 0){
			items.push_back({v * m, w * m});
		}
		
	}
	
	for(int i = 0; i < items.size(); ++ i){
		for(int j = W; j >= items[i].w; -- j){
			dp[j] = max(dp[j], dp[j - items[i].w] + items[i].v);
		}
	}
	cout << dp[W] << endl;
	return 0;
}
