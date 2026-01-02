class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(2, 0)));

        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int m = 0; m < n; m++) {


              for (int c = 0; c < n; c++) {
                degree[m][c][0] = graph[m].size();

                degree[m][c][1] = graph[c].size();
                for (int x : graph[c]) if (x == 0) degree[m][c][1]--;


            }
        }



           queue<tuple<int,int,int>> q;

        for (int i = 1; i < n; i++) {


            color[0][i][0] = color[0][i][1] = 1;
            q.emplace(0, i, 0);
            q.emplace(0, i, 1);

              color[i][i][0] = color[i][i][1] = 2;
            q.emplace(i, i, 0);
            q.emplace(i, i, 1);


        }

        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();
            int cur = color[m][c][t];

            if (t == 0) {
                for (int pc : graph[c]) {
                    if (pc == 0 || color[m][pc][1]) continue;
                    if (cur == 2) {


                        color[m][pc][1] = 2;
                        q.emplace(m, pc, 1);
                    } 
                    else if (--degree[m][pc][1] == 0) {

                        color[m][pc][1] = 1;
                        q.emplace(m, pc, 1);
                    }
                }
            } else {
                for (int pm : graph[m]) {
                    if (color[pm][c][0]) continue;


                    if (cur == 1) {

                        color[pm][c][0] = 1;
                        q.emplace(pm, c, 0);
                    } else if (--degree[pm][c][0] == 0) {
                        color[pm][c][0] = 2;
                        q.emplace(pm, c, 0);
                 
                 
                 
                    }
                     }
            }
        }




        return color[1][2][0];
    }
};
