#include<iostream>
using namespace std;

void bubbleSortAlgorithm(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n-i; j++){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
void printArray(int arr1[], int n){
    cout<<"Sorted arrray-"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr2[] ={4,3,2,1,65,32};
    bubbleSortAlgorithm(arr2,6);
    printArray(arr2,6);
}