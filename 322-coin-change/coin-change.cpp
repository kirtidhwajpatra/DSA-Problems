class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = amount + 1;

        vector<int> best(amount + 1, INF);

        best[0] = 0;

        for (int value = 1; value <= amount; value++) {
            for (int unit : coins) {

                if (unit <= value) {
                    best[value] = min(best[value], best[value - unit] + 1);
                }
             
               }
        }

        return best[amount] > amount ? -1 : best[amount];
    }

    
};
