//!========================================= Brute force =========================================

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum == k){
                    count++;
                }
            }
        }

        return count;
    }
};


//! ====================================== Optimal Approach =======================================

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;

        // sum - freq pairs
        unordered_map<int,int> PreSumMap;
        PreSumMap[0] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];

            int rem = sum - k;
            count += PreSumMap[rem];

            PreSumMap[sum]++;
        }

        return count;
    }
};