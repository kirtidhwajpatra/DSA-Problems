class Solution {
    vector<vector<int>> rects;
    vector<int> prefix;
    int total;

public:


    Solution(vector<vector<int>>& rects) : rects(rects), total(0) {

        
        for (auto& r : rects) {


            int count = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            total += count;
            prefix.push_back(total);
        }
    }




    vector<int> pick() {


        int k = rand() % total + 1;
        int idx = lower_bound(prefix.begin(), prefix.end(), k) - prefix.begin();

        auto& r = rects[idx];
        int x = r[0] + rand() % (r[2] - r[0] + 1);
        int y = r[1] + rand() % (r[3] - r[1] + 1);

        return {x, y};
    }
};
