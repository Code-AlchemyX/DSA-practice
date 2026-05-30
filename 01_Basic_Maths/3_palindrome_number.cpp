#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    int rev=0;

    if(x<0 || (x%10==0 && x!=0)){
        return false;
    }

    while(x>rev){
        rev = rev*10 + x%10;
        x/=10;
    }
    return ( x==rev || x==rev/10 );
}

int main(){
    int x;
    cin >> x;
    cout << isPalindrome(x);
}