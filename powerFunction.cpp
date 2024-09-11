// // Iterative way
#include<iostream>
using namespace std;

int powerFunction(int x, int n){
    int ans = 1;
    for(int i=0; i<n; i++){
        ans = ans*x;
    }
    return ans;
}
//O(log n) time complexity/ Recursive way
int power(int x, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    int half = power(x, n / 2);
    
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

int main()
{
    int ans = 1;
    int n, x;
    cout<<"Enter a number : ";
    cin>>x;
    cout<<"Enter its power : ";
    cin>>n;
    cout<<endl;
    cout<<"Iterative Way"<<endl;
    cout<<x<<" to the power "<<n<<" is : "<<powerFunction(x, n)<<endl;

    cout<<endl;
    cout<<"O(log n) time complexity "<<endl;
    cout<<x<<" to th epower "<<n<<" is : "<<power(x, n);
return 0;
}
