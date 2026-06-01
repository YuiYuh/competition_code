#include<bits/stdc++.h>
using namespace std;

string target = "123804765";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s = "";
unordered_map<string, int> dist;
unordered_map<string, int> vis;

int bfs(){
	if(s == target) return 0; 
	queue<string> q;
	q.push(s);
	q.push(target);
	dist[target] = 0;
	dist[s] = 0;
	vis[target] = 1;
	vis[s] = 2;
	
	while(!q.empty()){
		string curr = q.front();
		q.pop();
		int pos = curr.find("0");
		int x = pos / 3;
		int y = pos % 3;
		
		for(int i = 0; i < 4; ++ i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
			
			string temp = curr;
			swap(temp[pos], temp[(nx*3+ny)]);
			if(vis.count(temp)){
				if(vis[temp] != vis[curr]){
					return dist[temp] + dist[curr] + 1;
				}
				continue;
			}
			dist[temp] = dist[curr] + 1;
			vis[temp] = vis[curr];
			q.push(temp);
		}
		
	}
	
	return -1;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> s;
	
	cout << bfs() << '\n';
	
	return 0;
}
