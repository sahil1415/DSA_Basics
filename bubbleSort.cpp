#include<iostream>
using namespace std;

void bubbleSortAlgo(int arr2[], int n){
    int temp = 0;
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=i-1; j++){
            if(arr2[j]>arr2[j+1]){
                temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }
}
void traversing(int arr1[], int s){
    for(int i = 0; i< s; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {6,5,4,3,2,1};
    cout<<"Array before sorting - "<<endl;
    traversing(arr,6);
    cout<<"Array after sorting - "<<endl;
    bubbleSortAlgo(arr,6);
    traversing(arr,6);
}