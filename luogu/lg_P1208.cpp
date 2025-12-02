#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	map <int,int> ma;
	while(m--){
		int x,y;
		cin >> x >> y;
		ma[x] += y;
	}
	int sum = 0;
	long long money = 0;
	for(auto it = ma.begin(); it != ma.end(); it++){
		sum += it->second;
		money += (it->first) * (it->second);
		if(sum >= n){
			int ultra = sum - n;
			money = money - ultra * it->first;
			break;
		}
	}
	cout << money << endl;
	return 0;
}
