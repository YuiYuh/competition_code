#include<iostream>
using namespace std;

int n, q;
const int N = 1e8 + 10;
int primes[N];
bool is_nprime[N];

void get_prime(int limit){
    int cnt = 1;
    for(int i = 2; i <= limit; ++ i){
        if(!is_nprime[i]){
            primes[cnt++] = i;
        }
        for(int j = 1; j < cnt && i * primes[j] <= limit; ++ j){
            is_nprime[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    get_prime(n);
    while (q--)
    {
        int k;
        cin >> k;
        cout << primes[k] << '\n';
    }
    




    return 0;
}