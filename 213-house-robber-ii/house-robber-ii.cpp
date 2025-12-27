class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(run(nums, 0, n - 2), run(nums, 1, n - 1));
    }

private:
    int run(vector<int>& homes, int start, int end) {
        int take = 0, skip = 0;

        for (int i = start; i <= end; i++) {
            int nextTake = skip + homes[i];
            skip = max(skip, take);
            take = nextTake;
        }

        return max(take, skip);
    }
};
