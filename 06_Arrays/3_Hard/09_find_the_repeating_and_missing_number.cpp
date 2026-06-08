//! ============================================== Brute Force ==============================================

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1;
        int missing = -1;

        for (int i = 1; i <= n; i++) {
            int count = 0;
            
            for (int j = 0; j < n; j++) {
                if (arr[j] == i) {
                    count++;
                }
            }

            // Check if the current number is missing or repeating
            if (count == 2) {
                repeating = i;
            } else if (count == 0) {
                missing = i;
            }

            if (repeating != -1 && missing != -1) {
                break;
            }
        }

        return {repeating, missing};
    }
};


//! ============================================ Better Approach 1 ============================================
//* Sorting + Math


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long total_sum = (n*(n+1))/2;
        long long array_sum = 0;
        int repeating_num = -1;
        vector<int> ans;
        
        
        //! Finding the repeating number.
        sort(arr.begin() , arr.end());
        
        for(int i=0; i<n-1; i++){
            if(arr[i] == arr[i+1]){
                ans.push_back(arr[i]);
                repeating_num= arr[i];
                break;
            }    
        }
        
        //! Finding the missing number.
        for(int i=0; i<n; i++){
            array_sum += arr[i];
        }
        
        int missing_num = total_sum - (array_sum - repeating_num);
        ans.push_back(missing_num);
        
        return ans;
    }
};


//! ============================================ Better Approach 2 ============================================
//* Hashing



//! ================================================ Optimal Approach ================================================

