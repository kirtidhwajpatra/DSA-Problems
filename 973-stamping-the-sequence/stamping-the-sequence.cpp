class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size();
        vector<int> ans;

        vector<bool> used(n, false);
        int done = 0;

        auto can = [&](int i) {


            bool hit = false;
            for (int j = 0; j < m; j++) {
                if (target[i + j] == '?') continue;
                
                if (target[i + j] != stamp[j]) return false;
                hit = true;
            }


            return hit;
        };

        auto apply = [&](int i) {
            for (int j = 0; j < m; j++) {

                if (target[i + j] != '?') {


                    target[i + j] = '?';
                    done++;
                }
            }
        };

        while (done < n) {
            bool progress = false;


            for (int i = 0; i + m <= n; i++) {
                if (!used[i] && can(i)) {
                    apply(i);


                      used[i] = true;
                    progress = true;

                    ans.push_back(i);
                    if (done == n) break;
                }
            }
            if (!progress) return {};


        }



        reverse(ans.begin(), ans.end());
        return ans;
    }
};
