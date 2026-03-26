#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	int Q;
	cin >> Q;
	while(Q--){
		int op;
		cin >> op;
		switch(op){
			case 1:{
				string name;
				int score;
				cin >> name >> score;
				mp[name] = score;
				cout << "OK" << endl;
				break;
			}
			case 2:{
				string name;
				cin >> name;
				if(mp.count(name)){
					cout << mp[name] << endl;
				}else{
					cout << "Not found" << endl; 
				}
				break;
			}
			case 3:{
				string name;
				cin >> name;
				auto it = mp.find(name);
				if(it == mp.end()){
					cout << "Not found" << endl;
				}else{
					mp.erase(it);
					cout << "Deleted successfully" << endl;
				}
				break;
			}
			case 4:
				cout << mp.size() << endl;
		}
	}
	
	
	
	return 0;
}
