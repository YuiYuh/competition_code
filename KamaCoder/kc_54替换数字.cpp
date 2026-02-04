#include <iostream>
using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     string res;
//     string s;
//     string m = "number";
//     cin >> s;
//     for(auto p : s){
//         if(p >= '0' && p <= '9')
//             res += m;
//         else
//             res += p;
//     }
//     cout << res << endl;
//     return 0;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);                 // ⭐ 关键：一次读整行

    int count = 0;
    for (char c : s) if (c >= '0' && c <= '9') count++;

    int oldLen = (int)s.size();
    s.resize(oldLen + count * 5);    // 每个数字多 5 个字符

    int oIndex = oldLen - 1;
    int nIndex = (int)s.size() - 1;

    while (oIndex >= 0) {
        if (s[oIndex] >= '0' && s[oIndex] <= '9') {
            s[nIndex--] = 'r';
            s[nIndex--] = 'e';
            s[nIndex--] = 'b';
            s[nIndex--] = 'm';
            s[nIndex--] = 'u';
            s[nIndex--] = 'n';
        } else {
            s[nIndex--] = s[oIndex];
        }
        oIndex--;
    }

    cout << s << "\n";
    return 0;
}