class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int middle = (l + r) / 2;
        while(r >= l){
        	int middle = (l + (r - l)/2);
        	if(nums[middle] > target){
        		r = middle - 1;
			}
			else if(nums[middle] < target){
				l = middle + 1;
			}else
				return middle;
		}
        return r + 1;
    }
};
