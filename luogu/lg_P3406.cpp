#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m; 
long long a[MAXN];
long long d[MAXN];
long long cnt[MAXN];



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++ i){
		cin >> a[i];
	}
	
	for(int i = 1; i + 1 <= m; ++ i){
		int l = min(a[i], a[i + 1]);
		int r = max(a[i], a[i + 1]);
		d[l]++;
		d[r]--;
	}
	for(int i = 1; i <= n; ++ i){
		cnt[i] = cnt[i - 1] + d[i];
	}
	long long ans = 0;
	for(int i = 1; i < n; ++ i){
		long long A, b, c;
		cin >> A >> b >> c;
		long long planA = cnt[i] * A;
		long long planB = c + cnt[i] * b;
		ans += min(planA, planB);
		
	}
	
	cout << ans << endl;
	
	return 0;
}
