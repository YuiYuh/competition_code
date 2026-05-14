#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

typedef long long LL;

int n;
string s;

// ---------------- 回文自动机：统计不同奇数回文子串数量 ----------------
struct PAMNode{
    int ch[26];
    int fail;
    int len;

    PAMNode(){
        memset(ch, 0, sizeof ch);
        fail = 0;
        len = 0;
    }
};

struct PAM{
    vector<PAMNode> tree;
    string str;          // 已加入的字符串，str[0] 是哨兵
    int last;            // 当前最长回文后缀节点
    int tot;             // 节点数量
    LL oddCnt;           // 不同奇数回文子串数量

    PAM(int maxn = 0){
        tree.resize(maxn + 5);
        init();
    }

    void init(){
        // 0 号节点：长度 0 的根
        // 1 号节点：长度 -1 的根
        tree[0] = PAMNode();
        tree[1] = PAMNode();

        tree[0].len = 0;
        tree[0].fail = 1;

        tree[1].len = -1;
        tree[1].fail = 1;

        last = 0;
        tot = 1;
        oddCnt = 0;

        str.clear();
        str += '#'; // 哨兵，防止越界
    }

    int get_fail(int x, int pos){
        while(str[pos - tree[x].len - 1] != str[pos]){
            x = tree[x].fail;
        }
        return x;
    }

    void add(char c){
        str += c;
        int pos = (int)str.size() - 1;
        int id = c - 'a';

        int cur = get_fail(last, pos);

        // 如果这个回文串以前没出现过，新建节点
        if(tree[cur].ch[id] == 0){
            ++tot;
            tree[tot] = PAMNode();
            tree[tot].len = tree[cur].len + 2;

            if(tree[tot].len == 1){
                tree[tot].fail = 0;
            }else{
                int p = get_fail(tree[cur].fail, pos);
                tree[tot].fail = tree[p].ch[id];
            }

            tree[cur].ch[id] = tot;

            // 只统计奇数长度回文串
            if(tree[tot].len % 2 == 1){
                oddCnt++;
            }
        }

        last = tree[cur].ch[id];
    }
};

// ---------------- 后缀自动机：统计不同子串总数 ----------------
struct SAMNode{
    int ch[26];
    int link;
    int len;

    SAMNode(){
        memset(ch, -1, sizeof ch);
        link = -1;
        len = 0;
    }
};

struct SAM{
    vector<SAMNode> st;
    int last;
    int tot;
    LL total; // 当前字符串不同子串总数

    SAM(int maxn = 0){
        st.resize(2 * maxn + 5);
        init();
    }

    void init(){
        st[0] = SAMNode();
        st[0].len = 0;
        st[0].link = -1;

        last = 0;
        tot = 0;
        total = 0;
    }

    void add(char c){
        int id = c - 'a';

        int cur = ++tot;
        st[cur] = SAMNode();
        st[cur].len = st[last].len + 1;

        int p = last;

        while(p != -1 && st[p].ch[id] == -1){
            st[p].ch[id] = cur;
            p = st[p].link;
        }

        if(p == -1){
            st[cur].link = 0;
        }else{
            int q = st[p].ch[id];

            if(st[p].len + 1 == st[q].len){
                st[cur].link = q;
            }else{
                int clone = ++tot;
                st[clone] = st[q];
                st[clone].len = st[p].len + 1;

                while(p != -1 && st[p].ch[id] == q){
                    st[p].ch[id] = clone;
                    p = st[p].link;
                }

                st[q].link = st[cur].link = clone;
            }
        }

        last = cur;

        // 新增的不同子串数量
        total += st[cur].len - st[st[cur].link].len;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> s;

    vector<LL> preOdd(n + 2, 0);
    vector<LL> sufOdd(n + 2, 0);
    vector<LL> sufTotal(n + 2, 0);

    // 1. 计算 preOdd[i]
    PAM pam1(n);

    for(int i = 1; i <= n; ++i){
        pam1.add(s[i - 1]);
        preOdd[i] = pam1.oddCnt;
    }

    // 2. 反转字符串，用前缀对应原串后缀
    string rev = s;
    reverse(rev.begin(), rev.end());

    // 3. 在反串上计算“前缀不同奇数回文子串数量”
    PAM pam2(n);
    vector<LL> revOdd(n + 2, 0);

    for(int i = 1; i <= n; ++i){
        pam2.add(rev[i - 1]);
        revOdd[i] = pam2.oddCnt;
    }

    // 4. 在反串上计算“前缀不同子串总数”
    SAM sam(n);
    vector<LL> revTotal(n + 2, 0);

    for(int i = 1; i <= n; ++i){
        sam.add(rev[i - 1]);
        revTotal[i] = sam.total;
    }

    // 5. 映射回原串后缀
    // 原串 s[i..n] 长度是 n - i + 1
    // 对应反串的前缀长度也是 n - i + 1
    for(int i = 1; i <= n; ++i){
        int len = n - i + 1;
        sufOdd[i] = revOdd[len];
        sufTotal[i] = revTotal[len];
    }

    // 6. 枚举切口
    LL ans = 0;

    for(int t = 1; t < n; ++t){
        LL A = preOdd[t];
        LL B = sufTotal[t + 1] - sufOdd[t + 1];

        ans = max(ans, A * B);
    }

    cout << ans << '\n';

    return 0;
}
