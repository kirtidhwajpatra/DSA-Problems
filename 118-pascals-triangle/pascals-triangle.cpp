class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int layer = 0; layer < numRows; layer++) {
            vector<int> row(layer + 1, 1);

            for (int slot = 1; slot < layer; slot++) {

                
                row[slot] = triangle[layer - 1][slot - 1]
                          + triangle[layer - 1][slot];
            }

               triangle.push_back(move(row));
        }



        return triangle;
    }
};
