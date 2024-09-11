#include<iostream>
using namespace std;

bool palindrome(string str, int i){
    if(i>=str.size()/2){
        return true;
    }
    if(str[i] != str[str.length()-i-1]){
        return false;
    }
    return palindrome(str, i+1);
}

int main(){
    string s = "WOasafW";
    int i = 0;
    cout<<"Is palindrome - "<<palindrome(s, i);
}