
// the best solution 100% beat with O(N LogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int,int>>p;

    for(int i = 0 ; i<n; i++)
    {
        p.push_back({nums[i],i});
    }
    sort(p.begin(),p.end());

    int r = 0,l = n-1;
    while(r < l){
        int sum = p[r].first + p[l].first;
        if(sum == target){
            return {p[r].second,p[l].second};
        }
        if(sum > target){
            l--;
        }
        if(sum < target ){
            r++;
        }
    }
     return {-1,-1};


    }
};
