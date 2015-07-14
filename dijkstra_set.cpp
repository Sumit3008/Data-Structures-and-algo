#include<bits/stdc++.h>

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

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

int dist[MAXX], n, m;
vector<pi_i> G[MAXX];

void dijkstra(int source){
	fill(dist, dist+n+5, INF);
	dist[source] = 0;
	set<pi_i> Q;
	Q.insert(MP(0, source));
	while(!Q.empty()){
		pi_i top = *Q.begin();
		Q.erase(Q.begin());
		int u = top.SS;
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i].FF, cost = G[u][i].SS;
			if(dist[v] > dist[u] + cost){
				if(Q.find( MP(dist[v], v) ) != Q.end()){
					Q.erase( Q.find( MP(dist[v], v) ) );
				}
				dist[v] = dist[u] + cost;
				Q.insert( MP(dist[v], v) );
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	
return 0;	
}
