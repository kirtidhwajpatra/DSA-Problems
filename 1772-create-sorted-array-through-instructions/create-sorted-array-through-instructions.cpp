class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int MOD = 1e9 + 7;
        int maxv = 100000;
        vector<int> bit(maxv + 2, 0);

        auto add = [&](int i, int v) {

            for (; i <= maxv; i += i & -i) bit[i] += v;

        };

        auto sum = [&](int i) {

            int s = 0;
            for (; i > 0; i -= i & -i) s += bit[i];
            return s;

        };


        long long ans = 0;
         for (int x : instructions) {
             int left = sum(x - 1);
            int right = sum(maxv) - sum(x);
            ans = (ans + min(left, right)) % MOD;
            add(x, 1);

        }

          return ans;
       }



};
