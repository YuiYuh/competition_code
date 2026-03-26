//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//int arr[MAXN];
//int n, Q;
//
//int find(int x){
//	for(int i = 1; i <= n; ++i){
//		if(arr[i] == x)
//			return i;
//	}
//	return 0;
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	
//
//	cin >> n;
//	for(int i = 1; i <= n; ++i){
//		cin >> arr[i];
//	}
//	cin >> Q;
//	while(Q--){
//		int x;
//		cin >> x;
//		cout << find(x) << endl;
//	}
//	
//	return 0;
//}标准TLE的过程

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val, id;
};

bool cmp(const Node& a, const Node& b){
	return a.val < b.val;
}

Node arr[100005];
int n, Q;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> arr[i].val; 
		arr[i].id = i;
	}
	
	sort(arr + 1, arr + 1 + n, cmp);
	
	cin >> Q;
	while(Q--){
		int x;
		cin >> x;
		
		int l = 1, r = n, ans = 0;
		 
		while(l <= r){
			int mid = l + ((r - l) >> 1);
			if(arr[mid].val == x){
				ans = arr[mid].id;
				break;
			}
			if(arr[mid].val < x) l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << endl;
	}
	
	return 0;
}






















 
