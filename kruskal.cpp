#include<iostream>
#include<algorithm>
#include<vector>
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define MAXX 1000006

using namespace std;

typedef pair<int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

int n, m, dsu[MAXX];
vector< pi_ii > V, MST;	//vector containing (edge wt, u, v)
vector< pi_i > G[MAXX];	//vector containing (v, wt)

int find(int val){
	if(dsu[val] < 0) return val;
	else{
		dsu[val] = find(dsu[val]);
		return dsu[val];
	}
}

void merge(int ele1, int ele2){
	int root1 = find(ele1), root2 = find(ele2);
	if(dsu[root1] < dsu[root2]){
		dsu[root1] += dsu[root2];
		dsu[root2] = root1;
	}else{
		dsu[root2] +=dsu[root1];
		dsu[root1] = root2;
	}
}

void kruskal(){
	for(int i=0;i<n;i++) dsu[i] = -1;
	
	sort(V.begin(), V.end());
	
	for(int i=0;i<m;i++){
		int u = V[i].SS.FF, v = V[i].SS.SS, w = V[i].FF;
		if(find(u) != find(v)){
			MST.PB(MP(w, MP(u, v)));
			merge(u, v);
		}
	}
}

int main(){
	cin>>n>>m;int u, v, w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		V.PB(MP(w, MP(u, v)));
		G[u].PB(MP(v, w));G[v].PB(MP(u, w));
	}
	
return 0;
}


