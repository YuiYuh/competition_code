#include<bits/stdc++.h>
using namespace std;

const int N = 50005;
int l0, n, m;
int arr[N];
//int dist[N];
int ans;

bool check(int x){
	int cnt = 0;
	int last = 0;
	
	for(int i = 1; i <= n + 1; ++ i){
		if(arr[i] - arr[last] < x){
			cnt++;
		}else{
			last = i;
		}
	}
	return cnt <= m;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> l0 >> n >> m;
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
		//dist[i] = arr[i] - arr[i - 1];
		//cout << dist[i] << endl;
	}// 2 9 3 3 4 4
	//dist[n + 1] = l0 - arr[n];
	arr[n + 1] = l0;
	int l = 1, r = l0;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(check(mid)){//mid = 2
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}	
	}
	
	cout << ans << endl;
	return 0;
}
