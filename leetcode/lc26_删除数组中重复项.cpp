#include<bits/stdc++.h>
class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		int slow = 0;
		for(int fast = 1; fast < nums.size(); fast++){
			if(nums[fast] != nums[slow]){
				nums[++slow] = nums[fast];
			}
		}
		return slow+1;
	}
};

//[1,2,2,3,4,5]
//[1,2,3,4,5,?]
