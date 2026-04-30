#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
typedef pair<int,int> PII;
long long n, s;
PII a[MAXN];
long long ans, cnt;

bool cmp(const PII &a, const PII &b){
	return a.second < b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> s;
	long long sum_s = 0;
	int max_n = 0;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i].first >> a[i].second;
		sum_s += a[i].first;
		max_n = max(a[i].second, max_n); // 4
	}
	
	sort(a + 1, a + n + 1, cmp);//(3,2)(5,2)(2,4)
	
	for(int i = 1; i <= n; ++ i){
		if(a[i].second <= cnt){
			sum_s -= a[i].first;
			continue;
		}
		
		if(sum_s >= s){
			long long num = a[i].second - cnt;
			ans += num * s;
			cnt += num;
		}else{
			ans += (long long)(a[i].second - cnt) * a[i].first;
		}
		sum_s -= a[i].first;
	}
	cout << ans; 
	
	return 0;
} 
