class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        int full = (1 << n) - 1;

        for (int mask = 1; mask < full; mask++) {
            long long prod = 1;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {


                    prod *= nums[i];
                    if (prod > target) {
                        valid = false;
                        break;
                    }
                   }
            }

            if (!valid || prod != target) continue;

            long long other = 1;


            for (int i = 0; i < n; i++)    {
                if (!(mask & (1 << i))) {


                    other *= nums[i];
                    if (other > target) break;
                }
                 }

            if (other == target) return true;


        }

        return false;
        
       }
};
