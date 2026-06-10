//! Brute Force --> Linear Search.

//! Optimal Approach -->

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = n; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

        //*maybe an answer.
            if (arr[mid] >= target) {
                ans = mid; 
                high = mid-1;   //look for more small index on left
            } else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};