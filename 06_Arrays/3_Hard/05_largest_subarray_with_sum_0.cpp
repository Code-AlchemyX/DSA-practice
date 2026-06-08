//! ================================================ Brute Force ================================================

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int maxlen = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];

                if (sum == 0) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};


//! ============================================== Optimal Approach ==============================================

class Solution {
  public:
    int maxLength(vector<int>& arr) {
       int n = arr.size();
       int maxlen = 0;
       int sum = 0;
       
       unordered_map<int,int> PreSumMap;
       // sum - index pairs
       
       for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(sum == 0){
                maxlen = i+1;
            }
            else {
                if(PreSumMap.find(sum) != PreSumMap.end()){
                    int len = i - PreSumMap[sum];
                    maxlen = max(maxlen , len);
                }
                else {
                    PreSumMap[sum] = i;
                }
            }
        }
        
        return maxlen;
    }
};