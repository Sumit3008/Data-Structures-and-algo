/*
	Note : this can be modified for eluerian tour as it has 2 vertices that have odd degree(start, end) 
	Note : in directed graph indegree of each node equals its outdegree
	Note : needs to be modified for multiple edges the visited edges are multiple
*/
#include <bits/stdc++.h>
#include <unistd.h>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

int n, m, deg[MAXX];
vector<int> G[MAXX];
set<pi_i> vis;

void euler_ckt(int node){
	for(int i = 0;i<G[node].size();i++){
		int v = G[node][i];
		if(vis.count(MP(node, v)) == 0){
			vis.insert(MP(node, v));
			vis.insert(MP(v, node));
			euler_ckt(G[node][i]);
		}
	}
	cout << node << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		int p, q;
		cin >> p >> q;
		G[p].PB(q);G[q].PB(p);
		deg[p]++;deg[q]++;
	}
	for(int i = 1;i<=n;i++){
		if(deg[i] % 2 == 1){
			cout << "Euler ckt not possible odd degree found" << endl;
			return 0;
		}
	}
	euler_ckt(1);
	cout << endl;
	
return 0;	
}
/*
7 12
1 4
1 5
2 4
2 5
2 6
2 7
3 4
3 7
4 6
5 6
5 7
6 7
*/


