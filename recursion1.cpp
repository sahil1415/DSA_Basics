#include<iostream>
using namespace std;

void print(int i, int n){
    if(i>n)  {return;}
    i++;
    cout<<"Sahil Ansari"<<endl;
    print(i, n);
}

int main(){
    int i = 1;
    int n;
    cout<<"Enter number of operations - "<<endl;
    cin>>n;
    print(i, n);
}