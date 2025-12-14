class Solution {
public:
    int ans = INT_MAX;
    
    void backtrack(vector<int>& cookies, vector<int>& buckets, int i) {
        if (i == cookies.size()) {

            int mx = 0;
            for (int x : buckets) mx = max(mx, x);
            ans = min(ans, mx);
            return;
          }


        for (int j = 0; j < buckets.size(); j++) {
            buckets[j] += cookies[i];
            if (buckets[j] < ans) backtrack(cookies, buckets, i + 1);
            buckets[j] -= cookies[i];
            if (buckets[j] == 0) break;
          }

          
    }


    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> buckets(k, 0);
        backtrack(cookies, buckets, 0);
        return ans;
    }
};
