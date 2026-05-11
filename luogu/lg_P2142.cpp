#include<bits/stdc++.h>
using namespace std;

bool geq(const string& a, const string& b){
	if(a.size() != b.size()){
		return a.size() > b.size();
	}else{
		return a >= b;
	}
}

string sub(string a, string b){
	string ans;
	
	int i = a.size() - 1;
	int j = b.size() - 1;
	int borrow = 0;
	while(i >= 0 || j >= 0){
		int x = 0;
		int y = 0;
		if(i >= 0){
			x = a[i] - '0';
			i--;
		}
		if(j >= 0){
			y = b[j] - '0';
			j--;
		}
		x -= borrow;
		if(x < y){
			x += 10;
			borrow = 1;
		}else{
			borrow = 0;
		}
		ans += char(x - y + '0');
	}
	
	while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
	reverse(ans.begin(), ans.end());
	return ans;
	
} 


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	string a, b;
	cin >> a >> b;
	if(geq(a, b)){
		cout << sub(a, b) << '\n';
	}else{
		cout << '-' << sub(b, a) << '\n';
	}
	
	
	return 0; 
} 
