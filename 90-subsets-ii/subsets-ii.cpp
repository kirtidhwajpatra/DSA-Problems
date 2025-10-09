class Solution {
public:
    void GetAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets){
        if(i == nums.size()){
            allSubsets.push_back(ans);
            return;
        }

        //include
        ans.push_back(nums[i]);
        GetAllSubsets(nums, ans, i+1, allSubsets);

        ans.pop_back();
        
        //special case: Skip duplicates idx
        int idx = i+1;
        while(idx<nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        GetAllSubsets(nums, ans, idx, allSubsets);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;
        GetAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};