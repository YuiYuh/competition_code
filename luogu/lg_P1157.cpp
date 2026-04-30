#include<iostream>
#include<iomanip>
using namespace std;

const int MAXN = 25;
int arr[MAXN];
int n, r;

void dfs(int x, int start){
    if(x > r){
        for(int i = 1; i <= r; ++ i){
            cout << setw(3) << arr[i];
        }
        cout << '\n';
        return ;
    }

    for(int i = start; i <= n - (r - x); ++ i){
            
            arr[x] = i;
            dfs(x + 1, i + 1);
            
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> r;
    dfs(1, 1);



    return 0;
}