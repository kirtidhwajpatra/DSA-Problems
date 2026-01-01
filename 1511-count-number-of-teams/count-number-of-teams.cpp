class Solution {
public:
    int numTeams(vector<int>& rating) {


    int n = rating.size();
        int ans = 0;

        for (int j = 1; j < n - 1; j++) {
              int leftSmall = 0, leftLarge = 0;
            int rightSmall = 0, rightLarge = 0;

            for (int i = 0; i < j; i++) {


                  if (rating[i] < rating[j]) leftSmall++;
                else leftLarge++;
              }

            for (int k = j + 1; k < n; k++) {

                 if (rating[k] < rating[j]) rightSmall++;
                else rightLarge++;

            }

            ans += leftSmall * rightLarge;
            ans += leftLarge * rightSmall;


            }
 


        return ans;
    }
};
