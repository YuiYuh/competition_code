#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n; 
ll x, y, w, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> x >> y >> w;
	
	vector<pair<ll, ll>> r(n);
	for (int i = 0; i < n; ++i) {
        cin >> r[i].first >> r[i].second;
    }
	sort(r.begin(),r.end());
	
	ll rem = 0;
	bool first_trip = true;
	
	for(int i = 0; i < n; ++i){
		ll f = r[i].first;
		ll a = r[i].second;
		
		if(rem > 0 && a > 0){
			ll take = min(rem, a);
			a -= take;
			rem -= take;
		}
		if(a > 0){
			if(first_trip){
				ans += abs(x - f) + (y - f);
				first_trip = false;
				a -= w;
				if(a < 0){
					rem = -a;
					a = 0;
				}else rem = 0;
			}
			
			if(a > 0){
				ll num_trips = (a + w - 1) / w;
				ans += num_trips * 2 * (y - f);
				rem = num_trips * w - a;
			}
			
		}
		
		
	}
	
	cout << ans << endl;
	return 0;
} 
