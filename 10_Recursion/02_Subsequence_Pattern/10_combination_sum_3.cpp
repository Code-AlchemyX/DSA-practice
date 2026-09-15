class Solution {
public:
    void generate(int k, int n, vector<vector<int>>& result, vector<int> temp, int target, int start) {

        if(k == 0 && target == 0) {
            result.push_back(temp);
            return;
        }

        if (k < 0 || target < 0 || start > 9) {
            return;
        }

        for(int i = start; i <= 9; i++) {

            temp.push_back(i);
            target -= i;

            generate(k - 1, n, result, temp, target, i + 1);

            target += i;
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        int target = n;
        int start = 1;

        generate(k, n, result, temp, target, start);

        return result;
    }
};