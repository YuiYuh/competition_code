// #include <iostream>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n,m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for(int i = 0; i < n; ++i){
//         cin >> a[i];
//     }

//     vector<int> cnt(m + 1, 0);
//     int satisfy = 0;
//     int l = 0;

//     int ansL = 0, ansR = n - 1;
//     int minLen = n + 1;

//     for(int r = 0; r < n; ++r){
//         if(cnt[a[r]] == 0) satisfy++;
//         cnt[a[r]]++;

//         while(satisfy == m){
//             if(r - l + 1 < minLen){
//                 minLen = r - l + 1;
//                 ansL = l;
//                 ansR = r;
//             }
//             cnt[a[l]]--;
//             if(cnt[a[l]] == 0) satisfy--;
//             l++;
//         }
//     }
//     cout << (ansL + 1) << ' ' << (ansR + 1) << endl;
//     return 0;
// }
#include <iostream>
using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n,m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }

//     vector<int> cnt(m + 1, 0);
//     int sa = 0;
//     int l = 0;
//     int ansL = 0, ansR = n - 1;
//     int minLen = n + 1;

//     for(int r = 0; r < n; ++r){
//         if(cnt[a[r]] == 0) sa++;
//         cnt[a[r]]++;

//         while(sa == m){
//             if(r - l + 1 < minLen){
//                 minLen = r - l + 1;
//                 ansL = l;
//                 ansR = r;
//             }
//             cnt[a[l]]--;
//             if(cnt[a[l]] == 0) sa--;//2 2 5 3 1 3 2 4 1 1
//             l++;
//         }
//     }
//     cout << (ansL + 1) << " " << (ansR + 1) << "\n";
//     return 0;
// }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> cnt(m + 1, 0);
    int satisfy = 0;
    int l = 0;
    int resL = 0, resR = 0;
    int minLen = n + 1;

    for(int r = 0; r < n; ++r){
        if(cnt[a[r]] == 0) satisfy++;
        cnt[a[r]]++;

        while(satisfy == m){
            if(r - l + 1 < minLen){
                minLen = r - l + 1;
                resL = l;
                resR = r;
            }
            cnt[a[l]]--;
            if(cnt[a[l]] == 0) satisfy--;
            l++;
        }
    }
    cout << (resL + 1) << " " << (resR + 1) << endl;
    return 0;
}