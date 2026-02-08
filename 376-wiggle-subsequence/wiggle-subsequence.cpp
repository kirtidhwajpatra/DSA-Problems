class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        int prevDiff = 0;
        int count = 1;  // at least one element is a wiggle

        for (int i = 1; i < n; i++) {
            int currDiff = nums[i] - nums[i - 1];

            // check sign change


            if ((currDiff > 0 && prevDiff <= 0) ||
                (currDiff < 0 && prevDiff >= 0)) {
                count++;

                prevDiff = currDiff;
            }

            
        }





        return count;
    }
};
