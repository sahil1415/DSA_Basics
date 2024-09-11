#include<bits/stdc++.h>
#include<stack>
#include<iostream>
using namespace std;
void solveNextSmaller(vector<int> &ans, vector<int> &v){
    stack<int> s;
    s.push(-1);
    int n = v.size();
    for(int i = n-1; i>=0; i--){
        int element = v[i];
        while(s.top() != -1 && s.top() >= element){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(element);
    }
}
void solvePreviousSmaller(vector<int> &ans, vector<int> &v){
    stack<int> s;
    s.push(-1);
    int n = v.size();
    for(int i = 0; i<n; i++){
        int element = v[i];
        while(s.top() >= element){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(element);
    }
}
int main(){
vector<int> v;
v.push_back(8);
v.push_back(4);
v.push_back(2);
v.push_back(6);
v.push_back(3);

vector<int> ans;
solveNextSmaller(ans, v);
reverse(ans.begin(), ans.end());
    for(int num : ans) cout<<num<<" ";
cout<<endl;

vector<int> ans1;
solvePreviousSmaller(ans1, v);
for(int num : ans1) cout<<num<<" ";
return 0;
}