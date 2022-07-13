/**
*    Coded by :  Harsh vardhan 
**/
#include<bits/stdc++.h>
using namespace std;
#define vv32 vector<vector<int>>
#define pb push_back
#define v32 vector<int>

int rec(int i,int n,int mw,vv32 &dp,v32 &wt,v32 &val){ 
    if(i==n){
        if(mw-wt[i]>=0){
            return val[i];
        }
        return 0;
    }  
    
    if(dp[i][mw]!=-1){
        return dp[i][mw];
    }
    
    int left=0+rec(i+1,n,mw,dp,wt,val);
    int right=INT_MIN;
    if(mw-wt[i]>=0){
        right=val[i]+rec(i+1,n,mw-wt[i],dp,wt,val);
    }
    
    return dp[i][mw]=max(left,right);
}
    

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vv32 dp(n+1,v32(maxWeight+1,-1));
    int x= rec(0,n-1,maxWeight,dp,weight,value);
    return x;
}

int main(){
    // no of elements in weight and value array
    int n;cin>>n;
    v32 weight(n),val(n);
    for(int i=0;i<n;++i){
        cin>>weight[i];
    }

    for(int i=0;i<n;++i){
        cin>>val[i];
    }

    //maxweight of bag
    int max_weight;cin>>max_weight;
    int ans=knapsack(weight,val,n,max_weight);
    cout<<ans<<'\n';
    return 0;
}