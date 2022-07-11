int mst(vector<vector<pair<int,int>>>&weighted_graph,int nodes){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q; //min heap having elements in the form of pair<int,int> where 1st element of the pair is weight and 2nd is nbr

    vector<bool>visited(nodes,false); // visited array ,here i am taking nodes number of elements because my graph right now is having nodes numbering from 0

    int ans=0;

    // note: the heap contains pair of the form <weight,nbr>, where as our graph contains pair of the form <nbr,weight>
    q.push({0,1}); //inserting 1st element in the heap (as it is the first element it is pointing to itself having weight 0)
    // if your nodes are starting from 1 or any other number just push {0,starting node} as first element in the heap as from this element only our algo is starting ,it's weight will not add to the answer as it is zero
    while(!q.empty()){

       auto top_element = q.top();
       q.pop();

       int weight = top_element.first;
       int node_value = top_element.second;

       if(visited[node_value] == true){
           continue;
       }

       ans += weight;

       visited[node_value]=true;

       // now iterate over all it's nbrs and check if they are visited or not,if not push them to min heap
       
       for(auto l: weighted_graph[node_value]){
          if(visited[l.first]==false){
              q.push({l.second,l.first});
          }
       }
    }
    return ans;
}


// time complexity : ElogV AS WE ARE USING HEAP WHICH HAS INSERTION OPERATION OF LOGN AND THERE ARE E EDGES