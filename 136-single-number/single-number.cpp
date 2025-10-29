class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int uniqueElement = 0;
        for( int i : nums){
            uniqueElement^=i;
        }

        return uniqueElement;
        
    }
};