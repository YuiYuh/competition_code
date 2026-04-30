#include<iostream>
using namespace std;

const int MAXN = 25;
int a[MAXN];
int n, k ,cnt;

bool is_prime(long long x){
    if(x < 2) return false;
    if(x == 2 || x == 3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;
    for(long long i = 5; i * i <= x; i += 6){
        if(x % i == 0 || x % (i + 2) == 0){
            return false;
        }
    }
    return true;
}


void dfs(int x, int start, long long sum){
    if(x > k){
        if(is_prime(sum)) cnt++;
        return ;
    }
    for(int i = start; i <= n; ++ i){
        dfs(x + 1, i + 1, sum + a[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);


    cin >> n >> k;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }

    dfs(1, 1, 0);


    cout << cnt << endl;

    return 0;
}