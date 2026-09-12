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


//!  Print the sum of first n natural numbers --> Method 1
// void sum(int i, int n, int &total_sum){
//     //* Base case
//     if(i > n) return;

//     total_sum += i;
//     sum(i+1 , n , total_sum);
// }

// int main(){
//     int n;
//     cout << "Enter n: " << endl;
//     cin >> n;
    
//     int total_sum = 0;
//     int i = 0;
//     sum(i , n , total_sum);

//     cout << total_sum << endl;

//     return 0;
// }


//!  Print the sum of first n natural numbers --> Method 2
// void func(int n , int sum){
//     //* Base case
//     if(n < 1){
//         cout << sum << endl;
//         return;
//     }

//     func(n-1 , sum + n);
// }

// int main(){
//     int n;
//     cout << "Enter n: " << endl;
//     cin >> n;
    
//     int sum = 0;
//     func(n, sum);

//     return 0;
// }


//! Factorial of n --> Method 1 (counting from n to 1)

// void func(int n, int &fact) {
//     if (n <= 1) {
//         return;
//     }

//     fact *= n;
//     func(n - 1, fact);
// }

// int main() {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     if (n < 0) {
//         return 1;
//     }

//     int fact = 1;
//     func(n, fact);

//     cout << fact << endl;
//     return 0;
// }


//! Factorial of n --> Method 2 (counting from 1 to n)

// void func(int i, int &fact , int n) {
//     if(i > n){
//         return;
//     }

//     func(i+1 , fact , n);
//     fact *= i;
// }

// int main() {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     if (n < 0) {
//         return 1;
//     }

//     int fact = 1;
//     int i = 1;
//     func(i, fact , n);

//     cout << fact << endl;
//     return 0;
// }


//! Factorial of n --> Method 3

// int func(int n) {
//     if(n == 0) return 1;
//     return n*func(n-1);
// }

// int main() {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     cout << func(n) << endl;
//     return 0;
// }