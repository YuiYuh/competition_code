#include<bits/stdc++.h>
using namespace std;

int cnt;

int main(){
	
	for(int year = 2240; year <= 9876; year ++){
		for(int month = 1; month <= 12; month ++){
			for(int date = 1; date <= 31; date ++){
				if(year % 4 == 0|| year % 100 == 0){
					if(month == 2 && date >= 30) continue;
				}else{
					if(month == 2 && date >= 29) continue;
				}
				int arr[20] = {0};
				string s = "";
				s += year + '0';
				s += month + '0';
				s += date + '0';//224011
				for(int i = 0; i <s.size(); ++i){
					arr[s[i] - '0']++;// 0 1 2 3 4 5 6 7 8 9
				}                     // 1 2 2 0 1 0 0 0 0 0
				bool res = true;
				int max_num = -1;
				for(int i = 0; i <= 9; ++ i){
					max_num = max(max_num, arr[i]);//2
				}
				for(int i = 0; i <= 9; ++ i){
					if(arr[i] < max_num){
						res = false;
					}
				}
				if(res) cnt++;
			}
		}
	}
	cout << cnt;
	return 0;	
}
 
