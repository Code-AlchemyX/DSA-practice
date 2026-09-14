//! Optimal Approach

class Solution {
public:
    void generate(vector<int> &candidates , vector<vector<int>> &result , int target , vector<int> &temp , int sum , int index , int n){
        if(sum > target){
            return;
        }

        if(sum ==  target){
            result.push_back(temp);
            return;
        }

        if(index == n){
            return;
        }

        temp.push_back(candidates[index]);
        sum += candidates[index];
        
        generate(candidates , result , target , temp , sum , index , n);

        temp.pop_back();
        sum -= candidates[index];
        generate(candidates, result , target , temp , sum , index + 1 , n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        int index = 0;
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> temp;

        generate(candidates , result , target , temp , sum , index , n);

        return result;
    }
};