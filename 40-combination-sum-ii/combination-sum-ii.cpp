class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& c, int target, int start, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }



        for (int i = start; i < c.size(); i++) {
            if (i > start && c[i] == c[i - 1]) continue;
            if (c[i] > target) break;
            temp.push_back(c[i]);
            backtrack(c, target - c[i], i + 1, temp);
            temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> temp;
        backtrack(candidates, target, 0, temp);
        return ans;
    }
};