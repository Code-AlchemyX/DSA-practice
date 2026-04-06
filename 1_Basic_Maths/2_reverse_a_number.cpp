#include<bits/stdc++.h>
using namespace std;

int reverseDigits(int n) {
    int rev = 0;
    if(n==0){
        return 0;
    }
        
    while(n>0){
        rev = rev*10 + n%10;
        n/=10;
    }
    return rev;
}

int main(){
    int n;
    cin >> n;
    cout << reverseDigits(n);
}