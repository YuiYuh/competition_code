#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	deque <int> qMin;
	deque <int> qMax;
	int a[1000005];
	cin >> n >> k;
	for(int i = 0; i < n ; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		while(!qMin.empty() && a[qMin.back()]>=a[i]){
			qMin.pop_back();
		}
		qMin.push_back(i);
		if(qMin.front() <= i-k){
			qMin.pop_front();
		}
		if(i >= k-1){
			cout << a[qMin.front()] << " ";
		}
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		while(!qMax.empty() && a[qMax.back()] <= a[i]){
			qMax.pop_back();
		}
		qMax.push_back(i);
		if(qMax.front() <= i-k){
			qMax.pop_front();
		}
		if(i >= k-1){
			cout << a[qMax.front()]<< " ";
		}
	}
}
