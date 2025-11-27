#include<iostream>
#include<set>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	set <int> s;
	cin >> a >> b;
	for (int k = 0; k < b; k++)
	{
		int m, n;
		cin >> m >> n;
		for (int i = m; i <= n; i++)
		{
			s.insert(i);
		}
	}
	cout << ((a + 1) - (s.size()));
	return 0;
}
