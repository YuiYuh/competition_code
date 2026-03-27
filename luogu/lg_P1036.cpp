#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 25;
int arr[MAXN];
long long sum;
int n, k, cnt;

bool is_prime(long long num){
    if(num < 2) return false;
    if(num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (long long i = 5; i  <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false; 
    }
    return true;
}

void dfs(int step, int start, long long sum){
    if(step == k){
        if(is_prime(sum)){
            cnt ++;
        }
        return ;
    }
    for(int i = start; i <= n; ++i){
        dfs(step + 1, i + 1, sum + arr[i]);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    dfs(0,1,0);
    cout << cnt << endl;
    return 0;
}