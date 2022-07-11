void generatesubsequencesusingbitmask(string s,vector<string>&ans){
    int n=s.length();
    int subseq=(1<<n)-1;
    for(int i=1;i<=subseq;i++){
        int temp=i,j=0;
        string noob="";
        while(temp>0){
            if(temp&1){
               noob+=s[j];
            }
            j++;
            temp=temp>>1;
        }
        ans.push_back(noob);
    }
}