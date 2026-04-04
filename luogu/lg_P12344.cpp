#include<bits/stdc++.h>
using namespace std;




int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	string s;
	cin >> s;
	char ch = 'a';
	for(int i = 0; i < s.size(); ++ i){
		ch = max(ch, s[i]);
	}
	for(int i = 0; i < s.size(); ++ i){
		if(s[i] == ch) cout << ch;
	}
	
	
	return 0;
}
