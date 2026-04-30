#include<bits/stdc++.h>
using namespace std;

void my_to_lower(string &s){
	for(int i = 0; i < s.size(); ++ i){
		s[i] = tolower(s[i]); 
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	string s1, s2;
	cin >> s1;
	my_to_lower(s1);
	vector<string> v;
	cin.ignore();
	getline(cin, s2);
	my_to_lower(s2);
	s1 = " " + s1 + " ";
	s2 = " " + s2 + " ";

	int cnt = 0;
	int first = -1;
	
	size_t pos = s2.find(s1);
	while(pos != string::npos){
		cnt++;
		if(first == -1){
			first = pos;
		}
		pos = s2.find(s1, pos + 1);
	}
	
	if (cnt == 0) {
        cout << -1 << '\n';
    } else {
        cout << cnt << " " << first << '\n';
    }
    
	return 0;
}
