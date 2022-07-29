
int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;++i){
            for(int j=1;j<=n2;++j){
                if(s1[i-1]==s2[j-1]){
                    // if i==j
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    // if both indexes are npot same
                    
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }        
        return dp[n1][n2];
}
