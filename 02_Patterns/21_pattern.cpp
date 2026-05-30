//       *****
//       *   *
//       *   *
//       *   *
//       *****

//!=========================================== METHOD 1 ===========================================

#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern21(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==n-1 || j==0 || j==n-1){
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    Pattern p;
    p.pattern21(n);

    return 0;
}


//!=========================================== METHOD 2 ===========================================


// #include<bits/stdc++.h>
// using namespace std;

// class Pattern
// {
// public:
//     void pattern21(int n){
//         for(int i=0; i<n; i++){
//             if(i==0 || i==n-1){
//                 for(int j=0; j<n; j++){
//                     cout << "*";
//                 }
//             } else {
//                 cout << "*";
//                 for(int j=0; j<n-2; j++){
//                     cout << " ";
//                 }
//                 cout << "*";
//             }
//             cout << endl;
//         }
//     }
// };

// int main()
// {
//     int n;
//     cout << "Enter n : ";
//     cin >> n;

//     Pattern p;
//     p.pattern21(n);

//     return 0;
// }