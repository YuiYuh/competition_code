#include<iostream>
#include<cstring>
using namespace std;

const int N = 205;
int n, a, b;
int q[N * N];
int arr[N];
int d[] = {-1, 1};//上下两种 
int dist[N];


int bfs(){
    memset(dist, -1, sizeof dist);
    if(a == b) return 0;
    q[0] = a;
    dist[a] = 0;
    
    int hh = 0, tt = 0;

    while(hh <= tt){
        int t = q[hh++];
        for(int i = 0; i < 2; ++ i){
            int temp = d[i] * arr[t] + t;
            if(temp >= 1 && temp <= n && dist[temp] == -1){
                if(temp == b){
                    return dist[t] + 1;
                }
                dist[temp] = dist[t] + 1;
                q[++tt] = temp;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++ i){
        cin >> arr[i];
    }

    cout << bfs() << endl;




    return 0;
}