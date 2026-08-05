class Solution {
public:
    string reverseWords(string s) {
        string temp = {};
        int n = s.size();

        for(int i=n-1; i>=0; i--){
            //check for space's' between two words.
            while(i >= 0 && s[i] == ' '){
                i--;
            }
            if(i<0) break;

            // Mark j as end of the word and using while loop find the start of the word.
            int j=i;
            while(i >= 0 && s[i] != ' '){
                i--;
            }

            // Add spaces between words.
            if(!temp.empty()){
                temp.push_back(' ');
            }

            // Append the characters in new array.
            for (int k = i + 1; k <= j; k++){
                temp.push_back(s[k]);
            }
        }   
        return temp;
    }
};