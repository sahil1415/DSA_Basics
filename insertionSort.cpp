#include<iostream>
using namespace std;

void insertionSortAlgo(int arr[], int n){
       for(int i = 0; i< n; i++){
        int j = i;
        while(arr[j-1]>arr[j] && j>0){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
void traversing(int arr1[], int s){
    for(int i = 0; i<s; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr2[] = {6,5,4,3,2,1};
    cout<<"Array before sorting - "<<endl;
    traversing(arr2,6);
    cout<<"Array after sorting - "<<endl;
    insertionSortAlgo(arr2,6);
    traversing(arr2,6);
}