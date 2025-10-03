class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates for i

            for (int j = i+1; j < n; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue; // skip duplicates for j

                int p = j + 1, q = n - 1;

                while(p < q) {
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum < target) {
                        p++;
                    } else if(sum > target) {
                        q--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;

                        while(p < q && nums[p] == nums[p-1]) p++; // skip duplicates
                        while(p < q && nums[q] == nums[q+1]) q--; // skip duplicates
                    }
                }
            }
        }
        return ans;
    }
};
