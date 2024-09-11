#include<iostream>
using namespace std;

// 1 2 3   4   5     6          7
// A B BA BAB BABBA BABBABAB BABBABABBABBA
//10 01 11 12 23     35        58
int fibonaci(int n){
    if(n<=2){
        return n;
    }
    int last = fibonaci(n-1);
    int slast = fibonaci(n-2);
    
    return last+slast;

}

void nthFibo(int n){
    int x = n-1;
    int y = n-2;
    int l = fibonaci(x);
    int sl = fibonaci(y);

    cout<<"No of A's = "<<l-sl<<endl;
    cout<<"No of B's = "<<sl;
}

int main(){
    int z = 7;
    nthFibo(z);
}