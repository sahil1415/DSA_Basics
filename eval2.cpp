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

int  binarySearch(int arr[], int k, int n){
    int low = 0;
    int high = n-1;
    int mid  = (low+high)/2;
    while(low<high){
        if(arr[mid] == k){
            return mid;
        }
        if(k<arr[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        mid = (low+high)/2;
    }
    return -1;
}
void printArray(int arr3[],int n){
    for(int i = 0; i<n; i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr1[5] = {23,45,6,1,57};
    // sorting the given array
    cout<<"Unsorted Array-"<<endl;
    printArray(arr1,5);
    bubbleSortAlgo(arr1,5);
    cout<<"Sorted Array-"<<endl;
    printArray(arr1,5);
    int x = binarySearch(arr1,23,5);
    cout<<"Element found at index- "<<x<<endl;

}