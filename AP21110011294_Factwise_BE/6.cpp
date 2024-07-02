#include <bits/stdc++.h>
using namespace std;

int count(int num){
    vector<int> ones={0,3,3,5,4,4,3,5,5,4,3};
    vector<int> ten={6,6,8,8,7,7,9,8,8};
    vector<int> tens={6,6,5,5,5,7,6,6};
    int ans=0;
    string str=to_string(num);
    if(str.size()==3 && str[1]=='1'){
        int n=num%10;
        ans+=ten[n-1];
        ans+=10;
        num/=100;
    }
    if(num==1000){
        return 8;
    }
    if(num>1000){
        return -1;
    }
    int flag=0;
    if(num>=11 && num<=19){
        int n=num%10;
        return ten[n-1];
    }
    while(num){
        int n=num%10;
        if(flag==0){
            ans+=ones[n];
        }else if(flag==1){
            ans+=tens[n-2];
        }
        else{
            ans+=ones[n];
            ans+=10;
        }
        flag++;
        num/=10;
    }
    return ans;
}

int main()
{
    int num=214;
    int ans=count(num);
    cout<<ans;
    return 0;
}