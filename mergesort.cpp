void merge(vector<int>&array,int s,int e){
   vector<int>ans;   // initializing a empty array
   int mid=(s+e)/2;  // finding middle index
   int i=s;          // starting index of the left half of the array
   int j=mid+1;      // starting index of the right half of the array
   while(i<=mid and j<=e){   // checking whether the left index aur the right index are going out of bounds
    if(array[i]<array[j]){       // pushing the smallest element among these two to the ans array
        ans.push_back(array[i]);
        i++;
    }
    else{
        ans.push_back(array[j]);
        j++;
    }

   }
   if(j>=e and i<=mid){             // if the right array is exhausted, push all the elements of the left array
     for(int l=i;l<=mid;l++){       //    into the ans array
        ans.push_back(array[l]);
     }
   }
   if(i>=mid and j<=e){            // if the left array is exhausted, push all the elements of the right array
    for(int l=j;l<=e;l++){         // into the ans array
        ans.push_back(array[l]);
    }
   }
   int l=s;                     // replace the elemets in the ans array to the input array elements
   for(auto p:ans){
     array[l]=p;
     l++;
   }

}

void mergesort(vector<int>&array,int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergesort(array,s,mid);   // applying mergesort on the array to the left of mid
    mergesort(array,mid+1,e); // applying mergesort on the array to the right of the mid
    merge(array,s,e);         // merging the two of the arrays(left and right) to form a sorted one
    return; 
}