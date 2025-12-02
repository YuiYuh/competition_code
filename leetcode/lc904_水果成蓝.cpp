class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map <int,int> cnt;
        int i = 0;
        int result = 0;
        for(int j = 0; j< fruits.size();j++){
        	cnt[fruits[j]]++;
        	while(cnt.size()>2){
        		cnt[fruits[i]]--;
        		if(cnt[fruits[i]]==0)
        			cnt.erase(fruits[i]);
        			i++;
			}
			result = max(result,j-i+1);
		}
	return result;
    }
};
