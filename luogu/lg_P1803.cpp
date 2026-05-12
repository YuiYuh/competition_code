#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
struct Node{
	int s, t;
};
int n;
Node a[MAXN];
bool cmp(const Node& a, const Node& b){
	if(a.t != b.t){
		return a.t < b.t;
	}return a.s < b.s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i].s >> a[i].t;
	}
	sort(a + 1, a + 1 + n, cmp);
	
	int ans = 0;
	int last_end = 0;
	
	fpr(int i = 1; i <= n; ++ i){
		if(a[i].s >= last_end){
			ans++;
			last_end = a[i].t;
		}
	}
	cout << ans << endl;
	return 0;
}
