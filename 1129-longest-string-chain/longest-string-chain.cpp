class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        unordered_map<string, int> memory;
        int best = 1;


        
        for (auto &w : words) {


            int depth = 1;
            
            for (int i = 0; i < w.size(); i++) {


                   string shadow = w.substr(0, i) + w.substr(i + 1);
                if (memory.count(shadow)) {
                    depth = max(depth, memory[shadow] + 1);
                }
                 }
            
            memory[w] = depth;
            best = max(best, depth);

        }
        
        return best;
   
   
    }
};
