#include<bits/stdc++.h>
using namespace std;

int n;
int a[70];
bool vis[70];
int total_sum = 0;
int max_val = 0;
int target_len;
bool dfs(int completed, int left_len, int start_idx) {
    
    // 【终点线】如果拼好的根数 正好等于 总长/目标长，说明全部断木棍完美用完！
    if (completed == total_sum / target_len) {
        return true;
    }

    // 【阶段性胜利】当前这根木棍刚好填满了，开始拼下一根
    if (left_len == 0) {
        // 拼完一根，completed+1；新木棍还差 target_len；下一根依然从最长的断木棍(下标0)开始挑
        return dfs(completed + 1, target_len, 0);
    }

    // 从 start_idx 开始向后遍历每一根断木棍
    for (int i = start_idx; i < n; i++) {
        
        // 剪枝点 1：如果这根木棍用过了，或者它比当前需要的长度还要长，直接跳过
        if (vis[i] || a[i] > left_len) continue;

        // 尝试使用这根木棍
        vis[i] = true;
        
        // 带着更新后的“还差多少长度(left_len - a[i])”进入下一层搜
        // 下一根断木棍从 i + 1 开始找，避免回头重复选择
        if (dfs(completed, left_len - a[i], i + 1)) {
            return true; // 如果后面一路成功了，直接向上返回 true
        }
        
        // --- 如果走到这里，说明刚才选 a[i] 导致后面失败了，触发回溯，把它重新吐出来 ---
        vis[i] = false; 

        // 【剪枝点 2】：就是你刚刚参悟出来的绝招！
        // 如果 left_len == target_len，说明 a[i] 是作为当前这根新木棍的“第一根大骨干”放进去的。
        // 第一根大骨干拼下去都失败了，后面换更小的也绝对不可能成功，直接判定 target_len 方案完蛋！
        if (left_len == target_len) {
            return false;
        }

        // 【剪枝点 3】：刚好填满却在后面失败了
        // 如果 a[i] 刚好能把当前木棍填满（left_len == a[i]），但后续的木棍拼失败了。
        // 说明用这么刚好的木棍都凑不齐后面，换成几个更碎的短木棍去填这个空，只会让后面更难拼，直接返回失败。
        if (left_len == a[i]) {
            return false;
        }

        // 【剪枝点 4】：跳过相同长度的木棍
        // 如果当前长度为 a[i] 的木棍不合适被吐出来了，那么紧随其后、长度相同的木棍也一定不合适，直接用循环跳过。
        while (i + 1 < n && a[i] == a[i + 1]) {
            i++;
        }
    }

    return false; // 所有的断木棍都试过了，实在拼不出来
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];         // 累加总长度
        max_val = max(max_val, a[i]); // 记录单根最长长度
    }
	sort(a, a + n, greater<int>());
	for(int target_len = max_val; target_len <= total_sum; target_len++){
		if (total_sum % target_len != 0) continue;
		fill(vis, vis + n, false);
		if (dfs(0, target_len, 0)){
            // 因为 target_len 是从小到大枚举的，第一个成功的就是【最小可能长度】
            cout << target_len << "\n";
            return 0; 
        }
	}
	
	return 0;
}
