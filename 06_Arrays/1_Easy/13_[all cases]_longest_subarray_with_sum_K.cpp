//! ============================================ Brute Force ============================================
//! TC = O(n²) | SC = O(1) | Works for all cases

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum == k){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }

        return maxLen;
    }
};


//! ================================ Optimal (Positives + Negatives + Zeros) ================================
//! TC = O(n) avg [using unordered_map] | O(n log n) [using map]
//! SC = O(n) | Prefix Sum + Hashmap

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];

            if(sum == k){
                maxLen = max(maxLen, i+1);
            }

            long long rem = sum - k;
            if(preSumMap.find(rem) != preSumMap.end()){
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            if(preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};


//! ==================================== Optimal (Positives + Zeros Only) ====================================
//! TC = O(n) | SC = O(1) | Sliding Window

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int i = 0, j = 0;
        int sum = nums[0];

        while(j < n){
            while(i <= j && sum > k){
                sum -= nums[i];
                i++;
            }

            if(sum == k){
                maxLen = max(maxLen, j-i+1);
            }

            j++;
            if(j < n){
                sum += nums[j];
            }
        }

        return maxLen;
    }
};