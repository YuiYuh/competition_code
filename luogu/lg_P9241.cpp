#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int MAXN = 15;
int t[MAXN], d[MAXN], l[MAXN];
bool vis[MAXN];
bool found;
int n;

void dfs(int cnt, int last_time){
    if(found) return ;
    if(cnt == n){
        found = true;
        return ;
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            int start_time = max(last_time, t[i]);
            if(start_time <= t[i] + d[i]){
                vis[i] = true;
                dfs(cnt + 1, start_time + l[i]);
                vis[i] = false;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> t[i] >> d[i] >> l[i];
        }
        found = false;
        memset(vis, false, sizeof(vis));

        dfs(0,0);

        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}