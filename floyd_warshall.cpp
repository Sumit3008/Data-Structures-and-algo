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

int dist[105][105], n, m;

void floyd_warshall(){
	for(int i = 0;i < 105;i++) for(int j = 0;j < 105;j++) if(i != j) dist[i][j] = INF;
	for(int i = 0;i < m;i++){
		cin >> u >> v >> w;
		dist[u][v] = w;dist[v][u] = w;
	}
	for(int k = 0;k < n;k++){	//intermidiate vertex
		for(int i= 0;i < n;i++){
			for(int j = 0;j < n;j++){
				dist[i][j] = min( dist[i][k] + dist[k][j], dist[i][j] );
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	
return 0;	
}
