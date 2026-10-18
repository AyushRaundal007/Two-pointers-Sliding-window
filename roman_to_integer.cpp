#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Q. Convert a Roman number into Integer

int roman_to_integerI(string s){
    int n=s.size();

    if(n==0){
        return 0;
    }

    int num=0;
    // creating a hashmap in which each character represents a integer value
    unordered_map<char,int> m; // hashmap
    m.insert({'I',1});
    m.insert({'V',5});
    m.insert({'X',10});
    m.insert({'L',50});
    m.insert({'C',100});
    m.insert({'D',500}); 
    m.insert({'M',1000});
    
    for(int i=0; i<=n-2; i++){
        if(m[s[i]]>=m[s[i+1]]){
            num+=m[s[i]]; // addition
        }
        else{
            num-=m[s[i]]; // subtraction
        }
    }
    num+=m[s[n-1]];
    return num;
}

int roman_to_integerII(string s){
    int n=s.size();

    if(n==0){
        return 0;
    }

    int num=0;
    // creating a hashmap in which each character represents a integer value
    unordered_map<char,int> m; // hashmap
    m.insert({'I',1});
    m.insert({'V',5});
    m.insert({'X',10});
    m.insert({'L',50});
    m.insert({'C',100});
    m.insert({'D',500}); 
    m.insert({'M',1000});
    
    for(int i=n-1; i>=1; i--){
        if(m[s[i-1]]>=m[s[i]]){
            num+=m[s[i-1]]; // addition
        }
        else{
            num-=m[s[i-1]]; // subtraction
        }
    }
    num+=m[s[n-1]];
    return num;
}

int romanToInt(string s) {
        int num=0;
        string temp=s;
        if(temp[0]=='M'){
// temp here represents a 4 digit number             
            int m=0; // number of consecutive 'M's
            int i=0;
            while(i<temp.size()){
                if(temp[i]=='M'){
                    m++;
                    i++;
                }
                else{
                    break;
                }
            } // now i have number of consecutive 'M's

            if(m==1){
                num=num+1000;
                temp=temp.substr(1,temp.size()-1);
            }
            else if(m==2){
                num=num+2000;
                temp=temp.substr(2,temp.size()-2);
            }
            else{
                // m==3
                num=num+3000;
                temp=temp.substr(3,temp.size()-3);
            }

            if(temp.size()==0){
                return num;
            }
        }
        if(temp[0]=='C' || temp[0]=='D'){
// temp here represents a 3 digit number
            if(temp[0]=='C'){
                int c=0; // number of 'C's
                int i=0;
                while(i<temp.size()){
                    if(temp[i]=='C'){
                        c++;
                        i++;
                    }
                    else{
                        break;
                    }
                } // Now i have number of consecutive 'C's

                if(c==1){
                    if(temp.size()==1){
                        num=num+100;
                        temp=temp.substr(1,temp.size()-1);
                    }
                    else{
                        // temp.size()>1
                        if(temp[1]=='D'){
                            num=num+400;
                            temp=temp.substr(2,temp.size()-2);
                        }
                        else if(temp[1]=='M'){
                            num=num+900;
                            temp=temp.substr(2,temp.size()-2);
                        }
                        else{
                            // when temp[0]=='C'
                            // when temp[1]!='D' and temp[1]!='M'
                            num=num+100;
                            temp=temp.substr(1,temp.size()-1);
                        }
                    }
                }
                else if(c==2){
                    num=num+200;
                    temp=temp.substr(2,temp.size()-2);
                }
                else{
                    // c==3
                    num=num+300;
                    temp=temp.substr(3,temp.size()-3);
                }
            }
            else{
                // temp[0]=='D'
                if(temp.size()==1){
                    num=num+500;
                    temp=temp.substr(1,temp.size()-1);
                }
                else{
                    // temp.size()>1
                    int c=0; // number of 'C's
                    int i=1;
                    while(i<temp.size()){
                        if(temp[i]=='C'){
                            c++;
                            i++;
                        }
                        else{
                            break;
                        }
                    } // Now i have number of consecutive 'C's

                    if(c==0){
                        num=num+500;
                        temp=temp.substr(1,temp.size()-1);
                    }
                    else if(c==1){
                        num=num+600;
                        temp=temp.substr(2,temp.size()-2);
                    }
                    else if(c==2){
                        num=num+700;
                        temp=temp.substr(3,temp.size()-3);
                    }
                    else{
                        // c==3
                        num=num+800;
                        temp=temp.substr(4,temp.size()-4);
                    }
                }
            }

            if(temp.size()==0){
                return num;
            }
        }
        if(temp[0]=='X' || temp[0]=='L'){
// temp here represents a 2 digit number
            if(temp[0]=='X'){
                int x=0; // number of 'X's
                int i=0;
                while(i<temp.size()){
                    if(temp[i]=='X'){
                        x++;
                        i++;
                    }
                    else{
                        break;
                    }
                } // Now i have number of consecutive 'X's

                if(x==1){
                    if(temp.size()==1){
                        num=num+10;
                        temp=temp.substr(1,temp.size()-1);
                    }
                    else{
                        // temp.size()>1
                        if(temp[1]=='L'){
                            num=num+40;
                            temp=temp.substr(2,temp.size()-2);
                        }
                        else if(temp[1]=='C'){
                            num=num+90;
                            temp=temp.substr(2,temp.size()-2);
                        }
                        else{
                            // when temp[0]=='X'
                            // when temp[1]!='L' and temp[1]!='C'
                            num=num+10;
                            temp=temp.substr(1,temp.size()-1);
                        }
                    }
                }
                else if(x==2){
                    num=num+20;
                    temp=temp.substr(2,temp.size()-2);
                }
                else{
                    // x==3
                    num=num+30;
                    temp=temp.substr(3,temp.size()-3);
                }
            }
            else{
                // temp[0]=='L'
                if(temp.size()==1){
                    num=num+50;
                    temp=temp.substr(1,temp.size()-1);
                }
                else{
                    // temp.size()>1
                    int x=0; // number of 'X's
                    int i=1;
                    while(i<temp.size()){
                        if(temp[i]=='X'){
                            x++;
                            i++;
                        }
                        else{
                            break;
                        }
                    } // Now i have number of consecutive 'X's

                    if(x==0){
                        num=num+50;
                        temp=temp.substr(1,temp.size()-1);
                    }
                    else if(x==1){
                        num=num+60;
                        temp=temp.substr(2,temp.size()-2);
                    }
                    else if(x==2){
                        num=num+70;
                        temp=temp.substr(3,temp.size()-3);
                    }
                    else{
                        // x==3
                        num=num+80;
                        temp=temp.substr(4,temp.size()-4);
                    }
                }
            }

            if(temp.size()==0){
                return num;
            }
        }
        if(temp[0]=='I' || temp[0]=='V'){
// temp here represents a 1 digit number
            if(temp=="I"){
                num=num+1;
            }
            else if(temp=="II"){
                num=num+2;
            }
            else if(temp=="III"){
                num=num+3;
            }
            else if(temp=="IV"){
                num=num+4;
            }
            else if(temp=="V"){
                num=num+5;
            }
            else if(temp=="VI"){
                num=num+6;
            }
            else if(temp=="VII"){
                num=num+7;
            }
            else if(temp=="VIII"){
                num=num+8;
            }
            else{
                // temp=="IX"
                num=num+9;
            }
            temp="";
            return num;
        }
        return num;
    }

int main(){
    cout << roman_to_integerI("CMXCVIII") << endl;
    cout << roman_to_integerII("CMXCVIII") << endl;
    cout << romanToInt("CMXCVIII") << endl;
    return 0;
}