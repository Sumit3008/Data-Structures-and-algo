/*
	TOPOLOGICAL SORT (needs a Diricted Acyclic Graph)****
	Algo : (Queue + indegree) algorithm
	1) calculate all indegrees
	2) add all nodes with indegree = 0 to a set
	3) while set != empty
	4) remove a node from set and traverse all outgoing edges and remove them
	5) if when removing edges some node has outdegree of 0 add it to set
*/
#include<iostream>
#include<vector>
#include<set>

#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define MAXX 100005

using namespace std;

typedef pair<int, int> pi_i;
vector< pi_i > G[MAXX];

vector<int> TopoList;
set<int> S;

int n, m, indegree[MAXX];	//n = no of vertices, m = no of edges	

void TopoSort(){
	for(int i=0;i<n;i++){
		if(indegree[i] == 0) S.insert(i);
	}
	while(S.size() != 0){
		int node = *S.begin();
		S.erase(S.begin());
		TopoList.PB(node);
		for(int i=0;i<G[node].size();i++){
			int m = G[node][i].FF;		//edge from n to m
			if(G[node][i].SS == 1){
				G[node][i].SS == 0;	//remove edge
				indegree[m]--;
				
				if(indegree[m] <= 0) S.insert(m);
			}
		}
	}
	
	//if(GRAPH HAS EDGES) RETURN ERROR THAT GRAPH HAS CYCLES
}

int main(){
	cin>>n>>m;
	int p, q;
	for(int i=0;i<m;i++){
		cin>>p>>q;
		G[p].PB(MP(q, 1));	// 1 tells that edge present i.e has not been removed during algo
		indegree[q]++;		//direction of edge =>   p ----> q
	}
	
	TopoSort();
	
	cout<<"\nTopological Order : \n";	//Increasing end time(i.e the first ele should be done first)
	for(int i=0;i<TopoList.size();i++){
		cout<<TopoList[i]<<" "<<endl;
	}
return 0;
}

/*
6 6
0 1
0 2
2 1
1 3
4 3
4 5
*/

