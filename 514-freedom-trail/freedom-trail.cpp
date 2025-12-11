class Solution {
public:
    int n, m;
    string ring, key;
    unordered_map<char, vector<int>> pos;

    vector<vector<int>> dp;

    int solve(int i, int j) {
        if (j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for (int nxt : pos[key[j]]) {
            int dist = abs(nxt - i);
            int step = min(dist, n - dist);  
            ans = min(ans, step + 1 + solve(nxt, j + 1));
        }
        return dp[i][j] = ans;
    }

    int findRotateSteps(string ring, string key) {
        this->ring = ring;
        this->key = key;
        n = ring.size();
        m = key.size();

        for (int i = 0; i < n; i++) pos[ring[i]].push_back(i);

        dp.assign(n, vector<int>(m, -1));
        return solve(0, 0);
    }
};