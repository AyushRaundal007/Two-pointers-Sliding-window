#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Leetcode 4089
// You are given an integer array nums and two integers minK and maxK.
// A loose-bound subarray is a subarray in which every element is greater than or equal to minK and less than or equal to maxK.
// Return the number of loose-bound subarrays in nums.
// A subarray is a contiguous non-empty sequence of elements within an array.

// summary :
// integer array of size n , two number are given minK and maxK
// find all possible number of subarrays which satisfies the condition
// condition : each and every element of the subarray lies in the range of [minK,maxK]

// brute force approach
long long version0(vector<int>& nums, int minK, int maxK){
    int n=nums.size();
    long long int count=0;

    // all possible subarrays
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            bool isValid=true;
            for(int x=i; x<=j; x++){
                if(nums[x]<minK || nums[x]>maxK){
                    isValid=false;
                    break;
                }
            }
            if(isValid){
                count++;
            }
            else{
                break;
            }
        }
    }
    return count;
}

long long version1(vector<int>& nums, int minK, int maxK) {
    int n=nums.size();
    long long int count=0;

    for(int window_size=1; window_size<=n; window_size++){
        for(int start=0,end=window_size+start-1; end<n; start++,end++){
            bool isvalid=true;
            for(int x=start; x<=end; x++){
                if(nums[x]>=minK && nums[x]<=maxK){
                    continue;
                }
                else{
                    isvalid=false;
                    break;
                }
            }
            if(isvalid){
                count++;
            }
        }
    }
    return count;
}

long long version2(vector<int>& nums, int minK, int maxK) {
    int n=nums.size();
    long long int count=0;

    for(int window_size=1; window_size<=n; window_size++){
        for(int start=0,end=window_size+start-1; end<n; start++,end++){
            bool isValid=true;
            int inValid_index=start;
            for(int x=start; x<=end; x++){
                if(nums[x]>=minK && nums[x]<=maxK){
                    continue;
                }
                else{
                    isValid=false;
                    inValid_index=x;
                    break;
                }
            }
            if(isValid){
                count++;
            }
            else{
                start=inValid_index;
                end=window_size+start-1;
            }
        }
    }
    return count;
}
// optimized version
long long version3(vector<int>& nums, int minK, int maxK){
    int n=nums.size();
    long long int count=0;

    for(int i=0; i<n; i++){        // starting point of subarray
        for(int j=i; j<n; j++){        // ending point of subarray
            if(nums[j]>=minK && nums[j]<=maxK){
                count++;
            }
            else{
                break;
            }
        }
    }
    return count;
}

// best
long long countSubarrays(vector<int>& nums, int minK, int maxK){
    int n=nums.size();
    long long int count=0;
    // indices vector is a vector of inValid indices
    vector<int> indices={-1};

    for(int i=0; i<n; i++){
        if(nums[i]<minK || nums[i]>maxK){
            indices.push_back(i);
        }
    }
    indices.push_back(n);

    for(int i=1; i<indices.size(); i++){
        long long int size=indices[i]-indices[i-1]-1;
        count+=size*(size+1)/2;
    }
    return count;
}

// most optimized
long long finalversion(vector<int>& nums, int  minK, int maxK){
    int n=nums.size();
    long long int count=0;

    int prev=-1;
    for(int i=0; i<n; i++){
        if(nums[i]<minK || nums[i]>maxK){
            // i is invalid;
            long long int x=i-prev-1;
            count+=x*(x+1)/2;
            prev=i;
        }
    }
    long long int x=n-prev-1;
    count+=x*(x+1)/2;
    return count;
}

int main(){
    vector<int> nums={1,3,4,7,3,4};
    cout << countSubarrays(nums,1,5);
}