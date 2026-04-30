#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e3 + 10;
int arr[MAXN];
int pre[MAXN];
vector<int> e[MAXN];
multiset<int> s;
int n, ans = LLONG_MAX;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	
	for(int l = 1; l <= n; ++ l){
		for(int r = l; r <= n; ++ r){
			int sum = pre[r] - pre[l - 1];
			e[r].push_back(sum);
		} 
	}
	
	for(int l2 = 1; l2 <= n; ++ l2){
		for(auto val : e[l2 - 1]){
			s.insert(val);
		}
		for(int r2 = l2; r2 <= n; ++ r2){
			int sum2 = pre[r2] - pre[l2 - 1];
			
			if(s.empty()) continue;
			
			auto it = s.lower_bound(sum2);
			
			if(it != s.end()){
				ans = min(ans, abs(*it -sum2));
			}
			if(it != s.begin()){
				auto it_prev = prev(it);
				ans = min(ans, abs(*it_prev - sum2));
			}
			
			
		}
	}
	cout << ans << endl;
	return 0;
}
