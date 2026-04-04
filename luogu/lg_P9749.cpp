#include<bits/stdc++.h>
using namespace std;

int n, d;
const int MAXN = 1e5 + 10;
int w[MAXN];
long long ans;

// 1  2  3  4  5
// 10 20 30 40
// 9  8  9  6  5


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> d;
	int min_p = 0x3f3f3f3f;
	int cur_dist = 0; 
	
	for(int i = 1; i < n; ++ i){
		cin >> w[i];
	}
	
	for(int i = 1; i < n; ++ i){
		int youjia, num;
		cin >> youjia;
		min_p = min(youjia, min_p);
		
		if(cur_dist < w[i]){
			int dist = w[i] - cur_dist;
			num = (dist + d - 1) / d;
			ans += num * min_p;
			cur_dist += num * d; 
		} 
		
		cur_dist -= w[i];
	}
	
	cout << ans << endl;
	
	
	return 0;
}
