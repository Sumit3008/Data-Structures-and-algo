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

int n, SQRT, par[MAXX], ht[MAXX], rt[MAXX];
vector<int> G[MAXX];

void dfs(int v, int p = -1){
	if(p != -1) ht[v] = ht[p] + 1;
	par[v] = p;
	if(ht[v] % SQRT == 0) rt[v] = p;	//newlevel starts from here, newlevel node in prev level
	else rt[v] = rt[p];
	for(int i = 0;i < G[v].size();i++) if(G[v][i] != p) dfs(G[v][i], v);
}

int LCA(int u, int v){
	while(rt[u] != rt[v]){
		if(ht[u] > ht[v]) u = rt[u];
		else v = rt[v];
	}
	while(u != v){
		if(ht[u] > ht[v]) u = par[u];
		else v = par[v];
	}
	return u;
}

int LCAA(int u, int v){
	if(u == v) return u;
	if(ht[u] < ht[v]) swap(u, v);
	if(ht[u] == ht[v]){
		if(rt[u] == rt[v]) return LCA(par[u], par[v]);
		else return LCA(rt[u], rt[v]);
	}
	if(ht[u] - ht[v] < SQRT) return LCA(par[u], v);
	return LCA(rt[u], v);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("out.txt","w",stdout);
	
	SQRT = sqrt(n);
return 0;
}

//lower(==, lowestIdx), lower(>)
//upper(>)
