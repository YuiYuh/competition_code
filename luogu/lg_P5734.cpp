#include<bits/stdc++.h>
using namespace std;

int q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> q;
	string s;
	cin >> s;
	while(q--){
		int op;
		cin >> op;
		switch(op){
			case 1:{
				string temp;
				cin >> temp;
				s += temp;
				cout << s << endl;
				break;
			}
			case 2:{
				int a, b;
				cin >> a >> b;
				s = s.substr(a, b);
				cout << s << endl;
				break;
			}
			case 3:{
				int a;
				string temp;
				cin >> a >> temp;
				s.insert(a, temp);
				cout << s << endl;
				break;
			}
			case 4:{
				string temp;
				cin >> temp;
				size_t pos = s.find(temp);
				if(pos == string::npos){
					cout << -1 << endl;
				}else{
					cout << pos << endl;
				}
				break;
			}
			default:
				cout << "Error input!" << endl;
		}
	}
	
	return 0;
}
