#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5 + 10;
int arr[MAXN];
int n, k;

bool check(int len){
	if(len == 0) return true;
	int cnt = 0;
	for(int i = 1; i <= n; ++ i){
		cnt += arr[i] / len;
		if(cnt >= k) return true;
	}
	return cnt >= k;
} 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	

	cin >> n >> k;
	int max_l = 0;

	
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
		max_l = max(max_l, arr[i]);
	}
	
	int l = 1, r = max_l;
	int ans = 0;
	
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}
