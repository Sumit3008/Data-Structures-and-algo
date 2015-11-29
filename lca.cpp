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
template<class T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

const int LOGMAX = log2(MAXX);
int n, par[MAXX][LOGMAX], ht[MAXX], rt[MAXX];
vector<int> G[MAXX];

void dfs(int v, int p = -1){
	par[v][0] = p;
	if(p != -1) ht[v] = ht[p] + 1;
	for(int i = 1;i < LOGMAX;i++){
		if(par[v][i-1] != -1) par[v][i] = par[par[v][i-1]][i-1]; 
	}
	for(int i = 0;i < G[v].size();i++) if(G[v][i] != p) dfs(G[v][i], v);
}

int LCA(int u, int v){
	if(ht[u] < ht[v]) swap(u, v);
	for(int i = LOGMAX - 1;i >= 0;i--) if(par[u][i] != -1 && ht[par[u][i]] >= ht[v]) u = par[u][i];
	//now ht[u] == ht[v]
	if(u == v) return u;
	for(int i = LOGMAX - 1;i >= 0;i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("out.txt","w",stdout);
	
	memset(par, -1, sizeof par);
return 0;
}

//lower(==, lowestIdx), lower(>)
//upper(>)
