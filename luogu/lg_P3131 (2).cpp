#include<bits/stdc++.h>
using namespace std;

const int MAXN = 50005;
int arr[MAXN];
long long pre[MAXN];
int first[10];
int last[10]; 
int n;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	memset(first, -1, sizeof first);
//	memset(last, -1, sizeof last);
	first[0] = 0;
//	last[0] = 0;
	
	
	for(int i = 1; i <= n; ++ i){
		cin >> arr[i];
		pre[i] = (pre[i - 1] + arr[i]) % 7;
		if(first[pre[i]] == -1){
			first[pre[i]] = i;
		}
		last[pre[i]] = i;
	}
	int ans = 0;
	for(int i = 0; i <= 6; ++ i){
		ans = max(ans, last[i] - first[i]);
	}
	cout << ans << endl;
	return 0;
}
