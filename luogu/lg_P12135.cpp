#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;
	int last = -1, state = -1;
	for(int i = 0; i < s1.size(); ++ i){
		if(s1[i] == '.' && s2[i] == '.') continue;
		if(state != -1){
			ans += i - last - 1;	
		}
		if(s1[i] == '#' && s2[i] == '#'){
			state = 3;
		}else if(s1[i] == '#' && s2[i] == '.'){//state == 1
			if(state == 2){
				ans++;
				state = 3;
			}else{
				state = 1;
			}
		}else if(s1[i] == '.' && s2[i] == '#'){//state == 2
			if(state == 1){
				ans++;
				state = 3;
			}else{
				state = 2;
			}
		}
	last = i;	
	}
	cout << ans << endl;
	
	
	return 0;
}
