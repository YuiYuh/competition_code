//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 5005;
//const int MAXM = 2e5 + 5;
//
//struct Edge{
//	int u, v, w;
//	bool operator < (Edge &other) const {
//		return w < other.w;
//	}
//};
//
//int fa[MAXN];
//vector<Edge> e;
//
//int find(int x){
//	if(fa[x] == x) return x;
//	return fa[x] = find(fa[x]);
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
//	
//	int n, m;
//	cin >> n >> m;
//	
//	for(int i = 1; i <= n; ++ i){
//		fa[i] = i;
//	}
//	
//	for(int i = 1; i <= m; ++ i){
//		int x, y, z;
//		cin >> x >> y >> z;
//		e.push_back({x,y,z});
//	}
//	
//	sort(e.begin(), e.end());
//	
//	long long sum = 0;
//	int cnt = 0;
//	
//	for(int i = 0; i < e.size(); ++ i){
//		int u = e[i].u;
//		int v = e[i].v;
//		int w = e[i].w;
//		
//		if(find(u) != find(v)){
//			fa[find(u)] = find(v);
//			sum += w;
//			cnt++;
//			if(cnt == n - 1) break;
//		}
//	}
//	if(cnt == n - 1){
//		cout << sum << endl;
//	}else{
//		cout << "orz" << endl;
//	}
//	
//	
//	return 0;
//} 
#include<bits/stdc++.h>
using namespace std;

int fa[5005];

struct Edge{
	int u, v, w;
};

vector<Edge> e;

bool cmp(const Edge& x, const Edge& y){
	return x.w < y.w;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}


int n, m;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++ i){
		fa[i] = i;
	}
	
	for(int i = 1; i <= m; ++ i){
		int x, y, z;
		cin >> x >> y >> z;
		e.push_back({x, y, z});
	}
	
	sort(e.begin(), e.end(), cmp);
	
	long long sum = 0;
	int cnt = 0;
	
	for(int i = 0; i < e.size(); ++ i){
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
		
		if(find(u) != find(v)){
			fa[find(u)] = find(v);
			sum += w;
			cnt ++;
			if(cnt == n - 1) break;
		}
	}
	
	if(cnt == n - 1){
		cout << sum << endl;
	}else{
		cout << "orz" << endl;
	}

	return 0;
}














