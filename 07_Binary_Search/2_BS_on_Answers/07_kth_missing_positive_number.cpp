//! ============================================ Brute Force 1 ============================================

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) {
                k++;
            } else {
                break;
            }
        }
        return k;
    }
};


//! ============================================ Brute Force 2 ============================================

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int current = 1;
        int i = 0;

        while(missing.size() < k){
            if(i < arr.size() && arr[i] == current){
                i++;
            }
            else {
                missing.push_back(current);
            }
            current++;
        }

        return missing[k-1];
    }
};

//! =========================================== Optimal Approach ===========================================

// Dry run and derivation of the formula and logic is MUST ... Or else you'll be blank.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            
            int missing_count = arr[mid] - mid - 1;

            if(missing_count < k){
                low = mid +1;
            }
            else {
                high = mid -1;
            }  
        }

        return low + k;
    }
};