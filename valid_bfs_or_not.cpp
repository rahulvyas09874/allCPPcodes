
// the idea is simple i am taking a set for every node in the queue where i am passing the childrens to the set and i am also taking a global variable curr_index (this variable help me in moving through the sequence array ,it is initialized to 1)
// once all unvisited childrens are passed to the set(coz search operation is in O(1)) , i will iterate through the set and search for sequence[curr_idx],if it doesn't exist i will return false
// else i will increase curr_index++ and push sequence[curr_index] to queue coz it's a valid children and  search for next element

bool validBFS(int n, vector<int> sequence , vector<vector<int>>edges){
    vector<bool>visited(n+1,false);
    vector<vector<int>>graph(n+1);
    for(auto l:edges){
        graph[l[0]].push_back(l[1]);
        graph[l[1]].push_back(l[0]);
    }
    bool flag=false;
    int curr_index=1;
    queue<int>q;
    q.push(1);
    visited[1]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        set<int>s;
        for(auto nbrs:graph[top]){
            if(!visited[nbrs]){
                visited[nbrs]=true;
                s.insert(nbrs);
            }
        }
        int temp_size=0;
        while(temp_size<s.size()){
            if(s.count(sequence[curr_index])==0){
                return false;
            }
            q.push(sequence[curr_index]);
            curr_index++;
            temp_size++;
    }
    
  }
return true;
}


