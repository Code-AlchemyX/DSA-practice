#include<bits/stdc++.h>
using namespace std;

bool armstrongNumber(int n) {
    int count=0, sum=0, original=n;
        
    if(n<0){
        return false;
        }
        
    int temp = n;
    while(temp>0){
        temp/=10;
        count++;
    }
        
    while(n>0){
        sum += pow(n%10 , count);
        n/=10;
    }
    return sum == original;
}

int main(){
    int n;
    cin >> n;
    cout << armstrongNumber(n);
}