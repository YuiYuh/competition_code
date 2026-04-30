#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	if(n == 1){
		cout << -1 << endl;
		return ;
	}
	if(n == 2){
		cout << 1 << endl;
		return ;
	}
	if(n == 3){
		cout << 7 << endl;
		return ;
	}
	if (n == 4) { cout << 4 << endl; return; }
    if (n == 5) { cout << 2 << endl; return; }
    if (n == 6) { cout << 6 << endl; return; }
    if (n == 7) { cout << 8 << endl; return; }
    if (n == 8) { cout << 10 << endl; return; }
    if (n == 9) { cout << 18 << endl; return; }
    if (n == 10) { cout << 22 << endl; return; }
    if (n == 11) { cout << 20 << endl; return; }
    if (n == 12) { cout << 28 << endl; return; }
    if (n == 13) { cout << 68 << endl; return; }
    if (n == 14) { cout << 88 << endl; return; }
    
    int num_8 = n / 7;
    int rem = n % 7;
    
    if(rem == 0){
    	for(int i = 0; i < num_8; ++ i) cout << '8'; 
	}else if(rem == 1){
		cout << "10";
		for(int i = 0; i < num_8 - 1; ++i) cout << '8';
	}else if(rem == 2){
		cout << '1';
		for(int i = 0; i < num_8; ++i) cout << '8';
	}else if(rem == 3){
		cout << "200";
		for(int i = 0; i < num_8 - 2; ++i) cout << '8';
	}else if(rem == 4){
		cout << "20";
		for(int i = 0; i < num_8 - 1; ++i) cout << '8';
	}else if(rem == 5){
		cout << '2';
		for(int i = 0; i < num_8; ++i) cout << '8';
	}else if(rem == 6){
		cout << '6';
		for(int i = 0; i < num_8; ++i) cout << '8';
	}
	cout << '\n';
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}
