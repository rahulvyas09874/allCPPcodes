int lcs(string a,string b){
    int n1=a.length();
    int n2=b.length();

    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            // if the last char of both string matches 
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            // if the last char does not matches , then we have 2 cases taking one of the char and skip the other
            else{
                int temp1=dp[i][j-1];  // skipping the last char of string b
                int temp2=dp[i-1][j];  // skipping the last char of string a
                dp[i][j]=max(temp1,temp2);
            }
        }
    }
   
   // to print the lcs
    int i=n1;
    int j=n2;
    string ans="";
    while(i>0 and j>0){

        // move left from i,j
        if(dp[i][j]==dp[i][j-1]){
            j--;
        }

        // move up from i,j
        else if(dp[i][j]==dp[i-1][j]){
            i--;
        }

        // to include the char at i,j coz it is same
        else{
            ans+=a[i-1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());

    return dp[n1][n2];

}