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
for(int i = 0; i <= n; ++ i){
    for(int j = 0; j <= m; ++ j){
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
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
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
        auto it2 = lower_bound(g2.begin(),g2.end(),temp);
        if(it2 == g2.end()){
            g2.push_back(temp);
        }else{
            *it2 = temp;
        }
    }
    cout << g1.size() << " " << g2.size() << '\n';


    return 0;
}

//洛谷 1048 v->价值 w->权重
for(int i = 1; i <= m; ++ i){
    for(int j = t; j >= w[i]; -- j){
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}//dp代表 这个容量为j的背包最大价值
//cout << dp[MAXN] << '\n';

//洛谷 1060 我本想排序 后来思考了一下这题简直和上一题一模一样
//输入的时候v数组直接乘重要度 背包容量就是m
for(int i = 1; i <= n; ++ i){
    for(int j = m; j >= w[i]; j --){
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}

//洛谷 1616
for(int i = 1; i <= m; ++ i){
    for(int j = w[i]; j <= t; ++ j){
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
//cout << dp[t] << '\n';

//洛谷 1757 有点意思 同组互斥吗 我思考一下 有点不会 你等下和我讲一讲
vector<PII> arr[MAXN];
for(int g = 1; g <= max_group; ++ g){
    for(int j = m; j >= 0; -- j){
        for(const auto &i : arr[g]){
            if(j >= i.first){
                dp[j] = max(dp[j], dp[j - i.first] + i.second);
            }
        }
    }
}

//洛谷 1182
bool check(int mid){
    int length = 0;
    int cnt = 1;
    for(int i = 1; i <= n; ++ i){
        length += arr[i];
        if(length > mid){
            cnt++;
            length = arr[i];
        }
    }
    return cnt <= m;
}// 这里的大于等于小于等于你和我说一下 我有点搞不清楚啊
//我喜欢用下面这种
while(l <= r){
    mid = (r - l) / 2 + l;
    if(check(mid)){
        ans = mid;
        r = mid - 1;
    }else{
        l = mid + 1;
    }
}

//洛谷  1873
// l 从0开始 r记录为最大值 输入的时候的工作
bool check(int mid){
    long long sum = 0;
    for(int i = 1; i <= n; ++ i){
        if(mid < arr[i]){
            sum += (arr[i] - mid);
        }
    }
    return sum >= m;
}

//洛谷 2367 差分怎么写输入呢，，（已经想出来了）
cin > n >> p;
for(int i = 1; i <= n; ++ i){
    cin >> arr[i];
    d[i] = arr[i] - arr[i - 1];// 1 1 2 3 4 5
                               // 1 0 1 1 1 1   模拟一下
}
for(int i = 1; i <= p; ++ i){
    int x, y, z;
    cin >> x >> y >> z;

    d[x] += z;
    d[y + 1] -= z;
}
//跑循环取最小值 然后输出

//洛谷 3397 感觉二维的东西都比一维难啊
while(m--){
    cin >> x1 >> y1 >> x2 >> y2;
    d[x1][y1]++;
    d[x1][y2 + 1]--;
    d[x2 + 1][y1]--;
    d[s2 + 1][y2 + 1]++;
}
for(int i = 1; i <= n; ++ i){
    for(int j = 1; j <= n; ++ j){
        d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
    }
}

// 力扣 1
unordered_map<int, int> mp;
for(int i = 0; i < nums.size(); ++ i){
    auto p = mp.find(target - nums[i]);
    if(p == mp.end()){
        mp[nums[i]] = i;
    }else{
        cout << p ->second << ' ' << i;//*p.second
    }
}

//洛谷 3367   我要说fa数组要初始化为自己 路径压缩的意义是啥啊告诉我
void merge(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rootX != rootY){
        fa[x] = rootY;
    }
}
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

//洛谷 1551  这不是和上面一模一样吗
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rootX != rootY){
        fa[rootX] = rootY;
    }
}
string is_relative(int x, int y){
    if(find(x) == find(y)) return "Yes";
    return "No";
}
//然后输入的时候做好准备工作就行了

//洛谷 4779 dijkstra 展示我完整代码的能力 这个要提醒我复习的  
#include<iostream>
using namespace std;

const int MAXN = 2e5 + 10;
//int INF = INT_MAX;
int n, m, s;

struct Edge{
    int to, weight;
};

struct Node{
    int id;
    int dist;
    bool operator <(const Node& other) const {
        return dist > other.dist;
    }
};

vector<Edge> g[MAXN];
int dis[MAXN];
bool vis[MAXN];


void dijkstra(){
    memset(dis, 0x3f3f3f3f, sizeof dis);
    priority_queue<Node> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int u = curr.id;
        if(vis[u]) continue;
        vis[u] = true;
        for(auto& edge : g[u]){
            int v = edge.to;
            int w = edge.weight;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m >> s;
    //建图
    for(int i = 1; i <= m; ++ i){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijkstra();

    for(int i = 1; i <= n; ++ i){
		cout << dis[i] << (i == n ? "" : " ");
	}

    return 0;
}
//介于上面的dijkstra有借鉴的成分 我决定再自己手打一遍
void dijkstra(){
    memset(dis, 0x3f, sizeof dis);
    priority_queue<Node> pq;// 已经重载小于号了
    
    pq.push({s, 0});
    dis[s] = 0;

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int u = curr.id;
        if(vis[u]) continue;
        vis[u] = true;

        for(auto edge : g[u]){
            int v = edge.to;
            int w = edge.weight;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}

//洛谷 3366 find merge我就不写了
struct Edge{
    int u, v, w;
};
vector<Edge> e;

bool cmp(const Edge& a, const Edge& b){
    return a.w < b.w;
}

e.push_back({a, b, c});
sort(e.begin(), e.end(), cmp);

long long sum = 0;
int cnt = 0;

for(int i = 0; i < e.size(); ++ i){
    int u = e[i].u;
	int v = e[i].v;
	int w = e[i].w;
    if(find(u) != find(v)){
        merge(u, v);
        sum += w;
        cnt++;
        if(cnt == n - 1) break;//连完了 要是不等于的话就说明根本连接不上。
    }
}//连接完了就输出sum 否则orz
