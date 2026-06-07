//!=========================================== Brute Force ===========================================

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if( nums[i] + nums[j] + nums[k] == 0 ){
                        vector<int> triplet;

                        triplet.push_back(nums[i]);
                        triplet.push_back(nums[j]);
                        triplet.push_back(nums[k]);
                    
                        sort(triplet.begin(), triplet.end());
                        ans.insert(triplet);
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

//!=========================================== Better Approach ===========================================
