class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> length(n + 1);
        length[0] = 1;

        // Build lengths safely (cap at k)
        for (int i = 1; i <= n; i++) {
            length[i] = min(length[i - 1] * 2, k);
        }

        int shift = 0;

        // Reverse traversal
        for (int i = n; i > 0; i--) {
            long long half = length[i - 1];

            if (k > half) {
                k -= half;
                if (operations[i - 1] == 1) {
                    shift++;
                }
            }
        }

        return char('a' + (shift % 26));
    }
};
