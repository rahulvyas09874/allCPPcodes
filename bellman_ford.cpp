vector<int>bellman_ford(vector<vector<int>>&graph,int nodes,int src){  // graph is of the form {{a,b,c},{a1,b1,c1}} here there is a edge b/w a and b with weight c

	vector<int>distance(nodes+1,INT_MAX);  // DISTANCE ARRAY
	distance[src]=0;

	for(int i=0;i<nodes-1;i++){       // iterating over the edges nodes-1 times
        for(auto l:graph){
        	int par=l[0];
        	int child=l[1];
        	int weight=l[2];

        	if(distance[par]!=INT_MAX and distance[par]+weight<distance[child]){
        		distance[child]=distance[par]+weight;
        	}
        }
	}
	// check if there is a -ve weight cycle or not (to check this we can iterate over the edges one more time and 
	// relax them one time and check whether the distance to any node decreased or not, if it decreases then there is a -ve wt. cycle)
	for(auto l:graph){
		int par=l[0];
		int child=l[1];
		int weight=l[2];

		if(distance[par]!=INT_MAX and distance[par]+weight<distance[child]){ // there is a -ve cycle
              cout << "A -ve cycle Exist";
              exit(0);
		}
	}
	return distance;


}
