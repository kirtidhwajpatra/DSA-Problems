class Solution {
public:
    int power(int base, int exp) {
        int res = 1;
        base %= 1337;

        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1337;
            base = (base * base) % 1337;
            exp /= 2;
        }
        return res;
    }



    int superPow(int a, vector<int>& b) {
        
        if (b.empty()) return 1;

        int lastDigit = b.back();


        b.pop_back();
        int part1 = power(superPow(a, b), 10);
        int part2 = power(a, lastDigit);
        return (part1 * part2) % 1337;
    }
};
