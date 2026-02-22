class Solution {
public:
    int findfirst(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        int ans = -1;

        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                ans = mid;
                end = mid-1; //to find the left target
            } else if(nums[mid]<target){
                start=mid+1;
            } else {
                end=mid-1;
            }
        }
        return ans;
    }

    int findlast(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        int ans = -1;

        while(start<=end){
            int mid= start+(end-start)/2;
            if(nums[mid]==target){
                ans = mid;
                start = mid+1; //to find the right target
            } else if(nums[mid]<target){
                start=mid+1;
            } else {
                end=mid-1;
            }
        }
        
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftAnswer = findfirst(nums, target);
        int rightAnswer = findlast(nums, target);

        return {leftAnswer, rightAnswer};
    }
};