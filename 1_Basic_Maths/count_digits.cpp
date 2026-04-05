#include<bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    int count=0;
        if(n==0){
            return 1;
        }
        
        while(n>0){
            n = n / 10 ;
            count++;   
        }
    return count;
}

int main(){
    int n;
    cin >> n;
    cout << countDigits(n);
}