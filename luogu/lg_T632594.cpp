#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
long long w[MAXN];
long long a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k;
	long long m;
	cin >> n >> m >> k;
	for(int i = 1; i <n; ++i){
		cin >> w[i];//lufei  i -> i + 1
	}
	for(int i = 1; i <= n; ++i){
		cin >> a[i];// kuang i
	}
	
	priority_queue<long long, vector<long long>,greater<long long>> pq;
	long long sum_road = 0;
	long long sum_k = 0;
	long long ans = 0;
	
	
	for(int i = 1; i <= n; ++i){
		if(i > 1){
			sum_road += w[i - 1];
		} 
		
		if(sum_road > m) break;
		
		pq.push(a[i]);
		sum_k += a[i];
		
		if(pq.size() > k){
			sum_k -= pq.top();
			pq.pop();
		}
		long long last = m - sum_road;
		
		ans = max(ans, min(sum_k, last));
		
		
		
	}
	cout << ans << endl;
	return 0;
}














