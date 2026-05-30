//! Brute force --> Any sorting method.

//! Better Approach --> Counting the number of 0's , 1's and 2's then overwriting the same array.

//! Optimal Approach --> Dutch National Flag Algorithm.

//* Named by Edsger Dijkstra — he used the Dutch flag (3 colored stripes) as the analogy for sorting 3 distinct values.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid] , nums[low]);
                low++;
                mid++;
            } else if(nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid] , nums[high]);
                high--;
            }
        }
    }
};

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (0,1,2 only): ";
    for(int i=0; i<n; i++)
        cin >> nums[i];

    Solution s;
    s.sortColors(nums);

    cout << "Sorted: ";
    for(auto it : nums)
        cout << it << " ";
    cout << endl;

    return 0;
}