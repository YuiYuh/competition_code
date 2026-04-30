#include<bits/stdc++.h>
using namespace std;

int op1, op2, op3;
string s;
bool can_expand(char a, char b) {
    bool both_digit = isdigit(a) && isdigit(b);
    bool both_lower = islower(a) && islower(b);
    return (both_digit || both_lower) && a < b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> op1 >> op2 >> op3 >> s;
	
	size_t pos = s.find("-");
	string temp;
	while(pos != string::npos){
		char pre = s[pos - 1];
		char next = s[pos + 1];
		
		if (!can_expand(pre, next)) {
    		pos = s.find("-", pos + 1);
    		continue;
		}
		
		temp = "";
		
		int minus = next - pre;
		if(minus == 1){
			s.erase(pos, 1);
		}else if(minus > 1){
			s.erase(pos, 1);
			
			if(op1 == 3){				
				for(int i = pre + 1; i < next; ++ i){
					for(int j = 1; j <= op2; ++ j){
						temp += "*";
					}
				}
				s.insert(pos, temp);
			}else if(op1 == 1){
				for(int i = pre + 1; i < next; ++ i){
					for(int j = 1; j <= op2; ++ j){
						temp += char(i);
					}
				}
				if(op3 == 2){
					reverse(temp.begin(), temp.end());
				}
				s.insert(pos, temp);
			}else if(op1 == 2){
				for(int i = pre + 1; i < next; ++ i){
					for(int j = 1; j <= op2; ++ j){
						temp += toupper(char(i));
					}
				}
				if(op3 == 2){
					reverse(temp.begin(), temp.end());
				}
				s.insert(pos, temp);
			}
		}
		pos = s.find("-", pos + 1);
	}
	cout << s << endl; 
	return 0;
}
