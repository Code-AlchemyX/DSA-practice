class Solution {
  public:
    int floorSqrt(int n) {
        long long ans = 1;
        int low = 1;
        int high = n;
        
        while(low <= high){
            long long  mid = (low + high)/2;
            
            if( mid*mid <= n){
                ans = mid;
                low = mid +1;
            }
            else {
                high = mid -1;
            }
        }
        
        return ans;
    }
};