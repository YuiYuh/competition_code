/* 张宇豪大三最后的算法复习了  来复习一下张宇豪所有学过的算法，
怎么说呢，学了这么久的算法，感觉也没有什么是真的进脑子里的，但是偏偏运气好，进了蓝桥杯国赛
我在算法上面花的时间，堪比我学数学花的时间了，真的值得吗，其实我不认为，我也不认为我有概率拿奖
除非真的运气好到爆棚，当然我也不是一个自暴自弃的人，有这个机会，那我还是要争取一下的，复杂的，数论我肯定是不会的
希望可以多暴力来点分数吧，加油，最后的复习，记清楚模版，然后好好备战考研，我始终相信我自己。*/



//力扣27
int k = 0;
for(int x : nums){
    if(x != val){
        nums[k++] = x;
    }
}
return k;

//力扣977
int l = 0;
int r = nums.size();
while(l <= r){
    if(abs(nums[l]) >= nums[r]){
        res[k++] = num[l] * num[l];
    }else{
        res[k++] = nums[r] * nums[r];
    }
}
reverse(res.begin(),res.end());

//kamacoder 58
for(int i = 1; i <= n; ++ i){
    cin >> arr[i];
    pre[i] = pre[i - 1] + arr[i];
}// 用r - (l - 1);

//洛谷 2005                                    
for(int i = 1; i <= n; ++ i){
    for(int j = 1; j <= m; ++ j){              
        cin >> arr[i][j];
        pre[i][j] = arr[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }
}// s = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];


//洛谷 1605
void dfs(int x, int y){
    if(x == fx && y == fy){
        ans++;
        return ;
    }

    for(int i = 0; i < 4; ++ i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(vis[nx][ny]) continue;
        if(ob[nx][ny]) continue;

        vis[nx][ny] = true;
        dfs(nx, ny);
        vis[nx][ny] = false;
    }
}

//洛谷 1238
typedef pair<int,int> PII;
void dfs(int x, int y){
    if(x == endx && y == endy){
        found = true;
        for(int i = 0; i < path.size(); ++ i){
			cout << "(" << path[i].first << "," << path[i].second << ")" << (i == (int)path.size() - 1 ? "" : "->");
		}
		cout << '\n';
        return ;
    }
    for(int i = 0; i < 4; ++ i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(arr[nx][ny] == 0) continue;
        if(vis[nx][ny]) continue;

        vis[nx][ny] = true;
        path.push_back({nx, ny});
        dfs(nx, ny);
        path.pop_back();
        vis[nx][ny] = false;
    }

}

//洛谷 1443
void bfs(){

    while(hh <= tt){
        PII curr = q[hh++];

        for(int i = 0; i < 8; ++ i){
            int curr.x = x + dx[i];
            int curr.y = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(vis[nx][ny]) continue;
            dist[nx][ny] = dist[curr.x][curr.y] + 1;

            q[++tt] = {nx, ny};
        }
    }
    
    
}

//蓝桥 穿越雷区
int bfs(){
    while(hh <= tt){
        PII curr = q[hh++];
        for(int i = 0; i < 4; ++ i){
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            
            if(nx <= 0 || nx > n || ny <= 0 || ny > n || dist[nx][ny] != -1) continue;
            if(mp[nx][ny] == mp[curr.first][curr.second]) continue;
            if(mp[nx][ny] == 'B'){
                return dist[curr.first][curr.second] + 1;
            }
            dist[nx][ny] = dist[curr.first][curr.second] + 1;
            q[++tt] = {nx, ny};
        }
    }
    return -1;
}

//洛谷 1379
while(!q.empty()){
    string curr = q.front();
    q.pop();
    int pos = curr.find('0');
    int x = pos / 3;
    int y = pos % 3;
    if(curr == target) return dist[curr];
    for(int i = 0; i < 4; ++ i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
        string temp = curr;
        swap(temp[pos], temp[nx * 3 + ny]);
        if(dist.count(temp)) continue;
        dist[temp] = dist[curr] + 1;
        q.push(temp);
    }
}

//leetcode 15
vector<vector<int>> res;
sort(nums.begin(), nums.end());
for(int i = 0; i < nums.size(); ++ i){
    if(nums[i] > 0)
        return res;
    if(i > 0 && nums[i] == nums[i - 1]) continue;

    int left = i + 1;
    int right = nums.size() - 1;

    while(left < right){
        if(nums[i] + nums[left] + nums[right] > 0) right--;
        else if(nums[i] + nums[left] + nums[right] < 0) left++;
        else{
            res.push_back({nums[i], nums[left], nums[right]});
            while(right > left && nums[right] == nums[right - 1]) right--;
            while(left < right && nums[left] == nums[left + 1]) left++;

            right--;
            left++;
        }
    }
}
return res;

//洛谷 1216
for(int i = 1; i <= n; ++ i){
    dp[i] = arr[n][i];
}
for(int i = n - 1; i >= 1; -- i){
    for(int j = 1; j <= i; ++ j){
        dp[j] = max(dp[j],dp[j + 1]) + arr[i][j];
    }
}
cout << dp[1] << '\n';

//洛谷 1002
//先跑一个循环标记一下马占用的位置我记住bool ma[] 为true
dp[0][0] = 1;
for(int i = 0; i < n; ++ i){
    for(int j = 0; j < m; ++ j){
        if(i == 0 && j == 0) continue;
        if(ma[i][j]){
            dp[i][j] = 0;
        }else{
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
}
cout << dp[end_x][end_y] << '\n';

//洛谷 1434 你和我讲一下这题 那个转移方程怎么来的
int mem[MAXN][MAXN];
int dfs(int x, int y){
    if(mem[x][y] != 0) return mem[x][y];
    mem[x][y] = 1;
    for(int i = 0; i < 4; ++ i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
        if(mp[nx][ny] >= mp[x][y]) continue;
        mem[x][y] = max(mem[x][y], dfs(nx, ny) + 1);
    }
    return mem[x][y];
}

//洛谷 1020
#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    vector<int> g1;
    vector<int> g2;
    int temp = 0;

    while(cin >> temp){
        auto it1 = upper_bound(g1.begin(), g1.end(), temp, greater<int>());
        if(it1 == g1.end()){
            g1.push_back(temp);
        }else{
            *it1 = temp;
        }
    }



    return 0;
}