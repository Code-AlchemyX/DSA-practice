//       5 5 5 5 5 5 5 5 5 
//       5 4 4 4 4 4 4 4 5 
//       5 4 3 3 3 3 3 4 5 
//       5 4 3 2 2 2 3 4 5 
//       5 4 3 2 1 2 3 4 5 
//       5 4 3 2 2 2 3 4 5 
//       5 4 3 3 3 3 3 4 5 
//       5 4 4 4 4 4 4 4 5 
//       5 5 5 5 5 5 5 5 5

//!=================================== EASY UNDERSTANDABLE METHOD ===================================
#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern22(int n){
        for(int i=0; i<2*n-1; i++){
            for(int j=0; j<2*n-1; j++){
                int top = i;
                int bottom = 2*(n-1) - i;
                int left = j;
                int right = 2*(n-1) - j;
            
                int minimum = min({top, bottom, left, right});
                int value = n - minimum;
                cout << value << " ";    
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
    p.pattern22(n);

    return 0;
}

//!============== METHOD 2 - CAN BE UNDERSTOOD ONCE ABOVE METHOD IS CRYSTAL CLEARV==============

#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern22(int n){
        for(int i=0; i<2*n-1; i++){
            for(int j=0; j<2*n-1; j++){
                int value = n - min({i , j , 2*(n-1)-i , 2*(n-1)-j});
                cout << value << " ";
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
    p.pattern22(n);

    return 0;
}