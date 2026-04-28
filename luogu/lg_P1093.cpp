#include<bits/stdc++.h>
using namespace std;

struct students{
	int id,chinese, math, english,sum;
};

bool cmp(const students &a, const students &b){
	if(a.sum != b.sum) return a.sum > b.sum;
	if(a.chinese != b.chinese) return a.chinese > b.chinese;
	return a.id < b.id;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	vector<students> v;
	for(int i = 1; i <= t; ++ i){
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({i,x,y,z,(x+y+z)});
	}
	
	sort(v.begin(), v.end(),cmp);
	for(int i = 0; i < v.size() && i < 5; ++ i){
		cout << v[i].id << " " << v[i].sum << endl;
	}
	
	return 0;
} 
