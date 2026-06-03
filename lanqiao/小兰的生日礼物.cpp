#include<bits/stdc++.h>
using namespace std;

int cnt[10];

void add_digital(int x, int used[]){
    while(x > 0){
        used[x % 10]++;
        x /= 10;
    }
}

bool can_make(int a, int b, int c){
    int used[10] = {0};
    
    add_digital(a, used);
    add_digital(b, used);
    add_digital(c, used);
    
    for(int i = 0; i <= 9; ++ i){
        if(used[i] > cnt[i]) return false;
    }
    return true;
}


int main(){
    int ans = 0;
    
    cnt[0] = 2;
    cnt[1] = 1;
    cnt[2] = 2;
    cnt[5] = 2;
    cnt[6] = 1;
    
    for(int a = 1; a <= 655; ++ a){
        for(int b = a; b <= 655; ++ b){
            for(int c = b; c <= 655; ++ c){
                if(a + b <= c) continue;
                if(can_make(a, b, c)) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}