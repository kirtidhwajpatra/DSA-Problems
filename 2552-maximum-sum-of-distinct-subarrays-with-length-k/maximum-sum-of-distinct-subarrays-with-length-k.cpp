class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> count(100001, 0);
        long long curr = 0, res = 0;
        int distinct = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (++count[nums[i]] == 1) distinct++;
            curr += nums[i];
            if (i >= k) {
                if (--count[nums[i - k]] == 0) distinct--;
                curr -= nums[i - k];
            }
            if (distinct == k) res = max(res, curr);
        }
        return res;
    }
};
