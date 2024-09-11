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
void reverse(int arr[], int low, int high){
    if(low<high){
        swap(arr[low],arr[high]);
        reverse(arr,low+1,high-1);
    }
    return;
}

int main(){
    int a[8] = {1,2,3,4,5,6,7,8};
    int low = 0;
    int high = 7;
    cout<<"Array before reversing - "<<endl;
    printArray(a, 8);
    cout<<"Array after swapping - "<<endl;
    reverse(a,low, high);
    printArray(a,8);
}