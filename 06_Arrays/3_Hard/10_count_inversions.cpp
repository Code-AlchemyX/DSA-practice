//!============================================= Brute Force =============================================

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int count = 0;
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] > arr[j]){
                    count++;
                }
            }
        }
        
        return count;
    }
};

//!=========================================== Optimal Approach ===========================================

class Solution {
  public:
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;   
        int right = mid + 1;   
    
        // cnt variable to store the count of pairs
        int count = 0;
    
        // storing elements in the temporary array in a sorted manner 
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                // Calculate the inversions
                count += (mid - left + 1);
                right++;
            }
        }
    
        // if elements on the left half are still left 
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    
        // if elements on the right half are still left 
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        // transferring all elements from temporary to arr 
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    
        return count; 
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int count = 0;
        if (low >= high){
            return count;
        }

        int mid = (low + high) / 2 ;
        
        count += mergeSort(arr, low, mid);  // left half
        count += mergeSort(arr, mid + 1, high); // right half
        count += merge(arr, low, mid, high);  // merging of two halves
        
        return count;
    }

    int inversionCount(vector<int> &arr) {
        // Count the number of pairs:
        return mergeSort(arr, 0, arr.size() - 1);
    }
};