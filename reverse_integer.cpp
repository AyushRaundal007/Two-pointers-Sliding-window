#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int reverseInt(int x){
    int result=0;
    if(x<1000000000 && x>-1000000000){
        // when x is not a 10 digit number
        int temp=x;
        vector<int> vec; // reversed integer is stored here
        while(temp!=0){
            vec.push_back(temp%10);
            temp/=10;
        }
        int tens=1;
        for(int i=vec.size()-1; i>=0; i--){
            result=result+vec[i]*tens;
            tens*=10;
        }
    }
    else{
        // when x is a guaranteed 10 digit number
        int temp=x;
        vector<int> vec; // reversed integer is stored here
        while(temp!=0){
            vec.push_back(temp%10);
            temp/=10;
        }

        if(x>0){
            // all values in the vec vector are positive
            vector<int> comp={2,1,4,7,4,8,3,6,4,7};

            for(int i=0; i<10; i++){
                if(vec[i]>comp[i]){
                    return 0;
                }
                else if(vec[i]==comp[i]){
                    continue;
                }
                else{
                    break;
                }
            }

            // reversed x <= INT_MAX
            int tens=1;
            for(int i=vec.size()-1; i>=0; i--){
                result=result+vec[i]*tens;
                if(i==0){
                    break;
                }
                tens*=10;
            }
        }
        else{
            // all values in the vec vector are negative
            for(int i=0; i<10; i++){
                vec[i]=-vec[i];
            }
            // Now all are positive
            vector<int> comp={2,1,4,7,4,8,3,6,4,8};

            for(int i=0; i<10; i++){
                if(vec[i]>comp[i]){
                    return 0;
                }
                else if(vec[i]==comp[i]){
                    continue;
                }
                else{
                    break;
                }
            }

            // reversed x >= INT_MIN
            int tens=-1;
            for(int i=vec.size()-1; i>=0; i--){
                result=result+vec[i]*tens;
                if(i==0){
                    break;
                }
                tens*=10;
            }
        }
    }
    return result;
}

int main(){
    cout << reverseInt(123) << endl;
    cout << reverseInt(1999999999);
}