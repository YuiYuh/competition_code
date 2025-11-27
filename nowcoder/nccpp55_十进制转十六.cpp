#include <iostream>
#include <string>
using namespace std;

string toHexString(int n);

int main() {

    int n;
    cin >> n;

    string hexStr = toHexString(n);
    cout << hexStr << endl;

    return 0;
}

string toHexString(int n) {
    // write your code here......
    if(n == 0) return "0";
    string hex = "";
    char map[] = "0123456789ABCDEF";
    while(n > 0){
        int r = n % 16;
        hex = map[r] + hex;
        n /= 16;
    }
    return hex;
}
