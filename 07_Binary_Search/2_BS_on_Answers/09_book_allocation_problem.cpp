class Solution {
  public:
    bool allocationPossible(vector<int> &arr, int k , long long mid){
        // mid = max number of pages that can be alloted to each student
        int studentsAlloted = 1;
        long long pagesAlloted = 0;

        for(int i=0; i<arr.size(); i++){
            if (arr[i] > mid) return false;

            if(pagesAlloted + arr[i] <= mid){
                pagesAlloted += arr[i];
            }
            else{
                studentsAlloted++;
                pagesAlloted = arr[i];
            }
        }   
        
        if(studentsAlloted <= k) return true;
        
        return false;
    }
    
    long long findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(k > n) return -1;
        
        long long low = arr[0];
        long long high = 0;
        for(int i=0; i<n; i++){
            low = max(low , (long long)arr[i]);
            high += arr[i];
        }
        
        long long ans = -1;
        
        while(low <= high){
            long long mid = low + (high - low)/2;
            
            bool check = allocationPossible(arr, k , mid);
            
            if(check){
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};