#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt[100005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	ll ans = 0;
	ll rem = 0;
	cnt[0] = 1;
	
	for(int i = 1; i <= n; ++ i){
		
		int a;
		cin >> a;
		
		rem = (rem + a) % k;
		
		ans += cnt[rem];
		cnt[rem] ++;
		
	}
	cout << ans << endl;
	
	return 0;
}
