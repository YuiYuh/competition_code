#include<bits/stdc++.h>
#define int long long
using namespace std;


const int MAXN = 1e5 + 10;
int a[MAXN];
int b[MAXN];
int n;
double p;

bool check(double T){
	double total_needed = 0;
	for (int i = 1; i <= n; i++) {
        if (a[i] * T > b[i]) {
            total_needed += (a[i] * T - b[i]);
        }
    }
    return total_needed <= p * T;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int sum_a = 0;
	cin >> n >> p;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i] >> b[i];
		sum_a += a[i];
	}
	if(sum_a <= p){
		cout << -1 << endl;
		return 0;
	}
	
	double l = 0, r = 1e10;
	for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if (check(mid)) {
            l = mid; 
        } else {
            r = mid; 
        }
    }
	cout << fixed << setprecision(10) << l << endl;
	return 0;
}
