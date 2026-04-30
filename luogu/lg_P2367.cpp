#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e6 + 5;
int arr[MAXN];
int d[MAXN];
int n, p;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> p;
	
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
		d[i] = arr[i] - arr[i - 1];
	}
	
	while(p--){
		int x, y, z;
		cin >> x >> y >> z;
		d[x] += z;
		d[y + 1] -= z;
	}
	
	int min_score = 0x3f3f3f3f;
	int current_score = 0;
	for(int i = 1; i <= n; ++ i){
		current_score += d[i];
		min_score = min(min_score, current_score);
	}
	cout << min_score << endl;
	return 0;
}
