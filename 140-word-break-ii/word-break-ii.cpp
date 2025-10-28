
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return dfs(s, dict, memo);
    }
    
    vector<string> dfs(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
        if (memo.count(s)) return memo[s];
        vector<string> result;
        if (dict.count(s)) result.push_back(s);
        for (int i = 1; i < s.size(); i++) {
            string prefix = s.substr(0, i);
            if (dict.count(prefix)) {
                string suffix = s.substr(i);
                vector<string> temp = dfs(suffix, dict, memo);
                for (auto& t : temp) result.push_back(prefix + " " + t);
            }
        }
        return memo[s] = result;
    }
};
