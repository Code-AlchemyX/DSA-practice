//! Brute Force

class Solution {
public:

    bool isValid(string s) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '1' && s[i - 1] == '1')
                return false;
        }

        return true;
    }

    void generate(string s, vector<string>& result, int n) {

        if(s.size() == n) {
            if(isValid(s))
                result.push_back(s);

            return;
        }

        // Choose 0
        s.push_back('0');
        generate(s, result, n);
        s.pop_back();

        // Choose 1
        s.push_back('1');
        generate(s, result, n);
        s.pop_back();
    }

    vector<string> generateBinaryStrings(int n) {

        string s;
        vector<string> result;

        generate(s, result, n);

        return result;
    }
};




//! Optimal Approach

class Solution {
public:
    void generate(string s , vector<string> &result , int n){
        if(s.size() == n){
            result.push_back(s);
            return;
        }

        s.push_back('0');
        generate(s , result , n);
        s.pop_back();

        if(s.empty() || s.back() != '1'){
            s.push_back('1');
            generate(s , result , n);
            s.pop_back();
        }
    }

    vector<string> generateBinaryStrings(int n) {
        string s;
        vector<string> result;

        generate(s , result , n);

        return result;
    }
};
