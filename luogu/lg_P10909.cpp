#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int MAXN = 100005;
int n, m;
int a[MAXN];


bool check(int L){
	int total_normal_needed = 0;
	int max_save = 0;
	for(int i = 1; i <= n; ++ i){
		int d = a[i] - a[i - 1];
		
		int normal_need = (d + L - 1) / L - 1;
		if(normal_need < 0) normal_need = 0;
		int skill_need = 0;
		if(d > 2 * L){
			skill_need = (d - 2 * L + L - 1) / L;
		}else{
			skill_need = 0;
		}
		total_normal_needed += normal_need;
		int current_save = normal_need - skill_need;
		if (current_save > max_save) {
            max_save = current_save;
        }
	}
	return (total_normal_needed - max_save) <= m;
}



signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i];
	} 
	int l = 1, r = 1e8;
	int ans = 1e8;
	
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
} 
