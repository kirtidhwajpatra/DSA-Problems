class Solution {
public:
    map<vector<int>, int> memo;
    
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        if (memo.count(needs)) return memo[needs];
        int n = price.size();
        int res = 0;

        for (int i = 0; i < n; i++) res += needs[i] * price[i];
        for (auto& sp : special) {


            bool ok = true;
            vector<int> nxt = needs;
            for (int i = 0; i < n; i++) {
                if (nxt[i] < sp[i]) {
                    ok = false;
                    break;
                }
                nxt[i] -= sp[i];
            }
            if (ok) res = min(res, sp[n] + dfs(price, special, nxt));
        }
        
        return memo[needs] = res;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};
