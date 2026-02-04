#include <bits/stdc++.h>
using namespace std;

const int N = 6;
const int TARGET = 3;
int board[N][N] = {
  {1,0,2,0,2,2},
  {2,2,2,0,2,2},
  {2,2,2,2,0,0},
  {2,2,2,2,2,2},
  {2,2,1,2,2,1},
  {2,0,2,2,1,2}
};

bool isValid(int r, int c, int val){
  if(c >= 2 && board[r][c - 1] == val && board[r][c - 2] == val) return false;

  if(r >= 2 && board[r - 1][c] == val && board[r - 2][c] == val) return false;

  int rowCount = 0;
  for(int j = 0; j < N; j++){
    if(board[r][j] == val) rowCount++;
  }
  if(rowCount >= TARGET) return false;

  int colCount = 0;
  for(int i = 0; i < N; i++){
    if(board[i][c] == val) colCount++;
  }
  if(colCount >= TARGET) return false;

  return true;
}

bool isUnique(){
  set<string> rows;
  for(int i = 0; i < N; i++){
    string rowStr = "";
    for(int j = 0; j < N; j++) rowStr += to_string(board[i][j]);
    if(rows.count(rowStr)) return false;
    rows.insert(rowStr);
  }

  set<string> cols;
  for(int j = 0; j < N; j++){
    string colStr = "";
  for(int i = 0; i < N; i++) colStr += to_string(board[i][j]);
  if(cols.count(colStr)) return false;
  cols.insert(colStr);
  }
  return true;
}

bool solve(int index){
  if(index == N * N) return isUnique();
  int r = index / N;
  int c = index % N;

  if(board[r][c] != 2){
    return solve(index + 1);
  }
  for(int val = 0; val <= 1; val++){
    if(isValid(r,c,val)){
      board[r][c] = val;
      if(solve(index + 1)) return true;
      board[r][c] = 2;
    }
  }
  return false;
}

int main()
{
  // 请在此输入您的代码
  if(solve(0)){
    string resultStr = "";
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        resultStr += to_string(board[i][j]);
      }
    }
    cout << resultStr;
  }
  return 0;
}
















