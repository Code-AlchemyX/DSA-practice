//! --------------------------------------------- FLOOR --------------------------------------------- 


//* -------------------- Brute Force --------------------- 

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int flr = -1;
        
        for(int i=n-1; i>=0; i--){
            if(arr[i] <= x){
                flr = i;
                break;
            }
        }
        
        return flr;
    }
};

//* ------------------ Optimal Approach --------------------

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int flr = -1;
        
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] <= x){
                flr = mid;
                low = mid +1;
            } else {
                high = mid -1;
            }
        }
        
        return flr;
    }
};





//! --------------------------------------------- CEIL --------------------------------------------- 

//* -------------------- Brute Force --------------------- 

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int cl = -1;
        
        for(int i=0; i<n; i++){
            if(arr[i] >= x){
                cl = i;
                break;
            }
        }
        
        return cl;
        
    }
};


//* ------------------ Optimal Approach --------------------

class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int cl = -1;
        
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] >= x){
                cl = mid;
                high = mid -1;
            } else {
                low = mid +1;
            }
        }
        
        return cl;
        
    }
};
