//!============================================ Brute Force - 1 ============================================
//* Easiest solution 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = -1 , end = -1;
        
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                if(start == -1){
                    start = i;
                }
                end = i;
            }
        }

        return {start , end};
    }
};


//!============================================ Brute Force - 2 ============================================
 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = -1;
        int end = -1;

        // 1. Scan from left to right to find the FIRST occurrence
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                start = i;
                break; // Stop immediately at the first match
            }
        }

        // 2. Scan from right to left to find the LAST occurrence
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == target) {
                end = i;
                break; // Stop immediately at the first match from the back
            }
        }

        return {start, end};
    }
};


//!============================================ Brute Force - 3 ============================================
//* This solution i've derived myself :)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = -1;
        int end = -1;

        for(int i=0; i<n; i++){
            if(nums[i] == target){
                start = i;
                int j = i;
                while( j < n  &&  nums[j] == target){
                    j++;
                }
                end = j-1;
                break;
            }
        }

        return {start , end};
    }
};



//!=============================================== Optimal Approach 1 ===============================================

class Solution {
public:
    int firstOccurence(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int first = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                first = mid;
                high = mid -1;
            }
            else if(nums[mid] < target){
                low = mid +1;
            } 
            else {
                high = mid -1;
            }
        }

        return first;  
    }

    int lastOccurence(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int last = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                last = mid;
                low = mid +1;
            } 
            else if(nums[mid] < target){
                low = mid +1;
            }
            else {
                high = mid -1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = firstOccurence(nums , target);

        //* This loop saves time of logn. [not compulsory tho]
        if(first == -1){
            return {-1,-1};
        }

        int last = lastOccurence(nums , target);

        return {first , last};
    }
};


//!=============================================== Optimal Approach 2 ===============================================

class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid -1;
            } else {
                low = mid +1;
            }
        }
        return ans;  
    }

    int upperBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] > target){
                ans = mid;
                high = mid -1;
            } else {
                low = mid +1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int lb = lowerBound(nums , target);
        int ub = upperBound(nums , target);

        if(lb == n || nums[lb] != target){
            return {-1,-1};
        }

        return {lb , ub-1};
    }
};