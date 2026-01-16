class Solution {
public:
    vector<string> findWords(vector<string>& words) {


        unordered_set<char> r1{'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> r2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> r3{'z','x','c','v','b','n','m'};

        vector<string> res;

        for (auto& w : words) {


            unordered_set<char>* row =
                r1.count(tolower(w[0])) ? &r1 :

                r2.count(tolower(w[0])) ? &r2 : &r3;

            bool ok = true;

            for (char c : w)
                if (!row->count(tolower(c))) {
                    ok = false;
                    break;
                }

            if (ok) res.push_back(w);
        }

        return res;

        
    }


};
