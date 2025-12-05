class Solution {
public:
    unordered_map<int,bool> memo;
    
    bool dfs(int used, int total, int maxInt, int desiredTotal) {
        if (total >= desiredTotal) return false;
        if (memo.count(used)) return memo[used];
        
        for (int i = 1; i <= maxInt; i++) {
            int mask = 1 << (i - 1);
            if (used & mask) continue;

            if (!dfs(used | mask, total + i, maxInt, desiredTotal))
                return memo[used] = true;
        }
        return memo[used] = false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;

        if (sum < desiredTotal) return false;
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }
};
