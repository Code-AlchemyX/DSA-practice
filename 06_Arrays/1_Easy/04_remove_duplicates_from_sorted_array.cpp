//! =========================================== Brute Force ===========================================

vector<int> removeDuplicates(vector<int> &arr) {
    vector<int> temp;

    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] != arr[i+1]) {
            temp.push_back(arr[i]);
        }
    }

    temp.push_back(arr[arr.size()-1]);

    return temp;
}

//! =========================================== Optimal Approach ===========================================

class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        int n = arr.size();
        int i = 0;  // tracks last unique element position
        
        for(int j=1; j<n; j++){
            if(arr[j] != arr[i]){  // new unique element found
                i++;
                arr[i] = arr[j];   // place it at next position
            }
        }
        
        // first i+1 elements are unique
        return vector<int>(arr.begin(), arr.begin()+i+1);
    }
};

//* return i --> if qs asks to return how many unique numbers are there.