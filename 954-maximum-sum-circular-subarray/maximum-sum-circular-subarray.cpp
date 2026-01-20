class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int total = 0;
        int hi = a[0], lo = a[0];
        int runHi = 0, runLo = 0;

        for (int x : a) {


            runHi = max(x, runHi + x);
            hi = max(hi, runHi);

            runLo = min(x, runLo + x);

            lo = min(lo, runLo);

            total += x;
        }

        if (hi < 0) return hi;
       
       return max(hi, total - lo);

       
    }
};
