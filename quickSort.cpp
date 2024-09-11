#include<iostream>
#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSortAlgo(int arr[], int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSortAlgo(arr, low, pIndex - 1);
        quickSortAlgo(arr, pIndex + 1, high);
    }
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[9] = {4, 5, 6, 2, 3, 7, 9, 1, 8};
    int size = 9;
    int low = 0;
    int high = size - 1;
    auto start = high_resolution_clock::now();
    quickSortAlgo(arr, low, high);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    display(arr, size);
    cout << endl;
    cout << "Time taken by QuickSort: " << duration.count() << " microseconds" << endl;
}
