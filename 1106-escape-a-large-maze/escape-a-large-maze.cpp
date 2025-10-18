
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.empty()) return true;
        unordered_set<long long> st;
        for (auto& b : blocked) st.insert(((long long)b[0] << 20) | b[1]);
        auto bfs = [&](vector<int>& start, vector<int>& end) {
            unordered_set<long long> vis;
            queue<pair<int,int>> q;
            q.push({start[0], start[1]});
            vis.insert(((long long)start[0] << 20) | start[1]);
            int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
            int limit = blocked.size() * (blocked.size() - 1) / 2;
            while (!q.empty() && vis.size() <= limit) {
                auto [x,y] = q.front();
                q.pop();
                if (x == end[0] && y == end[1]) return true;
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || ny < 0 || nx >= 1e6 || ny >= 1e6) continue;
                    long long key = ((long long)nx << 20) | ny;
                    if (st.count(key) || vis.count(key)) continue;
                    vis.insert(key);
                    q.push({nx, ny});
                }
            }
            return vis.size() > limit;
        };
        return bfs(source, target) && bfs(target, source);
    }
};
