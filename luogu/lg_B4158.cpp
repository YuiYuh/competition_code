#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int is_prime(int x){
	if(x < 2) return false;
	if(x == 2 || x == 3) return true;
	if(x % 2 == 0 || x % 3 == 0) return false;
		
	for(int i = 5; i <= sqrt(x); i += 6){
		if(x % i == 0 || x % (i + 2) == 0){
			return false;
		}
	}
	return true;
}

int dfs(int pos){
	if(pos == s.size()){
		int val = stoi(s);
		return is_prime(val) ? val : -1;
	}
	
	if(isdigit(s[pos])) return dfs(pos + 1);
	else{
		for(int i = 0; i <= 9; ++ i){
			s[pos] = i + '0';
			int res = dfs(pos + 1);
			if(res != -1) return res;
			s[pos] = '*';
		}
	}
	return -1;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	cin >> n;
	while(n--){

		cin >> s;
		cout << dfs(0) << endl;
	}
	
	return 0; 
} 
