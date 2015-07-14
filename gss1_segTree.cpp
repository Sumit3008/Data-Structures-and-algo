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

typedef pair <LL, LL> pi_i;
typedef pair<pi_i, pi_i> pii_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

int n, a[MAXX], m;

struct node{
	int tot, l, r, best;
}ST[MAXX];

node merge(node n1, node n2){
	node temp;
	temp.tot = n1.tot + n2.tot;
	temp.l = max(n1.l , n1.tot+n2.l);
	temp.r = max(n2.r, n2.tot+n1.r);
	temp.best = max( max(n1.best, n2.best), n1.r+n2.l );
return temp;
}

void build(int idx, int start, int end){
	if(start == end){
		ST[idx].best = a[start];ST[idx].tot = a[start];
		ST[idx].l = a[start];ST[idx].r = a[start];
		return;
	}
	int mid = (start+end)/2;
	build(2*idx, start, mid);
	build(2*idx+1, mid+1, end);
	ST[idx] = merge(ST[2*idx], ST[2*idx+1]);
}

node query(int idx, int start, int end, int L, int R){
	node ans;
	ans.tot = INF, ans.l = 0; ans.r = 0;ans.best = 0;
	if(start > R || end < L) return ans;
	if(start >= L && end <= R) return ST[idx];
	int mid = (start+end)/2;
	node n1 = query(2*idx, start, mid, L, R);
	node n2 = query(2*idx+1, mid+1, end, L, R);
	if(n1.tot == INF) return n2;
	if(n2.tot == INF) return n1;
	ans = merge(n1, n2);
return ans;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	//cin >> n;
	scanf("%d", &n);
	//for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	build(1, 0, n-1);
	
	//cin >> m;
	scanf("%d", &m);
	int a, b;
	while( m-- ){
		//cin >> a >> b;a--;b--;
		scanf("%d%d", &a, &b);a--;b--;
		node ans = query(1, 0, n-1, a, b);
		printf("%d\n", ans.best);
		//cout << query(1, 0, n-1, a, b).best << endl;
	}
return 0;	
}
