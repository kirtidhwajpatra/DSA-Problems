class Solution {
    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
          int m = l + (r - l) / 2;
        int cnt = mergeSort(nums, l, m) + mergeSort(nums, m + 1, r);
        int j = m + 1;

        for (int i = l; i <= m; i++)    {
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) j++;
            cnt += j - (m + 1);


        }


        vector<int> tmp;
        int i = l;
        j = m + 1;


        while (i <= m && j <= r) {

            if (nums[i] <= nums[j]) tmp.push_back(nums[i++]);
            else tmp.push_back(nums[j++]);

        }


          while (i <= m) tmp.push_back(nums[i++]);
        while (j <= r) tmp.push_back(nums[j++]);
        for (int k = 0; k < tmp.size(); k++) nums[l + k] = tmp[k];
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
