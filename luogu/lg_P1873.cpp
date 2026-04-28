#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int arr[MAXN];
int n, m, ans;

bool check(int x){
	long long sum = 0;
	for(int i = 1; i <= n; ++ i){
		if(arr[i] > x){
			sum += (arr[i] - x);
		}
	}
	return sum >= m;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	int max_height = -1;
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
		max_height = max(max_height, arr[i]);
	}
	int l = 0, r = max_height;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
