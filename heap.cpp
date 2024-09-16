#include<iostream>
using namespace std;
class Heap{
    public:
    int capacity;
    int* arr;
    int index;

    Heap(int size){
        this->capacity = size;
        this->arr = new int[size];
        index = 0;
        for(int i=0; i<capacity; i++){
            arr[i] = 0;
        }
    }

    void printHeap(){
        for(int i=1; i<capacity; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void insertInHeap(int val){
        // if no space is available
        if(index == capacity-1){
            cout<<"Heap Overflow"<<endl;
        }
        // if space is available
        index++;
        arr[index] = val;

        // now heapify put that value at its correct position
        int i = index;
        while(i > 1){
            int parentIndex = i/2;

            if(arr[parentIndex] < arr[i]){
                swap(arr[i], arr[parentIndex]);
                i = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void deleteInHeap(int val){
        // replacement 
        swap(arr[1], arr[index]);
        // size decrease
        index--;
        // heapify
        heapify(arr, index, 1);

    }
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
};
int main(){
    Heap pq(10);
    pq.insertInHeap(10);
    pq.printHeap();
    pq.insertInHeap(20);
    pq.printHeap();
    pq.insertInHeap(30);
    pq.printHeap();
    pq.insertInHeap(40);
    pq.printHeap();
    pq.insertInHeap(50);
    pq.printHeap();
    pq.deleteInHeap(50);
    pq.printHeap();
return 0;
}