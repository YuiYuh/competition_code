#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, S, T;
double a[N];   // 存原始每个元素的价值指数
double b[N];   // 存减去猜测平均值后的“净价值”
double sum[N]; // 存“净价值”的前缀和

// 这个 check 函数用来验证：在当前的考核标准 mid 下，能否找到一段合法长短的净价值区间和 >= 0
bool check(double mid) {
    // 1. 【核心转化】：每个人都扣掉标准 mid，算出净价值，并求前缀和
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - mid;
        sum[i] = sum[i - 1] + b[i]; // 净价值的前缀和
    }

    // 2. 【寻找最大区间和】：
    // 当右端点是 R 时，合法的左端点 j (即 L-1) 范围是 [R - T, R - S]
    // 我们的目标是让 sum[R] - sum[j] 尽量大（最好 >= 0），也就是让 sum[j] 尽量小
    
    // 在考场上，为了最稳妥、防写错，我们可以用双端队列（deque）来当做一个“滚动的菜市场”
    // 这个队列里面存的是下标 j，它帮我们盯着窗口 [R-T, R-S] 里的历史最低价（sum[j]的最小值）
    deque<int> q; 

    for (int R = S; R <= n; R++) {
        // 新合格的左端点 j 进入窗口候选区
        int new_j = R - S;
        
        // 维护单调性：新来的人 new_j 如果比队尾的人还要便宜（sum[new_j] <= sum[q.back()]）
        // 那队尾的人永远没有出头之日了，直接踢出队列
        while (!q.empty() && sum[q.back()] >= sum[new_j]) {
            q.pop_back();
        }
        q.push_back(new_j); // 把新来的合格人选塞进队尾

        // 剔除过期人员：如果队头的人已经太老了，出了左边界（小于 R - T），强行踢走
        while (!q.empty() && q.front() < R - T) {
            q.pop_front();
        }

        // 此时，队头 q.front() 就是我们千挑万选出来的 [R-T, R-S] 范围内让 sum[j] 最小的那个人
        int best_j = q.front();

        // 如果最棒的 sum[R] - 最小的 sum[best_j] 成功打破了 0 的底线
        // 说明我们猜的这个平均标准 mid 完全合格！
        if (sum[R] - sum[best_j] >= 0) {
            return true; 
        }
    }
    
    // 找遍了所有的右端点 R，都无法让净价值总和 >= 0，说明这个标准 mid 定得太高了
    return false;
}

int main() {
    // 关流加速：国赛 1e5 数据量，必须加
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> S >> T;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 3. 【实数二分答案】
    // 题目说价值指数在 -10000 到 10000 之间，所以平均值也一定在这个范围内
    double l = -10000.0, r = 10000.0;
    
    // 技巧：实数二分不要写 while(l <= r)，因为浮点数有精度误差，容易死循环
    // 直接暴力循环 60 次，精度就足以达到 10 的负十几次方，稳稳通过
    for (int iter = 0; iter < 60; iter++) {
        double mid = (l + r) / 2.0;
        
        if (check(mid)) {
            l = mid; // 既然能达到标准 mid，说明答案可能更大，往右半边找
        } else {
            r = mid; // 达不到标准 mid，说明猜太高了，往左半边收缩
        }
    }

    // 4. 精准保留 3 位小数输出
    cout << fixed << setprecision(3) << l << "\n";

    return 0;
}
