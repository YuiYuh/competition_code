#include<bits/stdc++.h>
using namespace std;

int first_pos[7];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	int n;
	cin >> n;
	
	for(int i = 0; i < 7; i++){
		first_pos[i] = -1;
	}
	first_pos[0] = 0;
	
	long long current_rem = 0;
	int max_length = 0;
	
	for(int i = 1; i <= n; ++i){
		long long cow_id;
		cin >> cow_id;
		
		current_rem = (current_rem + cow_id) % 7;
		
		if(first_pos[current_rem] == -1){
			first_pos[current_rem] = i;
		}else{
			max_length = max(max_length, i - first_pos[current_rem]);
		}
	}
	
	cout << max_length << endl;
	
	return 0;
}
