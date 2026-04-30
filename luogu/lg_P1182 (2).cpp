#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
long long arr[MAXN];
int n, m;
long long l, r, ans; 

bool check(long long mid){
	int cnt = 1;
	long long current_sum = 0;
	for(int i = 1; i <= n; ++ i){
		current_sum += arr[i];
		if(current_sum > mid){
			cnt++;
			current_sum = arr[i];
		}
	}
	return cnt <= m;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
		l = max(arr[i], l);
		r += arr[i];
	}
	while(l <= r){
		long long mid = (r - l) / 2 + l;
		
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
} 
