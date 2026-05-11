#include<bits/stdc++.h>
using namespace std;

//const int MAXN = 1e8 + 5;
//bool is_composite[MAXN];
//int prime[MAXN];
//int cnt;
//
//void get_prime(int n){
//	for(int i = 2; i <= n; ++ i){
//		if(!is_composite[i]){
//			prime[++cnt] = i;
//		}
//		for(int j = 1; j <= cnt && prime[j] <= n / i; ++ j){
//			is_composite[i * prime[j]] = true; 
//			if(i % prime[j] == 0){
//            	break;
//			}	
//		}
//	}
//}

const int MAXN = 1e8 + 5;
bool st[MAXN];
int prime[MAXN];
int cnt;

void get_prime(int n){
	for(int i = 1; i <= n; ++ i){
		if(!st[i]){
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt && prime[j] <= n / i; ++ j){
			st[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

void gett_prime(int n){
	for(int i = 2; i <= n; ++ i){
		if(!st[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt && prime[j] <= n / i; ++ j){
			st[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
} 



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	get_prime(n);
	while(q--){
		int temp;
		cin >> temp;
		cout << prime[temp] << '\n';
	}
	
	
	return 0;
}
