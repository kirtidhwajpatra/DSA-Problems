class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> map(n);


           vector<int> gravity(n), path;
        queue<int> open;

        for (auto& e : edges) {


            map[e[1]].push_back(e[0]);
            gravity[e[0]]++;
        }

        for (int i = 0; i < n; i++)
            if (!gravity[i]) open.push(i);

        while (!open.empty()) {
            int now = open.front(); open.pop();
            path.push_back(now);

            for (int next : map[now])
                if (--gravity[next] == 0)
                    open.push(next);
            }

        return path.size() == n ? path : vector<int>{};
   
   
   
   
      }

      
};
