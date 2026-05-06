#include<bits/stdc++.h>
using namespace std;

const int N = 5;
int mp[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string start; 
string target = "123804765";


int bfs(){
	queue<string> q;
	unordered_map<string, int> dist;
	q.push(start);
	dist[start] = 0;
	while(!q.empty()){
		string cur = q.front();
		q.pop();
		
		if(cur == target){
			return dist[cur];
		}
		int pos = cur.find('0');
		
		int x = pos / 3;
		int y = pos % 3;
		for(int i = 0; i < 4; ++ i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3){
				continue;
			}
			int new_pos = nx * 3 + ny;
			string next = cur;
			swap(next[pos], next[new_pos]);
			if(!dist.count(next)){
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> start;
	cout << bfs() << endl;
	
	return 0;
}
