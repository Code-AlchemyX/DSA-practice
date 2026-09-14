class Solution {
public:
    void generate(vector<int> &candidates, vector<vector<int>> &result, int target, vector<int> &temp, int index) {
        if(target == 0) {
            result.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i - 1]) continue;

            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);

            generate(candidates , result , target - candidates[i] , temp , i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int index = 0;

        sort(candidates.begin(), candidates.end());

        generate(candidates, result, target, temp, index);

        return result;
    }
};