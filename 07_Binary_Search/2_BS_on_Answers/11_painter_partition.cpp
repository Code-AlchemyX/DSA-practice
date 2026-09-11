class Solution {
  public:
    bool canCompleteInTime(vector<int> &arr, int k, int mid){
        //! mid = the max time alloted.    
        int timeReq = 0; 
        int paintersReq = 1;
        
        for(int i=0; i<arr.size(); i++){
            if(timeReq + arr[i] <= mid){
                timeReq += arr[i];
            }
            else {
                paintersReq++;
                timeReq = arr[i];
            }
        }
        
        if(paintersReq <= k) return true;
        
        return false;
    }
    
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int low = arr[0];
        int high = 0;
        
        for(int i=0; i<n; i++){
            low = max(low , arr[i]);
            high += arr[i];
        }
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            bool check = canCompleteInTime(arr, k , mid);
            
            if(check){
                high = mid -1;
            }
            else {
                low = mid +1;
            }
        }
        
        return low;
    }
};