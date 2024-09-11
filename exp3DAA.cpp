#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;
void frequency(vector<int> &nums, map<int, int> &mpp){
    int n  = nums.size();
    int i = 0;
    while(i < n){
        mpp[nums[i]]++;
        i++;
    }
}
int main(){
    vector<int> nums = {1,2,3,2,4,5,5,6,7,8,9,9,0,1,1};
    map<int, int> mpp;
    frequency(nums, mpp);
    for(auto it : mpp){
        cout<<"Number = "<<it.first<<"   "<<"Frequency = "<<it.second<<endl;
    }
    
return 0;
}