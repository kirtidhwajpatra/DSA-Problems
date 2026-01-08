class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // Start with the first array's extremes
        int globalMin = arrays[0][0];
         int globalMax = arrays[0].back();
        
        int answer = 0;

        // Traverse remaining arrays
        for (int i = 1; i < arrays.size(); i++) {


            int currMin = arrays[i][0];
            int currMax = arrays[i].back();

            //formingg max distance..
              answer = max(answer, abs(currMax - globalMin));


            answer = max(answer, abs(globalMax - currMin));

            // Update global extremes
            globalMin = min(globalMin, currMin);


            globalMax = max(globalMax, currMax);
          }

        return answer;
    }
};
