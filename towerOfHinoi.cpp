#include<iostream>
using namespace std;

void towerOfHinoi(int n, string source, string auxilary, string destination, int &cnt){
    if(n == 0){
        return;
    }
    towerOfHinoi(n-1, source ,destination, auxilary,cnt);
    cout<<"Moved disc "<<n<<" from "<<source<< " to "<<destination<<endl;
    cnt++;
    towerOfHinoi(n-1, auxilary, source, destination, cnt);
}
int main(){
    int n;
    int cnt = 0;
    cout<<"Enter the no of disc - ";
    cin>>n;
    towerOfHinoi(n, "source", "auxilary", "destination", cnt);
    cout<<"total number of movements = "<<cnt;
}


// C++ recursive function to 
// solve tower of hanoi puzzle 
// #include <bits/stdc++.h> 
// using namespace std; 
  
// void towerOfHanoi(int n, char from_rod, char to_rod, 
//                   char aux_rod) 
// { 
//     if (n == 0) { 
//         return; 
//     } 
//     towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
//     cout << "Move disk " << n << " from rod " << from_rod 
//          << " to rod " << to_rod << endl; 
//     towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
// } 
  
// // Driver code 
// int main() 
// { 
//     int N = 3; 
  
//     // A, B and C are names of rods 
//     towerOfHanoi(N, 'A', 'C', 'B'); 
//     return 0; 
// } 