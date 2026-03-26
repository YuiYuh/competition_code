#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i){
		ll a, b;
		cin >> a >> b;
		if(a == 1){
			if(s.find(b) != s.end()){
				cout << "Already Exist" << endl;
			}else{
				s.insert(b);
			}
		}else if(a == 2){
			if(s.empty()){
				cout << "Empty" << endl;
				continue;
			}
			auto it = s.find(b);
			if(it != s.end()){
				cout << *it << endl;
				s.erase(it);
			}else{
				auto it2 = s.lower_bound(b);
				if(it2 == s.begin()){
					cout << *it2 << endl;
					s.erase(it2);
				}else if(it2 == s.end()){
					--it2;
					cout << *it2 << endl;
					s.erase(it2);
				}else{
					auto it1 = prev(it2);
					ll lower = b - * it1;
					ll upper = *it2 - b;
					if(lower <= upper){
						cout << *it1 << endl;
						s.erase(it1);
					}else{
						cout << *it2 << endl;
						s.erase(it2);
					} 
				}
			}
		}
	
	}
	
	
	
	
	
	
	
	
	return 0;
} 
