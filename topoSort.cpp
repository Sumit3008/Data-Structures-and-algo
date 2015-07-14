/*
	TOPOLOGICAL SORT (needs a Diricted Acyclic Graph)****
	Topo order : ordered according to Increasing endTime of a node.
*/
#include<iostream>
#include<vector>

#define PB push_back
#define MP make_pair
#define FF first
#define MAXX 100005

using namespace std;

typedef pair<int, int> pi_i;
vector< pi_i > G[MAXX];

vector<int> TopoList;

int n, m, visited[MAXX], startTime[MAXX], endTime[MAXX], timee=0;	//n = no of vertices, m = no of edges	

void dfs(int start){
	timee = timee+1;
	startTime[start] = timee;
	visited[start] = 1;
	for(int i=0;i<G[start].size();i++){
		if(visited[G[start][i].FF] == 0) dfs(G[start][i].FF);
	}
	//cout<<start<<endl;
	TopoList.PB(start);	//adding to list in topo order
	timee = timee+1;
	endTime[start] = timee;
}

int main(){
	cin>>n>>m;
	int p, q;
	for(int i=0;i<m;i++){
		cin>>p>>q;
		G[p].PB(MP(q, 1));	//dist is 1
	}
	for(int i=0;i<n;i++) if(visited[i] == 0) dfs(i);
	for(int i=0;i<n;i++){
		cout<<"Node "<<i<<" : "<<startTime[i]<<" "<<endTime[i]<<endl;
	}
	cout<<"\nTopological Order : \n";	//Increasing end time(i.e the first ele should be done first)
	for(int i=0;i<TopoList.size();i++){
		cout<<TopoList[i]<<" "<<endTime[TopoList[i]]<<endl;
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

