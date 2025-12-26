class Solution {
public:
    bool canCross(vector<int>& stones) {



        unordered_map<int, unordered_set<int>> momentum;
        momentum[0].insert(0);

        unordered_set<int> land(stones.begin(), stones.end());
        int destination = stones.back();

        
        for (int spot : stones) {
            for (int leap : momentum[spot]) {


                for (int shift = -1; shift <= 1; shift++) {
                    int nextLeap = leap + shift;
                    if (nextLeap <= 0) continue;

                    int nextSpot = spot + nextLeap;
                    if (nextSpot == destination) return true;

                     if (land.count(nextSpot)) {
                        momentum[nextSpot].insert(nextLeap);
                    }


                }
            }
           }

        return false;
    }


};
