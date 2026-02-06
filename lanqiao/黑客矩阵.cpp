#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 500005;
typedef long long ll;

ll fact[MAXN], invFact[MAXN];
int cnt[MAXN];

ll qpow(ll a,ll b){
	ll res = 1;
	a %= MOD;
	while(b > 0){
		if(b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void initMath(int n){
	fact[0] = 1;
	for(int i = 1; i <= n; i++){
		fact[i] =  fact[i - 1] * i % MOD; 
	}
	invFact[n] = qpow(fact[n], MOD - 2);
	for(int i = n - 1; i >= 0; i--){
		invFact[i] = invFact[i + 1] * (i + 1) % MOD;
	}	
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int totalNum;
	if(!(cin >> totalNum)) return 0;
	
	int matrixSize = totalNum - 2;
	int maxVal = 0;
	
	for(int i = 0; i < totalNum; i++){
		int x;
		cin >> x;
		cnt[x]++;
		maxVal = max(maxVal,x);
	}
	
	initMath(max(totalNum,maxVal));
	
	ll denominatorInv = 1;
	for(int i = 0; i < MAXN; i++){
		if(cnt[i] > 0){
			denominatorInv = denominatorInv * invFact[cnt[i]] % MOD;
		}
	}
	
	ll baseC = fact[matrixSize] * denominatorInv % MOD;
	ll totalAns = 0;
	
	for(ll n = 1; n * n <= matrixSize; n++){
		if(matrixSize % n == 0){
			ll m = matrixSize / n;
			if(n == m){
				if(cnt[n] >= 2){
					ll ways = baseC * cnt[n] % MOD * (cnt[n] - 1) % MOD;
					totalAns = (totalAns + ways) % MOD;
				}
				}else{
					if (n < MAXN && m < MAXN && cnt[n] >= 1 && cnt[m] >= 1) {
                    // 数学结论：方案数 = baseC * f1 * f2
                    ll ways = baseC * cnt[n] % MOD * cnt[m] % MOD;
                    // 因为 (n,m) 和 (m,n) 是两种不同的原矩阵形状，所以乘 2
                    totalAns = (totalAns + ways * 2) % MOD;
				}		
			}
		}
	}
	cout << totalAns << endl;

	return 0;
}
