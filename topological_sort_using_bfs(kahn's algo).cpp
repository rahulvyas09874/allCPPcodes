vector<int>topological_sort_for_DAG_using_bfs(vector<vector<int>>&graph,int n){
    vector<bool>visited(n,false);
    vector<int>indegree_for_nodes(n,0);
    for(auto l:graph){
        for(auto p:l){
            indegree_for_nodes[p]++;
        }
        
    }
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree_for_nodes[i]==0){
            q.push(i);
            visited[i]=true;
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        ans.push_back(curr);
        for(auto l:graph[curr]){
                indegree_for_nodes[l]--;
                if(indegree_for_nodes[l]==0){
                    q.push(l);
                } 
        }


    }
    if(ans.size()!=n){
        ans.clear();
    }
    return ans;
}
  