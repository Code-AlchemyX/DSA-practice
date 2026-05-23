#include<bits/stdc++.h>
using namespace std;

// Condition --> If there exists a solution it only has one pair in array whose sum = target. 
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(target - nums[i]) > 0) {
            return {mp[target - nums[i]], i};
        }
        mp[nums[i]] = i;
    }

    return {-1, -1};
}

int main(){
    int n,target;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter target : ";
    cin >> target;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<int> result = twoSum(nums , target);
    cout << result[0] << " " << result[1];

    return 0;
}