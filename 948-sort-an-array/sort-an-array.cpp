class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        vector<int> a(n1), b(n2);
        for (int i = 0; i < n1; i++) a[i] = nums[l + i];
        for (int i = 0; i < n2; i++) b[i] = nums[m + 1 + i];
        int i = 0, j = 0, k = l;

        //
        while (i < n1 && j < n2) {

            if (a[i] <= b[j]) nums[k++] = a[i++];
            
            else nums[k++] = b[j++];
        }   
        while (i < n1) nums[k++] = a[i++];

        while (j < n2) nums[k++] = b[j++];
      }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;

        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }



    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

          return nums;
   
   
     }
};
