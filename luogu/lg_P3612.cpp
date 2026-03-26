#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int arr[MAXN];
long long q[MAXN];
int n;

void get_pre(){
	for(int i = 1; i <= n; ++i){
		q[i] = q[i - 1] + arr[i];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> arr[i];
	}
	get_pre();
	
	int t;
	cin >> t;
	while(t--){
		int l, r;
		cin >> l >> r;
		
		int ans = q[r] - q[l - 1];
		cout << ans << endl;
		
	}
	
	return 0;
} 
