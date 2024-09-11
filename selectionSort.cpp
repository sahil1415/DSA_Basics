#include<iostream>
using namespace std;

void selectionSortAlgo(int arr2[], int n){
       for(int i = 0; i< n; i++){
        int min = arr2[i];
        int j;
        for(j = i+1; j < n; j++){
            if(arr2[j]<min){
                min = arr2[j];
            }
            int temp = arr2[i];
            arr2[i] = min;
            arr2[j] = temp;
            cout<<'i'<<endl;
        }
    }
}
void traversing(int arr[], int s){
    for(int i = 0; i<s; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr1[] = {1,2,3,4,5,6};
    cout<<"Array before sorting - "<<endl;
    traversing(arr1,6);
    cout<<"Array after sorting - "<<endl;
    selectionSortAlgo(arr1,6);
    traversing(arr1,6);
}