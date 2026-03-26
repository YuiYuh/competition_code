#include<bits/stdc++.h>
using namespace std;

int n;
long long s[15], b[15];
long long min_diff = 2e18;

void dfs(int x, long long sour, long long bitter, int count){
	if(x == n){
		if(count > 0){
			min_diff = min(min_diff, abs(sour - bitter));
		}
		return ;
	}
	
	dfs(x + 1, sour, bitter, count);
	dfs(x + 1, sour * s[x], bitter + b[x], count + 1);
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> s[i] >> b[i];
	}
	dfs(0, 1, 0, 0);
	cout << min_diff << endl; 
	return 0; 
} 
