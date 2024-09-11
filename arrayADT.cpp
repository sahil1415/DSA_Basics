#include<iostream>
using namespace std;

class arrayADT{
    public:
    int size;
    int *ptr;
    arrayADT(int size){
        this -> size = size;
        int *ptr = new int(size);
    }
};

//creating memory for the array
void createArray(arrayADT *a, int value, int index){
    a-> ptr[index] = value;
}

void printArray(arrayADT *a){
    for(int i = 0; i<a->size; i++){
        cout<<a->ptr[i]<<" ";
    }
}

int main(){
    arrayADT *a;
    createArray(*&a, 10, 0);
    printArray(*&a);
}


