#include<bits/stdc++.h>
using namespace std;

int n, x, temp;
long long ans;
long long sum;
long long now;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> x;
	for(int i = 1; i <= n; ++ i){
		cin >> temp;
		sum += temp;//累计和 
		now += x - temp;//增益  
		ans = max(ans, now);//累计增益 
		if(now < 0) now = 0; //重新开始一个区间 
	}
	cout << ans + sum << endl;//累计和加增益为答案 
	
	return 0;
}
