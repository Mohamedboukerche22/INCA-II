class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int r = 0;r <n;r++){
                if(r == i){
                    continue;
                }
                if(nums[i] + nums[r] == target ){
                    return {i,r};
                }
            }
        }
        return {0,0};
        
    }
};
