//! Brute Force

class Solution {
public:
    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;

        for (int num = 0; num < (1 << n); num++) {
            string s = "";

            for (int i = n - 1; i >= 0; i--) {
                if (num & (1 << i))
                    s += '1';
                else
                    s += '0';
            }

            bool valid = true;

            for (int i = 1; i < n; i++) {
                if (s[i] == '1' && s[i - 1] == '1') {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(s);
        }

        return ans;
    }
};



//! Optimal Approach

