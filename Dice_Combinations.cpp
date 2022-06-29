/**
*    Coded by :  Harsh vardhan 
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;

    //dp[i] -> no of ways we can throw a dice till index i
    int mod=1e9+7;
    vector<int> dp(n+1,0);   
    dp[0]=1;
    for(int i=0;i<=n;++i){
        for(int j=1;j<=6;++j){
            if(j>i){
                break;
            }
            dp[i]=(dp[i]+dp[i-j])%mod;
        }
    }
    cout<<dp[n];
    return 0;
}
