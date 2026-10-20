#include<iostream>
#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2){
    if(num1=="0" || num2=="0"){
        return "0";
    }
    if(num2.size()>num1.size()){
        swap(num1,num2);
    }
    string ans="";
    int num_zeros=0;

    for(int i=num2.size()-1; i>=0; i--){
        if(num2[i]=='0'){
            num_zeros++;
            continue;
        }
        string temp_ans="";
        for(int j=1; j<=num_zeros; j++){
            temp_ans+='0';
        }
        // calculate temp_ans
        int carry=0;
        for(int j=num1.size()-1; j>=0; j--){
            int product=carry+(num2[i]-'0')*(num1[j]-'0');
            char tempchar='0'+product%10;
            temp_ans+=tempchar;
            product/=10;
            carry=product;
        }   
        if(carry!=0){
            char tempchar='0'+carry;
            temp_ans+=tempchar;
        }
        // Now we have temp_ans
        if(ans.size()==0){
            ans=temp_ans;
            num_zeros++;
            continue;
        }
        // updating ans
        string new_ans="";
        // reusing carry variable
        carry=0;
        for(int j=0; j<min(temp_ans.size(),ans.size()); j++){
            int sum=(ans[j]-'0')+(temp_ans[j]-'0')+carry;
            char tempchar='0'+sum%10;
            new_ans+=tempchar;
            sum/=10;
            carry=sum;
        }

        if(temp_ans.size()==ans.size()){
            if(carry!=0){
                char tempchar='0'+carry;
                new_ans+=tempchar;
            }
        }
        else if(temp_ans.size()>ans.size()){
            for(int j=ans.size(); j<temp_ans.size(); j++){
                int sum=(temp_ans[j]-'0')+carry;
                char tempchar='0'+sum%10;
                new_ans+=tempchar;
                sum/=10;
                carry=sum;
            }
            if(carry!=0){
                char tempchar='0'+carry;
                new_ans+=tempchar;
            }
        }
        else{
            for(int j=temp_ans.size(); j<ans.size(); j++){
                int sum=(ans[j]-'0')+carry;
                char tempchar='0'+sum%10;
                new_ans+=tempchar;
                sum/=10;
                carry=sum;
            }
            if(carry!=0){
                char tempchar='0'+carry;
                new_ans+=tempchar;
            }
        }
        ans=new_ans;
        num_zeros++;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
   cout << multiply("12334566778899000674647464748589679857463534353647597978563424347586969695843525648585433","65655444664746474758855858747447474848483992847657689700605948476367282828292020292878885677888999") << endl;
   cout << ("809831466615623504401085407417665434064148955147308111494349056119702557030679337242395356113737022086597355147824367240845246831180827025381228664340640437144321129965506832609942351567"=="809831466615623504401085407417665434064148955147308111494349056119702557030679337242395356113737022086597355147824367240845246831180827025381228664340640437144321129965506832609942351567");
}