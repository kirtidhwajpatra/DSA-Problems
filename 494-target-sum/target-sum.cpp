class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums) sum += x;
        if ((sum + target) % 2 || sum < abs(target)) return 0;
        int S = (sum + target) / 2;
        
        vector<int> dp(S + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int j = S; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }
        return dp[S];
    }
};
