#include<iostream>
using namespace std;

const int MAXN = 15;
bool col0[15];
bool xie1[30];
bool xie2[30];
int path[15];
int n, sum;

void dfs(int row){
    if(row > n){
        sum ++;
        if(sum <= 3){
            for(int i = 1; i <= n; ++ i){
                cout << path[i] << (i == n ? "" : " ");
            }
            cout << '\n';
        }
        return ;
    }

    for(int col = 1; col <= n; ++ col){
        if(!col0[col] && !xie1[row + col] && !xie2[row - col + n]){
            path[row] = col;
            col0[col] = true;
            xie1[row + col] = true;
            xie2[row - col + n] = true;
            dfs(row + 1);
            col0[col] = false;
            xie1[row + col] = false;
            xie2[row - col + n] = false;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    dfs(1);

    cout << sum << endl;
    
    return 0;
}