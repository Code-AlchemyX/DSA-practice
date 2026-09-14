//! Brute Force

class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for(char ch : s) {
            if(ch == '(')
                balance++;
            else
                balance--;

            if(balance < 0)
                return false;
        }

        return balance == 0;
    }

    void generate(string s, vector<string>& result, int count, int n) {

        if(count == 2 * n) {
            if(isValid(s))
                result.push_back(s);

            return;
        }

        s.push_back('(');
        generate(s, result, count + 1, n);
        s.pop_back();

        s.push_back(')');
        generate(s, result, count + 1, n);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string s;

        generate(s, result, 0, n);

        return result;
    }
};



//! Optimal Approach 


class Solution {
public:
    void generate(string s , vector<string> &result , int left , int right){
        if(left == 0 && right == 0){
            result.push_back(s);
            return;
        }

        if(left > 0){
            s.push_back('(');
            left--;

            generate(s , result , left , right);

            s.pop_back();
            left++;
        }

        if(right > left){
            s.push_back(')');
            right--;
            
            generate(s , result , left , right);
        
            s.pop_back();
            right++;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        int left = n;
        int right = n;

        generate(s , result , left , right);
        
        return result;
    }
};
