//! ========================= Brute force --> Any sorting methods ===========================

//! ==================================== Better approach ====================================
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = int(n/2);
        unordered_map<int,int> mp;

        for(auto it : nums){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second > target){
                return it.first;
            }
        }
        return -1;
    }
};


//!============================== Optimal approach --> Moore's Voting method ==============================
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int element;

        for(int i=0; i<n; i++){
            if(count == 0){
                count = 1;
                element = nums[i];
            } else if(nums[i] == element){
                count++;
            } else {
                count--;
            }
        }

        int counter = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == element){
                counter++;
            }
        }

        if( counter > int(n/2) ){
            return element;
        }

        return -1;
    }
};

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> nums[i];

    Solution s;
    cout << "Majority element: " << s.majorityElement(nums) << endl;

    return 0;
}