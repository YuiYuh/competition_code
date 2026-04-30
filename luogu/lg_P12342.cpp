#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++ i){
		cin >>b[i];
	}
	sort(a.begin(),a.end()),sort(b.begin(),b.end());   
	int cnt = 0;                      // 12 14 22 31
	int i = 0, j = 0;                 //  3 19 27 44
	while(j < n && i < n){
		if(b[j] < a[i]){
		cnt++;
		i++;
		j++;
		}
		if(b[j] >= a[i]){
			i++;
		}
	}
	cout << n - cnt << endl;
	return 0;
}
