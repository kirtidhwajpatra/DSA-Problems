class Solution {
public:
    int n;
    vector<vector<vector<pair<int,int>>>> paths;
    int ans = 0;

    bool valid(const vector<vector<pair<int,int>>>& cur) {
        int mx = 0;
        for (auto& v : cur) mx = max(mx, (int)v.size());


        for (int t = 0; t < mx; t++) {
              set<pair<int,int>> s;
            for (auto& v : cur) {

                pair<int,int> p = t < v.size() ? v[t] : v.back();
                if (s.count(p)) return false;
                s.insert(p);
            }


           }
        return true;
    }



    void dfs(int i, vector<vector<pair<int,int>>>& cur) {


           if (i == n) {
            if (valid(cur)) ans++;
            return;
        }
        for (auto& p : paths[i]) {
            cur.push_back(p);
            dfs(i + 1, cur);
            cur.pop_back();
        }
    }

    vector<vector<pair<int,int>>> gen(string& piece, int r, int c) {
        vector<vector<pair<int,int>>> res;
        vector<pair<int,int>> dirs;

        if (piece == "rook" || piece == "queen") {
            dirs.push_back({1,0});
            dirs.push_back({-1,0});
            dirs.push_back({0,1});
            dirs.push_back({0,-1});
        }
        if (piece == "bishop" || piece == "queen") {
            dirs.push_back({1,1});
            dirs.push_back({1,-1});
            dirs.push_back({-1,1});
            dirs.push_back({-1,-1});
        }

        res.push_back({{r,c}});
        for (auto& d : dirs) {
            vector<pair<int,int>> path;
            int x = r, y = c;
            path.push_back({x,y});
            while (true) {
                x += d.first;
                y += d.second;
                if (x < 1 || x > 8 || y < 1 || y > 8) break;
                path.push_back({x,y});
                res.push_back(path);
               }
        }



        return res;
    }

    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        n = pieces.size();
        paths.resize(n);
        for (int i = 0; i < n; i++) {
            paths[i] = gen(pieces[i], positions[i][0], positions[i][1]);
        }
        vector<vector<pair<int,int>>> cur;
        dfs(0, cur);

        return ans;

       }
};
