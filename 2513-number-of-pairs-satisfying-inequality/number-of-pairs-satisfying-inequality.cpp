class Solution {
public:
    long long ans = 0;

    void mergeSort(vector<long long>& a, int l, int r, int diff) {
        if (l >= r) return;
        int m = (l + r) / 2;
        mergeSort(a, l, m, diff);

        mergeSort(a, m + 1, r, diff);

        int j = m + 1;

        for (int i = l; i <= m; i++) {
            while (j <= r && a[i] > a[j] + diff) j++;

            ans += (r - j + 1);
        }


        inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1);
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();

           vector<long long> a(n);

        for (int i = 0; i < n; i++) a[i] = nums1[i] - nums2[i];
        mergeSort(a, 0, n - 1, diff);

        return ans;

       }



};

