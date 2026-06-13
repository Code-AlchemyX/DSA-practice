class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low)/2;

            // If the array isn't rotated , the search space is already sorted
            if(nums[low] <= nums[high]){
                ans = min(ans , nums[low]);
                break;
            }

            if(nums[low] <= nums[mid]){           // Left side is sorted.
                ans = min(ans , nums[low]);
                low = mid +1;
            }
            else {                                // Right side is sorted.      
                ans = min(ans , nums[mid]);
                high = mid -1;
            }
        }

        return ans;
    }
};