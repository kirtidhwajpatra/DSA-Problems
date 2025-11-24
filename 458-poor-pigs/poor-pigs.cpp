class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        
        int states = rounds + 1;
        
        int pigs = 0;
        long long possible = 1;
        
        while (possible < buckets) {

            pigs++;
            possible *= states;
        }
        
        return pigs;
    }
};
