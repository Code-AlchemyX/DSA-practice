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

