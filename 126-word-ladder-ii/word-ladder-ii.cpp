class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        unordered_map<string, vector<string>> parents;
        unordered_set<string> curr, next;
        curr.insert(beginWord);
        bool found = false;
        while (!curr.empty() && !found) {
            for (auto& w : curr) dict.erase(w);
            for (auto& w : curr) {
                string s = w;
                for (int i = 0; i < s.size(); i++) {
                    char c = s[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        s[i] = ch;
                        if (!dict.count(s)) continue;
                        next.insert(s);
                        parents[s].push_back(w);
                        if (s == endWord) found = true;
                    }
                    s[i] = c;
                }
            }
            swap(curr, next);
            next.clear();
        }
        vector<vector<string>> res;
        if (!found) return res;
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, res);
        return res;
    }
    void dfs(string& word, string& beginWord, unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> tmp = path;
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            return;
        }
        for (auto& p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};
