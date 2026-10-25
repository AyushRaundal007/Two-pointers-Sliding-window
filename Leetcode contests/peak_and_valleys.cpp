#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Leetcode 4088
int diff_peak_and_valleys(const vector<int> &nums){
    int n=nums.size();
    int sum=0;
    for(int i=1; i<=n-2; i++){
        if(nums[i]>nums[i+1] && nums[i]>nums[i-1]){
            sum+=nums[i];
        }
        else if(nums[i]<nums[i+1] && nums[i]<nums[i-1]){
            sum-=nums[i];
        }
    }
    return sum;
}

int main(){
    vector<int> nums={1,3,7,5};
    cout << diff_peak_and_valleys(nums);
}