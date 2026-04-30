#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;//9e8 + ???

long long power(long long base, long long exp){
	long long res = 1;
	base %= MOD;
	while(exp > 0){
		if(exp & 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}

void f(){
	long long x, y;
	cin >> x >> y;
	
	if(x == 0){
		cout << 0 << endl;
		return ;
	}
	
	if(x <= y + 1){
		cout << x % MOD << '\n';
	}else{
		
		long long s = (y + 1) % MOD;
		long long steps = x - (y + 1);
		long long ans = (s * power(2, steps)) % MOD;
		cout << ans << endl;
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		f();
	}
	
	return 0;
}
