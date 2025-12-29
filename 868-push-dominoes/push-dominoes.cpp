class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> wind(n, 0);

//

        int force = 0;
        for (int i = 0; i < n; i++) {

            if (d[i] == 'R') force = n;
            else if (d[i] == 'L') force = 0;
            else force = max(force - 1, 0);
              wind[i] += force;
          }


        force = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (d[i] == 'L') force = n;
            else if (d[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            wind[i] -= force;
        }
        

        for (int i = 0; i < n; i++) {
            if (wind[i] > 0) d[i] = 'R';
            else if (wind[i] < 0) d[i] = 'L';
            else d[i] = '.';
        }

        return d;
    }
};
