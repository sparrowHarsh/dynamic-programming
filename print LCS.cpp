void LCS(){
    string s1,s2;cin>>s1>>s2;
    string ans="";
    int n1=sz(s1),n2=sz(s2);
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=n2;++j){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }    
 
    // string ans="";
    int i=n1,j=n2;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;j--;
        }else{
            int x=max(dp[i-1][j],dp[i][j-1]);
            if(dp[i-1][j]==x){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(all(ans));
    cout<<ans<<ln;
}
