#include <iostream>
using namespace std;
void reverse(string &s, int start, int end){
    for(int i = start, j = end; i < j; i++,j--){
        swap(s[i],s[j]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    string s;
    cin >> s;
    reverse(s, 0, s.size() - 1);
    reverse(s, 0, k - 1);
    reverse(s, k, s.size() - 1);
    cout << s << endl;

    return 0;
}