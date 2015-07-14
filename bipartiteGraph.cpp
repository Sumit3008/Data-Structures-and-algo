/*
	Bipartite graph : i.e checking if graph is bipartite or not using dfs and coloring(can also use bfs)
	1)color every node opposite to its parent
	2) if a child already visited then check that its color should be different than its parent
		** If color is the same then a odd cycle exists and graph is not bipartite
	3) If we find no odd cycles then graph is bipartite
*/

#include<iostream>
#include<vector>

#define PB push_back

using namespace std;

int n, m, visited[3000], col[3000];
vector<int> G[3000];
bool ans;

void dfs(int start, int color){
	int newColor;
	if(color == 1) newColor = 2;
	else newColor = 1;
	
	visited[start] = 1;
	col[start] = color;
	for(int i=0;i<G[start].size();i++){
		int m = G[start][i];
		if(visited[m] == 0) dfs(m, newColor);
		else{
			if(col[m] != newColor){	//odd cycle found graph not bipartite
				ans = false;
			}
		}
	}
}

int main(){
	
	ans = true;	//i.e assuming graph is bipartite
	
	cin>>n>>m;int aa, bb;
	for(int i=0;i<n;i++) G[i].clear(), visited[i] = 0, col[i] = 0;
	for(int i=0;i<m;i++){
		cin>>aa>>bb;
		G[aa].PB(bb);G[bb].PB(aa);
	}
	for(int i=0;i<n;i++){
		if(visited[i] == 0) dfs(i, 1);
	}
	
	if(ans == true){
		cout<<"Graph is Bipartite"<<endl;
	}else{
		cout<<"Graph is not Bipartite"<<endl;
	}
	
return 0;
}


