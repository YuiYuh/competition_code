// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         std::unordered_map<int,int> map;
//         for(int i = 0; i < nums.size(); i++){
//             auto p = map.find(target - nums[i]);
//             if(p != map.end()){
//                 return {p -> second, i};
//             }
//             map[nums[i]] = i;
//         }
//         return {};
//     }
// };
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> mp;
            for(int i = 0; i < nums.size(); i++){
                auto p = mp.find(target - nums[i]);
                if(p != mp.end()){
                    return {p -> second, i};
                }
                mp[nums[i]] = i;
            }
            return {};
        }
};