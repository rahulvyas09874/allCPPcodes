int partition(vector<int>&nums,int s,int e){ // partition function (it always takes the last element as the pivot)
    int i=s-1;                               // the index i is pointing to the left of start 
    int pivot=nums[e];                       // pivot is the last element
    for(int j=s;j<=e;j++){                   // iterating from start to end and increasing j on every iteration, and whenever
        if(nums[j]<pivot){                        //->continue finding any element smaller than pivot ,increasing i and replacing it with the current jth element
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[i+1],nums[e]);             // lastly we have all the numbers till i smaller than pivot, so will replace i+1 with pivot element 
    return i+1;                           // returning the final index of the pivot
}

void quicksort(vector<int>&nums,int s,int e){
    if(s>=e){                                     // if there are 1 or no element in the partiton array,simply return
        return;
    }
    int firstpartition=partition(nums,s,e);      // finding the correct index of the pivot(nums[e]);
    quicksort(nums,s,firstpartition-1);          // sorting the left part of the array which is left to the correct index element(which was pivot);
    quicksort(nums,firstpartition+1,e);          //sorting the right part of the array which is right to the correct index element(which was pivot);
    return;
}



// worst case (N^2);
// avg case (NlogN);