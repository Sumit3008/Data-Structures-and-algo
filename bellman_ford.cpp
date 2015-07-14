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

vector<pi_i> G[MAXX];
int dist[MAXX], n, m;

void bellman_ford(int source){
	fill(dist, dist+n+5, INF);
	dist[source] = 0;
	for(int i=1;i<=n;i++){	//loop n-1 times
		//traversing all edges O(m)
		for(int j=0;j<n;j++){
			for(int k = 0;k < G[j].size();k++){
				int v = G[j][k].FF;
				int w = G[j][k].SS;
				if(dist[v] > dist[j] + w){
					if(i == n){
						cout << "Negative Cycle Found" << endl;
						return;
					}else dist[v] = dist[j] + w;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	
return 0;	
}
