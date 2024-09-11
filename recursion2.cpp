#include<iostream>
using namespace std;


void linearFun(int i, int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    // linearFun(i+1,n);  works
    linearFun(++i,n);
    // linearFun(i++,n); infinite loop printing 1 only
}
int main(){
    int i = 1;
    int n;
    cout<<"Enter the range - ";
    cin>>n;
    linearFun(i, n);
}