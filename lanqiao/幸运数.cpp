#include<bits/stdc++.h>
using namespace std;


long long ans;

int main(){
	
	struct Range{
		int start, end, d;
	};
	
	vector<Range> ranges = {
		{10, 99, 10},
		{1000, 9999, 100},
		{100000, 999999, 1000},
		{10000000, 99999999, 10000}
	};
	
	for(auto& r : ranges){
		for(int i = r.start; i <= r.end; ++ i){
			if(i / r.d == i % r.d){
				ans++;
			}
		}
	} 
	cout << ans;
	return 0;
}
