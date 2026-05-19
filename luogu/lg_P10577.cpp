#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct Rabbit{
	long long pos;
	int id;
};
int n;
Rabbit a[MAXN];
int to[MAXN];
long long final_pos[MAXN];
long long ans[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i].pos;
		a[i].id = i;
	}
	
	sort(a + 1, a + n + 1, [](const Rabbit& x, const Rabbit& y){
		return x.pos < y.pos;
	});
	
	for(int i = 1; i <= n; ++ i){
		if(i == 1){
			to[i] = i + 1;
		}else if(i == n){
			to[i] = i - 1;
		}else{
			long long left_dist = a[i].pos - a[i - 1].pos;
			long long right_dist = a[i + 1].pos - a[i].pos;
			if(left_dist <= right_dist){
				to[i] = i - 1;
			}else{
				to[i] = i + 1;
			}
		}
	}
	
	for(int i = 1; i <= n; ++ i){
		final_pos[i] = -1;
	}
	for(int i = 1; i <= n; ++ i){
		if(final_pos[i] != -1) continue;
		vector<int> path;
		int cur = i;
		
		while(final_pos[cur] == -1){
			path.push_back(cur);
			int nxt = to[cur];
			if(to[nxt] == cur){
				long long meet = (a[cur].pos + a[nxt].pos) / 2;
				final_pos[cur] = meet;
				final_pos[nxt] = meet;
				break;
			}
			cur = nxt;
		}
		long long meet = final_pos[cur];
		for(int x : path){
			final_pos[x] = meet;
		}
	}
		for(int i = 1; i <= n; ++i){
        	int original_id = a[i].id;
        	ans[original_id] = final_pos[i];
    	}
		for(int i = 1; i <= n; ++i){
        	cout << ans[i];

       		if(i < n) cout << ' ';
    	}

    	
	
	cout << '\n';
	return 0;
}
