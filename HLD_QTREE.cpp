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

#define MAXX 50005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

const int LOGMAX = log2(MAXX) + 1;
int n, par[MAXX][LOGMAX], subsize[MAXX], ht[MAXX], otherEnd[MAXX];
int chainNo, chainHead[MAXX], chainIdx[MAXX], posInBase[MAXX];
int baseArray[MAXX], ptr;
int ST[6*MAXX];
vector<int> G[MAXX], cost[MAXX], idx[MAXX];

inline void build(int idx, int st, int en){
	if(st == en){
		ST[idx] = baseArray[st];
		return;
	}
	int mid = (st+en)/2;
	build(2*idx, st, mid);
	build(2*idx+1, mid+1, en);
	if(ST[2*idx] > ST[2*idx+1]) ST[idx] = ST[2*idx];
	else ST[idx] = ST[2*idx+1];
}

inline int queryST(int idx, int st, int en, int L, int R){
	if(st > R || en < L) return -1;
	if(st >= L && en <= R) return ST[idx];
	int mid = (st+en)/2;
	int ans1 = queryST(2*idx, st, mid, L, R);
	int ans2 = queryST(2*idx+1, mid+1, en, L, R);
	if(ans1 > ans2) return ans1;return ans2;
}

inline int query_up(int u, int v){	//v is ancestor of u
	if(u == v) return 0;
	int uchain, vchain = chainIdx[v], ans = -1;
	
	while(1){
		uchain = chainIdx[u];
		if(uchain == vchain){
			if(u == v) break;
			int temp = queryST(1, 0, ptr-1, posInBase[v]+1, posInBase[u]);
			if(temp > ans) ans = temp;
			break;
		}
		int temp = queryST(1, 0, ptr-1, posInBase[chainHead[uchain]], posInBase[u]);
		if(temp > ans) ans = temp;
		u = chainHead[uchain];
		u = par[u][0];
	}
	return ans;
}

inline void updateST(int idx, int st, int en, int L, int val){
	if(st > L || en < L) return;
	if(st == L && en == L){
		ST[idx] = val;return;
	}
	int mid = (st+en)/2;
	updateST(2*idx, st, mid, L, val);
	updateST(2*idx+1, mid+1, en, L, val);
	if(ST[2*idx] > ST[2*idx+1]) ST[idx] = ST[2*idx];
	else ST[idx] = ST[2*idx+1];
}

inline void change(int i, int val){
	int u = otherEnd[i];
	updateST(1, 0, ptr-1, posInBase[u], val);
}

inline int LCA(int u, int v){
	if(ht[u] < ht[v]) swap(u, v);
	for(int i = LOGMAX - 1;i >= 0;i--) if(par[u][i] != -1 && ht[par[u][i]] >= ht[v]) u = par[u][i];
	//now ht[u] == ht[v]
	if(u == v) return u;
	for(int i = LOGMAX - 1;i >= 0;i--) if(par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return par[u][0];
}

inline int query(int u, int v){
	int lca = LCA(u, v);
	int ans1 = query_up(u, lca);
	int ans2 = query_up(v, lca);
	if(ans2 > ans1) return ans2;return ans1; 
}

inline void HLD(int curr, int prev, int costt){
	if(chainHead[chainNo] == -1) chainHead[chainNo] = curr;
	chainIdx[curr] = chainNo;
	posInBase[curr] = ptr;
	baseArray[ptr++] = costt;
	
	int sc = -1, scCost;
	for(int i = 0;i < G[curr].size();i++){
		if(G[curr][i] != prev){
			if(sc == -1 || subsize[sc] < subsize[G[curr][i]]){
				sc = G[curr][i];
				scCost = cost[curr][i];
			}
		}
	}
	
	if(sc != -1) HLD(sc, curr, scCost);
	
	for(int i = 0;i < G[curr].size();i++){
		if(G[curr][i] == prev) continue;
		if(sc != G[curr][i]){
			chainNo++;
			HLD(G[curr][i], curr, cost[curr][i]);
		}
	}
}

inline void dfs_lca(int curr, int prev, int _ht){
	par[curr][0] = prev;
	ht[curr] = _ht;
	subsize[curr] = 1;
	
	for(int i = 1;i < LOGMAX;i++) if(par[curr][i-1] != -1) par[curr][i] = par[par[curr][i-1]][i-1];
	
	for(int i = 0;i < G[curr].size();i++){
		if(G[curr][i] != prev){
			otherEnd[idx[curr][i]] = G[curr][i];
			dfs_lca(G[curr][i], curr, _ht+1);
			subsize[curr] += subsize[G[curr][i]];
		}
	}
}

inline void init(){
	memset(par, -1, sizeof par);
	ptr = 0;
	for(int i = 0;i < n;i++) G[i].clear(), cost[i].clear(), idx[i].clear(), chainHead[i] = -1;
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("out.txt","w",stdout);
	
	int t;scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		init();
		for(int i = 1;i < n;i++){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);u--;v--;
			G[u].PB(v);G[v].PB(u);
			cost[u].PB(c);cost[v].PB(c);
			idx[u].PB(i-1);idx[v].PB(i-1);
		}
		
		chainNo = 0;
		dfs_lca(0, -1, 0);
		HLD(0, -1, -1);
		build(1, 0, ptr-1);
		
		char que[20];
		int a, b;
		while(1){
			scanf("%s", que);
			if(que[0] == 'D') break;
			scanf("%d%d", &a, &b);
			if(que[0] == 'Q'){
				printf("%d\n", query(a-1, b-1));
			}else{
				change(a-1, b);
			}
		}
	}

return 0;
}

//lower(==, lowestIdx), lower(>)
//upper(>)
/*
1
10
1 2 1
1 3 3
1 4 1
2 7 5
3 5 2
3 6 1
7 8 3
6 9 3
9 10 4
*/
