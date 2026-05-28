#include<iostream>
using namespace std;

const int MAXN = 1e5 + 5;
int length[MAXN];
int width[MAXN];
int n, k;


bool check(int mid){
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        int a = length[i] / mid;
        int b = width[i] / mid;
        cnt += (a * b);
    }
    return cnt >= k;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> k;
    int max_length = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> length[i] >> width[i];
        max_length = max(max_length,max(width[i], length[i]));
    }

    int l = 1;
    int r = max_length;
    int ans = 0;

    while(l <= r){
        int mid = (r - l) / 2 + l;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
