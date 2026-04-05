#include<bits/stdc++.h>
#define int long long
using namespace std;


const int MAXN = 1e5 + 10;
int n, m, sum, max_val;
int arr[MAXN];

bool check(int len){
	int cnt = 1;
	int current_sum = 0;
	for(int i = 1; i <= n; ++ i){
		if(current_sum + arr[i] <= len){
			current_sum += arr[i];
		}else{
			cnt++;
			current_sum = arr[i];
		}
	} 
	return cnt <= m;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> n >> m; 
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i]; 
		sum += arr[i]; 
		max_val = max(max_val, arr[i]);#include<bits/stdc++.h>
#define int long long
using namespace std;


const int MAXN = 1e5 + 10;
int n, m, sum, max_val;
int arr[MAXN];

bool check(int len){
	int cnt = 1;
	int current_sum = 0;
	for(int i = 1; i <= n; ++ i){
		if(current_sum + arr[i] <= len){
			current_sum += arr[i];
		}else{
			cnt++;
			current_sum = arr[i];
		}
	} 
	return cnt <= m;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> n >> m; 
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i]; 
		sum += arr[i]; 
		max_val = max(max_val, arr[i]);
	}
	
	int l = max_val, r = sum;
	int ans = 0;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
		
	}
	cout << ans << endl;
	return 0;
}#include<bits/stdc++.h>
#define int long long
using namespace std;


const int MAXN = 1e5 + 10;
int n, m, sum, max_val;
int arr[MAXN];

bool check(int len){
	int cnt = 1;
	int current_sum = 0;
	for(int i = 1; i <= n; ++ i){
		if(current_sum + arr[i] <= len){
			current_sum += arr[i];
		}else{
			cnt++;
			current_sum = arr[i];
		}
	} 
	return cnt <= m;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> n >> m; 
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i]; 
		sum += arr[i]; 
		max_val = max(max_val, arr[i]);
	}
	
	int l = max_val, r = sum;
	int ans = 0;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
		
	}
	cout << ans << endl;
	return 0;
}#include<bits/stdc++.h>
#define int long long
using namespace std;


const int MAXN = 1e5 + 10;
int n, m, sum, max_val;
int arr[MAXN];

bool check(int len){
	int cnt = 1;
	int current_sum = 0;
	for(int i = 1; i <= n; ++ i){
		if(current_sum + arr[i] <= len){
			current_sum += arr[i];
		}else{
			cnt++;
			current_sum = arr[i];
		}
	} 
	return cnt <= m;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> n >> m; 
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i]; 
		sum += arr[i]; 
		max_val = max(max_val, arr[i]);
	}
	
	int l = max_val, r = sum;
	int ans = 0;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
		
	}
	cout << ans << endl;
	return 0;
}
	}
	
	int l = max_val, r = sum;
	int ans = 0;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
		
	}
	cout << ans << endl;
	return 0;
}
