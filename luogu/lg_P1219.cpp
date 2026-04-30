//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 15;
//int n,total_ans;
//int path[MAXN];
//bool vis_col[MAXN];
//bool vis_diag1[40];
//bool vis_diag2[40];
//
//void dfs(int row){
//	if(row > n){
//		total_ans ++;
//		if(total_ans <= 3){
//			for(int i = 1; i <= n; ++ i){
//				cout << path[i] << (i == n ? "" : " ");
//			}
//			cout << '\n';
//		}
//		return ;
//	}
//	
//	for(int col = 1; col <= n; col++){
//		if (!vis_col[col] && !vis_diag1[row - col + n] && !vis_diag2[row + col]){
//			path[row] = col;
//			vis_col[col] = true;
//			vis_diag1[row - col + n] = true;
//			vis_diag2[row + col] = true;
//			
//			dfs(row + 1);
//			//huanyuan
//			vis_col[col] = false;
//            vis_diag1[row - col + n] = false;
//            vis_diag2[row + col] = false;
//			
//		}
//	}
//}
//
//
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	cin >> n;
//	dfs(1);
//	cout << total_ans << endl;
//	
//	
//	
//	return 0;

#include<bits/stdc++.h>
using namespace std;

int n, total_sum;
int path[15];
bool vis_col[15];
bool xie1[40];//zhu
bool xie2[40];//fu

void dfs(int row){
	if(row > n){
		total_sum ++;
		if(total_sum <= 3){
			for(int i = 1; i <= n; ++ i){
				cout << path[i] << (i == n ? "" : " ");
			}
			cout << '\n';
		}
		return ;
	}

	for(int col = 1; col <= n; ++ col){
		if(!vis_col[col] && !xie1[row - col + n] && !xie2[row + col]){
			path[row] = col;
			vis_col[col] = true;
			xie1[row - col + n] = true;
			xie2[row + col] = true;
			
			dfs(row + 1);
			vis_col[col] = false;
			xie1[row - col + n] = false;
			xie2[row + col] = false;
		}
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	dfs(1);
	
	cout << total_sum;
	
	return 0;
} 

