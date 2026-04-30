#include<bits/stdc++.h>
using namespace std;

const int MAXN = 11;
char op[] = {' ', '+', '-'};
int n;

bool check(string s){
	vector<long long> nums;
	vector<char> symbols;
	
	long long current_num = 0;
	for(int i = 0; i < s.size(); ++ i){
		if(isdigit(s[i])){
			current_num = current_num * 10 + (s[i] - '0');
		}else if(s[i] != ' '){
			nums.push_back(current_num);
			current_num = 0;
			symbols.push_back(s[i]);
		}
	}
	nums.push_back(current_num);
	long long ans = nums[0];
	for(int i = 0; i < symbols.size(); ++i){
		if(symbols[i] == '+'){
			ans += nums[i + 1];
		}else{
			ans -= nums[i + 1];
		}
	}
	return ans == 0;
} 



void dfs(int step, string path){
	if(step == n + 1){
		if(check(path)){
			cout << path << endl;
		}
		return ;
	}
	
	for(int i = 0; i < 3; ++ i){
		dfs(step + 1, path + op[i] + char(step + '0'));
	}
	
	
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	cin >> n;
	dfs(2, "1");
	
	return 0;
}

