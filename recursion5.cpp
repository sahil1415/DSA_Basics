#include<iostream>
using namespace std;

int fact(int n){
    if(n>0){
        return n*fact(n-1);
    }
    return 1;
}

int main(){
    int a = 0;
    cout<<"Faactorial of "<<a<<" is - "<<fact(a);
} 