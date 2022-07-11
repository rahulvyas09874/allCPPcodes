void longest_increasing_subsequence_bottom_up_dp(vector<int>&nums,vector<int>&dp){
   // suppose nums={1,3,2,8,7,6,12,9};
   // take a dp array of same size as that of nums and initialize all its element to 1 
   //coz minimum length of longest_increasing_subsequence is 1 only
   // take 2 pointers i and j where i is going to every position from 2nd index (1) and j is moving from 0 to i-1
   // in every iteration, if at any place you encounter nums[i]>nums[j] then update dp[i]=max(dp[i],dp[j]+1)
   for(int i=1;i<nums.size();i++){
      for(int j=0;j<i;j++){
         if(nums[i]>nums[j]){
            dp[i]=max(dp[i],dp[j]+1);
         }
      }
   }


}
note: this approach is n^2

// now we are having our dp array in which the last element is the length of longest increasing subsequence 
// to get the exact numbers ,take a pointer i starting from the last index of nums array if
// dp[i]==length of longest increasing subsequence ,take that number in the answer array and decrease 
// length of longest increasing subsequence (length--) and i should always be decreasing

vector<int>ans;
int i=nums.size()-1;
while(i>=0 and length>=0){
   if(dp[i]==length){
      ans.push_back(nums[i]);
      length--;
   }
   i--;
}

// now your ans vector is having the longest increasing subsequence

1 2 2 3 3 3 4 4







//nlogn approach:, this also gives us the sequence

int longestIncreasingSubsequence(vector<int>&nums){
    int n=nums.size();
    vector<int>ans;
    ans.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]>ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            // as the curr element is smaller than the last element in the ans vector, find it's right position in the answer vector
            int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[idx]=nums[i];
        }
    }
    return ans.size();

}