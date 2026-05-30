#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int i=0; i<nums.size(); i++){
        result = result^nums[i];
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout << singleNumber(nums);

    return 0;
}