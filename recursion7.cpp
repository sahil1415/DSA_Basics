#include<iostream>

using namespace std;

// reversing an array using recursion
void printArray(int arr[], int size){
    int i = 0;
    while(i<size){
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
}
void reverse(int arr[], int i, int s){
    if(i>=s/2){
        return;
    }
    swap(arr[i], arr[s-i-1]);
    reverse(arr, i+1, s);
}

int main(){
    int a[8] = {1,2,3,4,5,6,7,8};
    int i = 0;
    int size = 8;
    cout<<"Array before reversing - "<<endl;
    printArray(a, 8);
    cout<<"Array after swapping - "<<endl;
    reverse(a, i, size);
    printArray(a,8);
}