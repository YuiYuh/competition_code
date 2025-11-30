//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int result = nums.size()+1;
//		int sum = 0;
//		int sublength = 0;
//		for(int i = 0; i < nums.size(); i++){
//			sum = 0;
//			for(int j = i; j < nums.size(); j++){
//				sum += nums[j];
//				if(sum >= s){
//					sublength = j - i + 1;
//					result = result < sublength ? result : sublength;
//					break;
//				}
//			}
//		} 
//		return result == nums.size()+1 ? 0 : result;
//    }
//};³¬Ê±³¬Ê±³¬Ê±
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
		int sum = 0;
		int i = 0;
		int sublength = 0;
		for(int j = 0; j < nums.size(); j++){
			sum += nums[j];
			while(sum >= target){
				sublength = (j - i + 1);
				result = result < sublength ? result : sublength;
				sum -= nums[i++];
			}
		} 
		return result == INT_MAX ? 0 : result;
    }
};














 
