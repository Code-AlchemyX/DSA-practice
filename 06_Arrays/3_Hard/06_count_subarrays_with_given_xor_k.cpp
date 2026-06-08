//! ========================================== Brute Force ==========================================

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long n = arr.size();
        long count = 0;
        
        for(long i=0; i<n; i++){
            long XOR = 0;
            
            for(long j=i; j<n; j++){
                XOR = XOR ^ arr[j];
                
                if( XOR == k){
                    count++;
                }
            }
        }
        return count;
    }
};

//! ========================================= Optimal Approach =========================================

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long n = arr.size();
        long count = 0;
        long XOR = 0;
        
        map<int,int> mp;
        mp[XOR]++;          // { (0,1) }
        
        
        for(int i=0; i<n; i++){
            XOR = XOR ^ arr[i];
            
            int x = XOR ^ k;
            count += mp[x];
            
            mp[XOR]++;
        }
        
        return count;
    }
};
