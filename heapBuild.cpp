#include<iostream>
using namespace std;
void heapify(int* arr, int n, int currentIndex){

        int i = currentIndex;  // 1
        int rightIndex = 2*i+1;
        int leftIndex = 2*i;

        // lets assume the largest value index is i
        int largestIndex = currentIndex;

        if(leftIndex < n && arr[leftIndex] > arr[largestIndex]){
            largestIndex = leftIndex;
        }
        if(rightIndex < n && arr[rightIndex] > arr[largestIndex]){
            largestIndex = rightIndex;
        }

        if(largestIndex != i){
            swap(arr[currentIndex], arr[largestIndex]);
            i = largestIndex;
            heapify(arr, n, i);
        }
    }

    void buildHeap(int* arr, int n){
        for(int i=n/2; i>0; i--){
            heapify(arr, n, i);
        }
    }

    void heapSort(int* arr, int n){
        while(n > 1){
            swap(arr[1], arr[n-1]);
            n--;

            heapify(arr, n+1, 1);
        }
    }
int main(){
    int arr[] = {-1, 10, 20, 30, 40, 50};
    int size = 6;

    buildHeap(arr,6);
    cout<<endl;

    for(int i=1; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr, 6);

    cout<<"Printing heap Sort - ";
    for(int i=1; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
return 0;
}