#include<bits/stdc++.h>
using namespace std;

const long long A = 10120300500;

void write(__int128 x){
	if(x == 0){
		cout << 0;
		return ;
	}
	string s;
	while(x > 0){
		int digit = x % 10;
		s.push_back(digit + '0');
		x /= 10;
	}
	reverse(s.begin(), s.end());
	cout << s;
} 

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    __int128 ans = 0;
	long long M = A * 2;
	
	for(long long p = 1; p * p <= M; ++ p){
		if(M % p != 0) continue;
		long long q = M / p;
		if((p + q) % 2 != 0) continue;
		__int128 x = ((__int128)p + q) / 2;
		__int128 n = x * x - A;
		ans += n;
		
	}	
	
    write(ans);
    
    return 0;
}
