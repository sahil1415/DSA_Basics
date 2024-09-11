// Sum of first numbers using recursion

//Parameterized approach

// #include<iostream>
// using namespace std;

// void Sum(int i, int sum){
//     if(i<1){
//         cout<<sum;
//         return;
//     }
//     Sum(i-1,sum+i);
// }
// int main(){
//     int i = 5;
//     int sum = 0;
//     Sum(i,sum);
// }

// functional approach

#include<iostream>
using namespace std;

int Sum(int n){
    if(n>0){
        return n + Sum(n-1);
    }
    return 0;
}

int main(){
    int n = 5;
    cout<<Sum(n);
}
