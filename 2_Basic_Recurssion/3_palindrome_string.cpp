 #include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    string t;

    for(int i=0 ; i<s.size() ; i++){
        char ch = s[i];

        if(ch>='0' && ch<='9'){
            t.push_back(ch);
        }

        if(ch>='a' && ch<='z'){
            t.push_back(ch);
        }

        if(ch>='A' && ch<='Z'){
            t.push_back(ch + 'a' - 'A');
        }
    }

    string rev = t;
    reverse(rev.begin() , rev.end());

    return rev == t;        
}

int main(){
    string s;
    // cin >> s;  --> This doesn't read spaces in sentence.
    getline(cin , s);  // This reads the spaces in the sentence too.
    cout << isPalindrome(s);

    return 0;
}