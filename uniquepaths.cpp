#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m,int n) {
    if(m==1){
        return 1;
    }
    int count=0;
    for(int i=0; i<n; i++){
        count=count+uniquePaths(m-1,n-i);
    }
    return count;
}



int main(){
    cout << uniquePaths(30,9);
}