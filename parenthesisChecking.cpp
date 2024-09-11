#include<iostream> 
#include<bits/stdc++.h>
using namespace std;

    bool parenthesisChecking(string str){
        stack<char> s;
        for(int i = 0; str[i]!='\0'; i++){
            if(str[i]=='[' ||str[i]=='{' || str[i]=='('){
                s.push(str[i]);
            }
            else if(str[i]==']' || str[i]=='}'|| str[i]==')'){
                if(s.empty()){
                    return false;
                }
                s.pop();
            }
        }
        if(s.empty()){
            return true;
        }
        return false;
    }
int main(){
        string str1= "[{()}";
    if(parenthesisChecking(str1)){
        cout<<"Expression is balanced"<<endl;
    }
    else{
        cout<<"Expression not balanced";
    }
}