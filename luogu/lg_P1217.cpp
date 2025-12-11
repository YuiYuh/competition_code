////#include<bits/stdc++.h>
////using namespace std;
////int main(){
////	ios::sync_with_stdio(false);
////	cin.tie(nullptr);
////	int a,b;
////	cin >> a >> b;
////	vector<int>v;
////	for(int i = a; i <= b; i++){
////		for(int j = 2; j <= i * 0.5; j++){
////			if(i % j != 0){
////				v.push_back(i);
////				break;
////			}
////		}
////	}
////	for(int e : v){
////		int x = e;
////		int rev = 0;
////		while(x > 0){
////			rev = rev * 10 + x % 10;
////			x /= 10;
////		}
////		if(rev == e)
////			cout << e << endl;
////	}
////	return 0;
////}
//#include<bits/stdc++.h>
//using namespace std;
//bool isPrime(int x){
//	if(x < 2) return false;
//	for(int i = 2; i*i<=x;i++){
//		if(x % i == 0)
//			return false;
//	}
//	return true;
//}
//bool isPalindrome(int x){
//	int t = x;
//	int rev = 0;
//	while(t > 0){
//		rev = rev * 10 + t % 10;
//		t /= 10;
//	}
//	return rev == x;
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int a,b;
//	cin >> a >> b;
//	for(int i = a; i <= b; i++){
//		if(isPrime(i)&&isPalindrome(i))
//		cout << i << '\n';
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x){
	if(x < 2) return false;
	if(x % 2 == 0) return x == 2;
	for(int i = 3; 1LL * i * i <= x;i++){
		if(x % i == 0) return false;
	}
	return true;
}
int makePa(int x, bool odd){
	int res = x;
	if(odd) x /= 10;
	while(x > 0){
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	cin >> a >> b;
    vector<int> ans;
	int maxLen = 0;
	for(int t = b; t > 0; t/= 10) maxLen++;
	if(a <= 11 && 11 <= b && isPrime(11)){
		ans.push_back(11);
	} 
	for(int len = 1; len <= maxLen; len++){
		if((len&1)==0) continue;
		int halfLen = (len + 1) / 2;
		int start = 1;
		for(int i = 1; i < halfLen; ++i) start *= 10;
        int end = start * 10;
		for(int prefix = start; prefix < end; ++prefix){
			if((prefix / start) % 2==0) continue;
			int x = makePa(prefix,true);
			if(x < a||x>b) continue;
			if(isPrime(x)){
				ans.push_back(x);
			}
		}
		
	}
    sort(ans.begin(),ans.end());
    for(int e : ans) cout << e << '\n';
	return 0;
}







 

