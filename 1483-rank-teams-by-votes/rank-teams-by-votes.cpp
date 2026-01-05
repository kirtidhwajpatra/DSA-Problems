class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        vector<vector<int>> cnt(26, vector<int>(n, 0));
        
        
        
        
        for (auto &vote : votes) {
              for (int i = 0; i < n; i++) {


                cnt[vote[i] - 'A'][i]++;
              }
        }
        
        vector<char> teams;
        for (char c : votes[0]) teams.push_back(c);


        
        sort(teams.begin(), teams.end(), [&](char a, char b) {
              for (int i = 0; i < n; i++) {
                if (cnt[a - 'A'][i] != cnt[b - 'A'][i])
                    return cnt[a - 'A'][i] > cnt[b - 'A'][i];
            }
            return a < b;


        });
        
       
       
       
        return string(teams.begin(), teams.end());
    }
};
