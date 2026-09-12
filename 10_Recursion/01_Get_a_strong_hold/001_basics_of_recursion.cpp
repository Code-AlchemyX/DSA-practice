#include<bits/stdc++.h>
using namespace std;

//! Print 1 to n --> Method 1 (print then call)
// void print(int i, int n){
//     //* Base case
//     if(i > n) return;

//     cout << i << endl;
//     print(i+1, n);
// }

// int main(){
//     int n;
//     cout << "Enter n: " << endl;
//     cin >> n;
    
//     int i = 1;
//     print(1, n);

//     return 0;
// }


//! Print 1 to n --> Method 2 (call then print)
// void print(int i, int n){
//     //* Base case
//     if(i < 1) return;

//     print(i-1, n);
//     cout << i << endl;
// }

// int main(){
//     int n;
//     cout << "Enter n: " << endl;
//     cin >> n;
    
//     int i = n;
//     print(i, n);

//     return 0;
// }


//! Print n to 1 --> Method 1
// void print(int i, int n){
//     //* Base case
//     if(i < 1) return;

//     cout << i << endl;
//     print(i-1, n);
// }

// int main(){
//     int n;
//     cout << "Enter n: " << endl;
//     cin >> n;
    
//     int i = n;
//     print(i, n);

//     return 0;
// }


//! Print n to 1 --> Method 2
// void print(int i, int n){
//     //* Base case
//     if(i > n) return;

//     print(i+1, n);
//     cout << i << endl;
// }

// int main(){
//     int n;
//     cout << "Enter n: " << endl;
//     cin >> n;
    
//     int i = 1;
//     print(i, n);

//     return 0;
// }