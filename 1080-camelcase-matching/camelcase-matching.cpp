class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto& q : queries) {
            int i = 0, j = 0;
            bool ok = true;
            while (i < q.size()) {
                if (j < pattern.size() && q[i] == pattern[j]) {
                    i++;
                    j++;


                }  else {
                    if (isupper(q[i])) {
                        ok = false;
                        break;
                    }
                    i++;
                }
            }
            if (j != pattern.size()) ok = false;
            res.push_back(ok);
           }


           return res;
    }
};
