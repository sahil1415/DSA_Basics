#include<iostream>
using namespace std;

void towerOfHinoi(int n, string source, string destination, string helper){
    if(n == 0){
        return;
    }
    towerOfHinoi(n-1, source , destination, helper);
    cout<<n<<"Moved disc "<<n<<" from "<<source<< " to "<< destination<<endl;
    towerOfHinoi(n-1, helper , destination, source);
}
int main(){
    int n;
    cout<<"Enter the no of disc - ";
    cin>>n;
    towerOfHinoi(n, "source", "helper", "destination");
}