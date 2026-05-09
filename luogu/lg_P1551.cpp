#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
int fa[N];
int n, m, p;

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	int rootx = find(x);
	int rooty = find(y);
	
	if(rootx != rooty){
		fa[rootx] = rooty;
	}
}

string is_rela(int x, int y){
	return find(x) == find(y) ? "Yes" : "No";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	
	cin >> n >> m >> p;
	
	for(int i = 1; i <= n; ++ i){
		fa[i] = i;
	}
	
	for(int i = 1; i <= m; ++ i){
		int x, y;
		cin >> x >> y;
		merge(x, y);	
	}
	
	for(int i = 1; i <= p; ++ i){
		int x, y;
		cin >> x >> y;
		cout << is_rela(x, y) << '\n';
	}
	

	return 0;
}
