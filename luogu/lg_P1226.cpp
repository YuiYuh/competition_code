#include<bits/stdc++.h>
using namespace std;

long long a, b, p;
long long qpow(long long a, long long b, long long p){
	long long ans = 1;
	a %= p;
	
	while(b > 0){
		if(b & 1){
			ans = ans * a % p;
		}
		 a = a * a % p;
		 b >>= 1; 
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long a, b, p;
	cin >> a >> b >> p;
	 
	cout << a << '^' << b << " mod " << p <<'='<<qpow(a,b,p);
	
	
	
	
	return 0;
}

long long qpow(long long a, long long b, long long){
	long long ans = 1;
	a %= p;
	while(b > 0){
		if(b & 1){
			ans = ans * a % p;
		}
		a = a* a % p;
		b >>= 1;
	}
	return ans;
}














