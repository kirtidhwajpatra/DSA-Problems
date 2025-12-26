class Solution {
public:

    bool wordBreak(string text, vector<string>& bank) {

        
        unordered_set<string> lexicon(bank.begin(), bank.end());
        int n = text.size();

        vector<char> reachable(n + 1, 0);
        reachable[0] = 1;

        
        
        for (int anchor = 0; anchor < n; anchor++) {

            if (!reachable[anchor]) continue;

            string probe;
            for (int cursor = anchor; cursor < n; cursor++) {
                probe.push_back(text[cursor]);
                if (lexicon.count(probe)) {
                    reachable[cursor + 1] = 1;
                }

                  }

        }


        return reachable[n];
    }
};
