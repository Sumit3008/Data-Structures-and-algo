/*
	Strongly connected components (needs a Diricted Graph)****
	
	Steps : 
	1) call DFS(G) for all vertices, and compute endTimes of all nodes
	2) compute G_T i.e transpose of G, by reversing all edges
	3) call DFS_reverse(G_T) and call all vertices in order of decreasing End Times from step 1.
	4) each traversal of DFS_reverse(G_T) of a node is outputed as a seperate SCC.
	
	To check that is graph SC : 
	1) call DFS(G) for only 1 vertice(starting vertice), if any vertice is not visited return false
	2) compute G_T i.e transpose of G, by reversing all edges
	3) call DFS_reverse(G_T) from the starting vertice, if any vertice is not visited then return false
	4) return true
*/
#include<iostream>
#include<vector>

#define PB push_back
#define MP make_pair
#define FF first
#define MAXX 100005

using namespace std;

typedef pair<int, int> pi_i;
vector< pi_i > G[MAXX], G_T[MAXX];

vector<int> List;

int n, m, visited[MAXX], startTime[MAXX], endTime[MAXX], timee=0;	//n = no of vertices, m = no of edges	

void dfs(int start){
	timee = timee+1;
	startTime[start] = timee;
	visited[start] = 1;
	for(int i=0;i<G[start].size();i++){
		if(visited[G[start][i].FF] == 0) dfs(G[start][i].FF);
	}
	List.PB(start);
	timee = timee+1;
	endTime[start] = timee;
}

void dfs_reverse(int start){
	visited[start] = 1;
	cout<<start<<" ";
	for(int i=0;i<G_T[start].size();i++){
		if(visited[G_T[start][i].FF] == 0) dfs_reverse(G_T[start][i].FF);
	}
}

int main(){
	cin>>n>>m;
	int p, q;
	for(int i=0;i<m;i++){
		cin>>p>>q;
		G[p].PB(MP(q, 1));	//dist is 1
		G_T[q].PB(MP(p, 1));	//transpose of G
	}
	for(int i=0;i<n;i++) if(visited[i] == 0) dfs(i);
	for(int i=0;i<n;i++){
		cout<<"Node "<<i<<" : "<<startTime[i]<<" "<<endTime[i]<<endl;
	}
	
	for(int i=0;i<n;i++) visited[i] = 0;
	timee = 0;
	
	cout<<"\nSCC's : "<<endl;
	for(int i=List.size()-1;i>=0;i--){	//Decreasing order of time
		if(visited[List[i]] == 0){
			dfs_reverse(List[i]);
			cout<<endl;
		}
	}
	
return 0;
}

/*
6 8
0 1
0 2
2 1
1 3
3 2
4 3
4 5
5 5
*/

/*
corman example : 
8 14
0 1
1 2
1 5
1 4
2 3
2 6
3 2
3 7
4 5
4 0
5 6
6 5
6 7
7 7
*/

