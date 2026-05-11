#include<bits/stdc++.h>
using namespace std;




int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	string a, b;
	cin >> a >> b; 
	string ans = "";
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;
	
	while(i >= 0 || j >= 0 || carry){
		int sum = carry;
		if(i >= 0) sum += a[i--] - '0';
		if(j >= 0) sum += b[j--] - '0';
		ans += char(sum % 10 + '0');
		carry = sum / 10;
	}
	reverse(ans.begin(), ans.end());
	
	cout << ans << '\n';
	
	return 0;
} 
