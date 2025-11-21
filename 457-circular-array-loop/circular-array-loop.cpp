class Solution {
public:
    int nextIdx(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int slow = i, fast = i;
            bool dir = nums[i] > 0;

            while (true) {
                int ns = nextIdx(nums, slow);
                if (nums[ns] == 0 || (nums[ns] > 0) != dir) break;

                int nf = nextIdx(nums, fast);
                if (nums[nf] == 0 || (nums[nf] > 0) != dir) break;

                int nf2 = nextIdx(nums, nf);
                if (nums[nf2] == 0 || (nums[nf2] > 0) != dir) break;

                slow = ns;
                fast = nf2;

                if (slow == fast) {
                    if (slow == nextIdx(nums, slow)) break;
                    return true;
                }
            }

            int j = i, sign = nums[i];
            while (nums[j] != 0 && (nums[j] > 0) == (sign > 0)) {
                int nxt = nextIdx(nums, j);
                nums[j] = 0;
                j = nxt;
            }
        }
        return false;
    }
};
