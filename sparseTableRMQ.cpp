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

const int LOGMAX = log2(MAXX)+1;
int a[MAXX], n, ST[MAXX][LOGMAX];	//ST[i][j] is the index of the minimum value in the sub array 
					//starting at i having length 2^j

void process(){
	for(int i=0;i<n;i++) ST[i][0] = i;
	for(int j = 1; 1 << j <= n; j++){
		for(int i = 0; i + (1 << j) - 1 < n; i++){
			int idx1 = ST[i][j-1];
			int idx2 = ST[ i + (1 << (j-1)) ] [j-1];
			if(a[idx1] <= a[idx2]) ST[i][j] = idx1;
			else ST[i][j] = idx2;
		}
	}
}

int RMQ(int L, int R){
	int k = log2(R-L+1);	//int k = 31 - __builtin_clz(R-L+1);
	int idx1 = ST[L][k];
	int idx2 = ST[R - (1 << k) + 1][k];
	if(a[idx1] <= a[idx2]) return idx1;
	else return idx2;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	
return 0;	
}

