#include <bits/stdc++.h>
using namespace std;

int count(vector<int>& cardPoints,int k,int l,int r){
    if(l>r || k==0){
        return 0;
    }
    int a=cardPoints[l]+count(cardPoints,k-1,l+1,r);
    int b=cardPoints[r]+count(cardPoints,k-1,l,r-1);
    return max(a,b);
}

int main()
{
    vector<int> cardPoints = {9,7,7,9,7,7,9};
    int k = 7;
    int ans=count(cardPoints,k,0,cardPoints.size()-1);
    cout<<ans;
    return 0;
}