#include<iostream>
using namespace std;
typedef long long ll;
// const int MAXN = 1e5 + 5;
// int arr[MAXN];
// int pre[MAXN];// 1 2 3 2 4 5 6 1 0 2 
// int first[15];// 1 2 3 4 5
// int last[15];//  1 3 6 10 15
// int n, k;    //  1 1 0 5 1

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);

//     cin >> n >> k;
//     for(int i = 1; i <= n; ++ i){
//         cin >> arr[i];
//         pre[i] = arr[i] + pre[i - 1];
//         pre[i] %= k;
//         if(first[pre[i]] == 0){
//             first[pre[i]] == i;
//         }else{
//             last[pre[i]] == i;
//         }

//     }



//     return 0;
// }

const int MAXN = 1e5 + 10;
ll cnt[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    cnt[0] = 1;
    ll ans = 0;
    ll rem = 0;

    for(int i = 1; i <= n; ++ i){
        int temp = 0;
        cin >> temp;
        rem = (rem + temp) % k;
        ans += cnt[rem];
        cnt[rem]++;
    }
    cout << ans << endl;

    return 0;
}