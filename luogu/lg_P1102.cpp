//#include<bits/stdc++.h> 
//using namespace std;
//
//typedef long long LL;
//const int MAXN = 2e5 + 10;
//
//map<LL,LL> mp;
//LL arr[MAXN];
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	LL n,c;
//	cin >> n >> c;
//	for(int i = 1; i <= n; ++i){
//		cin >> arr[i];
//		mp[arr[i]]++;
//	}
//	LL ans = 0;
//	for(int i = 1; i <= n; ++i){
//		ans += mp[a[i] + c];
//	}
//	cout << ans << endl;
//	return 0;
//} 
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 2e5 + 10;
LL arr[MAXN];
LL ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	int N, C;
	cin >> N >> C;
	 for(int i = 0; i < N; ++ i){
	 	cin >> arr[i];
	 }
	
	sort(arr, arr + N);
	int l = 0, r = 0; 
//	for(int i = 0; i < N; ++ i){
//		LL target = arr[i] + C;
//		auto it1 = lower_bound(arr, arr + N, target);
//		auto it2 = upper_bound(arr, arr + N, target);
//		ans += it2 - it1;
//	}
//	cout << ans << endl;

	for(int i = 0; i < N; ++ i){
		LL target = arr[i] + C;
		while (l < N && arr[l] < target) {
            l++;
        }
        while (r < N && arr[r] <= target) {
            r++;
        }
        ans += (r - l);
	}


	cout << ans << endl;



	return 0;
}
