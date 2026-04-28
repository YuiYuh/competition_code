#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 500005;
ll a[MAXN];

void solve() {
    int n;
    ll k;
    if (!(cin >> n >> k)) return;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    // 特判：如果操作次数多到可以把宝石变到只剩一个值
    if (k >= n - 1) {
        cout << 0 << "\n";
        return;
    }

    ll min_diff = -1;

    // 枚举左端点跨过的个数 i
    for (int i = 0; i <= k; i++) {
        // 根据公式 min(2*i + j, i + 2*j) <= k 反推最大可能的 j
        ll j1 = k - 2 * i;
        ll j2 = (k - i) / 2;
        ll j = max(j1, j2);

        if (j < 0) j = 0;
        
        // 确保 i 和 j 的总和不会把数组删空
        if (i + j >= n) j = n - i - 1;

        int left_idx = i;
        int right_idx = n - 1 - (int)j;

        if (left_idx <= right_idx) {
            ll curr_diff = a[right_idx] - a[left_idx];
            if (min_diff == -1 || curr_diff < min_diff) {
                min_diff = curr_diff;
            }
        }
    }

    cout << min_diff << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
