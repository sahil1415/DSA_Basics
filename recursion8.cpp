#include<iostream>
using namespace std;

// finding the kth fibonacci number 

// 0    1    1    2    3    5    8    13    21    34
// 0th  1st  2nd  3rd  4th  5th  6th  7th   8th   9th 

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    int last = fibonacci(n-1);
    int slast = fibonacci(n-2);

    return last+slast;
}

int main(){
    int n = 6;
    cout<<n<<"th fibonacci = "<<fibonacci(n);
}