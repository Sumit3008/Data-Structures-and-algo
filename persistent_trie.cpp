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

#define MAXX 50000000

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

int root[MAXX], chld[MAXX][2], cnt[MAXX], bits = 19;
int NEXT_FREE_IDX = 1, rt = 1;

void copy(int curr, int prev){
	chld[curr][0] = chld[prev][0];
	chld[curr][1] = chld[prev][1];
	//LOG(chld[curr][0]);
	//LOG(chld[curr][1]);cout<<endl;
}

void insert(int x){
	int currNode = root[rt] = NEXT_FREE_IDX;
	NEXT_FREE_IDX++;
	copy( currNode, root[rt-1] );
	cnt[currNode] = cnt[ root[rt-1] ] + 1;
	rt++;
	for(int i = bits;i >= 0;i--){
		int b = (x >> i) & 1;
		if(chld[currNode][b] > 0){	//bit exists in prev versions of trie
			copy( NEXT_FREE_IDX, chld[currNode][b] );	//copying bits to new version
			cnt[NEXT_FREE_IDX] = cnt[ chld[currNode][b] ];
		}
		chld[currNode][b] = NEXT_FREE_IDX;
		currNode = NEXT_FREE_IDX;
		cnt[currNode]++;
		NEXT_FREE_IDX++;
	}
}

void del(int k){
	rt -= k;
}

int xorMax(int L, int R, int x){
	int a = root[L], b = root[R];
	int y = 0;
	for(int i=bits;i>=0;i--){
		bool c = !((x >> i) & 1);
		if( cnt[ chld[a][c] ] < cnt[ chld[b][c] ] ){	//if cnt is smaller i.e a bit was added in the interval from a to b
			y |= c << i;
			a = chld[a][c];
			b = chld[b][c];
		}else if( cnt[ chld[a][!c] ] < cnt[ chld[b][!c] ] ){
			y |= (!c) << i;
			a = chld[a][!c];
			b = chld[b][!c];
		}else break;	//cannot maximize xor furthur
	}
	return y;
}

int order_of_key(int L, int R, int x){	//no of ele smaller than k
	int a = root[L], b = root[R];
	int ans = 0;
	for(int i=bits;i>=0;i--){
		bool c = (x >> i) & 1;
		if(c == 1) ans += cnt[ chld[b][0] ] - cnt[ chld[a][0] ];	//counting ele to the left
		a = chld[a][c];
		b = chld[b][c];
	}
	ans += cnt[b] - cnt[a];	//ele equal to x
	return ans;
}

int find_by_order(int L, int R, int x){	//kth order stat
	int a = root[L], b = root[R];
	int ans = 0;
	for(int i=bits;i>=0;i--){
		//LOG(cnt[ chld[b][0] ] - cnt[ chld[a][0] ]);
		//LOG(a);LOG(b);
		if(x > cnt[ chld[b][0] ] - cnt[ chld[a][0] ]){
			x -= (cnt[ chld[b][0] ] - cnt[ chld[a][0] ]);
			ans |= 1 << i;
			a = chld[a][1];
			b = chld[b][1];
		}else{
			a = chld[a][0];
			b = chld[b][0];
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("out.txt","w",stdout);
	
	int m, qr;
	cin >> m;
	while( m-- ){
		cin >> qr;
		if(qr == 0){
			int x;cin >> x;
			insert(x);
		}else if(qr == 1){
			int L, R, x;cin >> L >> R >> x;
			cout << xorMax(L-1, R, x) << endl;
		}else if(qr == 2){
			int k;cin >> k;
			del(k);
		}else if(qr == 3){
			int L, R, x;cin >> L >> R >> x;
			cout << order_of_key(L-1, R, x) << endl;
		}else{
			int L, R, x;cin >> L >> R >> x;
			cout << find_by_order(L-1, R, x) << endl;
		}
	}
	
return 0;	
}
