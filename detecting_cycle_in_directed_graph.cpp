bool dfs(int start,vector<bool>visited,vector<bool>stack,vector<vector<int>>graph){
    visited[start]=true;
    stack[start]=true;

    for(auto child:graph[start]){
        if(visited[child]==true and stack[child]==true){
            return true;
        }
        else if(visited[child]==false){
            if(dfs(child,visited,stack,graph)){
                return true;
            }
        }
    }
    stack[start]=false;
    return false;
}





bool cycle(int n,vector<vector<int>>edges){
    vector<vector<int>>graph(n+1);
    for(auto l:edges){
        graph[l[0]].push_back(l[1]);
    }
    vector<bool>visited(n+1,false);
    vector<bool>stack(n+1,false);
    for(int i=0;i<n+1;i++){
        if(!visited[i]){
            if(dfs(i,visited,stack,graph)){
                return true;
            }
        }

    }
    return false;
}
