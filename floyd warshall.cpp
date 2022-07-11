vector<vector<int>>floyd_warshall(int nodes,vector<vector<int>>&edges){
     vector<vector<int>>dis(nodes+1,vector<int>(nodes+1,100000));

     // construct the dis matrix using the edges
     for(auto l:edges){
        dis[l[0]][l[1]]=l[2];  // for directed edge
     }

     // IF NODES ARE STARTING FROM 1 START FROM 1 TO NODES ELSE START FROM 0 TO NODES-1

     for(int i=0;i<nodes;i++){
        for(int row=0;row<nodes;row++){
            for(int column=0;column<nodes;column++){
                if(row==column){
                    dis[row][column]=0;
                }
                else{
                  dis[row][column]=min(dis[row][column],dis[row][i]+dis[i][column]);
                }
            }
        }
     }
   return dis
}

