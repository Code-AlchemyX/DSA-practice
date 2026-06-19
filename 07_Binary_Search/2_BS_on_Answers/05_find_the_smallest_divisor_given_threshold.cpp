//! Brute Force

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        for (int d = 1; d <= maxi; d++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ceil((double)(nums[i]) / (double)(d));
            }
            if (sum <= threshold) {
                return d;
            }
        }
        return -1;
    }
};


//! Optimal Approach

class Solution {
public:
    int sumByD(vector<int> &arr, int div) {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            //sum = sum + ceil((double)(arr[i]) / (double)(div));   OR --> 
            sum += (arr[i] + div - 1) / div;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        //* If the qs says return -1 then -->
        // if (n > threshold) return -1;

        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};