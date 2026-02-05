//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//void solve(){
//	ll n,k;
//	cin >> n >> k;
//	
//	int flipCount = 0;
//	
//	while(n > 1){
//		if(k % 2 == 0){
//			flipCount++;
//		}
//		k = (k + 1) / 2;
//		n--;
//	}
//	
//	if(flipCount % 2 == 0){
//		cout << "RED" << '\n';
//	}else{
//		cout << "BLACK" << '\n';
//	}
//	
//}
//
//
//int main()
//{
//  // 请在此输入您的代码
//  ios::sync_with_stdio(false);
//  cin.tie(0);
//  
//  int m;
//  cin >> m;
//  while(m--){
//  	solve();
//  }
//  
//  return 0;
//}
//
#include<bits/stdc++.h>
using namespace std;

int main(){
	int m;
	cin >> m;
	while(m--){
		long long n,k;
		cin >> n >> k;
		
		int ones = __builtin_popcountll(k - 1);
		if(ones % 2 == 0) cout << "RED" << endl;
		else cout << "BLACK" << endl;
	}
	
	return 0;
}









