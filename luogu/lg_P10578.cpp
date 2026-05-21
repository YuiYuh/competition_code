#include<bits/stdc++.h>
using namespace std;


int T;
string target = "123456789";
unordered_map<string, int> dist_map;

int pos[4][4] = {
    {0, 1, 3, 4},
    {1, 2, 4, 5},
    {3, 4, 6, 7},
    {4, 5, 7, 8}
};

string rotate_cw(string s, int id){
	int a = pos[id][0];
	int b = pos[id][1];
	int c = pos[id][2];
	int d = pos[id][3];
	
	string t = s;
	t[a] = s[b];
	t[b] = s[d];
	t[c] = s[a];
	t[d] = s[c];
	
	return t;
}

void bfs(){
	queue<string> q;
	dist_map[target] = 0;
	q.push(target);
	while(!q.empty()){
		string cur = q.front();
		q.pop();
		for(int i = 0; i < 4; ++ i){
			string nxt = rotate_cw(cur, i);
			if(dist_map.count(nxt)) continue;
			dist_map[nxt] = dist_map[cur] + 1;
			q.push(nxt);
		}
	}
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	bfs();
	cin >> T;
	while(T--){
		string s = "";
		for(int i = 1; i <= 9; ++ i){
			char temp;
			cin >> temp;
			s += temp;
		}
		
		if(s == target){
			cout << 0 << '\n';
			continue;
		}
		cout << dist_map[s] << '\n';
		
	}
	
	
	
	return 0;
} 


//string rotate_cw(string s, int id){
//	  int a = pos[id][0];
//    int b = pos[id][1];
//    int c = pos[id][2];
//    int d = pos[id][3];
//
//    string t = s;
//
//    t[a] = s[b];
//    t[b] = s[d];
//    t[c] = s[a];
//    t[d] = s[c];
//
//    return t;
//} 
//
//
//
//
//
//void bfs(){
//	queue<string> q;
//	dist_map[target] = 0;
//	q.push(target);
//	while(!q.empty()){
//		string cur = q.front();
//		q.pop();
//		for(int i = 0; i < 4; ++ i){
//			string nxt = rotate_cw(cur, i);
//			if(dist_map.count(nxt)) continue;
//			dist_map[nxt] = dist_map[cur] + 1;
//			q.push(nxt);
//		} 
//	}
//	
//}
//

