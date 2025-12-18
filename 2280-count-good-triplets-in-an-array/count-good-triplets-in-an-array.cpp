class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();


        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[nums2[i]] = i;

        vector<int> a(n);
        

        for (int i = 0; i < n; i++) a[i] = pos[nums1[i]];

        vector<int> bit(n + 1, 0);



        auto update = [&](int i) {
            for (++i; i <= n; i += i & -i) bit[i]++;
        };

        auto query = [&](int i) {
            long long s = 0;
            for (++i; i > 0; i -= i & -i) s += bit[i];
            return s;

        };


        vector<long long> left(n), right(n);

        for (int i = 0; i < n; i++) {
            left[i] = query(a[i] - 1);
            update(a[i]);
          }



        fill(bit.begin(), bit.end(), 0);

        for (int i = n - 1; i >= 0; i--) {
              right[i] = query(n - 1) - query(a[i]);
            update(a[i]);
           }


           long long ans = 0;
        for (int i = 0; i < n; i++) ans += left[i] * right[i];
        return ans;
    }
};
