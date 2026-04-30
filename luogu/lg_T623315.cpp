#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;
int arr[MAXN];
int n, x;

void f(){
	bool res = true;
	for(int i = 1; i < n; ++i){
		int j = i + 1;
		int abs = arr[j] - arr[i];
		if(abs >= 0){
			if(abs > 1){
				res = false;
				break;
			}
		}else{
			if((abs * -1) > x){
				res = false;
				break;
			}
		}
	}
	if(res){
		cout << "Win" << endl;
	}else cout << "Lose" << endl;
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> x;
		for(int i = 1; i <= n; ++i) cin >> arr[i];
		f();
		
	}
	
	return 0;
}//114512 114514 114514 

