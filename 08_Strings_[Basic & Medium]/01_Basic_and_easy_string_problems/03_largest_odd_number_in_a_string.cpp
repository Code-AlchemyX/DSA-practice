class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

//! Check why num[i] - '0' is used not directly num[i].
//! Also check why int(nums[i]) isn't used for conversion.

        for(int i=n-1; i>=0; i--){
            if( (num[i] - '0') % 2 != 0 ){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};