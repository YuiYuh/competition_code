#include <bits/stdc++.h>
using namespace std;

bool isContinuous(int v1, int v2, int v3){
	int arr[3] = {v1, v2, v3};
	sort(arr, arr + 3);
	return (arr[1] == arr[0] + 1 && arr[2] == arr[1] + 1);
} 

int main()
{
  // 请在此输入您的代码
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	for(int i = 0; i < n; ++i) cin >> c[i];
	
	int m = 0;
	cin >> m;
	
	long long totalScore = 0;
	int p1 = 0, p2 = 0, p3 = 0;
	
	while(m--){
		int x1, x2, x3;
		cin >> x1 >> x2 >> x3;
		
		p1 = (p1 + x1) % n;
		p2 = (p2 + x2) % n;
		p3 = (p3 + x3) % n;
		
		int v1 = a[p1], v2 = b[p2], v3 = c[p3];
		
		if((v1 == v2 && v2 == v3) || v2 == v1 + 1 && v3 == v2 + 1){
			totalScore += 200;
		}
		else if((v1 == v2 || v2 == v3 || v1 == v3) || isContinuous(v1,v2,v3))
			totalScore += 100;
}
	
	cout << totalScore;
  return 0;
}




