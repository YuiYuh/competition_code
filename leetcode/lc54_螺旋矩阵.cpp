class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startx = 0;
		int starty = 0;
		int i,j;
		int m = matrix[0].length() / 2;
		int n = matrix.length() / 2; 
		int num = m*n;
		if(m==n){
			int mid = m / 2;
		}
		while(num){
		
			for(j; j < m; j++){
				num--;
				cout << matrix[i][j];
				if(num == 0)
					break;
			}
			for(i; i < n; i++){
				num--;
				cout << matrix[i][j];
				if(num == 0)
					break;
			}
			for(j; j > startx; j--){
				num--;
				cout << matrix[i][j];
				if(num == 0)
					break;
			}
			for(i; i > starty; i--){
				num--;
				cout << matrix[i][j];
				if(num == 0)
					break; 
			}
				
			if(n == m && m % 2){
				cout << matrix[mid][mid];
			}	
		}
		
    }
};
