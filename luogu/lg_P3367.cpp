#include<bits/stdc++.h>
using namespace std;


const int MAXN = 2e5 + 5;

int fa[MAXN];
int n, m;

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}


void merge(int x, int y){
	int rootX = find(x);
    int rootY = find(y);

    if(rootX != rootY){
        fa[rootX] = rootY;
    }
}

char is_together(int x, int y){
	if(find(x) == find(y)){
        return 'Y';
    }else{
        return 'N';
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		fa[i] = i;
	}
	
	for(int i = 1; i <= m; ++ i){
		int z, x, y;
		cin >> z >> x >> y;
		if(z == 1){
			merge(x, y);
		}else if(z == 2){
			cout << is_together(x, y) << '\n';
		}
	}
	return 0;
}
