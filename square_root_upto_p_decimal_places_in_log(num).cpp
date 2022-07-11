float square_root_of_a_number(int num,int p){
   float ans=0;
   // for integer part
   int s=0;
   int e=num;
   int integer_part=0;                   // the idea is simple just use binary search where s=0 and e=num
   while(s<=e){                          // we will not return anyhting from this fn(either we will get out of while loop)
      int mid=(s+e)/2;                   // when s>e or will break when mid the root till then we will do binary search only
      if(mid*mid==num){                  // and if we encounter mid*mid<num , we will keep updating our answer to be mid
         integer_part=mid;               // coz we need to find the just int value (which is gonna be somewhat less than the actual root)
         break;                          // for e.g in some case 1 2 3 4 5 6 let mid=3 and e=4 then we will make ans =mid
      }                                  //  coz mid*mid <num and will make s= mid+1 now both e and s are same so we will get mid as e
      else if(mid*mid<num){              //  and upon checking mid*mid>num so we will make e=mid-1, now s>e , we will break
         integer_part=mid;
         s=mid+1;
        
      }
      else{
         e=mid-1;
      }
   }
   ans+=integer_part;
   // for decimal part
   float inc=0.1;
   for(int place=1;place<=p;place++){          //  as we want only p decimal places , so we will find the
      int p=1;                                 // max value which can be accomodated a each point 
      while(ans*ans<=num and p<=9){
         ans+=inc;
         p++;
      }
      ans-=inc;
      inc/=10.0;

   }

   return ans;


   
}