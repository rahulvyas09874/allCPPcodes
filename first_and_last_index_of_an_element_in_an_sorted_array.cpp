
int lowerbound(vector<int>&nums,int key){
   int s=0;
   int e=nums.size()-1;                              // the main idea of this function is that if we found a index with value as key, then instead of
   int idx=-1;                                       //  aborting the search we will keep on going left to check whether another key exist on the left side or not and while
   while(s<=e){                                      // doing so we will keep updating the idx of key with latest small index
      int mid=(s+e)/2;
      if(nums[mid]==key){
         idx=mid;
         e=mid-1;
      }
      else if(nums[mid]>key){
         e=mid-1;
      }
      else{
         s=mid+1;
      }
      
   }
   return idx;
}

int upperbound(vector<int>&nums,int key){
    int s=0;
   int e=nums.size()-1;
   int idx=-1;
   while(s<=e){
      int mid=(s+e)/2;                                // the main idea of this function is that if we found a index with value as key, then instead of
      if(nums[mid]==key){                             // aborting the search we will keep on going right to check whether another key exist on the right side or not
         idx=mid;
         s=mid+1;
      }
      else if(nums[mid]>key){
         e=mid-1;
      }
      else{
         s=mid+1;
      }
   }
   return idx;
}