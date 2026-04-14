#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, maxCount = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }

    return maxCount;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout << findMaxConsecutiveOnes(nums);

    return 0;
}