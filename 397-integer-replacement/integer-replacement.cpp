class Solution {
public:
    int integerReplacement(int n) {
        long long value = n;
        int moves = 0;

          while (value != 1) {
            if ((value & 1) == 0) {
                value >>= 1;
            } 
            
            else {
                if (value == 3 || ((value >> 1) & 1) == 0) {
                    value--;
                } else {
                    value++;
                }
            }
            moves++;
            }

      
      
        return moves;
    }
};
