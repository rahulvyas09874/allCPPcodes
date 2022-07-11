class dijkshtra{

public:
    vector<int>distance,parent;
    vector<vector<pair<int,int>>>graph;                        // graph has edges as a vector of 2 elements where 1st one is the distance and 2nd is the node
    dijkshtra(int nodes,vector<vector<pair<int,int>>>&adj){
        graph=adj;
        distance.resize(nodes+1,INT_MAX);
        parent.resize(nodes+1,-1);
    }

    int find_dis(int src,int des){
    set<pair<int,int>>s;
    distance[src]=0;
    s.insert({0,src}); //inserting src node as 1st element in the set ,the element will look like: {0,src}
    parent[src]=src;
    while(!s.empty()){
        auto it=s.begin();
        int node=it->second;
        int dis_till_curr_node=it->first;
        s.erase(it);
        for(auto nbr:graph[node]){

            int nbr_node=nbr.second;
            int curr_egde_dis=nbr.first;

            if( dis_till_curr_node + curr_egde_dis < distance[nbr_node] ){

                // if a entry of nbr_node already exist in the set, delete that entry first
             auto temp=s.find( {distance[nbr_node],nbr_node} );

             if(temp!=s.end()) {
                s.erase(temp);
             }

             // update the distance and insert it into the set
              distance[nbr_node]=dis_till_curr_node+curr_egde_dis;  
              s.insert( { distance[nbr_node] , nbr_node });
              parent[nbr_node]=node;
            }
        }
    }
    return distance[des];
  }
  // this function will return the path followed to find the shortest distance
  vector<int> find_path(int src,int des){    //returns the node path followed to reach des from src
    find_dis(src,des);
    vector<int>ans;
    int temp=des;
    while(temp!=src){
        ans.push_back(temp);
        temp=parent[temp];
    }
    ans.push_back(src);
    reverse(ans.begin(),ans.end());
    return ans;
  }





};