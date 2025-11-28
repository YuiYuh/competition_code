//class Solution {
//public:
//    int mySqrt(int x) {
//        if(x == 1)
//            return 1;
//        int min = 0;
//        int max = x;
//        while(max-min>1)
//        {
//            int m = (max+min)/2;
//            if(x/m<m)
//                max = m;
//            else
//                min = m;
//        }
//        return min;
//    }
class Solution{
public:
	int mySqrt(int x){
		if(x == 0 || x == 1) return x;
		
		int left = 0;
		int right = x;
		int an = 0;
		
		while(left <= right){
			int mid = left + (right-left)/2;
			long long square = 1LL * mid *mid;
			
			if(square == x) return mid;
			else if(square < x){
				an = left;
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		return an;
	}
}; 






