#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int arr[MAXN];
int n, m, x;


int find(){
	int l = 1, r = n;
	int ans = -1;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(arr[mid] >= x){
			if(arr[mid] == x){
				ans = mid;
			}
			r = mid - 1;
		}else{
			l = mid + 1;
		}
		
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
	}
	while(m--){
		cin >> x;
		cout << find() << " ";
	}
	cout << '\n';
	
	return 0;
}
