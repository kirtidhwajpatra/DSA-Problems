class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0, F0 = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            F0 += (long long)i * nums[i];

        }
        
        long long ans = F0;

        long long F = F0;
        
        for (int k = 1; k < n; k++) {
            F = F + sum - n * (long long)nums[n - k];
            
            ans = max(ans, F);
        }
        
        return ans;
    }
};
