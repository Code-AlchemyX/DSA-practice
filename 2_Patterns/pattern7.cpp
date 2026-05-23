//!=========================================== METHOD 1 ===========================================

#include <bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern7(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // spaces = (n-1-i) times
            for (int j = 0; j < n - 1 - i; j++)
            {
                cout << " ";
            }

            // stars = (2*i+1) times
            for (int j = 0; j < 2 * i + 1; j++)
            {
                cout << "*";
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
    p.pattern7(n);

    return 0;
}



//!=========================================== METHOD 2 ===========================================


// #include<bits/stdc++.h>
// using namespace std; 

// class Pattern {
// public:
//     void pattern7(int n) {
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=2*n-1; j++){
//                 if(j >= n-(i-1) && j <= n+(i-1)){
//                     cout << "*";
//                 } else {
//                     cout << " ";
//                 }
//             }
//             cout << endl;
//         }
//     }
// };


// int main(){
//     int n;
//     cout << "Enter n : ";
//     cin >> n;

//     Pattern p;
//     p.pattern7(n);

//   return 0;
// }
