#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
long long a[MAXN];


void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a, a + n);
	if(k >= n - 1){
		cout << 0 << '\n';
		return ;
	}
	
	long long min_diff = LLONG_MAX;
	for(int i = 0; i <= k; ++ i){
		int j = k - i;
		int l = i, r = n - j - 1;
		long long curr_diff = a[r] - a[l];
		
		min_diff = min(curr_diff, min_diff);
	}
	cout << min_diff << '\n';
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}

	return 0;
} 
