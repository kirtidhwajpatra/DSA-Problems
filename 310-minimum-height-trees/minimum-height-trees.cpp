class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        
        vector<vector<int>> graph(n);
         vector<int> degree(n);
        
        for (auto &e : edges) {


            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
              degree[e[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        
        int remaining = n;
        
        while (remaining > 2) {
            int layer = q.size();
            remaining -= layer;
            
            while (layer--) {
                int node = q.front(); q.pop();

                for (int next : graph[node]) {

                    if (--degree[next] == 1) {
                        q.push(next);
                    }
              
                  
                   }
            }
        }
        
        vector<int> answer;
        while (!q.empty()) {
            answer.push_back(q.front());
            q.pop();
          }
        
     
     
     
        return answer;
    }
};
