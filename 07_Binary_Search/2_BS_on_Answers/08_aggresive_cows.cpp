//!============================================ Brute Force ============================================

class Solution {
  public:
    bool canWePlace(vector<int>& stalls , int dist , int cows){
        int n = stalls.size();
        int cntCows = 1;
        int last = stalls[0];
        
        for(int i=1; i<n; i++){
            if(stalls[i] - last >= dist){
                cntCows++;
                last = stalls[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin() , stalls.end());
        
        int limit = stalls[n-1] - stalls[0];
        for(int i=0; i <= limit; i++){
            if(canWePlace(stalls, i, k) == true){
                continue;
            } else {
                return i-1;
            }
        }
        return limit;
    }
};

//! ========================================== Optimal Approach ==========================================

class Solution {
  public:
    bool canWePlace(vector<int>& stalls , int dist , int cows){
        int n = stalls.size();
        int cntCows = 1;
        int last = stalls[0];
        
        for(int i=1; i<n; i++){
            if(stalls[i] - last >= dist){
                cntCows++;
                last = stalls[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin() , stalls.end());
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canWePlace(stalls, mid, k) == true) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
