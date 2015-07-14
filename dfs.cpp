#include<iostream>
#include<vector>

#define PB push_back
#define MP make_pair
#define FF first
#define MAXX 100005

using namespace std;

typedef pair<int, int> pi_i;
vector< pi_i > G[MAXX];

int n, m, visited[MAXX];	//n = no of vertices, m = no of edges	

void dfs(int start){
	visited[start] = 1;
	for(int i=0;i<G[start].size();i++){
		if(visited[G[start][i].FF] == 0) dfs(G[start][i].FF);
	}
	cout<<start<<endl;
}

int main(){
	cin>>n>>m;
	int p, q;
	for(int i=0;i<m;i++){
		cin>>p>>q;
		G[p].PB(MP(q, 1));	//dist is 1
		//G[q].PB(MP(p, 1));	//for undirected
	}
	for(int i=0;i<n;i++) if(visited[i] == 0) dfs(i);
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

