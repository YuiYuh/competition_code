class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int startx = 0;
        int starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int offset = 1;
        int i,j;
        while(loop--){
        	i = startx;
        	j = starty;
        	
        	
        	for(i;i < n - offset; i++){
        		res[j][i] = count++;
			}
			for(j; j < n - offset; j++){
				res[j][i] = count++;
			}
			for(; i > startx; i--){
				res[j][i] = count++;
			}
			for(; j > starty; j--){
				res[j][i] = count++;
			}
			
			startx++;
			starty++;
			
			offset++;
		}
		if(n % 2){
			res[mid][mid] = count;
		}
		return res;
    }
};
