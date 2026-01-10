

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> result;
        vector<int> indices_a, indices_b;


        int n = s.length();
        int len_a = a.length();

        int len_b = b.length();


        for (int i = 0; i <= n - len_a; ++i) {
            
            if (s.compare(i, len_a, a) == 0) {
                indices_a.push_back(i);
            }
             }

        for (int j = 0; j <= n - len_b; ++j) {
            if (s.compare(j, len_b, b) == 0) {
                indices_b.push_back(j);
            }
        }

        for (int i : indices_a) {

            auto it = lower_bound(indices_b.begin(), indices_b.end(), i - k);

            if (it != indices_b.end() && *it <= i + k) {
                result.push_back(i);
          
          
          
              }


        }

        return result;
   
   
   
   
      }
};