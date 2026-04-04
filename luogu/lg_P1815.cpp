#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[55][55];

void solve(deque<pair<int,int>> dq){
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++ i){
		char d = s[i];
		//处理尾巴 
		vis[dq.back().first][dq.back().second] = false;
		dq.pop_back();
		//看看头 
		if(d == 'E'){
			if(dq.front().second + 1 > 50){
				cout << "The worm ran off the board on move " << (i + 1) << '.' << endl;
				return ;
			}else if(vis[dq.front().first][dq.front().second + 1]){
				cout << "The worm ran into itself on move " << (i + 1) << '.' << endl;
				return ;
			} 
			dq.push_front({dq.front().first,dq.front().second + 1});
			vis[dq.front().first][dq.front().second] = true;
		}
		if(d == 'S'){
			if(dq.front().first + 1> 50){
				cout << "The worm ran off the board on move " << (i + 1) << '.' << endl;
				return ;
			}else if(vis[dq.front().first + 1][dq.front().second]){
				cout << "The worm ran into itself on move " << (i + 1) << '.' << endl;
				return ;
			} 
			dq.push_front({dq.front().first + 1,dq.front().second});
			vis[dq.front().first][dq.front().second] = true;
		}
		if(d == 'W'){
			if(dq.front().second - 1 < 1){
				cout << "The worm ran off the board on move " << (i + 1) << '.' << endl;
				return ;
			}else if(vis[dq.front().first][dq.front().second - 1]){
				cout << "The worm ran into itself on move " << (i + 1) << '.' << endl;
				return ;
			} 
			dq.push_front({dq.front().first,dq.front().second - 1});
			vis[dq.front().first][dq.front().second] = true;
		}
		if(d == 'N'){
			if(dq.front().first - 1 < 1){
				cout << "The worm ran off the board on move " << (i + 1) << '.' << endl;
				return ;
			}else if(vis[dq.front().first - 1][dq.front().second]){
				cout << "The worm ran into itself on move " << (i + 1) << '.' << endl;
				return ;
			} 
			dq.push_front({dq.front().first - 1,dq.front().second});
			vis[dq.front().first][dq.front().second] = true;
		}
		//没撞 走完了
		if(i == (n - 1)){
			cout <<  "The worm successfully made all " << n << " moves." << endl;
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	
	while(1){
		cin >> n;
		if(n == 0) break;
		
		memset(vis, false, sizeof vis);
		deque<pair<int,int>> dq;
		for(int i = 30; i >= 11; -- i){
			dq.push_back({25,i});
			vis[25][i] = true;
		}
		
		solve(dq);
	}
	return 0;
}
