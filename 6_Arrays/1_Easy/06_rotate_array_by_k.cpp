//!================================= METHOD 1 ( EASY to understand )====================================== 

//* Logic ----->

class Solution {
  public:
    void Reverse(vector<int>& arr, int low, int high){
        while(low<high){
            swap(arr[low] , arr[high]);
            low++;
            high--;
        }    
    }
        
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();    
        if(d>=n){
            d %= n;
        }
        
        //Step 1
        Reverse(arr, 0, d-1);
        
        //Step 2
        Reverse(arr, d, n-1);
        
        //Step 3
        Reverse(arr, 0, n-1);
        
    }
};



//!==================================== METHOD 2 =========================================== 
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k, int n) {
    k = k % n;

    // case 1: k < n → k%n = k → k unchanged → runs normally
    // case 2: k = n → k%n = 0 → returns immediately → no rotation
    // case 3: k > n → k%n = remainder → k reduced → runs with new k

    if (k == 0) return;

    vector<int> temp(k);

    for (int i = 0; i < k; i++)
        temp[i] = nums[n-k+i];

    for (int i = n-1; i >= k; i--)
        nums[i] = nums[i-k];

    for (int i = 0; i < k; i++)
        nums[i] = temp[i];
}

int main(){
    int n,k;
    cout << "Enter size of array : " << endl;
    cin >> n;

    cout << "Enter k : "<< endl;
    cin >> k;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    rotate(nums , k , n);

    for(int i=0; i<n; i++){
        cout << nums[i]<<" ";
    }

    return 0;
}