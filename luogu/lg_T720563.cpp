#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans;

int main(){
	ll date1 = 789456;
	ll date2 = 654321;
	int cnt1 = 901234;
	int cnt2 = 500001;
	while(cnt1){         // 901234
		if(date1 < date2){
			ans += cnt2;
			cnt1--;
			date1 += 567890;
		}else{
			cnt2--;
			date2 += 876543;
		}
	}
	cout << ans;
}
