#include<iostream>
#include<vector>
#include<queue>
using namespace std;


typedef pair<int,int> PII;

int k[205];
int dist[205];
int n, a, b; 

int bfs(){
    queue<PII> q;
    q.push({a, 0});
    dist[a] = 0;

    while(!q.empty()){
        PII curr =  q.front();
        q.pop();

        if(curr.first == b) return curr.second;

        int next_floor[2] = {curr.first + k[curr.first], curr.first - k[curr.first]};

        for(int i = 0; i < 2; ++i){
            int next_f = next_floor[i];
            if(next_f >= 1 && next_f <= n && dist[next_f] == -1){
                dist[next_f] = curr.second + 1;
                q.push({next_f, curr.second + 1});
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b;

    for(int i = 1; i <= n; ++i){
        cin >> k[i];
        dist[i] = -1;
    }

    cout << bfs() << endl;

    return 0;
}