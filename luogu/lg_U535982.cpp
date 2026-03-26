#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		int n;
		int cnt1 = 0;
		string s;
		cin >> n >> s;
		for(int i = 0; i < 2 * n; ++ i){
			if(i % 2 == 0){
				if(s[i] == 'A')
					cnt1++;
			}else{
				if(s[i] == 'B')
					cnt1++;
			}
		} 
		int cnt2 = 2 * n - cnt1;
		int ans = min(cnt1,cnt2);
		ans >>= 1; 
		cout << ans << endl; 
	}
	return 0; 
} 
