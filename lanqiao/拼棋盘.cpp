#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

const int BIG = 10;
const int BOARD8 = 8;
const int BOARD6 = 6;

int BigBoard[BIG][BIG];// 0 sign for empty and 1 sign for used


struct Cell{
    int x, y, c;
};

vector<Cell> piece;

vector<Cell> make_board(int n){
    vector<Cell> res;
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            res.push_back({i, j, (i + j) % 2});//0 是白 1 是黑
        }
    }
    return res;
}

void print_board(const vector<Cell>& piece){
    int maxx = 0;
    int maxy = 0;
    

    for(auto cell : piece){
        maxx = max(maxx, cell.x);
        maxy = max(maxy, cell.y);
    }
    vector<string> g(maxx + 1, string(maxy + 1, '.'));

    for(auto cell : piece){
        g[cell.x][cell.y] = cell.c ? '#' : '0';
    }

    for(int i = 0; i <= maxx; ++ i){
        cout << g[i] << endl;
    }
}

bool cmp_cell(const Cell& a, const Cell& b){
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.c < b.c;
}

void normalize(vector<Cell>& piece){
    int minx = 1e9;
    int miny = 1e9;

    for(auto cell : piece){
        minx = min(minx, cell.x);
        miny = min(miny, cell.y);
    }

    for(auto& cell : piece){
        cell.x -= minx;
        cell.y -= miny;
    }

    sort(piece.begin(), piece.end(), cmp_cell);
}
vector<Cell> rotate90(vector<Cell> piece){
    for(auto& cell : piece){
        int old_x = cell.x;
        int old_y = cell.y;

        cell.x = old_y;
        cell.y = -old_x;
    }

    normalize(piece);

    return piece;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    vector<Cell> board8 = make_board(BOARD8);
    vector<Cell> board6 = make_board(BOARD6);
    
    


    //print_board(board8);
    //cout << board8.size() << endl;
    return 0;
}