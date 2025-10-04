class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // stores prefixSum -> frequency
        mp[0] = 1;  // prefix sum = 0 occurs once (important base case)
        
        int count = 0;
        int prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;  // running prefix sum

            // check if (prefixSum - k) was seen before
            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            // store/update this prefixSum in map
            mp[prefixSum]++;
        }

        return count;
    }
};
